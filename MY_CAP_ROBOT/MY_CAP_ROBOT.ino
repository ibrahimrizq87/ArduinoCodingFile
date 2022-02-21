#include <Servo.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
#define S0 4
#define S1 5
#define S2 6
#define S3 7
#define sensorOut 8
int frequency = 0;
int val=0;
int val2=0;
int val3=0;
int val4=0;
int x =0;
int outPin1 = 11;      
int outPin2 = 12;    
char bt=0;
Servo myservo;
void setup() {
  lcd.begin(16, 2); 
  myservo.attach(9);
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);
  
  // Setting frequency-scaling to 20%
  digitalWrite(S0,HIGH);
  digitalWrite(S1,LOW);
  
  Serial.begin(9600);
}
void loop() 
{
if (Serial.available() > 0) 
{ 
 bt = Serial.read();   
 
 
 if(bt == '1')        
 { 
  for (x = 0; x <= 200; x += 1) {
    val=analogRead(A0);
lcd.print("INTENSTY OF LIGHT");
lcd.setCursor(0, 0);
lcd.setCursor(6, 1);
lcd.print(val);
delay(10);
    
    
    }
 lcd.clear();
 } 
 else if (bt == '2')        
 { 
 for (x = 0; x <= 200; x += 1) {
    val2=analogRead(A1);
lcd.print("THE TEMPERUTUER ");
lcd.setCursor(0, 0);
lcd.setCursor(6, 1);
lcd.print(val2);

delay(10);
    }
lcd.clear();
 } 

 else if (bt == '3')        
 { 
 for (x = 0; x <= 200; x += 1) {
val3=analogRead(A2);
  myservo.write(30); 
lcd.print("SOIL MOISTUER ");
lcd.setCursor(0, 0);
lcd.setCursor(6, 1);
lcd.print(val3);
delay(10);
    }
  myservo.write(180);  
lcd.clear();
 } 
 else if (bt == '4')        
 { 
 for (x = 0; x <= 200; x += 1) {
    val4=analogRead(A3);
lcd.print("METHANE GAS ");
lcd.setCursor(0, 0);
lcd.setCursor(6, 1);
lcd.print(val4);

delay(10);
    }
lcd.clear();
 } 
 else if (bt == '0')        
 { 
 if (digitalRead(2)== LOW){
lcd.print("PLANT IN FRONT ");
lcd.setCursor(0, 0);
lcd.setCursor(6, 1);
lcd.print(" OF THE ROBOT ");
delay(1000);
lcd.clear();
lcd.print(" TAKE DATA ");
 delay(1000);
lcd.clear();
 }else{
  lcd.print("NO PLANTS IN FRONT ");
lcd.setCursor(0, 0);
lcd.setCursor(6, 1);
lcd.print(" OF THE ROBOT ");
delay(1000);
lcd.clear();
 lcd.print("DO NOT TAKE DATA ");
 delay(1000);
lcd.clear();
}
 } 

else if (bt == '5')        
 { 
 if (digitalRead(3)== LOW){
  lcd.print("WORNING");
lcd.setCursor(0, 0);
lcd.setCursor(6, 1);
lcd.print(" HEAVY RAIN ");
 delay(1500);
 lcd.clear();
 }else{
    lcd.print(" CLEAR ");
lcd.setCursor(0, 0);
lcd.setCursor(6, 1);
lcd.print(" NO RAIN ");
delay(1500);
lcd.clear();
  }
 }

else if (bt == '6')        
 { 
  for (x = 0; x <= 30; x += 1) {
   if (x<=10){
    digitalWrite(outPin1,HIGH);
    digitalWrite(outPin2, LOW);
    }else{
     digitalWrite(outPin1,LOW);
    digitalWrite(outPin2, HIGH);
    }

  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  frequency = pulseIn(sensorOut, LOW);
  lcd.print("R= ");
  lcd.print(frequency);
  lcd.setCursor(0, 0);
  delay(100);
  
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  frequency = pulseIn(sensorOut, LOW);
lcd.setCursor(6, 1);
lcd.print("G= ");
lcd.print(frequency);
 
  delay(100); 
   
 }
 lcd.clear();
 }
    digitalWrite(outPin1,HIGH);
    digitalWrite(outPin2, LOW);
    delay(1000);
    digitalWrite(outPin1,LOW);
    digitalWrite(outPin2, LOW);
}

}


