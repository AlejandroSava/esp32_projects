#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <esp_log.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

#define TAG "LOG_ESP32"

void task1(void* params){ // create the task1
    while(true){
        printf("Reading the temperature from %s\n", (char*) params);
        vTaskDelay(1000 / portTICK_PERIOD_MS);

    }
}

void task2(void* params){ //create the task2
    while(true){
        printf("Reading the humidity from %s\n", (char*) params);
        vTaskDelay(2000 / portTICK_PERIOD_MS);

    }
}

void task3(void* params){ //create the task3
    while(true){
        printf("second core: %s\n", (char*) params);
        vTaskDelay(2000 / portTICK_PERIOD_MS);

    }
}

void app_main(void)
{   esp_log_level_set("*", ESP_LOG_ERROR);
    ESP_LOGI(TAG, "--- FreeRTOS Example ---");

    // run tasks at the same time
    xTaskCreate(&task1, "temperature reading", 2048, "task1", 2, NULL);
    xTaskCreate(&task2, "humidity reading", 2048, "task2", 2, NULL);

    // by default the esp32 only use the first core that is for applicactions.
    // to use the second core, we can use the next one 
    xTaskCreatePinnedToCore(&task3, "core 2", 2048, "task3", 2, NULL,1); // the latest number points to core 2, 1 --> core 2, 0 -- > core 1
}
