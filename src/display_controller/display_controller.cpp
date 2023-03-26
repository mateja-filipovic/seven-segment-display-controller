#include "display_controller.h"

// VARIABLES -------------------------------------------------------------

SevSeg_Number DisplayController::numbers[] = {
    { { HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, LOW } },    // 0
    { { LOW, HIGH, HIGH, LOW, LOW, LOW, LOW } },        // 1
    { { HIGH, HIGH, LOW, HIGH, HIGH, LOW, HIGH } },     // 2
    { { HIGH, HIGH, HIGH, HIGH, LOW, LOW, HIGH } },     // 3
    { { LOW, HIGH, HIGH, LOW, LOW, HIGH, HIGH } },      // 4
    { { HIGH, LOW, HIGH, HIGH, LOW, HIGH, HIGH } },     // 5
    { { HIGH, LOW, HIGH, HIGH, HIGH, HIGH, HIGH } },    // 6
    { { HIGH, HIGH, HIGH, LOW, LOW, LOW, LOW } },       // 7
    { { HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH } },   // 8
    { { HIGH, HIGH, HIGH, HIGH, LOW, HIGH, HIGH } }     // 9
};

SecSeg_Digit DisplayController::digits[] = {
    { { LOW, HIGH, HIGH, HIGH } },                      // FIRST
    { { HIGH, LOW, HIGH, HIGH } },                      // SECOND
    { { HIGH, HIGH, LOW, HIGH } },                      // THIRD
    { { HIGH, HIGH, HIGH, LOW } }                       // FOURTH
};

uint8_t DisplayController::display_segment_pins_ordered[] = 
{ 
    SEGMENT_A_PIN,
    SEGMENT_B_PIN,
    SEGMENT_C_PIN,
    SEGMENT_D_PIN,
    SEGMENT_E_PIN,
    SEGMENT_F_PIN,
    SEGMENT_G_PIN 
};

uint8_t DisplayController::display_display_segment_pins_ordered[] =
{
    DIGIT_1_PIN,
    DIGIT_2_PIN,
    DIGIT_3_PIN,
    DIGIT_4_PIN
};

// CODE -------------------------------------------------------------

void DisplayController::initalize_output_pins()
{
    for (uint8_t i = 0; i < 7; i++)
        pinMode(display_segment_pins_ordered[i], OUTPUT);

    for (uint8_t i = 0; i < 7; i++)
        pinMode(display_display_segment_pins_ordered[i], OUTPUT);
}

void DisplayController::print_number_on_digit(uint8_t number, uint8_t digit)
{
    for (uint8_t i = 0; i < 7; i++)
        digitalWrite(display_segment_pins_ordered[i], numbers[number].active[i]);
    
    for (uint8_t j = 0; j < 4; j++)
        digitalWrite(display_display_segment_pins_ordered[j], digits[digit].active[j]);
}