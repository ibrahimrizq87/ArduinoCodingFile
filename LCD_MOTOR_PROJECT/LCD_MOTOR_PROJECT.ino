#include <Servo.h>

Servo servo1; 

Servo servo2;

Servo servo3;

int pos = 0;

void setup() {

  servo1.attach(3); 

  servo2.attach(10); 
    
  servo3.attach(9); 
}

void loop() {
  
    for(int x = 0 ; x<=100 ; x++){
  motion1();
  if(digitalRead(7)== LOW)
  {
  break;
  }
  }  
delay(800);
for(int x = 0 ; x<=100 ; x++){
  motion2();
  if(digitalRead(7)== LOW)
  {
  break;
  }
  }  
delay(800);
for(int x = 0 ; x<=100 ; x++){
  motion3();
  if(digitalRead(7)== LOW)
  {
  break;
  }
  }  
delay(800);
for(int x = 0 ; x<=100 ; x++){
  motion4();
  if(digitalRead(7)== LOW)
  {
  break;
  }
  }  
delay(800);
for(int x = 0 ; x<=100 ; x++){
  motion5();
  if(digitalRead(7)== LOW)
  {
  break;
  }
  }  
delay(800);
for(int x = 0 ; x<=100 ; x++){
  motion6();
  if(digitalRead(7)== LOW)
  {
  break;
  }
  }  
delay(800);

}
void motion1(){
  
  for (pos = 60; pos <= 120; pos += 1) { 
    
    servo1.write(pos);
    servo2.write(pos); 

    delay(5); 
 }
  for (pos = 120; pos >= 60; pos -= 1) {
    servo1.write(pos);
    servo2.write(pos); 
    delay(5);                       
  }
  
  }
  
void motion2(){
  
  for (pos = 60; pos <= 120; pos += 1) { 
    
    servo1.write(pos);
    servo2.write(pos); 

    delay(10); 
 }
  for (pos = 120; pos >= 60; pos -= 1) {
    servo1.write(pos);
    servo2.write(pos); 
    delay(10);                       
  }
  }

void motion3(){
  
  for (pos = 60; pos <= 120; pos += 1) { 
    
    servo1.write(pos);
    servo2.write(pos); 

    delay(15); 
 }
  for (pos = 120; pos >= 60; pos -= 1) {
    servo1.write(pos);
    servo2.write(pos); 
    delay(15);                       
  }
  }


void motion4(){
   servo3.write(60); 
  for (pos = 60; pos <= 120; pos += 1) { 
    
    servo1.write(pos);
    servo2.write(pos); 
    
    delay(20); 
 }
  servo3.write(120);
  for (pos = 120; pos >= 60; pos -= 1) {
    servo1.write(pos);
    servo2.write(pos);
   
    delay(20);                       
  }
 
    
  }

void motion5(){
  
  for (pos = 60; pos <= 120; pos += 3) { 
    
    servo1.write(pos);
    servo2.write(pos); 
    servo3.write(pos);
    delay(20); 
 }
  for (pos = 120; pos >= 60; pos -= 3) {
    servo1.write(pos);
    servo2.write(pos);
    servo3.write(pos); 
    delay(20);                       
  }
  }
  
void motion6(){
  
  for (pos = 60; pos <= 120; pos += 3) { 
    
    servo1.write(pos);
    servo2.write(pos); 
    servo3.write(pos);
    delay(30); 
 }
  for (pos = 120; pos >= 60; pos -= 3) {
    servo1.write(pos);
    servo2.write(pos);
    delay(30);                       
  }
  }
