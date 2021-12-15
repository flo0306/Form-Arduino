#define PASVOLT (float)(5.0F / 1024.0F)
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned int palier=analogRead(A0);
  Serial.print("Voici la valeur a la borne :\t");
  Serial.print(palier);
  Serial.print("\tTension :\t");
  float pasSortie=33.5F/5.0F;
  Serial.print(palier*PASVOLT*pasSortie);
  Serial.print("\n");
}
