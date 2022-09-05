#include <LedControl.h>
//#include <Keypad.h>
//#include <Key.h>

LedControl lc = LedControl(32,34,36,1);

const byte ROWS = 4; //2byte
const byte COLS = 12;

byte rowPins[ROWS] = {13, 12, 11, 10};//, 8, 6};
byte colPins[COLS] = {9, 8, 7, 6, 5, 4, 3, 2, 22, 23, 24, 25};

char keys[ROWS][COLS] = 
{
  //{'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l'},
  //{'m', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x'}, 
  //{'1', '2', '3', '4', '5', '6', '7', '8', '9', '0', ']', '['},
 // {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L'}
};

//const byte Dot1[] = {B11000000, B11000000};

//Keypad kpd = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup()
{

  lc.shutdown(0,false); // power saving mode off
  lc.setIntensity(0,8); // Brightness 8
  lc.clearDisplay(0); // led initialization

  Serial.begin(9600);
  
  for(int i=0; i<ROWS; i++){ // lock with each row initialization
    pinMode(rowPins[i], OUTPUT);
    digitalWrite(rowPins[i], HIGH);   
  }
  for(int i=0; i<COLS; i++){
    pinMode(colPins[i], INPUT_PULLUP); //on-LOW, off-HIGH, lock with each col initialization
  }  

}
 

void loop()
{

  char val = '\0';
 
  for(int y=0; y<ROWS; y++){
    digitalWrite(rowPins[y], LOW);   //
    for(int x=0; x<COLS; x++){     
        if(!digitalRead(colPins[x]))
        {
          //Serial.println("green");
          val = keys[y][x];
          lc.setLed(0,y,x,true);
          lc.setLed(0,y,x+1,true);

        }
        else if(digitalRead(colPins[x]))
        {
          lc.setLed(0,y,x,false);
          //lc.setLed(0,y,x+1,false);

        }
    }        
    digitalWrite(rowPins[y], HIGH);  //
  }


 if(val!='\0'){
    Serial.println(val);
    delay(300);
 } 
 

}
