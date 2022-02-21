
#include <Servo.h>
    const int trigPin = 9;
    const int echoPin = 10;
    long duration;
    int distanceCm, distanceInch;
    Servo myservo;
    Servo servo;
    void setup() {
    Serial.begin(9600); 
    myservo.attach(6);
   servo.attach(5);
   
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
      pinMode(7, INPUT);
    
    }
    void loop() {
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    distanceCm= duration*0.034/2;
     Serial.print(distanceCm);
     if (distanceCm <= 15 ){
     myservo.write(0); 
     servo.write(0);
      delay(1000);
      }else{
        servo.write(90);
        myservo.write(90); 
      delay(1000);
     }
    }
