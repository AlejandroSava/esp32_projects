/*
 * SPDX-FileCopyrightText: 2010-2022 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: CC0-1.0
 */

#include <stdio.h>
#include <esp_log.h>
void app_main(void)
{
    printf("Hello World \n");
    esp_log_level_set("LOG", ESP_LOG_INFO); // setting the log level -> INFO level ignore the debug and verbose
    ESP_LOGE("LOG", "This is an error"); // for errors 
    ESP_LOGW("LOG", "This is a Warning"); // for warnings 
    ESP_LOGI("LOG", "This is an INFO"); // for information
    ESP_LOGI("LOG", "This is an INFO text"); // for information
    // There are other types of information
    ESP_LOGD("LOG", "This is for Debug"); // for debug
    ESP_LOGD("LOG", "This is for Verbose"); // for derbose


    esp_log_level_set("LOG2", ESP_LOG_VERBOSE); // setting the log level
    int number = 0; 
    ESP_LOGE("LOG2", "This is an error %d", number++); // for errors 
    ESP_LOGW("LOG2", "This is a Warning %d", number++); // for warnings 
    ESP_LOGI("LOG2", "This is an INFO %d", number++); // for information
    ESP_LOGI("LOG2", "This is an INFO text %d", number++); // for information
    // There are other types of information
    ESP_LOGD("LOG2", "This is for Debug %d", number++); // for debug
    ESP_LOGD("LOG2", "This is for Verbose %d", number++); // for derbose

}