#include <Keypad.h>
#include <Key.h>

const int ROWS = 2;
const int COLS = 2;

char keys[ROWS][COLS] = 
{
{'1', '1'},
{'1', '1'},
};

byte rowPins1[ROWS] = {13, 12}; 
byte rowPins2[ROWS] = {11, 10}; 
byte colPins1[COLS] = {9, 8}; 
byte colPins2[COLS] = {7, 6}; 



Keypad kpd1 = Keypad( makeKeymap(keys), rowPins1, colPins1, ROWS, COLS );
Keypad kpd2 = Keypad( makeKeymap(keys), rowPins2, colPins1, ROWS, COLS );
Keypad kpd3 = Keypad( makeKeymap(keys), rowPins1, colPins2, ROWS, COLS );
Keypad kpd4 = Keypad( makeKeymap(keys), rowPins2, colPins2, ROWS, COLS );



void setup()

{
  Serial.begin(9600); 
}


void loop()
{

  char key1 = kpd1.getPressKey(); 
  char key2 = kpd2.getPressKey(); 
  char key3 = kpd3.getPressKey(); 
  char key4 = kpd4.getPressKey();  
  

if(!key1 && !key2 && !key3 && !key4)
{
  Serial.println("Green");
  delay(100);
}
else if(key1 && key2 && key3 && key4)
{
  Serial.println("Red");
}
else
{
  Serial.println("Yellow");
}

}
