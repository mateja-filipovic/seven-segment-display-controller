#ifndef _DISPLAY_CONTROLLER_
#define _DISPLAY_CONTROLLER_

#include "Arduino.h"

//       _ _ A _ _
//      |         |
//      F         B
//      |         |
//      |_ _ G _ _|
//      |         |
//      E         C
//      |         |
//      |_ _ D _ _| *H

// SEGMENT PINS
#define SEGMENT_A_PIN 11
#define SEGMENT_B_PIN 7
#define SEGMENT_C_PIN 4
#define SEGMENT_D_PIN 2
#define SEGMENT_E_PIN 1
#define SEGMENT_F_PIN 10
#define SEGMENT_G_PIN 5
#define SEGMENT_H_PIN 3 // decimal point

// DIGIT PINS
#define DIGIT_1_PIN 12
#define DIGIT_2_PIN 9
#define DIGIT_3_PIN 8
#define DIGIT_4_PIN 6

struct SevSeg_Number
{
    byte active[8];
};

struct SecSeg_Digit
{
    byte active[4];
};

class DisplayController
{

public:
    void initalize_output_pins();
    void print_number_on_digit(uint8_t, uint8_t);
    void activate_digit(uint8_t digit);
    void print_number(uint8_t number);

private:
    static SevSeg_Number numbers[10];
    static SecSeg_Digit digits[4];
    static uint8_t display_segment_pins_ordered[7];
    static uint8_t display_display_segment_pins_ordered[7];
    
};

#endif