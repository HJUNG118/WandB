#include <LedControl.h>

int sw[48] = {53, 52, 51, 50, 49, 48, 47, 46, 45, 44, 43, 42, 41, 40, 
39, 38, 37, 36, 35, 34, 33, 32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 
22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6};

LedControl lc = LedControl(A0, A2, A1, 3); //(DIN, CLK, CS, number of matrix)

void DotOn(int matrix, int row1, int col1, int row2, int col2){  //turns on the 4 dot matrix depending on the switch
    for(int a=row1; a<row2; a++) {
      for(int b=col1; b<col2; b++) {
        lc.setLed(matrix, a, b, 1); // (number of matrix, row, col, on) 
      }
    }
}

void DotOff(int matrix, int row1, int col1, int row2, int col2){  //turns off the 4 dot matrix depending on the switch
    for(int a=row1; a<row2; a++) {
      for(int b=col1; b<col2; b++) {
        lc.setLed(matrix, a, b, 0);  // (number of matrix, row, col, off)
      }
    }
}

void SWbool(int DotNum, int SwNum, int Row, int Col){ //the dot matrix is turned on and off according to a switch (with if-else if)
  if(!SwNum) {  //because sw is input_pullup
    DotOn(DotNum, Row, Col-2, Row+2, Col);
  }
  else if(SwNum) {
    DotOff(DotNum, Row, Col-2, Row+2, Col);
  }
}

void SWboolCollection(int DotNum, int select[], int Row, int Col)
{
  for(int i = 0; i < 48; i++) // number of sw is 48
  {
    SWbool(DotNum, select[i], Row, Col);
    Row = Row+2; 
    
    if((i%4 == 3)) //Change matrix number every 4 switches & Reset Row
    {
      DotNum++;
      Row = 0;
    }

    if(i%12 == 11) //Change column number every 12 switches & Reset to dot matrix number 0
    {
      Col = Col-2; 
      DotNum = 0;
    }

  }
}


void setup()
{
  for(int i = 0; i < 48; i++)
  {
    pinMode(sw[i], INPUT_PULLUP);
  }

  for(int j = 0; j < 3; j++) 
  {
    lc.shutdown(j,false); // power saving mode off
    lc.setIntensity(j,8); // Brightness 8
    lc.clearDisplay(j); // led initialization
  }
}

void loop()
{
  int SWselect[48];
  
  for(int i = 0; i < 48; i++)
  {
    SWselect[i] = digitalRead(sw[i]);
  }

  SWboolCollection(0, SWselect, 0, 8); //SWboolCollect function call
}
