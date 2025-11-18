#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

#define PIN_LED 2
#define PIN_SWITCH 23


void app_main(void)
{
    gpio_set_direction(PIN_LED, GPIO_MODE_OUTPUT);
    gpio_set_direction(PIN_SWITCH,GPIO_MODE_INPUT);
    gpio_pulldown_en(PIN_SWITCH); // enabling pull down for this pin

    while (true)
    {
        int status = gpio_get_level(PIN_SWITCH);
        gpio_set_level(PIN_LED, status);
        vTaskDelay(1);
    }
    
}
