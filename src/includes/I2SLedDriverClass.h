#ifndef _I2S_LED_DRIVER_CLASS
#define _I2S_LED_DRIVER_CLASS
#pragma once

class I2SLedDriver
{

public:
    I2SLedDriver(){}

/*init leds functions*/
bool initleds(Pixel leds,int int num_leds_per_strip)
/*showPixels functions*/
void showPixels();
void showPixels(uint8_t *leds);
void showPixels(uint8_t *leds,offsetDisplay offset);
void showPIxels(uint8_t *leds,offsetDisplay offset,displayMode dismode);
void showPIxels(uint8_t *leds,displayMode dismode);
void showPIxels(offsetDisplay offset,displayMode dismode);
void showPixels(offsetDisplay offset);
void showPIxels(displayMode dismode);

};

#endif