/* Blink Example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/

//#include <string.h>
//#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
//#include "sdkconfig.h"

#include "../components/driver.h"
#include "../components/button/button.h"
#include "../components/led/led.h"



static const char *TAG = "DEBUG";

#define BLINK_GPIO CONFIG_BLINK_GPIO

//DOC: https://docs.espressif.com/projects/esp-idf/en/latest/esp32/api-guides/build-system.html

uint8_t myDriverVar = 0;
uint8_t myButtonVar = 0;
uint8_t myLedVar = 0;
int counter = 0;



static void myapp_getdata(void){

    myDriverVar = driver(8);
    myButtonVar = myButton(2);
    myLedVar = driverLed(5);
    counter++;
    ESP_LOGI(TAG, "Counter: %d", counter);
}



static void myapp_task(void *pvParameters)
{
	myapp_getdata();

	ESP_LOGI(TAG, "Task Completed");
    vTaskDelete(NULL);
}




void app_main(void)
{

	ESP_LOGI(TAG, "Configs init!");
	printf("Hello from app_main!\n");

    while (1) {

        xTaskCreate(&myapp_task, "myapp_task", 8192, NULL, 5, NULL);
        vTaskDelay(2000 / portTICK_PERIOD_MS);

    }
}
