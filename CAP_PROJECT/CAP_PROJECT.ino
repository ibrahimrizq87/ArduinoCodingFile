
#include <Servo.h>

Servo myservo;
int pump_led = 2;
int pump = 6;
int motor_led = 3;
int box_led = 4;
int buzzer = 5;
int i = 0;
void setup() {
  
Serial.begin(9600);
myservo.attach(9);
pinMode(2,OUTPUT);
pinMode(3,OUTPUT);
pinMode(4,OUTPUT);
pinMode(5,OUTPUT);
pinMode(6,OUTPUT);

}

void loop() {
  

i ++;
if (i >= 5 ){
  Serial.println(" _________ worning there the box is full ___________ ");
  digitalWrite(motor_led,LOW);
  myservo.write(90);
  digitalWrite(pump,HIGH);
  digitalWrite(pump_led,LOW);
  digitalWrite(box_led,HIGH);
  digitalWrite(buzzer,HIGH);
i  =  0 ;  
delay(10000);
  }else{
    opration();
    }

}

void opration(){
  digitalWrite(box_led,LOW);
digitalWrite(buzzer,LOW);
  digitalWrite(pump,LOW);
  digitalWrite(pump_led,HIGH);
  Serial.println(" _________ Suction System ___________ ");
  digitalWrite(motor_led,LOW);
  myservo.write(90);
  delay (4000);
  Serial.println(" _________ Motor System ___________ ");
  digitalWrite(pump,HIGH);
  digitalWrite(pump_led,LOW);
  digitalWrite(motor_led,HIGH);
  myservo.write(180);
    
  delay (4000);

  }
