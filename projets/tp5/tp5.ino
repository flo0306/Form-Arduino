#define PASVOLT (float)(5.0F / 1024.0F)
#include <LCD_I2C.h>
LCD_I2C lcd(0x27, 16, 2); // Default address of most PCF8574 modules, change according


void setup()
{
  lcd.begin();
  lcd.backlight();
  pinMode(2, INPUT);
  attachInterrupt(INT0, changeType, RISING);
}

volatile bool etatBoutton = true;

void loop() {
  if (etatBoutton)
  {
    voltMetre();
  }
  else
  {
    ohmMetre();
  }
}

void voltMetre() {
  unsigned int mesure = analogRead(A0);
  float valeurMesure = mesure * PASVOLT;
  lcd.print("Voltmetre");
  lcd.setCursor(6, 1);
  lcd.print(valeurMesure);
  lcd.print("V");
  delay(500);
  lcd.clear();
}

void ohmMetre() {
  unsigned int mesure = analogRead(A0);
  float valeurMesure = 10000.0F * ((5.0F)/(mesure * PASVOLT))-10000.0F;
  lcd.print("Ohmmetre");
  lcd.setCursor(1, 1);
  lcd.print(valeurMesure);
  lcd.print(" Ohms");
  delay(500);
  lcd.clear();
}

void changeType() {
  etatBoutton = !etatBoutton;
}
