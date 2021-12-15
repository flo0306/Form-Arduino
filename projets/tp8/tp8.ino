#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>
#include <Adafruit_BMP085.h>
#include <LCD_I2C.h>

LCD_I2C lcd(0x27, 16, 2); // Default address of most PCF8574 modules, change according

Adafruit_BMP085 bmp;
Adafruit_MPU6050 mpu;
  
void setup() {
  pinMode(2, INPUT);
  bmp.begin();
  lcd.begin();
  lcd.backlight();
  mpu.begin();
  mpu.setAccelerometerRange(MPU6050_RANGE_2_G);
  mpu.setGyroRange(MPU6050_RANGE_250_DEG);
  mpu.setFilterBandwidth(MPU6050_BAND_94_HZ);
}
  
void loop() {
  bool buttonState=digitalRead(2);
  if (buttonState) {
    mpu6050 ();
  }
  else {
    bmp085 ();
  }
}

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
