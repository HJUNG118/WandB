#include <Arduino.h>
#include <wandb.h>

LedControl matrix = LedControl(A0, A2, A1, 3); //(DIN, CLK, CS, number of matrix)

void SWinput(int sw[], int a) // sw 48 input declaration
{
  for(int i = 0; i < a; i++)
  {
    pinMode(sw[i], INPUT_PULLUP);
  }
}

void MatrixSetting() //matrix setting
{
  for(int i = 0; i < 3; i++) 
  {
    matrix.shutdown(i,false); // power saving mode off
    matrix.setIntensity(i,8); // Brightness 8 
    matrix.clearDisplay(i); // led initialization
  }
}

void SWread(int SWselect[], int sw[]) // Read 48 switch signals
{
  for(int i = 0; i < 48; i++)
  {
    SWselect[i] = digitalRead(sw[i]);
  }
}

void DotOn(int MatrixNum, int row1, int col1, int row2, int col2){  //turn on the 4 dot matrix depending on the switch
    for(int a=row1; a<row2; a++) {
      for(int b=col1; b<col2; b++) {
        matrix.setLed(MatrixNum, a, b, 1); // (number of matrix, row, col, on) 
      }
    }
}

void DotOff(int MatrixNum, int row1, int col1, int row2, int col2){  //turn off the 4 dot matrix depending on the switch
    for(int a=row1; a<row2; a++) {
      for(int b=col1; b<col2; b++) {
        matrix.setLed(MatrixNum, a, b, 0);  // (number of matrix, row, col, off)
      }
    }
}

void SWbool(int MatrixNum, int SwNum, int Row, int Col){ //the dot matrix is turned on and off according to a switch (with if-else if)
  if(!SwNum) {  //because sw is input_pullup
    DotOn(MatrixNum, Row, Col-2, Row+2, Col);
  }
  else if(SwNum) {
    DotOff(MatrixNum, Row, Col-2, Row+2, Col);
  }
}

void SWboolCollection(int MatrixNum, int SWselect[], int Row, int Col)
{
  for(int i = 0; i < 48; i++) // number of sw is 48
  {
    SWbool(MatrixNum, SWselect[i], Row, Col);
    Row = Row+2; 
    
    if((i%4 == 3)) //Change matrix number every 4 switches & Reset Row
    {
      MatrixNum++;
      Row = 0;
    }
    if(i%12 == 11) //Change column number every 12 switches & Reset to dot matrix number 0
    {
      Col = Col-2; 
      MatrixNum = 0;
    }
  }
}