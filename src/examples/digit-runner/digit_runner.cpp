#include "digit_runner.h"

DigitRunner::DigitRunner(DisplayController* _display_controller) :
    display_controller(_display_controller),
    digit(0),
    number(0) { }

void DigitRunner::run_example()
{
    run_digits();
}

void DigitRunner::run_digits()
{
    for(uint8_t i = 0; i < DIGIT_RUNNER_MAX_ITERATIONS; i++)
    {
        display_controller->print_number_on_digit(number, digit);

        number = (number + 1) % (DIGIT_RUNNER_NUMBER_MAX_VALUE + 1);
        digit = (digit + 1) % DIGIT_RUNNER_NUMBER_OF_DIGITS;
        
        delay(DIGIT_RUNNER_INTERVAL);
    }
}