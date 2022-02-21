#include <Wire.h>

#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2); 

void setup() {
  
lcd.init(); 

lcd.backlight();

 pinMode(2,OUTPUT);
 pinMode(3,OUTPUT);
 pinMode(4,OUTPUT);
 pinMode(5,OUTPUT);
 pinMode(7,INPUT);
 
 }

void loop()
{
  lcd.print("LG Technology");
  lcd.setCursor(0, 0);

for(int x = 0 ; x <=100 ; x++)
{
lcd.setCursor(0, 1);
lcd.print("Scrub Motion ");
  scrubMotion();
  if(digitalRead(7)== LOW)
  {
  break;
  }
  }
  delay(800);
for(int x = 0 ; x <=100 ; x++){
  lcd.setCursor(0, 1);
lcd.print("Stepping Motion ");
  steppingMotion();
  if(digitalRead(7)== LOW)
  {
  break;
  }
  }
  delay(800);
  for(int x = 0 ; x <=100 ; x++){
    lcd.setCursor(0, 1);
lcd.print("Tumble Motion ");
  TumbleMotion();
  if(digitalRead(7)== LOW)
  {
  break;
  }
  }
  delay(800);
  for(int x = 0 ; x <=1000 ; x++){
  lcd.setCursor(0, 1);
lcd.print("Filtration ");
  Filtration();
  if(digitalRead(7)== LOW)
  {
  break;
  }
  }
  delay(800);
  for(int x =0 ; x <=100 ; x++){
    lcd.setCursor(0, 1);
lcd.print("Swing Motion ");
  SwingMotion();
  if(digitalRead(7)== LOW)
  {
  break;
  }
  }
  delay(800);
  for(int x = 0 ; x<=100 ; x++){
   lcd.setCursor(0, 1);
lcd.print("Roling Motion ");
  RolingMotion();
  if(digitalRead(7)== LOW)
  {
  break;
  }
  }  
delay(800);
}
void scrubMotion(){

digitalWrite(2,HIGH); 

digitalWrite(3,LOW);

digitalWrite(4,HIGH);

digitalWrite(5,LOW);

delay(500);


digitalWrite(2,LOW); 

digitalWrite(3,LOW);

digitalWrite(4,LOW);

digitalWrite(5,LOW);

delay(100);

digitalWrite(2,LOW); 

digitalWrite(3,HIGH);

digitalWrite(4,LOW);

digitalWrite(5,HIGH);

delay(500);

}


void steppingMotion(){

digitalWrite(2,HIGH); 

digitalWrite(3,LOW);

digitalWrite(4,HIGH);

digitalWrite(5,LOW);

delay(500);

digitalWrite(2,LOW); 

digitalWrite(3,LOW);

digitalWrite(4,LOW);

digitalWrite(5,LOW);

delay(500);

}

void TumbleMotion(){
  
digitalWrite(2,LOW); 

digitalWrite(3,HIGH);

digitalWrite(4,LOW);

digitalWrite(5,HIGH);

delay(100);

digitalWrite(2,LOW); 

digitalWrite(3,LOW);

digitalWrite(4,LOW);

digitalWrite(5,LOW);

delay(100);

}


void Filtration(){
  
digitalWrite(2,HIGH); 

digitalWrite(3,LOW);

digitalWrite(4,HIGH);

digitalWrite(5,LOW);

}

void SwingMotion(){
  
digitalWrite(2,HIGH); 

digitalWrite(3,LOW);

digitalWrite(4,HIGH);

digitalWrite(5,LOW);

delay(300);

digitalWrite(2,LOW); 

digitalWrite(3,LOW);

digitalWrite(4,LOW);

digitalWrite(5,LOW);

delay(300);

digitalWrite(2,LOW); 

digitalWrite(3,HIGH);

digitalWrite(4,LOW);

digitalWrite(5,HIGH);

delay(300);

}

void RolingMotion(){
  

digitalWrite(2,HIGH); 

digitalWrite(3,LOW);

digitalWrite(4,HIGH);

digitalWrite(5,LOW);

delay(300);

digitalWrite(2,LOW); 

digitalWrite(3,LOW);

digitalWrite(4,LOW);

digitalWrite(5,LOW);

delay(300);

}
