#include <HX711.h>
#include <Wire.h>

HX711 scale1;
HX711 scale2;
HX711 scale3;
 
float calibration_factor1 = 372;
float calibration_factor2 = 372;
float calibration_factor3 = 372;
  
int MyString;
float Parameter1;
float Parameter2;
float Parameter3;


void setup() {

 Serial.begin(9600);

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
 MyString = Parameter1 + Parameter2 + Parameter3 ;

 Serial.print(scale1.get_units(5)*0.001 , 1);   //first = Unit conversion (lb to kg), second = decimal point
 Serial.print(",");
 Serial.print(scale2.get_units(5)*0.001 , 1);   //first = Unit conversion (lb to kg), second = decimal point
 Serial.print(",");
 Serial.print(scale3.get_units(5)*0.001 , 1);   //first = Unit conversion (lb to kg), second = decimal point
 Serial.print(",");
 Serial.println(MyString *0.001 , 1);
 delay(1000);
 }
