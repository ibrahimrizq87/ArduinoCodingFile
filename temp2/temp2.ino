 #include <LiquidCrystal.h>

 int sensorPin = A0; //the analog pin the TMP36's Vout (sense) pin is connected to
 int x=0;
 int y=0;
 const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

 void setup()
 {
 Serial.begin(9600); 
lcd.begin(16, 2);
 lcd.print(" degrees F");
 lcd.print(" degrees C");
 
 }
 void loop() 
 {
 lcd.setCursor(0, 1);
 int reading = analogRead(sensorPin);
 
 float voltage = reading * 5.0;
 voltage /= 1024.0;
 Serial.print(voltage); Serial.println(" volts");

 
 float temperatureC = (voltage - 0.5) * -100 ; 
 Serial.print(temperatureC); 
 Serial.println(" degrees C");
lcd.print(temperatureC);
 // now convert to Fahrenheit
 float temperatureF = (temperatureC * 9.0 / 5.0) + 32.0;
 Serial.print(temperatureF); Serial.println(" degrees F");
 lcd.print(temperatureF);

x= temperatureC;
 if( x >= y){
  Serial.print(" warning ");
  }
 y = temperatureC += 10;
 delay(1000); //waiting a second

 
 
 }
