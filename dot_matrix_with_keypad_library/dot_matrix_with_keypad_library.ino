#include <LedControl.h>
#include <Keypad.h>

LedControl lc = LedControl(32,34,36,1);

const byte ROWS = 4; //2byte
const byte COLS = 12;

byte rowPins[ROWS] = {13, 12, 11, 10};//, 8, 6};
byte colPins[COLS] = {9, 8, 7, 6, 5, 4, 3, 2, 22, 23, 24, 25};

char keys[ROWS][COLS] = 
{
  {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l'},
  {'m', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x'}, 
  {'1', '2', '3', '4', '5', '6', '7', '8', '9', '0', ']', '['},
  {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L'}
};

void DotOn(int i, int k, int x, int y){
    for(int a=i; a<x; a++) {
      for(int b=k; b<y; b++) {
        lc.setLed(0,a,b,true);  
      }
    }
    return 0;
}

void DotOff(int i, int k, int x, int y){
    for(int a=i; a<x; a++) {
      for(int b=k; b<y; b++) {
        lc.setLed(0,a,b,0);
        }
      }
      return 0;  
}

void setup()

{

  Serial.begin(9600); //

  lc.shutdown(0,false); // power saving mode off
  lc.setIntensity(0,8); // Brightness 8
  lc.clearDisplay(0); // led initialization

}


void loop()
{
  Keypad kpd = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
  char key = kpd.getPressKey(); //10byte

  if(key)
  {
    Serial.println(key);
  }

  if(key == 'a'){
    DotOn(0, 0, 2, 2);
  }
  else if(key != 'a'){
    DotOff(0, 0, 2, 2);
  }

  if(key == 'b'){
  DotOn(0, 2, 2, 4);
  }
  else if(key != 'b'){
   DotOff(0, 2, 2, 4);
  }
  //switch(key){
    //case 'a':
    //DotUp(0, 0);
    //DotDown(0, 0);

    //case 'b':
    //DotUp(0, 2);
    //DotDown(0, 2);

  //}
  


}  
