
// include the library code:
#include <LiquidCrystal.h>
#include <Servo.h>
Servo myservo;
int sensorPin = A0;  
int sensorPin1 = A1;
int sensorPin2 = A2;
int sensorPin3 = A3;
int Val = 0;
int Val1 = 0;
int Val2 = 0;
int Val3 = 0;
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int x=0;
char bt = 0;
void setup() {
  myservo.attach(9);
  myservo.write(0);  
 pinMode(8,OUTPUT);
  
  Serial.begin(9600);
  }

void loop() {
   if (Serial.available() > 0) 
{ 
 bt = Serial.read();
if(bt == '1')       
 { 
 
  lcd.begin(16, 2);
  lcd.print("methane sensor");
    for (x = 0; x <= 50; x += 1) {          
   lcd.setCursor(0, 1);
  Val = analogRead(sensorPin); 
lcd.print(Val);
delay(100);
}
 lcd.begin(16, 2);
  lcd.print("temperature sensor");

for (x = 50; x >= 0; x-= 1) { 
  lcd.setCursor(0, 1);
  Val1 = analogRead(sensorPin1); 
float voltage = Val1 * 5.0;
voltage /= 1024.0; 
float temperatureC = (voltage - 0.5) * -100 ; 
lcd.print(temperatureC +25); lcd.println(" degrees C ");
lcd.print(Val1);
delay(100);
}
   lcd.begin(16, 2);
  lcd.print("intnsity of light ");

for (x = 0; x <=50; x += 1) {          
  
  lcd.setCursor(0, 1);
  Val2 = analogRead(sensorPin2); 
lcd.print(Val2);
delay(100);
}
myservo.write(80);
   digitalWrite(8,HIGH);
   lcd.begin(16, 2);
  lcd.print("soil moisture ");
for (x = 50; x >= 0; x -= 1) { 
 
  lcd.setCursor(0, 1);
  Val3 = analogRead(sensorPin3); 
lcd.print(Val3);
delay(100);
}
myservo.write(0);
digitalWrite(8,LOW);
 } 

}
delay(100);
}
