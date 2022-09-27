#include <LedControl.h>

int sw[12] = {29, 28, 27, 26, 25, 24, 13, 12, 11, 10, 9, 8};
int button = 7;

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
void CGget(int button) 
{
    if(Serial.available())
    {
      String weight = Serial.readStringUntil('\n');                                                       
      
      float w1 = weight.indexOf(","); //Output the index value of the character to be separated
      float w2= weight.indexOf(",", w1+1); 
      float length = weight.length(); 
      
      String we1 = weight.substring(0, w1); //String separated by index
      String we2 = weight.substring(w1+1, w2); 
      String we3 = weight.substring(w2+1, length); 

      float wgt1 = we1.toFloat();
      float wgt2 = we2.toFloat();
      float wgt3 = we3.toFloat();
      
      
      float CG = ((wgt1 * 1) + (wgt2 * 2) +(wgt3 * 3)) / (wgt1 + wgt2 + wgt3);
      Serial.println(CG);
      Coordinate(CG);
    }
}

void Coordinate(float CGcoordinate)
{
  if(1 < CGcoordinate < 2)
  {
    if(!button){
      DotOn(0, 0, 0, 8, 8);
    }
    else{
      DotOff(0, 0, 0, 8, 8);
    }
  }
  else if(2 <= CGcoordinate < 3)
  {
    if(!button){
      DotOn(1, 0, 0, 8, 8);
    }
    else{
      DotOff(1, 0, 0, 8, 8);
    }
  }
  else if(3 <= CGcoordinate < 4)
  {
    if(!button){
      DotOn(2, 0, 0, 8, 8);
    }
    else{
      DotOff(2, 0, 0, 8, 8);
    }
  }
}

void SWbool(int DotNum, int SwNum, int Row, int Col){ //the dot matrix is turned on and off according to a switch (with if-else if)
  if(!SwNum) {  //because sw is input_pullup
    DotOn(DotNum, Row, Col-4, Row+4, Col);
  }
  else if(SwNum) {
    DotOff(DotNum, Row, Col-4, Row+4, Col);
  }
}

void SWboolCollection(int DotNum, int select[], int Row, int Col)
{
  for(int i = 0; i < 12; i++) // number of sw is 48
  {
    SWbool(DotNum, select[i], Row, Col); 
    Row = Row + 4;
    
    if(i%2 == 1) //Change matrix number every 4 switches & Reset Row
    {
      DotNum++;
      Row = 0;
    }

    if(i == 5) //Change column number every 12 switches & Reset to dot matrix number 0
    {
      Col = 4; 
      DotNum = 0;
    }

  }
}

void setup()
{
  Serial.begin(9600);
  Serial1.begin(9600);
  for(int i = 0; i < 12; i++)
  {
    pinMode(sw[i], INPUT_PULLUP);
  }
  pinMode(button, INPUT_PULLUP);

  for(int j = 0; j < 3; j++) 
  {
    lc.shutdown(j,false); // power saving mode off
    lc.setIntensity(j,8); // Brightness 8
    lc.clearDisplay(j); // led initialization
  }
}

void loop()
{
  int SWselect[12];
  
  for(int i = 0; i < 12; i++)
  {
    SWselect[i] = digitalRead(sw[i]);
  }
  int buttonstate = digitalRead(button);

  SWboolCollection(0, SWselect, 0, 8); //SWboolCollect function call
  CGget(buttonstate);
}
