#include "src/display_controller/display_controller.h"

DisplayController display_controller = DisplayController();

void setup()
{
   display_controller.initalize_output_pins();
}

void loop()
{
    for (uint8_t i = 0; i < 10; i++)
    {
        display_controller.print_number_on_digit(i, 0);
        delay(5000);
    }
}