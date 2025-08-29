#include <stdio.h>
#include "esp_log.h"
#include "calc.h"
#define TAG "ESP32_IN_C"



void app_main(void)
{
    //esp_log_level_set(TAG, ESP_LOG_INFO); // setting the log level -> INFO level ignore the debug and verbose
    ESP_LOGI(TAG, "THIS IS AN EXAMPLE OF HEADERS FILES");
    int a = 10;
    int b = 5;

    printf("the values are: a = %d, b = %d \n", a, b);
    printf("the add result is: %d \n", add(a, b));
    printf("the sub result is: %d \n", sub(a, b));
    printf("the mul result is: %d \n", mul(a, b));
    printf("the divi result is: %f \n", divi(a, b));

}
