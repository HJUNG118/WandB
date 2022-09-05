const byte rows = 4; //4 rows
const byte cols = 4; //12 columns

byte rowPins[rows] = {13, 12, 11, 10};
byte colPins[cols] = {9, 8, 7, 6};

void setup(){
  Serial.begin(9600);
  
  for(int i=0;i<rows;i++){
    pinMode(rowPins[i], OUTPUT);
    digitalWrite(rowPins[i], HIGH);   // 
  }
  for(int i=0;i<cols;i++){
    pinMode(colPins[i], INPUT_PULLUP); //on-LOW, off-HIGH
  }  
}

void loop(){
  
  char val = '\0';
 
  for(int x=0;x<cols;x++){
    digitalWrite(rowPins[x], LOW);   //
    for(int a=0;a<1;a++){     
        if(!digitalRead(colPins[a])) // if col is pushed, colpin is output-> LOW
        {
          val = 'A';
        }
    }
    for(int b=1;b<2;b++){     
        if(!digitalRead(colPins[b])) // if col is pushed, colpin is output-> LOW
        {
          val = 'B';
        }
    }
    for(int c=2;c<3;c++){     
        if(!digitalRead(colPins[c])) // if col is pushed, colpin is output-> LOW
        {
          val = 'C';
        }
    }
    for(int d=3;d<4;d++){     
        if(!digitalRead(colPins[d])) // if col is pushed, colpin is output-> LOW
        {
          val = 'D';
        }
    }
  }
        
  

 if(val!='\0'){
    Serial.println(val);
    delay(300);
 }      
}
