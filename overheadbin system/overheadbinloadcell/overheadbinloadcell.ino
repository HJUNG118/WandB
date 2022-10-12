#include <HX711.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>


LiquidCrystal_I2C lcd(0x27, 16, 2);

HX711 scale1;
HX711 scale2;
HX711 scale3;

float calibration_factor1 = 372;
float calibration_factor2 = 372;
float calibration_factor3 = 372;

double MyString;
float Parameter1;
float Parameter2;
float Parameter3;

int Red = A7;
int Yew = A8;
int Grn = A9;

void setup() {

  Serial.begin(9600);

  lcd.begin ();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("CJU");
  lcd.setCursor(6, 1);
  lcd.print("VUASRL");
  
  delay(3000);
  lcd.clear();
  
  pinMode(Red, OUTPUT);
  pinMode(Yew, OUTPUT);
  pinMode(Grn, OUTPUT);

  scale1.begin(2, 3);
  scale1.tare(); // first HX711 DTpin, second HX711 SCKpin

  scale2.begin(A0, A1);
  scale2.tare();

  scale3.begin(A2, A3);
  scale3.tare();

  scale1.set_scale();
  scale2.set_scale();
  scale3.set_scale();

}

void loop() {

  scale1.set_scale(calibration_factor1);
  scale2.set_scale(calibration_factor2);
  scale3.set_scale(calibration_factor3);

  Parameter1 = scale1.get_units();    //여기 set_scale 로 바꿔보기.
  Parameter2 = scale2.get_units();
  Parameter3 = scale3.get_units();

  MyString = (Parameter1 + Parameter2 + Parameter3) * 0.001; // if 47 goes up, the led doesn't work

  //char Receive = Serial.read();

  if (Serial.available())
  {
    char Receive = Serial.read();

    if (MyString < 0.5 && Receive == 'g')
    {
      digitalWrite(Grn , 255);
      digitalWrite(Yew, 0);
      digitalWrite(Red , 0);
    }
    else if (MyString > 0 && MyString < 10 && Receive == 'y')
    {
      digitalWrite(Grn , 0);
      digitalWrite(Yew, 255);
      digitalWrite(Red , 0);
    }
    else if (MyString > 10)// && Receive == 'r')
    {
      digitalWrite(Grn , 0);
      digitalWrite(Yew, 0);
      digitalWrite(Red , 255);
    }

    Serial.println(Receive);

  }
    lcd.setCursor(0, 0);
    lcd.print("Weight");
    lcd.setCursor(0, 1);
    lcd.print(MyString);
    lcd.setCursor(6 ,1);
    lcd.print("  kg");
}
