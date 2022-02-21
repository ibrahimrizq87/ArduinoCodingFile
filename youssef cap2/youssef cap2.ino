#include <Servo.h>
Servo servo;
Servo servo2;
int pos = 0;
int pos2 = 0;
int pos3 = 0;
int state=0;
void setup() {
  servo.attach(9);
  servo2.attach(10);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  Serial.begin(9600); 
}
void loop() {
 if(Serial.available() > 0){ 
    state = Serial.read(); 
 }
 if (state == '2') {
  digitalWrite(8, HIGH);
Serial.println("2");
  servo2.write(0);
  servo.write(180);
delay(100);
}
if (state == '1')
{
   digitalWrite(8, LOW);
Serial.println("1");
 servo.write(0);
 servo2.write(180);
delay(100);
  }
  
 if (state == '0') {
Serial.println("0");
   servo.write(0);
   servo2.write(0);
   delay(100);
 }
   
}

