#ifndef _I2S_DEFINES
#define _I2S_DEFINES
#pragma once



#ifndef I2S_DEVICE
#define I2S_DEVICE 0
#endif

#define MIN(a, b) (((a) < (b)) ? (a) : (b))


#ifndef NBIS2SERIALPINS
#define NBIS2SERIALPINS 1
#endif

#ifndef NUM_LEDS_PER_STRIP
#define NUM_LEDS_PER_STRIP 256
#endif

#ifndef STATICCOLOR
#define STATICCOLOR 1
#endif

#ifdef COLOR_RGBW
#define p_r 1
#define p_g 0
#define p_b 2
#define nb_components 4
#else
#ifdef COLOR_RGB
#define p_r 0
#define p_g 1
#define p_b 2
#define nb_components 3
#else
#ifdef COLOR_RBG
#define p_r 0
#define p_g 2
#define p_b 1
#define nb_components 3
#else
#ifdef COLOR_GBR
#define p_r 2
#define p_g 0
#define p_b 1
#define nb_components 3
#else
#ifdef COLOR_BGR
#define p_r 2
#define p_g 1
#define p_b 0
#define nb_components 3
#else
#ifdef COLOR_BRG
#define p_r 1
#define p_g 2
#define p_b 0
#define nb_components 3
#else
#ifdef COLOR_GRB
#define p_r 1
#define p_g 0
#define p_b 2
#define nb_components 3
#else

#define p_r 1
#define p_g 0
#define p_b 2
#define nb_components 3
#endif
#endif
#endif
#endif
#endif
#endif
#endif

#ifdef _USE_PALETTE
    #ifndef PALETTE_SIZE
        #define _palette_size 1
    #else
      #define _palette_size PALETTE_SIZE
    #endif
#else
    #define _palette_size nb_components
#endif

#define OFFSET (NUM_VIRT_PINS + 1)
#define I2S_OFF (((NUM_VIRT_PINS + 1) * NUM_LEDS_PER_STRIP) * _palette_size)
#define I2S_OFF2 ((I2S_OFF * NBIS2SERIALPINS - NUM_LEDS_PER_STRIP * _palette_size))
#define I2S_OFF3 ((I2S_OFF * NBIS2SERIALPINS + NUM_LEDS_PER_STRIP * _palette_size))
#define I2S_OFF4 ((I2S_OFF * NBIS2SERIALPINS - 3 * NUM_LEDS_PER_STRIP * _palette_size))
#define I2S_OFF_MAP (((NUM_VIRT_PINS + 1) * NUM_LEDS_PER_STRIP))
#define I2S_OFF2_MAP ((I2S_OFF_MAP * NBIS2SERIALPINS - NUM_LEDS_PER_STRIP))
#define I2S_OFF3_MAP ((I2S_OFF_MAP * NBIS2SERIALPINS + NUM_LEDS_PER_STRIP))
#define I2S_OFF4_MAP ((I2S_OFF_MAP * NBIS2SERIALPINS - 3 * NUM_LEDS_PER_STRIP))
#define BUFFOFF ((NBIS2SERIALPINS * 8) - 1)
#define AAA (0x00AA00AAL)
#define CCC (0x0000CCCCL)
#define FFF (0xF0F0F0F0L)
#define FFF2 (0xF0F0F0FL)


/*****mapping defines*****/

#define __NO_MAPPING           0x1000
#define __HARDWARE_MAP         0x1001
#define __SOFTWARE_MAP         0x1010
#define __HARDWARE_MAP_PROGMEM 0x1100
#ifndef MAPPING_TYPE
#define MAPPING_TYPE __NO_MAPPING
#endif


#if MAPPING_TYPE != __NO_MAPPING
#define _LEDMAPPING
#endif

#ifdef HARDWARE_SCROLL
#define __HARDWARE_S
#define __HARDWARE_MAP
#endif

#ifdef _HARDWARE_SCROLL_MAP
#define __HARDWARE_S
#define __HARDWARE_MAP
#endif

/****end of mapping defines****/

#endif

