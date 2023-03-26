#ifndef _DIGIT_RUNNER_H_
#define _DIGIT_RUNNER_H_

#include <Arduino.h>
#include "../../display_controller/display_controller.h"

#define DIGIT_RUNNER_INTERVAL 1000          // switch digits & increment every 1000 millis
#define DIGIT_RUNNER_NUMBER_MAX_VALUE 9
#define DIGIT_RUNNER_NUMBER_OF_DIGITS 4
#define DIGIT_RUNNER_MAX_ITERATIONS 100

class DigitRunner
{
public:
    DigitRunner(DisplayController* _display_controller);
    void run_example();

private:
    void run_digits();

    uint8_t digit;
    uint8_t number;

    DisplayController* display_controller;
};

#endif