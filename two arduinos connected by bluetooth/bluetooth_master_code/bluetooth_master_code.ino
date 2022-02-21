  #include <Servo.h>
  #include <LiquidCrystal.h>
  const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
  LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
  int state = 0;
  int potValue = 0;
  Servo servo1;
  Servo servo2; 
  void setup() {
  pinMode(8,OUTPUT);
  Serial.begin(9600); 
  }
  void loop() {
  if(Serial.available() > 0){
  state = Serial.read(); 
  }
  if (state == '1') {
  lcd.begin(16, 2);
  lcd.print("Warning Fire");
  lcd.setCursor(0, 1);
  lcd.print("Starting Reaction");
  digitalWrite(8,HIGH);
  servo1.write(180);
  servo2.write(0);
  state = 0;
  Serial.println("1");
  
  }
  else if (state == '2') {
  lcd.begin(16, 2);
  lcd.print("Warning Fire");
  lcd.setCursor(0, 1);
  lcd.print(" ((Escap)) ");
  digitalWrite(8,HIGH);
  servo2.write(180);
  servo1.write(0);
  state = 0;
  Serial.println("2");
  
  }else{
  lcd.begin(16, 2);
  lcd.print("Normal condition ");
  digitalWrite(8,LOW);
  servo1.write(0);
  servo2.write(0);
  Serial.println("0");
  
  }
  delay(100);
  }
