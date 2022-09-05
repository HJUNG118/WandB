#include <Keypad.h>
#include <Key.h>


const byte ROWS = 2; //2byte
const byte COLS = 2;

char keys[ROWS][COLS] = 
{
  {'1','2'},
  {'3','4'}
};


byte rowPins1[ROWS] = {22, 23};
byte rowPins2[ROWS] = {24, 25};
byte colPins1[COLS] = {13, 12};
byte colPins2[COLS] = {11, 10};
byte colPins3[COLS] = {9, 8}; 
byte colPins4[COLS] = {7, 6}; 
byte colPins5[COLS] = {5, 4}; 
byte colPins6[COLS] = {27, 26}; 

Keypad kpd1 = Keypad( makeKeymap(keys), rowPins1, colPins1, ROWS, COLS );
Keypad kpd2 = Keypad( makeKeymap(keys), rowPins2, colPins1, ROWS, COLS );
Keypad kpd3 = Keypad( makeKeymap(keys), rowPins1, colPins2, ROWS, COLS );
Keypad kpd4 = Keypad( makeKeymap(keys), rowPins2, colPins2, ROWS, COLS );
Keypad kpd5 = Keypad( makeKeymap(keys), rowPins1, colPins3, ROWS, COLS );
Keypad kpd6 = Keypad( makeKeymap(keys), rowPins2, colPins3, ROWS, COLS );
Keypad kpd7 = Keypad( makeKeymap(keys), rowPins1, colPins4, ROWS, COLS );
Keypad kpd8 = Keypad( makeKeymap(keys), rowPins2, colPins4, ROWS, COLS );
Keypad kpd9 = Keypad( makeKeymap(keys), rowPins1, colPins5, ROWS, COLS );
Keypad kpd10 = Keypad( makeKeymap(keys), rowPins2, colPins5, ROWS, COLS );
Keypad kpd11 = Keypad( makeKeymap(keys), rowPins1, colPins6, ROWS, COLS );
Keypad kpd12 = Keypad( makeKeymap(keys), rowPins2, colPins6, ROWS, COLS );







void setup()

{

  Serial.begin(9600); //
}


void loop()
{

  char key1 = kpd1.getPressKey(); //10byte
  char key2 = kpd2.getPressKey(); 
  char key3 = kpd3.getPressKey(); 
  char key4 = kpd4.getPressKey(); 
  char key5 = kpd5.getPressKey();
  char key6 = kpd6.getPressKey();
  char key7 = kpd7.getPressKey(); 
  char key8 = kpd8.getPressKey();
  char key9 = kpd9.getPressKey(); 
  char key10 = kpd10.getPressKey(); 
  char key11 = kpd11.getPressKey(); 
  char key12 = kpd12.getPressKey();


if(!key1 && !key2 && !key3 && !key4 && !key5 && !key6 && !key7 && !key8 && !key9 && !key10 && !key11 && !key12)
{
  Serial.println("green");
}
else if(key1 && key2 && key3 && key4 && key5 && key6 && key7 && key8) // && key9 && key10 && key11 && key12)
{
  Serial.println("Red");
}
//else if(key1 && key2 && key3 && key4)
//{
 // Serial.println("d");
//}
else
{
  Serial.println("Yellow");
}


}
