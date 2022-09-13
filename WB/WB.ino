#include "wandb.h"

int sw[48] = {53, 52, 51, 50, 49, 48, 47, 46, 45, 44, 43, 42, 41, 40, 
39, 38, 37, 36, 35, 34, 33, 32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 
22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6};

void setup()
{
  SWinput(sw, 48);
  MatrixSetting();
}

void loop()
{
  int SWselect[48];
  SWread(SWselect, sw, 48);
  SWboolCollection(0, SWselect, 0, 8); //SWboolCollect function call
}
