#include <Servo.h>
int outPin1 = 5;     //motor1 
int outPin2 = 6;    //motor1 
int outPin3 = 11;   //motor2 
int outPin4 = 12;   //motor2 
char bt = 0; 
void setup() 
{ 
Serial.begin(9600); 
pinMode(outPin1,OUTPUT); 
pinMode(outPin2,OUTPUT); 
pinMode(outPin3,OUTPUT); 
pinMode(outPin4,OUTPUT);

} 
void loop() 
{ 
if (Serial.available() > 0) 
{ 
 bt = Serial.read();  
 
 if(bt == '1')        //move forwards 
 { 
   digitalWrite(outPin1,HIGH); 
   digitalWrite(outPin2,LOW); 
   digitalWrite(outPin3,HIGH); 
   digitalWrite(outPin4,LOW); 
 Serial.println("1");
 } 
 else if (bt == '2')       //move backwards 
 { 
   digitalWrite(outPin1,LOW); 
   digitalWrite(outPin2,HIGH); 
   digitalWrite(outPin3,LOW); 
   digitalWrite(outPin4,HIGH); 
 Serial.println("2");
 } 
 else if (bt == '5')     //stop!! 
 {    
   digitalWrite(outPin1,LOW); 
   digitalWrite(outPin2,LOW); 
   digitalWrite(outPin3,LOW); 
   digitalWrite(outPin4,LOW); 
 
Serial.println("0");
} 
 else if (bt == '4')    //right 
 { 
   digitalWrite(outPin1,HIGH); 
   digitalWrite(outPin2,LOW); 
   digitalWrite(outPin3,LOW); 
   digitalWrite(outPin4,LOW); 
 Serial.println("4");
 } 
 else if (bt == '3')     //left 
 { 
   digitalWrite(outPin1,LOW); 
   digitalWrite(outPin2,LOW); 
   digitalWrite(outPin3,HIGH); 
   digitalWrite(outPin4,LOW); 
 Serial.println("3");
 } 
   
}
}
