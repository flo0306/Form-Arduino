void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(2, INPUT);
pinMode(12, OUTPUT);
attachInterrupt(INT0,turnOnlight,CHANGE);
}
volatile bool ledState=false;

void loop() {
  // put your main code here, to run repeatedly:
 Serial.print("Hello\n");
 digitalWrite(12,ledState);
}

void turnOnlight() {
 ledState=!ledState;
}
