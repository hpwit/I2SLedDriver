#ifndef I2S_STATIC_FUNCTIONS_DEF
#define I2S_STATIC_FUNCTIONS_DEF
#pragma once

static void IRAM_ATTR _I2SLedDriverInterruptHandler(void *arg);

static inline __attribute__((always_inline))  void IRAM_ATTR transpose16x1_noinline2(unsigned char *A, uint8_t *B);

static inline __attribute__((always_inline))  void IRAM_ATTR loadAndTranspose(I2SLedDriver * driver);
static TaskHandle_t I2SLedDriver_dispTaskHandle = 0;
static TaskHandle_t I2SLedDriver_returnTaskHandle = 0;
static void showPixelsTask(void *pvParameters);
static intr_handle_t _gI2SLedDriver_intr_handle=NULL;
static xSemaphoreHandle I2SLedDriver_sem = NULL;
static xSemaphoreHandle I2SLedDriver_semSync = NULL;
static xSemaphoreHandle I2SLedDriver_semDisp = NULL;
static xSemaphoreHandle I2SLedDriver_waitDisp = NULL;

#endif