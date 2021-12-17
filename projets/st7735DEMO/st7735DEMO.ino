#include "struct.h"
#include "st7735.h"
void setup() {
  // put your setup code here, to run once:
  initDatas();
  initST();
  Serial.begin(9600);
  char buff[51]="";
  //sprintf(buff,"%l Pa",s.meteo.pressure);  
 Serial.println(buff);
}

void loop() {
  // put your main code here, to run repeatedly:
  loopST(s);
  delay(700);
}

void initDatas(){
  s.meteo.pressure=1001000ul;
  s.meteo.temp=40.54F;
  s.meteo.rhumidity=60.0F;
  s.geo.alt=1000.0F;
  s.tm.Hour=12;
  s.tm.Minute=23;
}
