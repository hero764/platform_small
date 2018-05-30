#include <Radio.h>             //библиотека для радиопередачи
#include <SPI.h>          
#include "nRF24L01.h"    
#include "RF24.h"        


int msg[2];                    //вводим массив для передачи координат X и Y
int x;
int y;
Lbr tr;                       //обращаемся к структуре lbr в radio.h, в дальнейшем обращаться к ней будем через "tr"

void setup() {
  Serial.begin(9600); 
  tr.begin();                
  tr.startWriting(0);        //обращаемся к функции startWriting() в структуре lbr находящейся в библиотеке radio.cpp, в скобочках пишем номер канала по которому бедт идти предача
}

void loop() {
   x = analogRead(A0);       //считывание значений со входа А0
   y = analogRead(A1);       //считывание значений со входа А1
   Serial.print("transmitted x: ");
     Serial.println(x);
     Serial.print("transmitted y: ");
     Serial.println(y);
    tr.transmitte(x, y);    //обращаемся к функции trinsmitte в структуре lbr находящейся в библиотеке radio.cpp
  delay(10);
}
