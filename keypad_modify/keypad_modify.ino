int sw[48] = {53, 52, 51, 50, 49, 48, 47, 46, 45, 44, 43, 42, 41, 40, 
39, 38, 37, 36, 35, 34, 33, 32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 
22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6};

void SWon(int on[])
{
  for(int i = 0; i < 2; i++)
  {
    if(on[i] == HIGH)
    {
      Serial.println("green");
    }

  } 
}

void SWoff(int off[])
{
  for(int i = 0; i < 48; i++)
  {
    off[i] == LOW;
  } 
}

void setup() {
  Serial.begin(9600);
  
  for(int i = 0; i < 48; i++)
  {
    pinMode(sw[i], INPUT_PULLUP);
  }


}

void loop() {

  int SWselect[48];
  
  for(int i = 0; i < 48; i++)
  {
    SWselect[i] = digitalRead(sw[i]);
  }

//if(!SWselect[0] && !SWselect[1] && !SWselect[2] && !SWselect[3] && !SWselect[4])
//{
  //Serial.println("red");
//}

SWon(SWselect);



  
}
