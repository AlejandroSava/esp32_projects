#include <stdio.h>
#include <esp_sleep.h>

#include <puflib.h>
void app_main(void)
{
  printf("This is a puf importing ... ... ...");
  puflib_init(); // needs to be called first in app_main
    
    enroll_puf(); // enrollment needs to be done only once at the beginning

        // condition will be true, if a PUF response is ready (useful after a restart)
        if(PUF_STATE != RESPONSE_READY) {
            bool puf_ok = get_puf_response();
            if(!puf_ok) {
                get_puf_response_reset(); // the device resets now and the app starts again from app_main
            }
        }

        // PUF_RESPONSE_LEN is a PUF response length in bytes
        for (size_t i = 0; i < PUF_RESPONSE_LEN; ++i) {
            printf("%02X ", PUF_RESPONSE[i]); // PUF_RESPONSE is a buffer with the PUF response
        }
        printf("\n");

        clean_puf_response();
}

    void RTC_IRAM_ATTR esp_wake_deep_sleep(void) {
        esp_default_wake_deep_sleep();
        puflib_wake_up_stub(); // needs to be called somewhere in wake up stub
    }

