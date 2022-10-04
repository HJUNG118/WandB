#include <Arduino.h>
#include <wandb.h>

LedControl matrix = LedControl(A0, A2, A1, AllDotNum); //(DIN, CLK, CS, number of matrix)

void SWinput(int sw[], int SwNum) // sw 48 input declaration
{
  for(int i = 0; i < SwNum; i++)
  {
    pinMode(sw[i], INPUT_PULLUP);
  }
}

void MatrixSetting() //matrix setting
{
  for(int i = 0; i < AllDotNum; i++) 
  {
    matrix.shutdown(i,false); // power saving mode off
    matrix.setIntensity(i,DotBrightness); // Brightness 8 
    matrix.clearDisplay(i); // led initialization
  }
}

void SWread(int SWselect[], int sw[], int SwNum) // Read SwNum switch signals
{
  for(int i = 0; i < SwNum; i++)
  {
    SWselect[i] = digitalRead(sw[i]);
  }
}

void DotOn(int MatrixNum, int row1, int col1, int row2, int col2){  //turn on the 4 dot matrix depending on the switch
    for(int a=row1; a<row2; a++) {
      for(int b=col1; b<col2; b++) {
        matrix.setLed(MatrixNum, a, b, true); // (number of matrix, row, col, on) 
      }
    }
}

void DotOff(int MatrixNum, int row1, int col1, int row2, int col2){  //turn off the 4 dot matrix depending on the switch
    for(int a=row1; a<row2; a++) {
      for(int b=col1; b<col2; b++) {
        matrix.setLed(MatrixNum, a, b, false);  // (number of matrix, row, col, off)
      }
    }
}

void print_weight()
{
  OzOled.printString("1:", 0, 0);
  OzOled.printString("2:", 8, 0);
  OzOled.printString("3:", 0, 2);
  OzOled.printString("Total  : ", 0, 4);
 }

void print_CG()
{
  OzOled.printString("CG     :", 0, 6);
}

void LoadCell_Weight(float wgt1, float wgt2, float wgt3, float wgt4)
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

void CGposition(float x, float y)
{
  OzOled.printString(x, 10 ,6);
  OzOled.printString(",", 11 ,6);
  OzOled.printString(y, 13 ,6);
}


void CGweightGet() 
{
  if(Serial.available())
  {
    String weight = Serial.readStringUntil('\n');                                                       
      
    float w1 = weight.indexOf(","); //Output the index value of the character to be separated
    float w2= weight.indexOf(",", w1+1); 
    float w3= weight.indexOf(",", w2+1); 
    float length = weight.length(); 
      
    String we1 = weight.substring(0, w1); //String separated by index
    String we2 = weight.substring(w1+1, w2); 
    String we3 = weight.substring(w2+1, w3); 
    String we4 = weight.substring(w3+1, length); 

    float wgt1 = we1.toFloat();
    float wgt2 = we2.toFloat();
    float wgt3 = we3.toFloat();
    float wgt4 = we4.toFloat();

    LoadCell_Weight(wgt1, wgt2, wgt3, wgt4);
  }

}

void CGcoordinateGet(int sw[])
{
  float xcoordinate[AllSwNum];
  float ycoordinate[AllSwNum];
  float xWgtMulDistance = 0;
  float yWgtMulDistance = 0;
  float xCGcoordinate;
  float yCGcoordinate;
  float WgtTotal = 0;
      
  for(int i = 0; i < AllSwNum; i++)
  {
    int x = i + StartCol;
    int y = FirstRow;
    if(i > RowReplacement)
    {
      y = SecondRow;
      x = i - RowReplacement;
    }
    if(!sw[i])
    {
        xcoordinate[i] = x * StandardWgt;
        ycoordinate[i] = y * StandardWgt;
        WgtTotal += StandardWgt;
    }
    if(sw[i])
    {
      xcoordinate[i] = 0;
      ycoordinate[i] = 0;
    }

    xWgtMulDistance += xcoordinate[i];
    yWgtMulDistance += ycoordinate[i];
  }
  xCGcoordinate = xWgtMulDistance / WgtTotal;
  yCGcoordinate = yWgtMulDistance / WgtTotal;

  Serial.print(xCGcoordinate, DecimalPoint);
  Serial.print("\t");
  Serial.println(yCGcoordinate, DecimalPoint);

  CGposition(xCGcoordinate, yCGcoordinate);
}

void SWbool(int MatrixNum, int SwNum, int Row, int Col){ //the dot matrix is turned on and off according to a switch (with if-else if)
  if(!SwNum) {  //because sw is input_pullup
    DotOn(MatrixNum, Row, Col-NextCoordinate, Row+NextCoordinate, Col);
  }
  else if(SwNum) {
    DotOff(MatrixNum, Row, Col-NextCoordinate, Row+NextCoordinate, Col);
  }
}


void SWboolCollection(int DotNum, int select[], int Row, int Col)
{
  for(int i = 0; i < AllSwNum; i++) // number of sw is 48
  {
    SWbool(DotNum, select[i], Row, Col); 
    Row = Row + NextCoordinate;
    
    if(i%ChangeDotNum == ResetRow) //Change matrix number every 4 switches & Reset Row
    {
      DotNum++;
      Row = 0;
    }

    if(i == ChangeColNum) //Change column number every 12 switches & Reset to dot matrix number 0
    {
      Col = NextCoordinate; 
      DotNum = 0;
    }

  }
}