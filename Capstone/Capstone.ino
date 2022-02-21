#include <Servo.h>

const int LDRpin = A0;
const int Servo1pin = 9;
const int Servo2pin = 10;
const int Servo3pin = 11;
const int DelayTime = 25;
const int DelayTimeBack = 50;

int LDR_S;
int Sun;
int Mirror = 93 ;

Servo servo1;
Servo servo2;
Servo servo3;

void setup() {

servo1.attach(Servo1pin);
servo2.attach(Servo2pin);
servo3.attach(Servo3pin);


pinMode(Servo1pin, OUTPUT);
pinMode(Servo2pin, OUTPUT);
pinMode(Servo3pin, OUTPUT);
pinMode(LDRpin , INPUT);

Serial.begin(9600);
}

void loop() {

 LDR_S = analogRead(LDRpin);
Serial.print(LDR_S);
Serial.println(" ");
delay (100);

 if ( 0 < LDR_S < 20){
 for (Sun = 0 ; Sun <= 180 ; Sun +=1){
 servo1.write(Sun);
 delay(DelayTime);
  if(Sun == 90 ) { servo3.write(180); }
  if(Sun == 180) { servo3.write(0); }  
  delay(DelayTime);
 }
  }
   }
  
  //=================//
  }
  
  //=================//
  
  if (Sun = Sun + 1){ Mirror +=1 ;}
  if (Sun = Sun + 2){ Mirror +=1 ;}
  servo2.write(Mirror);
  delay(DelayTime);
  
  //===========//
    servo2.write(0);
    delay(DelayTimeBack); 
}
