#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int conductivity1 = 0; // agreculture

int conductivity2 = 0; // drink water

int conductivity3 = 0; // industrial 

void setup()
{
  lcd.begin(16, 2);                         
pinMode(8,OUTPUT);
pinMode(9,OUTPUT);
pinMode(10,OUTPUT);
}
 
void loop()                     
{
  // ------------------------------------------------------------------------
 lcd.begin(16, 2);
  
  lcd.print("Starting ");
lcd.setCursor(0, 1);

lcd.print("Prediction 1.....");
delay (5000);
 lcd.begin(16, 2);
  
  lcd.print("Conductivity is  ");
lcd.setCursor(0, 1);

lcd.print(conductivity1);

delay(7000);
 
 digitalWrite(8,HIGH);
 
 lcd.begin(16, 2);
  
  lcd.print("Suction to --->  ");
lcd.setCursor(0, 1);

lcd.print("agricalture");

 delay (35000);
 
 digitalWrite(8,LOW);
 
  // ------------------------------------------------------------------------
  
 lcd.begin(16, 2);
  
  lcd.print("Starting ");
lcd.setCursor(0, 1);

lcd.print("Prediction2 .....");
delay (5000);
 lcd.begin(16, 2);
  
  lcd.print("Conductivity is  ");
lcd.setCursor(0, 1);

lcd.print(conductivity2);

delay(7000);
 
 digitalWrite(9,HIGH);
 
 lcd.begin(16, 2);
  
  lcd.print("Suction to --->  ");
lcd.setCursor(0, 1);

lcd.print("Industrial ");

 delay (35000);
 
 digitalWrite(9,LOW);

  // ------------------------------------------------------------------------
  
 lcd.begin(16, 2);
  
  lcd.print("Starting ");
lcd.setCursor(0, 1);

lcd.print("Prediction3 .....");
delay (5000);
 lcd.begin(16, 2);
  
  lcd.print("Conductivity is  ");
lcd.setCursor(0, 1);

lcd.print(conductivity3);

delay(7000);
 
 digitalWrite(10,HIGH);
 
 lcd.begin(16, 2);
  
  lcd.print("Suction to --->  ");
lcd.setCursor(0, 1);

lcd.print("drinking water");

  // ------------------------------------------------------------------------
 delay (35000);
 
 digitalWrite(10,LOW);
}
