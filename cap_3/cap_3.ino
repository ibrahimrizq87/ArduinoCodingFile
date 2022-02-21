#include <Servo.h>
Servo servo;  
Servo servo2; 
int pos = 0; 
int sensorPin = A0; 
int Val = 0;  

void setup() {
  Serial.begin(9600);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  servo.attach(9);
  servo2.attach(10);  
}

void loop() {
Val = analogRead(sensorPin);  
Serial.println(Val);
delay(100); 
  for (pos = 0; pos <= 180; pos += 1) { 
    if (Val<100){
      
      delay(300000);
      pos=180;
      }
   servo.write(pos);
   servo2.write(pos);             
    delay(15);                      
  }
  for (pos = 180; pos >= 0; pos -= 1) { 
    if (Val<100){
      delay(300000);
      pos=0;
      }
    servo.write(pos);              
    servo2.write(pos);
    delay(15);                       
  }
}

