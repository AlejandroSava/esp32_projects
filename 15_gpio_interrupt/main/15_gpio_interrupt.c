#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "freertos/queue.h"
#define PIN_LED 2
#define PIN_SWITCH 23

QueueHandle_t interruptQueue;
static void IRAM_ATTR gpio_isr_handler(void *args){
    int pinNumber = (int) args;
    xQueueSendFromISR(interruptQueue, &pinNumber, NULL);
}

void buttonPushedTask (void *params){
    int pinNumber, count = 0;
    while (true)
    {
        if(xQueueReceive(interruptQueue, &pinNumber, portMAX_DELAY)){
            printf("GPIO %d was pressed %d times. The state is %d\n", pinNumber, count++, gpio_get_level(PIN_SWITCH));
        }
    }
    
}

void app_main(void)
{
    gpio_set_direction(PIN_LED, GPIO_MODE_OUTPUT);
    gpio_set_direction(PIN_SWITCH,GPIO_MODE_INPUT);
    gpio_pulldown_en(PIN_SWITCH); // enabling pull down for this pin
    gpio_pullup_dis(PIN_SWITCH);
    gpio_set_intr_type(PIN_SWITCH, GPIO_INTR_POSEDGE);
    
    // typedef enum {
    // GPIO_INTR_DISABLE = 0,     /*!< Disable GPIO interrupt                             */
    // GPIO_INTR_POSEDGE = 1,     /*!< GPIO interrupt type : rising edge                  */
    // GPIO_INTR_NEGEDGE = 2,     /*!< GPIO interrupt type : falling edge                 */
    // GPIO_INTR_ANYEDGE = 3,     /*!< GPIO interrupt type : both rising and falling edge */
    // GPIO_INTR_LOW_LEVEL = 4,   /*!< GPIO interrupt type : input low level trigger      */
    // GPIO_INTR_HIGH_LEVEL = 5,  /*!< GPIO interrupt type : input high level trigger     */
    // GPIO_INTR_MAX,
    // } gpio_int_type_t;

    interruptQueue = xQueueCreate(10, sizeof(int));
    xTaskCreate(buttonPushedTask, "buttonPushedTask", 2048, NULL, 1, NULL);

    printf("STARTING ISR SERVICE\n");
    gpio_install_isr_service(0);
    gpio_isr_handler_add(PIN_SWITCH, gpio_isr_handler, (void *) PIN_SWITCH);
    
}
