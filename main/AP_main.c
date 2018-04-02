/* Hello World Example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_spi_flash.h"
#include "esp_wifi.h"


#define SSID "Test"  //Set your SSID


void app_main()
{

	wifi_init_config_t wifiInitializationConfig = WIFI_INIT_CONFIG_DEFAULT();
	esp_wifi_init(&wifiInitializationConfig);
	esp_wifi_set_storage(WIFI_STORAGE_RAM);
	esp_wifi_set_mode(WIFI_MODE_AP);


    wifi_config_t ap_config =
    	{
          .ap = {
            .ssid = SSID,
            .channel = 5,
            .authmode = WIFI_AUTH_OPEN,
            .ssid_hidden = 0,
            .max_connection = 3,
            .beacon_interval = 100
          	  	}
        };

    esp_wifi_set_config(WIFI_IF_AP, &ap_config);
    esp_wifi_start();

}
