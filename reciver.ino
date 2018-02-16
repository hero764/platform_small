#include <MyWheel.h>
#include <Radio.h>
#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"



int msg[2];
int x1;
int x2;
int x;
int y;
Lbr tr;
MyClass L298N;

void setup()
{
  L298N.begin(7, 6, 5, 2, 4, 3); 
  Serial.begin(9600); 
  tr.begin();
  tr.startListening(0);
}

void loop() {
    
                             
     tr.receive(x, y);   
     x1 = map(x, 0, 1023, -100, 100);
     x2 = map(y, 0, 1023, -100, 100);
     L298N.controlMotors(x1, x2);
   }

