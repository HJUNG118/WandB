int sw[12] = {41, 39, 37, 35, 33, 31, 28, 26, 24, 22, 20, 18};
int led = 2;


void setup() {
  Serial.begin(9600);
  
  for(int i = 0; i < 48; i++)
  {
    pinMode(sw[i], INPUT_PULLUP);
  }
  pinMode(led, OUTPUT);


}

void loop() {

  int SWselect[12];

  for(int i = 0; i < 12; i++)
  {
    SWselect[i] = digitalRead(sw[i]);
  }


  if(!SWselect[0] && !SWselect[1] && !SWselect[2] && !SWselect[3] && !SWselect[4] && !SWselect[5]
  && !SWselect[6] && !SWselect[7] && !SWselect[8] && !SWselect[9] && !SWselect[10] && !SWselect[11])
  {
    digitalWrite(led, 1);
  }
  else if(SWselect[0] && SWselect[1] && SWselect[2] && SWselect[3] && SWselect[4] && SWselect[5]
  && SWselect[6] && SWselect[7] && SWselect[8] && SWselect[9] && SWselect[10] && SWselect[11])
  {
    digitalWrite(led, 0);
  }
  else
  {
    Serial.println("yellow");
  }

}
