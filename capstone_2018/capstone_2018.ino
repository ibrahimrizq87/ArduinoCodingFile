//add servo library
#include <Servo.h>

//define our servos
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;

//define our potentiometers
int pot1 = A0;
int pot2 = A1;
int pot3 = A2;
int pot4 = A3;
int pot5 = A4;
 
//variable to read the values from the analog pin (potentiometers)
int valPot1;
int valPot2;
int valPot3;
int valPot4;
int valPot5;
void setup()
{
  //attaches our servos on pins PWM 3-5-6-9 to the servos
  servo1.attach(9);
  servo1.write(0);  //define servo1 start position
  servo2.attach(11);
   //define servo2 start position
  servo3.attach(3);
   //define servo3 start position
  }

void loop()
{
  //reads the value of potentiometers (value between 0 and 1023)

  valPot1 = analogRead(pot1);
  Serial.print(" valPot1 ");
  valPot1 = map (valPot1, 0, 1023, 0, 180); //scale it to use it with the servo (value between 0 and 180)
  servo1.write(valPot1); //set the servo position according to the scaled value

  valPot2 = analogRead(pot2);
  valPot2 = map (valPot2, 0, 1023, 0, 180);
  servo2.write(valPot2);
  
  valPot3 = analogRead(pot3);
  valPot3 = map (valPot3, 0, 1023, 0, 180);
  servo3.write(valPot3);

  valPot4 = analogRead(pot4);
  valPot4 = map (valPot4, 0, 1023, 70, 150);
  servo4.write(valPot4);
  
valPot5 = analogRead(pot5);
  Serial.print(" valPot5 ");
  valPot5 = map (valPot1, 0, 1023, 0, 180); //scale it to use it with the servo (value between 0 and 180)
  servo5.write(valPot5); //set the servo position according to the scaled value

}
