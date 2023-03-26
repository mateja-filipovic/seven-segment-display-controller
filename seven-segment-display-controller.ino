#include "src/display_controller/display_controller.h"
#include "src/examples/counter/counter.h"
#include "src/examples/digit-runner/digit_runner.h"

DisplayController display_controller = DisplayController();

Counter counter_example = Counter(&display_controller);
DigitRunner digit_runner_example = DigitRunner(&display_controller);

void setup()
{
    display_controller.initalize_output_pins();
}

void loop()
{
    counter_example.run_example();
    digit_runner_example.run_example();
}