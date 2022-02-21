// Make a lcd screen display temperature in fahrenheit with a temperature sensor!

#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
 

void setup()
{
  lcd.begin(16, 2);                         
}
 
void loop()                     
{
 
lcd.clear();
 lcd.print(" hacking !!!!"); 
 
delay(1000);
 lcd.println(" degrees C ");
delay(1000);

}
