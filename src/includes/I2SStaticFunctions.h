#ifndef I2S_STATIC_FUNCTIONS
#define I2S_STATIC_FUNCTIONS
#pragma once


static void IRAM_ATTR _I2SLedDriverInterruptHandler(void *arg)
{

    // REG_WRITE(I2S_INT_CLR_REG(0), (REG_READ(I2S_INT_RAW_REG( 0 )) & 0xffffffc0) | 0x3f);
    //return;
    I2SLedDriver *cont = (I2SLedDriver *)arg;

    if (GET_PERI_REG_BITS(I2S_INT_ST_REG(I2S_DEVICE), I2S_OUT_EOF_INT_ST_S, I2S_OUT_EOF_INT_ST_S))
    {
        cont->framesync = !cont->framesync;

        if (((I2SLedDriver *)arg)->transpose)
        {
            cont->ledToDisplay++;
            if (cont->ledToDisplay < cont->num_led_per_strip)
            {

               loadAndTranspose(cont);

                if (cont->ledToDisplay == (cont->num_led_per_strip - 3)) //here it's not -1 because it takes time top have the change into account and it reread the buufer
                {
                    cont->DMABuffersTampon[cont->dmaBufferActive]->descriptor.qe.stqe_next = &(cont->DMABuffersTampon[3]->descriptor);
                }
                cont->dmaBufferActive = (cont->dmaBufferActive + 1) % 2;
            }
        }
        else
        {
            if (cont->framesync)
            {
                portBASE_TYPE HPTaskAwoken = 0;
                xSemaphoreGiveFromISR(cont->I2SLedDriver_semSync, &HPTaskAwoken);
                if (HPTaskAwoken == pdTRUE)
                    portYIELD_FROM_ISR();
            }
        }
    }

    if (GET_PERI_REG_BITS(I2S_INT_ST_REG(I2S_DEVICE), I2S_OUT_TOTAL_EOF_INT_ST_S, I2S_OUT_TOTAL_EOF_INT_ST_S))
    {


        cont->i2sStop(cont);

    }
    REG_WRITE(I2S_INT_CLR_REG(0), (REG_READ(I2S_INT_RAW_REG(0)) & 0xffffffc0) | 0x3f);
}


static void showPixelsTask(void *pvParameters)
{
    I2SLedDriver *cont = (I2SLedDriver *)pvParameters;
      if(cont->_gI2SLedDriver_intr_handle!=NULL)
  {
            esp_intr_free(cont->_gI2SLedDriver_intr_handle);
       
  }
   ESP_LOGV(TAG,"setting interupt handler");
        esp_err_t e = esp_intr_alloc(interruptSource, ESP_INTR_FLAG_INTRDISABLED | ESP_INTR_FLAG_LEVEL3 | ESP_INTR_FLAG_IRAM, &_I2SLedDriverInterruptHandler, cont, &cont->_gI2SLedDriver_intr_handle);
        if (e!=ESP_OK)
        {
            ESP_LOGE(TAG,"Impossible to create interupt allocation");
            return;
        }
       ESP_LOGV(TAG,"interupt handler set on core %d",xPortGetCoreID() );
  
    for(;;) {
        ulTaskNotifyTake(pdTRUE,portMAX_DELAY);
    cont-> ___showPixels();
      // xTaskNotifyGive(I2SLedDriver_returnTaskHandle);
    }
}


#endif