#include <Servo.h> 
#include "IRLibAll.h"
#include <IRLibRecvPCI.h> 
Servo servoLeft; 
Servo servoRight;
IRrecvPCI myReceiver(2);
IRdecode myDecoder;

void setup() {
  Serial.begin(9600);
  delay(2000); while (!Serial);
  myReceiver.enableIRIn();
  Serial.println(F("Active"));

servoLeft.attach(13); 
servoRight.attach(12); 
}

void loop() {
     if(myReceiver.getResults()) {
      myDecoder.decode();
     if(myDecoder.value==0x22DDA857){
      Serial.println(" up ");     
      servoRight.writeMicroseconds(1500);
      servoLeft.writeMicroseconds(1500);
      delay(2000); 
        }
     if(myDecoder.value==0x22DD28D7){
      Serial.println(" down ");     
      servoRight.writeMicroseconds(0);
      servoLeft.writeMicroseconds(0); 
        }
     if(myDecoder.value==0x22DDC837){
      Serial.println(" right ");
      servoRight.writeMicroseconds(1500);
      servoLeft.writeMicroseconds(0);
      delay(2000); 
        }
     if(myDecoder.value==0x22DD9867){
      Serial.println(" left "); 
      servoRight.writeMicroseconds(0);
      servoLeft.writeMicroseconds(1500);
      delay(2000); 
        }
    myReceiver.enableIRIn(); 
  }
}

