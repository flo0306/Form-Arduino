#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>
#include <LCD_I2C.h>

LCD_I2C lcd(0x27, 16, 2); // Default address of most PCF8574 modules, change according

Adafruit_MPU6050 mpu;

void setup() {
  mpu.begin();
  mpu.setAccelerometerRange(MPU6050_RANGE_2_G);
  mpu.setGyroRange(MPU6050_RANGE_250_DEG);
  mpu.setFilterBandwidth(MPU6050_BAND_94_HZ);
  lcd.begin();
  lcd.backlight();
}

void loop() {
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
