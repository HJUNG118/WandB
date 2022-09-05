int value;
float amp;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(A0, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
value = analogRead(A0);
amp = (((value-511)*5/0.66)*1000);
Serial.print(amp);
Serial.println("mA");
delay(1000);
}
