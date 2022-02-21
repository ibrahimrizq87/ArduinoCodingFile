#include <Servo.h>
Servo servo1;
Servo servo2;
Servo servo3;
int pos = 0;
int smokeA0 = A5;
int sensorThres = 400;
int S0 = 4;
int S1 = 5;
int S2 = 6;
int S3 = 7;
int sensorOut = 8;
int frequency = 0;
void setup() {
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);
  digitalWrite(S0,HIGH);
  digitalWrite(S1,LOW);
  pinMode(smokeA0, INPUT);
  servo1.attach(9);  
  servo2.attach(11);
  servo3.attach(3);  
  Serial.begin(9600);
}
void loop() {
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  frequency = pulseIn(sensorOut, LOW);
  frequency = map(frequency, 25,150,255,0); 
  Serial.print("G= ");//printing name
  Serial.print(frequency);//printing RED color frequency
  Serial.print("  ");
  delay(100);
   int analogSensor = analogRead(smokeA0); 
  if (frequency >=0){
   Serial.println("green");
  for (pos = 0; pos <= 180; pos += 1) {
  servo1.write(pos);              
  
  if (frequency >=100){
  
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  frequency = pulseIn(sensorOut, LOW);
  frequency = map(frequency, 35,270,255,0);
  if (frequency >=100){
  Serial.println("red"); 
   } 
 servo2.write(180);
 delay(1000);
 servo2.write(0);
 int analogSensor = analogRead(smokeA0);
 if (analogSensor >= sensorThres){
  servo3.write(0);
 delay(1000);
  servo2.write(180);
  }
  else{
    servo3.write(50);
    delay(1000);
    servo2.write(180); 
    }
  delay(1000);
 servo2.write(0);   
 servo3.write(100);
 }
  delay(10);
   }
for (pos = 180; pos >= 0; pos -= 1) {
  servo1.write(pos);              
  int analogSensor = analogRead(smokeA0);
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  frequency = pulseIn(sensorOut, LOW);
  frequency = map(frequency, 35,270,255,0);
  if (frequency >=100){
  Serial.println("red"); 
  servo2.write(180);
  delay(1000);
  servo2.write(0);
 int analogSensor = analogRead(smokeA0);
 if (analogSensor >= sensorThres){
  delay(100);
  servo3.write(0);
 delay(1000);
  servo2.write(180);
  }
  else{
    servo3.write(50);
    delay(1000);
    servo2.write(180);   
    }
    delay(1000);
    servo2.write(0);
    servo3.write(100); 
   }
    delay(15);
  }
  }  } 
