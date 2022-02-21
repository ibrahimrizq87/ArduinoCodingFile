#include <Stepper.h>
const int stepsPerRevolution = 200;
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);
int stepCount = 0;
int pot1 = A0;
int valPot1;
int valPot2;
int relay1 = 2;
int relay2 = 3;
int relay3 = 4;
int relay4 = 5;
int Val=0;
int No= 20 ;
String readString;
void setup() {
  Serial.begin(9600);
  pinMode(relay1, OUTPUT); 
  pinMode(relay2, OUTPUT); 
  pinMode(relay3, OUTPUT); 
  pinMode(relay4, OUTPUT); 
  pinMode(7,INPUT);
  pinMode(6,INPUT);
  }

void loop() {
  int sensorReading = analogRead(A0);
  int motorSpeed = map(sensorReading, 0, 1023, 0, 100);
  if (motorSpeed > 0) {
    myStepper.setSpeed(motorSpeed);
    myStepper.step(stepsPerRevolution / 100);
  }
  digitalWrite(relay3,LOW); 
  digitalWrite(relay4, HIGH);
  while (Serial.available()) {
    delay(3);  
    char c = Serial.read();
    readString += c; 
if (readString.length() >0) {
    Serial.println(readString);
    if (readString == "1 ON" )     
    {
      digitalWrite(relay1, HIGH);
    }
    if (readString == "1 OFF")
    {
      digitalWrite(relay1, LOW);
    }
    if (readString == "2 ON")     
    {
      digitalWrite(relay2, HIGH);
    }
    if (readString == "2 OFF")
    {
      digitalWrite(relay2, LOW);
    }    
    if (readString == "3 ON" )     
    {
      digitalWrite(relay3, HIGH);
    }
    if (readString == "3 OFF" )
    {
      digitalWrite(relay3, LOW);
    }    
    if (readString == "4 ON")     
    {
      digitalWrite(relay4, HIGH);
       }
    if (readString == "4 OFF")
    {
      digitalWrite(relay4, LOW);
    }
     readString="";
  } 

  }
   for (No = 20; No >= 0; No += 1) { 
    digitalWrite(relay1, HIGH);
    digitalWrite(relay2, HIGH);
    if(digitalRead(6)== HIGH){
    digitalWrite(relay1, LOW);
    digitalWrite(relay2, LOW);      
      delay(1000);
      }else{
    digitalWrite(relay1, HIGH);
    digitalWrite(relay2, HIGH);
    }
    delay(5000);                      
    digitalWrite(relay1, LOW);
    digitalWrite(relay2, LOW);
    Val = digitalRead(7);
if(Val==0)
{
  digitalWrite(relay3,LOW);
}
else
{
  digitalWrite(relay3,HIGH);
}
  delay(10000);
}
digitalWrite(relay1, HIGH);
digitalWrite(relay2, LOW); 
delay(1000);
digitalWrite(relay1, HIGH);
digitalWrite(relay2, HIGH);
delay(1000);
digitalWrite(relay1, HIGH);
digitalWrite(relay2, LOW);
delay(1000);
}
