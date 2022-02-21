#include <Servo.h>
int outPin1 = 6;     //motor1 
int outPin2 = 7;    //motor1 
int outPin4 = 4;   //motor2 
int outPin3 = 12;   //motor2 
char bt = 0;   
int water = 8;      
int pos = 0; 
int pos2= 0; 
int pos3= 0; 
int pos4= 0; 
Servo servo;
Servo servo2;
Servo servo3;
Servo servo4;
void setup() 
{ 
Serial.begin(9600); 
pinMode(outPin1,OUTPUT); 
pinMode(outPin2,OUTPUT); 
pinMode(outPin3,OUTPUT); 
pinMode(outPin4,OUTPUT);
pinMode(water,OUTPUT);
servo.attach(3);
servo2.attach(5);
servo3.attach(9);
servo4.attach(10);
} 
void loop() 
{ 
if (Serial.available() > 0) 
{ 
 bt = Serial.read();   
servo.write(0);
servo2.write(0);
servo3.write(0);
servo4.write(150);
pos = 0; 
pos2= 0; 
pos3= 0; 
pos4= 150; 
 
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
   digitalWrite(outPin4,HIGH); 
 Serial.println("4");
 } 
 else if (bt == '3')     //left 
 { 
   digitalWrite(outPin1,LOW); 
   digitalWrite(outPin2,HIGH); 
   digitalWrite(outPin3,HIGH); 
   digitalWrite(outPin4,LOW); 
 Serial.println("3");
 } 
   
  
   else if (bt == '6')     //left 
 { 
  digitalWrite(water,HIGH);
 
 Serial.println("6");
 } 
   else if (bt == '0')     //left 
 { 
 digitalWrite(water,LOW);
 Serial.println("0");
 }  
  
 else if (bt == '7')     //left 
 { 


for (pos3 = 0; pos3 <= 180; pos3 += 1) { 
    servo3.write(pos3);              
    delay(15);                       
      }
      delay(10);
      
for (pos2 = 0; pos2 <= 180; pos2 += 1) { 
    servo2.write(pos2);              
    delay(15);                       
}
delay(1000);
for (pos2 = 180; pos2 >= 0; pos2 -= 1) {
    servo2.write(pos2);             
    delay(15);                       
  }
for (pos4 = 150 ; pos4 >= 100; pos4 -= 1) { 
    servo4.write(pos4);              
    delay(15);                       
}

for (pos2 = 0; pos2 <= 180; pos2 += 1) { 
    servo2.write(pos2);              
    delay(15);                       
}
delay(1000);
for (pos2 = 180; pos2 >= 0; pos2 -= 1) {
    servo2.write(pos2);             
    delay(15);                       
  }

for (pos4 = 100; pos4 <= 150; pos4 += 1) {
    servo4.write(pos4);             
    delay(15);                       
  }

for (pos3 = 180; pos3 >= 0; pos3 -= 1) {
    servo3.write(pos3);             
    delay(15);                       
  }
    
 Serial.println("7");
 }   
  
  
   else if (bt == '8')     //left 
 { 
   

for (pos3 = 0; pos3 <= 180; pos3 += 1) { 
    servo3.write(pos3);              
    delay(15);                       
      }
      delay(10);
      
for (pos2 = 0; pos2 <= 180; pos2 += 1) { 
    servo2.write(pos2);              
    delay(15);                       
}
delay(1000);
for (pos2 = 180; pos2 >= 0; pos2 -= 1) {
    servo2.write(pos2);             
    delay(15);                       
  }
for (pos4 = 150 ; pos4 >= 20; pos4 -= 1) { 
    servo4.write(pos4);              
    delay(15);                       
}

for (pos2 = 0; pos2 <= 180; pos2 += 1) { 
    servo2.write(pos2);              
    delay(15);                       
}
delay(1000);
for (pos2 = 180; pos2 >= 0; pos2 -= 1) {
    servo2.write(pos2);             
    delay(15);                       
  }

for (pos4 = 20; pos4 <= 150; pos4 += 1) {
    servo4.write(pos4);             
    delay(15);                       
  }

for (pos3 = 180; pos3 >= 0; pos3 -= 1) {
    servo3.write(pos3);             
    delay(15);                       
  }
        
 Serial.println("8");
 } 
  
  
  

 
  
  } 
} 

