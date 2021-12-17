#include "st7735.h"
Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);
void showTime(char*);
void showTemp(char*);
void showHumi(char*);
void showPressure(char*);
void showAlti(char*);
void initFrame();

void initST() {
  tft.initR(INITR_BLACKTAB);      // Init ST7735S chip, black tab
  tft.fillScreen(ST77XX_BLACK);
  initFrame();
}

void loopST(S_Datas datas) {
  char buff[28]="";
  sprintf(buff,"%02d:%02d",datas.tm.Hour,datas.tm.Minute);
  showTime(buff);
  sprintf(buff,"%f°C",datas.meteo.temp);
  showTemp(buff); 
  //sprintf(buff,"%lf Pa",((double)((float)datas.meteo.pressure)/100000.0l));  
  //showPressure(buff);
  initFrame();
}

void initFrame(){
  tft.fillRect(0,0,128,8,ST77XX_BLUE);
  tft.drawLine(0,80,128,80,ST77XX_BLUE);
  tft.drawLine(64,18,64,160,ST77XX_BLUE);

}

void showTime(char* str)
{
  tft.fillRect(POS_TIME_X-6,POS_TIME_Y,44,12, ST77XX_BLUE);
    tft.setTextSize(1);
  tft.setCursor(POS_TIME_X,POS_TIME_Y);
  tft.setTextColor(ST77XX_WHITE);
  tft.print(str);
}

void showTemp(char* str)
{
  //tft.fillRect(POS_TEMP_X-2,POS_TEMP_Y-2,44,12, ST77XX_BLUE);
  tft.setTextSize(1);
  tft.setCursor(POS_TEMP_X,POS_TEMP_Y);
  tft.setTextColor(ST77XX_WHITE);
  tft.print(str);
}

//void showHumi(char* str)
//{
//  tft.fillRect(POS_TIME_X-2,POS_TIME_Y-2,44,12, ST77XX_BLUE);
//    tft.setTextSize(1);
//  tft.setCursor(POS_TIME_X,POS_TIME_Y);
//  tft.setTextColor(ST77XX_WHITE);
//  tft.print(str);
//}
//
//void showAlti(char* str)
//{
//  tft.fillRect(POS_TIME_X-2,POS_TIME_Y-2,44,12, ST77XX_BLUE);
//    tft.setTextSize(1);
//  tft.setCursor(POS_TIME_X,POS_TIME_Y);
//  tft.setTextColor(ST77XX_WHITE);
//  tft.print(str);
//}

//void showPressure(char* str)
//{
//  tft.setCursor(POS_PRESS_X,POS_PRESS_Y+50);
//  tft.setTextSize(2);
//  tft.setTextColor(ST77XX_WHITE);
//  tft.print(str);
//}
