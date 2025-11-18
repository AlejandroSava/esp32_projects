#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <esp_log.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

#define TAG "LOG_ESP32"

static TaskHandle_t receiverHandler = NULL;

void sender_task_1(void *params){
    while(true){
        ESP_LOGI(TAG, "--- Sender TASK ---");
        xTaskNotifyGive(receiverHandler);
        xTaskNotifyGive(receiverHandler);
        xTaskNotifyGive(receiverHandler);
        xTaskNotifyGive(receiverHandler);
        vTaskDelay(5000 / portTICK_PERIOD_MS);
    }
}

void receiver_task_2(void *params){
    while(true){
        ESP_LOGI(TAG, "--- Reicever TASK ---");
        uint32_t count  = ulTaskNotifyTake(pdFALSE, portMAX_DELAY);
        ESP_LOGI(TAG, "--- The TASK Count is %lu ---", count);
    }
}

void app_main(void)
{
    
    
    xTaskCreate(&receiver_task_2, "Receiver", 2048, "TASK 2", 1, &receiverHandler); // the receiver is first that the sender
    xTaskCreate(&sender_task_1, "Sender", 2048, "TASK 1", 1, NULL);
    /* NOTES
    you create the sender first. If it runs before receiverHandler is assigned by xTaskCreate for the receiver, xTaskNotifyGive(receiverHandler) will be called with NULL, which can assert/crash.
    Fix: Create the receiver first, or block the sender until the handle is valid.   
    // Case 1: pdTRUE → clears all at once
    ulTaskNotifyTake(pdTRUE, portMAX_DELAY); // count = 0 after this

    // Case 2: pdFALSE → decrements one by one
    ulTaskNotifyTake(pdFALSE, portMAX_DELAY); // count -= 1 (still 2 left)
    
    */

}
