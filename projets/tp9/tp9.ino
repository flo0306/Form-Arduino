#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>
#include <Adafruit_BMP085.h>
#include <LCD_I2C.h>
#include <DHT.h>
#include <DHT_U.h>
#define DHTPIN 8     // Digital pin connected to the DHT sensor 
#define DHTTYPE    DHT11     // DHT 11
LCD_I2C lcd(0x27, 16, 2); // Default address of most PCF8574 modules, change according

Adafruit_BMP085 bmp;
Adafruit_MPU6050 mpu;
DHT_Unified dht(DHTPIN, DHTTYPE);
  
void setup() {
  pinMode(2, INPUT);
  attachInterrupt(INT0,turnOnlight,CHANGE);
  bmp.begin();
  lcd.begin();
  lcd.backlight();
  mpu.begin();
  mpu.setAccelerometerRange(MPU6050_RANGE_2_G);
  mpu.setGyroRange(MPU6050_RANGE_250_DEG);
  mpu.setFilterBandwidth(MPU6050_BAND_94_HZ);
  dht.begin();
}
  
//void loop() {
//  bool buttonState1=digitalRead(2);
//
//  switch() {
//    case 1 (buttonState1) :
//    mpu6050 ();
//    break;
//    case 2 (buttonState1) :
//    bmp085 ();
//    break;
//   case 3 (buttonState1) :
//  dht11 ();
//  break;
//}
//}

void mpu6050 () {
    lcd.print(bmp.readPressure()/100000.0F);
    lcd.print("Bar");

    lcd.setCursor(0, 1);
    lcd.print(bmp.readTemperature());
    lcd.print("C   ");
   
    lcd.print(bmp.readAltitude());
    lcd.print("m");

    delay(800);
    lcd.clear();
}

void bmp085 () {
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);

  lcd.print("X: ");
  lcd.print(g.gyro.x);
  lcd.print(" (rad/s)");
 
  lcd.setCursor(0, 1);
  lcd.print("Y: ");
  lcd.print(g.gyro.y);
  
  lcd.print("  Z: ");
  lcd.print(g.gyro.z);
  
  delay(800);
  lcd.clear();
}

void dht11() {
  sensors_event_t event;
  
  dht.temperature().getEvent(&event);
  lcd.print(F("Temp: "));
  lcd.print(event.temperature);
  lcd.println(F(" C"));
  
  dht.humidity().getEvent(&event);
  lcd.setCursor(0, 1);
  lcd.print(F("Humidity: "));
  lcd.print(event.relative_humidity);
  lcd.println(F("%"));
  delay(800);
  lcd.clear();
}
