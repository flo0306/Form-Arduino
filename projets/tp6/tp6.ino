#include <Adafruit_BMP085.h>
#include <LCD_I2C.h>

LCD_I2C lcd(0x27, 16, 2); // Default address of most PCF8574 modules, change according

Adafruit_BMP085 bmp;
  
void setup() {
  bmp.begin();
  lcd.begin();
  lcd.backlight();
}
  
void loop() {
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
