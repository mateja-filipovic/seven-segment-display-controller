#ifndef _COUNTER_H_
#define _COUNTER_H_

#include <Arduino.h>
#include "../../display_controller/display_controller.h"

#define COUNTER_DIGIT_SWITCH_INTERVAL 2000      // switch digits every 2000 millis
#define COUNTER_UPDATE_INTERVAL 300             // increase the counter every 300 millis             
#define COUNTER_MAX_VALUE 201 
#define COUNTER_NUMBER_OF_DIGITS 4     

class Counter
{

public:
    Counter(DisplayController* _display_controller);
    void run_example();

private:
    void count();
    void update_counter();

    DisplayController* display_controller;      // used to display the counter

    unsigned long last_millis_checkpoint;
    uint16_t counter;
    uint8_t digits[COUNTER_NUMBER_OF_DIGITS];   // digits[0] is the biggest, and digits[3] is the smallest

};

#endif