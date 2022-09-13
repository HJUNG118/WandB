/*
wandb.h - Library for tact switch & dot matrix interlocking. 
this is made for making weigh and balance system.
Created by Hae jeong Lim, September 12, 2022
Released into the public domain
*/
#ifndef wandb_H
#define wandb_H
#include <LedControl.h>

void SWinput(int sw[], int a);
void MatrixSetting();
void SWread(int SWselect[], int sw[], int a);

void DotOn(int MatrixNum, int row1, int col1, int row2, int col2);
void DotOff(int MatrixNum, int row1, int col1, int row2, int col2);
void SWbool(int DMatrixNum, int SwNum, int Row, int Col);
void SWboolCollection(int MatrixNum, int select[], int Row, int Col);

/*
class WeighandBalance
{
    public:
    WeightandBalance(int sw[]);
    WeightandBalance();
}*/


#endif


