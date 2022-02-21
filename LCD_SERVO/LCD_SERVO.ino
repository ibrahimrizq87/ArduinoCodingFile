#include <LiquidCrystal.h>
#include <Servo.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
Servo myservo; 
int pos = 0;   
void setup() {
   myservo.attach(6);
  lcd.begin(16, 2);
  pinMode(8,OUTPUT);
  lcd.print("FARM WITHOUT");
}

void loop() {
  lcd.setCursor(0, 1);
 lcd.print("      ARM");
  for (pos = 30; pos <= 90; pos += 1) {
    myservo.write(pos);              
    delay(15);                       
  }
  for (pos = 90; pos >= 30; pos -= 1) { 
    myservo.write(pos);              
    delay(15);                       
  }
  }
