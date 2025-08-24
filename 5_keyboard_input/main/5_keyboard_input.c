/*
 * SPDX-FileCopyrightText: 2010-2022 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: CC0-1.0
 */

#include <stdio.h>
#include<string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

void app_main(void)
{

    char c = 0; 
    char str[100];
    memset(str, 0, sizeof(str)); // clean the block

    while (c != '\n'){
        c = getchar();
        if (c != 0xff){
            str[strlen(str)] = c; //strlen returns the S len 
            printf("str len: %d\n", strlen(str));
            printf("%c", c);
        }
        vTaskDelay(100 / portTICK_PERIOD_MS);
    }
    printf("You typed: %s", str);
}
