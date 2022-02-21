#include <Servo.h>
Servo myservo;
Servo horizontal; 
Servo vertical;
int servoh = 180; 
int servohLimitHigh = 180;
int servohLimitLow = 65;
int servov = 45;  
int servovLimitHigh = 80;
int servovLimitLow = 15;
int ldrlt = A0; 
int ldrrt = A1;  
int ldrld = A2; 
int ldrrd = A3; 
int heat=A4;
int heatval=0; 
int pos = 0;
int sensorPin = A5;  
int Val = 0;
int distanceCm, distanceInch;
const int trigPin = 9;
const int echoPin = 10;
long duration;
boolean x ;
void setup() {
Serial.begin(9600);
  horizontal.attach(11); 
  vertical.attach(6);
  horizontal.write(180);
  vertical.write(45);
  delay(3000);
myservo.attach(5);
pinMode(7,OUTPUT);
pinMode(8,OUTPUT);
pinMode(12,OUTPUT);
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
}

void loop() {
  x==LOW  ; 
    myservo.write(180);
    
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    distanceCm= duration*0.034/2;
    distanceInch = duration*0.0133/2;
    Serial.println("Distance: "); 
    Serial.println(distanceCm); 
    Serial.println(" cm");
    delay(10);
    Serial.println("Distance: ");
    Serial.println(distanceInch);
    Serial.println(" inch");
    delay(1000);
    if( distanceCm>=10&&distanceCm<=15){
    x==HIGH;
    }

Val = analogRead(sensorPin); 
Serial.println(Val);  
if(700<=Val&&Val<=1200&&x==HIGH){
  digitalWrite(7,HIGH); 
  }else{
    digitalWrite(7,LOW);
    }

if(600<=Val&&Val<=700&&x==HIGH){
  digitalWrite(8,HIGH); 
  }else{
    digitalWrite(8,LOW);
    }

if ( 400<=Val && Val<=500 &&x==HIGH )
{
  digitalWrite(12,HIGH); 
  }
  else
  {
    digitalWrite(12,LOW);
    }
    int heatval = analogRead(heat); 
    Serial.println(heatval);
    if (heatval>=21 && heatval<=25){
      digitalWrite(4,HIGH) ;
      }else{
        digitalWrite(4,LOW);
        }
    if (heatval>=25 && heatval<=30){
      digitalWrite(3,HIGH) ;
      }else{
        digitalWrite(3,LOW);
        }
    if (heatval>=30 && heatval<=35){
      digitalWrite(2,HIGH) ;
      }else{
        digitalWrite(2,LOW);
        }
    delay(15);
  int lt = analogRead(ldrlt); 
  int rt = analogRead(ldrrt); 
  int ld = analogRead(ldrld); 
  int rd = analogRead(ldrrd); 
  int dtime = 10;
  int tol = 50;
  
  int avt = (lt + rt) / 2; 
  int avd = (ld + rd) / 2; 
  int avl = (lt + ld) / 2; 
  int avr = (rt + rd) / 2; 

  int dvert = avt - avd; 
  int dhoriz = avl - avr;
  
  
    
  if (-1*tol > dvert || dvert > tol) 
  {
  if (avt > avd)
  {
    servov = ++servov;
     if (servov > servovLimitHigh) 
     { 
      servov = servovLimitHigh;
     }
  }
  else if (avt < avd)
  {
    servov= --servov;
    if (servov < servovLimitLow)
  {
    servov = servovLimitLow;
  }
  }
  vertical.write(servov);
  }
  
  if (-1*tol > dhoriz || dhoriz > tol) 
  {
  if (avl > avr)
  {
    servoh = --servoh;
    if (servoh < servohLimitLow)
    {
    servoh = servohLimitLow;
    }
  }
  else if (avl < avr)
  {
    servoh = ++servoh;
     if (servoh > servohLimitHigh)
     {
     servoh = servohLimitHigh;
     }
  }
  else if (avl = avr)
  {
    // nothing
  }
  horizontal.write(servoh);
  }
   delay(dtime);

}

