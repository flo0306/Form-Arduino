#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>
#include <Adafruit_BMP085.h>
#include <DHT.h>
#include <DHT_U.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#define DHTPIN 5     // Digital pin connected to the DHT sensor 
#define DHTTYPE    DHT11     // DHT 11
#define ONE_WIRE_BUS 4
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

Adafruit_BMP085 bmp;
Adafruit_MPU6050 mpu;
DHT_Unified dht(DHTPIN, DHTTYPE);
  
void setup() {
  Serial.begin(9600);
  bmp.begin();
  mpu.begin();
  mpu.setAccelerometerRange(MPU6050_RANGE_2_G);
  mpu.setGyroRange(MPU6050_RANGE_250_DEG);
  mpu.setFilterBandwidth(MPU6050_BAND_94_HZ);
  dht.begin();
  sensors.begin();
}

volatile int menuNum=1;

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
