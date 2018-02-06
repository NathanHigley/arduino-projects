#include <Servo.h> 
#include "IRLibAll.h"
#include <IRLibRecvPCI.h> 
Servo servo;
IRrecvPCI myReceiver(2);
IRdecode myDecoder;

void setup() {
  Serial.begin(9600);
  delay(2000); while (!Serial);
  myReceiver.enableIRIn();
  Serial.println(F("Active"));

servo.attach(12); 
}
void loop() {
  // put your main code here, to run repeatedly:
     if(myReceiver.getResults()) {
      myDecoder.decode();
     if(myDecoder.value==0xA10C840B){
      Serial.println("TURN");     
      servo.writeMicroseconds(1700);
      delay(430); }
    myReceiver.enableIRIn(); 
  }
}

