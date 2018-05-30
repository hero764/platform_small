#include <MyWheel.h>         //библиотека для управления двигателями
#include <Radio.h>           //библиотека для радиопередачи
#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"



int msg[2];                  //вводим массив для передачи координат X и Y
int x1;                      
int x2; 
int x;
int y;
Lbr tr;                      //обращаемся к структуре lbr в radio.h, в дальнейшем обращаться к ней будем через "tr"
MyClass L298N;               //обращаемся к структуре MyClass в MyWheel.h, в дальнейшем обращаться к ней будем через "L298N"

void setup()
{
  L298N.begin(7, 6, 5, 2, 4, 3);       //Задаем номера пинов к которым подключены соответствующие контакты в очередности pinUpRight, pinDownRight, pinSpeedRight, pinUpLeft, pinDownLeft, pinSpeedLeft
  Serial.begin(9600); 
  tr.begin();
  tr.startListening(0);                //обращаемся к функции startListening() в структуре lbr находящейся в библиотеке radio.cpp
}

void loop() {
    
                             
     tr.receive(x, y);                     //начинаем передачу X и Y обращаясь к функции recieve в библиотеке radio.h
     x1 = map(x, 0, 1023, -100, 100);
     x2 = map(y, 0, 1023, -100, 100);
     L298N.controlMotors(x1, x2);          //эта функция принимая значения x1 и x2 отправляет их в библиотеку MyWheel.h 
   }

