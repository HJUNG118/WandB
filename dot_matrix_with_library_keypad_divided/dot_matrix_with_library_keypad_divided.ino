#include <Keypad.h>
#include <Key.h>
#include <LedControl.h>

LedControl lc = LedControl(28,29,30,3); //(DIN, CLK, CS, matrix number)


const byte ROWS = 1; //
const byte COLS = 1;

char keys[ROWS][COLS] = {'1'}; //If not initialized, garbage values ​​are included.

byte rowPins1[ROWS] = {22};
byte rowPins2[ROWS] = {23};
byte rowPins3[ROWS] = {24};
byte rowPins4[ROWS] = {25};
byte colPins1[COLS] = {13};
byte colPins2[COLS] = {12};
byte colPins3[COLS] = {11};
byte colPins4[COLS] = {10};
byte colPins5[COLS] = {9};
byte colPins6[COLS] = {8};
byte colPins7[COLS] = {7};
byte colPins8[COLS] = {6};
byte colPins9[COLS] = {5};
byte colPins10[COLS] = {4};
byte colPins11[COLS] = {26};
byte colPins12[COLS] = {27};


void DotOn(int matrix, int row1, int col1, int row2, int col2){  //A function that turns on the 4 dot matrix depending on the switch
    for(int a=row1; a<row2; a++) {
      for(int b=col1; b<col2; b++) {
        lc.setLed(matrix,a,b,1);  
      }
    }
}

void DotOff(int matrix, int row1, int col1, int row2, int col2){  //A function that turns off the 4 dot matrix depending on the switch
    for(int a=row1; a<row2; a++) {
      for(int b=col1; b<col2; b++) {
        lc.setLed(matrix,a,b,0);  
      }
    }
}

void Keymatrix(int DotNum, char KeyNum, int Row, int Col) { //A function where the dot matrix is ​​turned on and off according to a switch (with if-else if)
  if(KeyNum) {
    DotOn(DotNum, Row, Col-2, Row+2, Col);
  }
  else if(!KeyNum) {
    DotOff(DotNum, Row, Col-2, Row+2, Col);
  }
}

void setup()

{

  Serial.begin(9600); //
  
  for(int i = 0; i < 3; i++) {
    lc.shutdown(i,false); // power saving mode off
    lc.setIntensity(i,8); // Brightness 8
    lc.clearDisplay(i); // led initialization
  }
}


void loop()
{

Keypad kpd1 = Keypad( makeKeymap(keys), rowPins1, colPins1, ROWS, COLS );
Keypad kpd2 = Keypad( makeKeymap(keys), rowPins1, colPins2, ROWS, COLS );
Keypad kpd3 = Keypad( makeKeymap(keys), rowPins1, colPins3, ROWS, COLS );
Keypad kpd4 = Keypad( makeKeymap(keys), rowPins1, colPins4, ROWS, COLS );
Keypad kpd5 = Keypad( makeKeymap(keys), rowPins1, colPins5, ROWS, COLS );
Keypad kpd6 = Keypad( makeKeymap(keys), rowPins1, colPins6, ROWS, COLS );
Keypad kpd7 = Keypad( makeKeymap(keys), rowPins1, colPins7, ROWS, COLS );
Keypad kpd8 = Keypad( makeKeymap(keys), rowPins1, colPins8, ROWS, COLS );
Keypad kpd9 = Keypad( makeKeymap(keys), rowPins1, colPins9, ROWS, COLS );
Keypad kpd10 = Keypad( makeKeymap(keys), rowPins1, colPins10, ROWS, COLS );
Keypad kpd11 = Keypad( makeKeymap(keys), rowPins1, colPins11, ROWS, COLS );
Keypad kpd12 = Keypad( makeKeymap(keys), rowPins1, colPins12, ROWS, COLS );

Keypad kpd13 = Keypad( makeKeymap(keys), rowPins2, colPins1, ROWS, COLS );
Keypad kpd14 = Keypad( makeKeymap(keys), rowPins2, colPins2, ROWS, COLS );
Keypad kpd15 = Keypad( makeKeymap(keys), rowPins2, colPins3, ROWS, COLS );
Keypad kpd16 = Keypad( makeKeymap(keys), rowPins2, colPins4, ROWS, COLS );
Keypad kpd17 = Keypad( makeKeymap(keys), rowPins2, colPins5, ROWS, COLS );
Keypad kpd18 = Keypad( makeKeymap(keys), rowPins2, colPins6, ROWS, COLS );
Keypad kpd19 = Keypad( makeKeymap(keys), rowPins2, colPins7, ROWS, COLS );
Keypad kpd20 = Keypad( makeKeymap(keys), rowPins2, colPins8, ROWS, COLS );
Keypad kpd21 = Keypad( makeKeymap(keys), rowPins2, colPins9, ROWS, COLS );
Keypad kpd22 = Keypad( makeKeymap(keys), rowPins2, colPins10, ROWS, COLS );
Keypad kpd23 = Keypad( makeKeymap(keys), rowPins2, colPins11, ROWS, COLS );
Keypad kpd24 = Keypad( makeKeymap(keys), rowPins2, colPins12, ROWS, COLS );

Keypad kpd25 = Keypad( makeKeymap(keys), rowPins3, colPins1, ROWS, COLS );
Keypad kpd26 = Keypad( makeKeymap(keys), rowPins3, colPins2, ROWS, COLS );
Keypad kpd27 = Keypad( makeKeymap(keys), rowPins3, colPins3, ROWS, COLS );
Keypad kpd28 = Keypad( makeKeymap(keys), rowPins3, colPins4, ROWS, COLS );
Keypad kpd29 = Keypad( makeKeymap(keys), rowPins3, colPins5, ROWS, COLS );
Keypad kpd30 = Keypad( makeKeymap(keys), rowPins3, colPins6, ROWS, COLS );
Keypad kpd31 = Keypad( makeKeymap(keys), rowPins3, colPins7, ROWS, COLS );
Keypad kpd32 = Keypad( makeKeymap(keys), rowPins3, colPins8, ROWS, COLS );
Keypad kpd33 = Keypad( makeKeymap(keys), rowPins3, colPins9, ROWS, COLS );
Keypad kpd34 = Keypad( makeKeymap(keys), rowPins3, colPins10, ROWS, COLS );
Keypad kpd35 = Keypad( makeKeymap(keys), rowPins3, colPins11, ROWS, COLS );
Keypad kpd36 = Keypad( makeKeymap(keys), rowPins3, colPins12, ROWS, COLS );

Keypad kpd37 = Keypad( makeKeymap(keys), rowPins4, colPins1, ROWS, COLS );
Keypad kpd38 = Keypad( makeKeymap(keys), rowPins4, colPins2, ROWS, COLS );
Keypad kpd39 = Keypad( makeKeymap(keys), rowPins4, colPins3, ROWS, COLS );
Keypad kpd40 = Keypad( makeKeymap(keys), rowPins4, colPins4, ROWS, COLS );
Keypad kpd41 = Keypad( makeKeymap(keys), rowPins4, colPins5, ROWS, COLS );
Keypad kpd42 = Keypad( makeKeymap(keys), rowPins4, colPins6, ROWS, COLS );
Keypad kpd43 = Keypad( makeKeymap(keys), rowPins4, colPins7, ROWS, COLS );
Keypad kpd44 = Keypad( makeKeymap(keys), rowPins4, colPins8, ROWS, COLS );
Keypad kpd45 = Keypad( makeKeymap(keys), rowPins4, colPins9, ROWS, COLS );
Keypad kpd46 = Keypad( makeKeymap(keys), rowPins4, colPins10, ROWS, COLS );
Keypad kpd47 = Keypad( makeKeymap(keys), rowPins4, colPins11, ROWS, COLS );
Keypad kpd48 = Keypad( makeKeymap(keys), rowPins4, colPins12, ROWS, COLS );

//char key[i] = kpd[i].getPressKey();
  char key1 = kpd1.getPressKey(); //48 needed
  char key2 = kpd2.getPressKey(); 
  char key3 = kpd3.getPressKey(); 
  char key4 = kpd4.getPressKey(); 
  char key5 = kpd5.getPressKey();
  char key6 = kpd6.getPressKey();
  char key7 = kpd7.getPressKey(); 
  char key8 = kpd8.getPressKey();
  char key9 = kpd9.getPressKey(); 
  char key10 = kpd10.getPressKey(); 
  char key11 = kpd11.getPressKey(); 
  char key12 = kpd12.getPressKey();
  char key13 = kpd13.getPressKey(); 
  char key14 = kpd14.getPressKey(); 
  char key15 = kpd15.getPressKey();
  char key16 = kpd16.getPressKey(); 
  char key17 = kpd17.getPressKey(); 
  char key18 = kpd18.getPressKey();
  char key19 = kpd19.getPressKey(); 
  char key20 = kpd20.getPressKey(); 
  char key21 = kpd21.getPressKey();
  char key22 = kpd22.getPressKey(); 
  char key23 = kpd23.getPressKey();  
  char key24 = kpd24.getPressKey();
  char key25 = kpd25.getPressKey();
  char key26 = kpd26.getPressKey(); 
  char key27 = kpd27.getPressKey(); 
  char key28 = kpd28.getPressKey();
  char key29 = kpd29.getPressKey(); 
  char key30 = kpd30.getPressKey(); 
  char key31 = kpd31.getPressKey();
  char key32 = kpd32.getPressKey(); 
  char key33 = kpd33.getPressKey(); 
  char key34 = kpd34.getPressKey();
  char key35 = kpd35.getPressKey(); 
  char key36 = kpd36.getPressKey(); 
  char key37 = kpd37.getPressKey();
  char key38 = kpd38.getPressKey(); 
  char key39 = kpd39.getPressKey(); 
  char key40 = kpd40.getPressKey();
  char key41 = kpd41.getPressKey(); 
  char key42 = kpd42.getPressKey(); 
  char key43 = kpd43.getPressKey();
  char key44 = kpd44.getPressKey(); 
  char key45 = kpd45.getPressKey(); 
  char key46 = kpd46.getPressKey();
  char key47 = kpd47.getPressKey(); 
  char key48 = kpd48.getPressKey(); 

//for(i = 0, i < 2; i++) {
 // for(j = 1; j < 49; j++) {
    //for(
 //}
//}

Keymatrix(0, key1, 0, 8);  // (matrix number, key number, row, col)
Keymatrix(0, key2, 2, 8);
Keymatrix(0, key3, 4, 8);
Keymatrix(0, key4, 6, 8);
Keymatrix(1, key5, 0, 8);
Keymatrix(1, key6, 2, 8);
Keymatrix(1, key7, 4, 8);
Keymatrix(1, key8, 6, 8);
Keymatrix(2, key9, 0, 8);
Keymatrix(2, key10, 2, 8);
Keymatrix(2, key11, 4, 8);
Keymatrix(2, key12, 6, 8);

Keymatrix(0, key13, 0, 6);  // (matrix number, key number, row, col)
Keymatrix(0, key14, 2, 6);
Keymatrix(0, key15, 4, 6);
Keymatrix(0, key16, 6, 6);
Keymatrix(1, key17, 0, 6);
Keymatrix(1, key18, 2, 6);
Keymatrix(1, key19, 4, 6);
Keymatrix(1, key20, 6, 6);
Keymatrix(2, key21, 0, 6);
Keymatrix(2, key22, 2, 6);
Keymatrix(2, key23, 4, 6);
Keymatrix(2, key24, 6, 6);

Keymatrix(0, key25, 0, 4);  // (matrix number, key number, row, col)
Keymatrix(0, key26, 2, 4);
Keymatrix(0, key27, 4, 4);
Keymatrix(0, key28, 6, 4);
Keymatrix(1, key29, 0, 4);
Keymatrix(1, key30, 2, 4);
Keymatrix(1, key31, 4, 4);
Keymatrix(1, key32, 6, 4);
Keymatrix(2, key33, 0, 4);
Keymatrix(2, key34, 2, 4);
Keymatrix(2, key35, 4, 4);
Keymatrix(2, key36, 6, 4);

Keymatrix(0, key37, 0, 2);  // (matrix number, key number, row, col)
Keymatrix(0, key38, 2, 2);
Keymatrix(0, key39, 4, 2);
Keymatrix(0, key40, 6, 2);
Keymatrix(1, key41, 0, 2);
Keymatrix(1, key42, 2, 2);
Keymatrix(1, key43, 4, 2);
Keymatrix(1, key44, 6, 2);
Keymatrix(2, key45, 0, 2);
Keymatrix(2, key46, 2, 2);
Keymatrix(2, key47, 4, 2);
Keymatrix(2, key48, 6, 2);

//if(key1 && key2 && key3 && key13 && key14 && key15)
//{
  //Serial.println("omg");
//}

}
