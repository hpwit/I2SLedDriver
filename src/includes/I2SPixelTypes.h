#ifndef _I2S_PIXELS_TYPES
#define _I2S_PIXELS_TYPES
#ifdef USE_FASTLED
    #include "FastLED.h"
#endif


#define _OUT_OF_BOUND -12

#define WS281X 0x0001
#define APA102 0x0002
#define SK6812 0x0011
#define HD107 0x0004
#define HD108 0x0008
#define WS2811 0x0010

#ifndef PIXEL_TYPE 
#pragma
#endif


struct IndvBrightness{
  uint8_t bred;
  uint8_t bgreen;
  uint8_t bblue;
inline IndvBrightness() __attribute__((always_inline))
    {
    }
inline IndvBrightness( uint8_t ir, uint8_t ig, uint8_t ib)  __attribute__((always_inline))
        : bred(ir), bgreen(ig), bblue(ib)
    {
    }
    inline IndvBrightness( uint8_t ir)  __attribute__((always_inline))
        : bred(ir), bgreen(ir), bblue(ir)
    {
    }
     
};


#ifdef COLOR_RGBW

struct Pixel {
    union {
        uint8_t raw[3];
        struct 
        {
            uint8_t red;
            uint8_t green;
            uint8_t blue;
            uint8_t white;
            
        };
        
    };

    inline Pixel(uint8_t r, uint8_t g,uint8_t b,uint8_t w) __attribute__((always_inline))
        :red(r),green(g),blue(b),white(w)
    {
        //brigthness =0xE0 |(br&31);
    }

    inline Pixel(uint8_t r, uint8_t g,uint8_t b) __attribute__((always_inline))
        :red(r),green(g),blue(b)
    {
            white = MIN(red, green);
            white = MIN(white, blue);
            red = red - white;
            green = green - white;
            blue = blue - white;
    }


	inline Pixel() __attribute__((always_inline))
    {

    }

       
#ifdef USE_FASTLED
inline Pixel &operator= (const CRGB& rhs) __attribute__((always_inline))
    {

        red = rhs.r;
        green = rhs.g;
        blue = rhs.b;
        white = MIN(red, green);
        white = MIN(white, blue);
        red = red - white;
        green = green - white;
        blue = blue - white;
        return *this;
    }
   #endif

inline Pixel (const Pixel& rhs) __attribute__((always_inline))
     {
         //brigthness=rhs.brigthness;
         red=rhs.red;
         green=rhs.green;
         blue=rhs.blue;
         white=rhs.white;
     }
     inline Pixel& operator= (const uint32_t colorcode) __attribute__((always_inline))
    {
       // rgb colorg; 
        red = (colorcode >> 24) & 0xFF;
        green = (colorcode >>  16) & 0xFF;
        blue = (colorcode >>  8) & 0xFF;
        white = colorcode  & 0xFF;
        return *this;
    }
        

};
#else

struct Pixel {
    union {
        uint8_t raw[3];
        struct 
        {
            uint8_t red;
            uint8_t green;
            uint8_t blue;
            
        };
        
    };

    inline Pixel(uint8_t r, uint8_t g,uint8_t b) __attribute__((always_inline))
    :red(r),green(g),blue(b)
{
    //brigthness =0xE0 |(br&31);
}

	inline Pixel() __attribute__((always_inline))
    {

    }

       
#ifdef USE_FASTLED
inline Pixel &operator= (const CRGB& rhs) __attribute__((always_inline))
    {
        red = rhs.r;
        green = rhs.g;
        blue = rhs.b;
        return *this;
    }
   #endif

inline Pixel (const Pixel& rhs) __attribute__((always_inline))
     {
         //brigthness=rhs.brigthness;
         red=rhs.red;
         green=rhs.green;
         blue=rhs.blue;
     }
     inline Pixel& operator= (const uint32_t colorcode) __attribute__((always_inline))
    {
       // rgb colorg; 
        red = (colorcode >> 16) & 0xFF;
        green = (colorcode >>  8) & 0xFF;
        blue = (colorcode >>  0) & 0xFF;
        return *this;
    }
        

};
#endif


          

#endif