#include "wandb.h"

int sw[12] = {29, 28, 27, 26, 25, 24, 13, 12, 11, 10, 9, 8};


void setup()
{
  Serial.begin(9600);
  SWinput(sw, 12); // SW INPUT-PULLUP declaration fuction
  MatrixSetting(); // dot matrix initialize, brightness setting, power on
}

void loop()
{
  int SWselect[12];
  SWread(SWselect, sw, 12); // read signal of 48 switch
  SWboolCollection(0, SWselect, 0, 8); //SWboolCollect function call
  CGweightGet();
  CGcoordinateGet(SWselect);
}
