const byte rows = 4; //4 rows
const byte cols = 12; //12 columns

byte rowPins[rows] = {13, 12, 11, 10};
byte colPins[cols] = {9, 8, 7, 6, 5, 4, 3, 2, 22, 23, 24, 25};

//char keys[rows][cols] = { };

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
  
  //char val = '\0';
 
  for(int y=0;y<rows;y++){
    digitalWrite(rowPins[y], LOW);   //
    for(int x=0;x<cols;x++){     
        if(!digitalRead(colPins[x]))
        {
          Serial.println("green");
          //val = "red";
        }
    }        
    digitalWrite(rowPins[y], HIGH);  //
  }


//if(val!='\0'){
    //Serial.println(val);
    //delay(300);
 //}      
}
