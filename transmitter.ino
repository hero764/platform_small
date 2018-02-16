#include <Radio.h>
#include <SPI.h>          
#include "nRF24L01.h"    
#include "RF24.h"        


int msg[2];
int x;
int y;
Lbr tr;

void setup() {
  Serial.begin(9600); 
  tr.begin();
  tr.startWriting(0);  
}

void loop() {
   x = analogRead(A0);         
   y = analogRead(A1);
   Serial.print("transmitted x: ");
     Serial.println(x);
     Serial.print("transmitted y: ");
     Serial.println(y);
    tr.transmitte(x, y);    
  delay(10);
}
