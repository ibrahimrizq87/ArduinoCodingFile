#include <Servo.h>

int trigPin = 9;

int echoPin = 10; 

Servo myservo;

int pos = 0;

void setup() {

   Serial.begin(9600);

   pinMode(5, OUTPUT);
   
   pinMode(2, INPUT);
   
   pinMode(6, OUTPUT);
   
   pinMode(4, OUTPUT);
   
   pinMode(7, OUTPUT);
   
   pinMode(trigPin, OUTPUT);
   
   pinMode(echoPin, INPUT);
  
myservo.attach(3);
}

void loop() {
   
  
  long duration, distance;
  
  digitalWrite(trigPin,HIGH);
  
  delayMicroseconds(1000);
  
  digitalWrite(trigPin, LOW);
  
  duration=pulseIn(echoPin, HIGH);
  
  distance =(duration/2)/29.1;


  

Serial.println(distance);

  if((distance>30))
 {
   myservo.write(80);  
   digitalWrite(5,LOW);                              
   digitalWrite(4,HIGH);                               
   digitalWrite(6,LOW);                               
   digitalWrite(7,HIGH);
Serial.println("moving forward");

     delay(200);

   }else if (distance <30 ){
         
   
  
   digitalWrite(4,LOW); 

   digitalWrite(5,LOW); 
   
   digitalWrite(6,LOW); 
   
   digitalWrite(7,LOW); 
   myservo.write(180);       
   
  
delay (1000);
 
 digitalWrite(4,LOW); 
   
   digitalWrite(5,HIGH); 
   
   digitalWrite(6,LOW); 
   
   digitalWrite(7,HIGH); 

delay(200);

Serial.println("moving backward");
}
if  (digitalRead(2)== LOW){
     
  
   digitalWrite(4,LOW); 

   digitalWrite(5,LOW); 
   
   digitalWrite(6,LOW); 
   
   digitalWrite(7,LOW); 
   myservo.write(180);       
   
  
delay (1000);
 
 digitalWrite(4,LOW); 
   
   digitalWrite(5,HIGH); 
   
   digitalWrite(6,LOW); 
   
   digitalWrite(7,HIGH); 

delay(200);

Serial.println("moving backward");
}

}
