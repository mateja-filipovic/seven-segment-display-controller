#include "counter.h"

Counter::Counter(DisplayController* _display_controller) : 
    display_controller(_display_controller),
    last_millis_checkpoint(0),
    counter(0) { }

void Counter::run_example()
{
    count();
}

void Counter::count()
{
    while (counter <= COUNTER_MAX_VALUE)
    {
        digits[0] = counter / 1000;
        digits[1] = (counter / 100) % 10;
        digits[2] = (counter / 10) % 10;
        digits[3] = counter % 10;

        // display each digit on display
        for (uint8_t i = 0; i < COUNTER_NUMBER_OF_DIGITS; i++){
            display_controller->print_number_on_digit(digits[i], i);
            delayMicroseconds(COUNTER_DIGIT_SWITCH_INTERVAL);
        }

        update_counter();
    }
}

// check if COUNTER_UPDATE_INTERVAL milliseconds have passed since the last increment
// if true, increment the counter
void Counter::update_counter()
{
    unsigned long time_now_millis = millis();

    if(time_now_millis - last_millis_checkpoint > COUNTER_UPDATE_INTERVAL)
    {
        last_millis_checkpoint = time_now_millis;
        counter++;
    }
}