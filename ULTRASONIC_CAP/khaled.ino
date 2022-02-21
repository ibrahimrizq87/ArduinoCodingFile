#include <Servo.h>
Servo myservo;
int pos = 0;
int sensorPin = A0;  
int Val = 0;
int distanceCm, distanceInch;
const int trigPin = 9;
const int echoPin = 10;
long duration;

boolean x ;
void setup() {
Serial.begin(9600);
myservo.attach(5);
pinMode(7,OUTPUT);
pinMode(8,OUTPUT);
pinMode(11,OUTPUT);
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);

}

void loop() {
digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    distanceCm= duration*0.034/2;
    distanceInch = duration*0.0133/2;
    Serial.println("Distance: "); // Prints string "Distance" on the LCD
    Serial.println(distanceCm); // Prints the distance value from the sensor
    Serial.println(" cm");
    delay(10);
    Serial.println("Distance: ");
    Serial.println(distanceInch);
    Serial.println(" inch");
    delay(15);
    digitalWrite(x,LOW);  
  if( &&distanceCm>=15&&distanceCm<=20){
    digitalWrite(x,HIGH);
    }else{
digitalWrite(x,LOW);
      }
  for (pos = 0; pos <= 180; pos += 1) { 
    myservo.write(pos);              
    delay(15);                       
  }
  for (pos = 180; pos >= 0; pos -= 1) { 
    myservo.write(pos);              
    delay(15);                       
  }

Val = analogRead(sensorPin); 
Serial.println(Val);  
if(700<=Val&&Val<=1200&&x=HIGH){
  digitalWrite(8,HIGH); 
  }else{
    digitalWrite(8,LOW);
    }

if(600<=Val&&Val<=700&&x=HIGH){
  digitalWrite(9,HIGH); 
  }else{
    digitalWrite(9,LOW);
    }

if( 400<=Val && Val<=500 &&x=HIGH )
{
  digitalWrite(11,HIGH); 
  }
  else
  {
    digitalWrite(11,LOW);
    }
    delay(100);
}

