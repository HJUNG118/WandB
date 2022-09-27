#include "wandb.h"
int sw[12] = {29, 28, 27, 26, 25, 24, 13, 12, 11, 10, 9, 8};

void setup() {
  Serial.begin(9600);
  SWinput(sw, 12);
}

void loop() {

  int SWselect[12];
  SWread(SWselect, sw, 12);
   //int grn = 1;
   //int yew = 2;
   //int red = 3;

  if(!SWselect[0] && !SWselect[1] && !SWselect[2] && !SWselect[3] && !SWselect[4] && !SWselect[5]
  && !SWselect[6] && !SWselect[7] && !SWselect[8] && !SWselect[9] && !SWselect[10] && !SWselect[11])
  {
    Serial.println('r');
    //delay(1000);
  }
  else if(SWselect[0] && SWselect[1] && SWselect[2] && SWselect[3] && SWselect[4] && SWselect[5]
  && SWselect[6] && SWselect[7] && SWselect[8] && SWselect[9] && SWselect[10] && SWselect[11])
  {
    Serial.println('g');
    //delay(1000);
  }
  else
  {
    Serial.println('y');
    //delay(1000);
  }

}
