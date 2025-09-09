#include <stdio.h>
#include <esp_log.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

#define TAG "LOG_ESP32"
#define LED 2 

uint8_t led_level = 0;

esp_err_t init_led(void){
    gpio_reset_pin(LED);
    gpio_set_direction(LED, GPIO_MODE_OUTPUT);
    return ESP_OK;
}

esp_err_t blink_led(void){
    led_level = !led_level;
    gpio_set_level(LED, led_level);
    return ESP_OK;
}

void app_main(void)
{
    init_led();
    while (1)
    {
        /* code */
        vTaskDelay(200 / portTICK_PERIOD_MS);
        blink_led();
        ESP_LOGI(TAG, "BLINK FUNCTION ... ... ... ");
        ESP_LOGI(TAG,"LED LEVEL is: %d", led_level);

    }
    
}


