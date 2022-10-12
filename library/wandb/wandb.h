/*
wandb.h - Library for tact switch & dot matrix interlocking. 
this is made for making weigh and balance system.
Created by Hae jeong Lim, September 12, 2022
Released into the public domain
*/
#ifndef wandb_H
#define wandb_H
#include <LedControl.h>
#include "position.h"

#define AllSwNum 12
#define AllDotNum 3
#define DotBrightness 8
#define ChangeDotNum 2
#define ChangeColNum 5
#define ResetRow 1
#define NextCoordinate 4
#define DecimalPoint 0
#define StandardWgt 1.5
#define RowReplacement 5
#define FirstRow 1
#define SecondRow 2
#define StartCol 1
#define MinilimitRange 2.5
#define MaxilimitRange 4.5
#define StanWeight 1.5
#define StartCoordinate 1;
#define StartCoorReset 5;

void SWinput(int sw[], int SwNum);
void MatrixSetting();
void SWread(int SWselect[], int sw[], int SwNum);
void output(int Warning, int Stability);
void DotOn(int MatrixNum, int row1, int col1, int row2, int col2);
void DotOff(int MatrixNum, int row1, int col1, int row2, int col2);

void CGweightGet();
void CGwarn(float Xvalue, int Warning, int Stability);
void CGcoordinateGet(int sw[], int Warning, int Stability);
void SWbool(int DMatrixNum, int SwNum, int Row, int Col);
void SWboolCollection(int MatrixNum, int select[], int Row, int Col);

#endif


