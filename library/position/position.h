/* 
    position.h - Library for print LCD position code.
    Created by JaeEun Kim Setember 30,2022
    Released into public domain
*/
#ifndef position_h
#define position_h

#include "Arduino.h"
#include <OzOLED.h>


void print_weight();
void print_CG();
void LoadCell_Weight(const char *wgt1, const char *wgt2, const char *wgt3, const char *wgt4);
void CGposition(const char *x, const char *y);

#endif



