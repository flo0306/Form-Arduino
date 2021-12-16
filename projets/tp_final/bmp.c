#include "bmp.h"
//instance d'acces au composant par librairie
Adafruit_BMP085 bmp;

void setupBMP(){
  if (!bmp.begin()) {
    return -1;
  }
  else {
    initialPressure = bmp.readPressure();
    return 1;
  }  
}



void loopBMP(){
  //float bmpTemp = bmp.readTemperature();
  data.meteo.pression = bmp.readPressure();
  data.geo.altitude = bmp.readAltitude(initialPressure);
  
}
