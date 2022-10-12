#include "Arduino.h"
#include "position.h"


void print_weight()
{
  OzOled.init();
  OzOled.clearDisplay();
  OzOled.printString("1:", 0, 0);
  OzOled.printString("2:", 8, 0);
  OzOled.printString("3:", 0, 2);
  OzOled.printString("Total  : ", 0, 4);
}

void print_CG()
{
  OzOled.printString("CG     :", 0, 6);
}

void LoadCell_Weight(const char *wgt1, const char *wgt2, const char *wgt3, const char *wgt4)
{
  OzOled.printString(wgt1, 2, 0);
  OzOled.printString("kg",5,0);
  OzOled.printString(wgt2, 10, 0);
  OzOled.printString("kg",13,0);
  OzOled.printString(wgt3, 2, 2);
  OzOled.printString("kg",5,2);
  OzOled.printString("0,0", 10 ,4);
  OzOled.printString(wgt4, 13,4);
}

void CGposition(const char *x, const char *y)
{
  OzOled.printString(x, 10 ,6);
  OzOled.printString(",", 11 ,6);
  OzOled.printString(y, 13 ,6);
}
