#include <LedControl.h>
#include <Wire.h>
#include <OzOLED.h>

int sw[12] = {29, 28, 27, 26, 25, 24, 13, 12, 11, 10, 9, 8};

int Red = A3;
int Grn = A4;

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

void LoadCell_Weight(const char *wgt1, const char *wgt2, const char *wgt3, const char *wgt4)
{
  OzOled.printString(wgt1, 2, 0);
  OzOled.printString("kg",5, 0);
  OzOled.printString(wgt2, 10, 0);
  OzOled.printString("kg",13,0);
  OzOled.printString(wgt3, 2, 2);
  OzOled.printString("kg",5, 2);
  OzOled.printString(wgt4, 10 ,4);
  OzOled.printString("kg", 13, 4);
}

void CGposition(const char *x, const char *y)
{
  OzOled.printString(x, 8 ,6);
  OzOled.printString(",", 11 ,6);
  OzOled.printString(y, 13 ,6);
}

void CGweightGet() 
{
  if(Serial.available())
  {
    char s1[6];
    char s2[6];
    char s3[6];
    char s4[6];
    
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
    
    dtostrf(wgt1 , 3, 1, s1);
    dtostrf(wgt2 , 3, 1, s2); 
    dtostrf(wgt3 , 3, 1, s3);
    dtostrf(wgt4 , 3, 1, s4); 

    LoadCell_Weight(s1, s2, s3, s4);
  }

}

void CGwarn(float Xvalue)
{
  if((Xvalue <= 2.5) || (Xvalue >= 4.5))
  {
    digitalWrite(Grn, 0);
    digitalWrite(Red, 255);
    delay(500);
    digitalWrite(Red, 0);
    delay(500);
  }
  else if((Xvalue >= 2.5) && (Xvalue <= 4.5))
  {
    digitalWrite(Grn, 255);
    digitalWrite(Red, 0);
    delay(500);
  }
}

void CGcoordinateGet(int sw[])
{
  float xcoordinate[12];
  float ycoordinate[12];
  float xWgtMulDistance = 0;
  float yWgtMulDistance = 0;
  float xCGcoordinate;
  float yCGcoordinate;
  float WgtTotal = 0;
  float mini = 2.5;
  float maxi = 4.5;
  char x1[5];
  char y1[5];
      
  for(int i = 0; i < 12; i++)
  {
    int x = i + 1;
    int y = 1;
    if(i > 5)
    {
      y = 2;
      x = i - 5;
    }
    if(!sw[i])
    {
        xcoordinate[i] = x * 1.5;
        ycoordinate[i] = y * 1.5;
        WgtTotal += 1.5;
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

  dtostrf(xCGcoordinate , 3, 1, x1); 
  dtostrf(yCGcoordinate , 3, 1, y1);  
  
  CGposition(x1, y1);
  CGwarn(xCGcoordinate);
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
  for(int i = 0; i < 12; i++)
  {
    pinMode(sw[i], INPUT_PULLUP);
  }

  pinMode(Red, OUTPUT);
  pinMode(Grn, OUTPUT);

  for(int j = 0; j < 3; j++) 
  {
    lc.shutdown(j,false); // power saving mode off
    lc.setIntensity(j,8); // Brightness 8
    lc.clearDisplay(j); // led initialization
  }
  OzOled.init();
  OzOled.clearDisplay();
  print_weight();
  print_CG();
}

void loop()
{
  int SWselect[12];

  for(int i = 0; i < 12; i++)
  {
    SWselect[i] = digitalRead(sw[i]);
  }

  SWboolCollection(0, SWselect, 0, 8); //SWboolCollect function cal
  CGweightGet();
  CGcoordinateGet(SWselect);
}
