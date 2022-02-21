#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2); 
void setup() {
lcd.init(); 
lcd.backlight();

}
void loop() 
{
lcd.print("ARDUINO PROJECTS");

delay(1500);
lcd.setCursor(6, 1);
lcd.print("SUBSCRIBE ");
delay(1500);
lcd.clear();
}
