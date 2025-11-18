#include <stdio.h>
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#define PIN 2

/*
some considerations:

not exced >= 20 MA/PIN in the GND
all pins, not exced >=40

*/

void app_main(void)
{
    gpio_set_direction(PIN, GPIO_MODE_OUTPUT); //GPIO_MODE_DISABLE, GPIO_MODE_INPUT, GPIO_MODE_OUTPUT, GPIO_MODE_OUTPUT_OD, GPIO_MODE_INPUT_OUTPUT_OD, GPIO_MODE_INPUT_OUTPUT
    int is_on = 0;
    while(true){
        is_on = !is_on;
        gpio_set_level(PIN, is_on);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}
// voltage output ESP32 = 3.3v 
// e.g voltage for on a LED = 2.75
/*
Vgnd = 3.3 - 2.75 v = 0.55 v
V = I * R 
R = V/ I
R = 0.55 / 0.020
R = 30 ohms

*/