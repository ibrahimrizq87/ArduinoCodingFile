

#include <Servo.h>
int sensorPin = A0;  
int Val1 = 0;
int sensorPin1 = A1;  
int Val2 = 0;
int sensorPin2 = A2;  
int Val3 = 0;
Servo servo;  // create servo object to control a servo
Servo servo1;// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

void setup() {
servo.attach(10);  // attaches the servo on pin 9 to the servo object
servo1.attach(9);
Serial.begin(9600);
}

void loop() {
Val1 = analogRead(sensorPin); 
Serial.println("Val1");
Serial.println(Val1);
Val2 = analogRead(sensorPin1); 
Serial.println("Val2");
Serial.println(Val2);
Val3 = analogRead(sensorPin2); 
Serial.println("Val3");
Serial.println(Val3);
  if( Val1 >= 30 ){
    servo1.write (30);
    }else{
    servo1.write (0);
    }
if( Val2 >= 30 ){
    servo1.write (90);
    }else{
    servo1.write (0);
    }
    if( Val3 >= 30 ){
    servo1.write (120);
    }else{
    servo1.write (0);
    }
delay(1000);
}
