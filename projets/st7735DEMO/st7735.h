#ifndef __ST7735
#define __ST7735
#include "struct.h"
  #include <Adafruit_ST77xx.h>
  #include <Adafruit_ST7789.h>
  #include <Adafruit_ST7735.h>
    #define TFT_CS        10
  #define TFT_RST        8 // Or set to -1 and connect to Arduino RESET pin
  #define TFT_DC         9
  #define POS_TIME_X 44
  #define POS_TIME_Y 8
  #define POS_TEMP_X 44
  #define POS_TEMP_Y 30
  #define POS_HUMI_X 30
  #define POS_HUMI_Y 10
  #define POS_PRESS_X 00
  #define POS_PRESS_Y 00
  #define POS_ALTI_X 00
  #define POS_ALTI_Y 00
void initST();
void loopST( S_Datas);
#endif
