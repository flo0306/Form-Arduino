#define PASVOLT (float)(5.0F / 1024.0F)
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  lcd.begin(16, 2);
  lcd.print("Voltmetre");
}

void loop() {
  unsigned int palier=analogRead(A0);
  float valeurMesure=palier*PASVOLT;
  lcd.setCursor(6, 1);
  lcd.print("          ");
   lcd.setCursor(6, 1);
  lcd.print(valeurMesure);
  lcd.print("V");
  delay(500);
}
