#include <Adafruit_Sensor.h>
#include <Wire.h>
#include <Adafruit_BMP085.h>
#include <DHT.h>
#include <DHT_U.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <SPI.h>
#include <SD.h>
#define DHTPIN 5     // Digital pin connected to the DHT sensor 
#define DHTTYPE    DHT11     // DHT 11
#define ONE_WIRE_BUS 4
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
File myFile;

Adafruit_BMP085 bmp;
DHT_Unified dht(DHTPIN, DHTTYPE);
  
void setup() {
  Serial.begin(9600);
  bmp.begin();
  dht.begin();
  sensors.begin();
  if (!SD.begin(10)) {
    Serial.println("SD initialization failed!");
    while (1);
  }
  Serial.println("SD initialization done.");
  myFile = SD.open("test.txt", FILE_WRITE);
  if (myFile) {
      Serial.print("Writing to test.txt...");
      myFile.println("testing 1, 2, 3.");
      // close the file:
      myFile.close();
      Serial.println("done.");
      } 
  else {
    // if the file didn't open, print an error:
      Serial.println("error opening test.txt");
      }

void loop() {

  // Aquisition
    //Pression+Altitude
  float Pressure=bmp.readPressure()/100000.0F;
  float Alti=bmp.readAltitude();
    //Humidité
  sensors_event_t event;
  dht.humidity().getEvent(&event);
  float Humi=event.relative_humidity;
    //Temperatue
  sensors.requestTemperatures();
  float tempC = sensors.getTempCByIndex(0);

  // Affichage
  Serial.println("Pression/Altitude :"); 
  Serial.print(Pressure);
  Serial.println(" bars");

  Serial.print(Alti);
  Serial.println(" metres");
  
  Serial.println("Humidite :"); 
  Serial.print(Humi);
  Serial.println("%");

  Serial.println("Temp: ");
  Serial.print(tempC);
  Serial.println("°C");
  Serial.print("\n");
  delay(1000);

}
