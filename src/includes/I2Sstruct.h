#ifndef _I2S_STRUCT
#define _I2S_STRUCT
#pragma once

typedef union
{
    uint8_t bytes[16*8];
    uint32_t shorts[16*2];
    //uint32_t raw[2];
} Lines;

class I2SClocklessVirtualLedDriver;
struct OffsetDisplay
{
    int offsetx;
    int offsety;
    int panel_height;
    int panel_width;
    int image_height;
    int image_width;
    int window_width;
    int window_height;
    int _offx;
    int xc;
    int yc;
    float rotation;
    bool enableLoopx;
    bool enableLoopy;
    bool enableRotation;
    float scallingx;
    float scallingy;
    int _scallingx;
    int _scallingy;
    long _deltax;
    long _deltay;
    int _defaultvalue;
    int _cos;
   int  _sin;
    int _offy;
};

enum class LedTypes
{
  WS281X,
  SK6812,
  VIRTUAL_WS281X,
  VIRTUAL_SK6812,
  APA102,
  HD108,
  HD107,
  WS2801,
};

enum colorarrangment
{
    ORDER_GRBW,
    ORDER_RGB,
    ORDER_RBG,
    ORDER_GRB,
    ORDER_GBR,
    ORDER_BRG,
    ORDER_BGR,
};

enum class  displayMode
{
    NO_WAIT,
    WAIT,
    LOOP,
    LOOP_INTERUPT,
};


struct I2SClocklessVirtualLedDriverDMABuffer
{
    lldesc_t descriptor;
    uint8_t *buffer;
};

typedef unsigned int strip_length;


class Pin
{
    uint8_t pin_num;
    public:
        Pin(uint8_t pinnum)
        {
            assert(isIn(pinnum)==true);
            pin_num=pinnum;
        }
    private:
    bool isIn(uint8_t value){
        for(int i=0;i++;i<22)
        {
            if(value == availablepins[i])
                return true;
            
        }
        return false;
    }
     uint8_t availablepins[21]={0,1,2,3,4,5,12,13,14,15,16,17,18,19,21,23,25,26,27,32,33};
}

#endif