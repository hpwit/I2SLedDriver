#ifndef I2S_CORE_INCLUDE
#define I2S_CORE_INCLUDE
#pragma once

#include "esp_heap_caps.h"
#include "soc/soc.h"
#include "soc/gpio_sig_map.h"
#include "soc/i2s_reg.h"
#include "soc/i2s_struct.h"
#include "soc/io_mux_reg.h"
#include "driver/gpio.h"
#if ESP_IDF_VERSION >= ESP_IDF_VERSION_VAL(5, 0, 0)
#include "hal/gpio_ll.h"
 #include "soc/gpio_struct.h"
 #include "rom/gpio.h"
 #endif
#include "driver/periph_ctrl.h"
#include "rom/lldesc.h"
#include <cstring>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/semphr.h"
#include <stdio.h>
#include <rom/ets_sys.h>
#include <soc/rtc.h>
#include "math.h"

#endif