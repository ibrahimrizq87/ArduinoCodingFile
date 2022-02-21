  
#include "Wire.h"
#include "I2Cdev.h"
#include "MPU6050.h"
#include "Servo.h"

MPU6050 mpu;
int16_t ax, ay, az;
int16_t gx, gy, gz;
Servo servo1;
Servo servo2;
Servo servo3;

const int button1 = 12;
const int button2 = 13;

int button1Pressed = 0;
boolean button2Pressed = false;

int val1;
int val2;
int val3;

int prevVal1;
int prevVal2;
int prevVal3;
int servo1PosSave[]={1,1,1,1,1};
int servo2PosSave[]={1,1,1,1,1};
int servo3PosSave[]={1,1,1,1,1};

void setup()
{
  Wire.begin();
Serial.begin(38400);
Serial.println("Initialize MPU");
mpu.initialize();
Serial.println(mpu.testConnection() ? "Connected" : "Connection failed");
servo1.attach(9);
servo2.attach(10);
servo3.attach(5);
 pinMode(button1, INPUT);
  pinMode(button2, INPUT);


}

void loop()
{
mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
val1 = map(ax, -17000, 17000, 0, 179);
if (val1 != prevVal1)
{
servo1.write(val1);
prevVal1 = val1;
}
val2 = map(ay, -17000, 17000, 0, 179);
if (val2 != prevVal2)
{
servo2.write(val2);
prevVal2 = val2;
}




val3 = map(az, -17000, 17000, 0, 179);
if (val3 != prevVal3)
{
servo3.write(val3);
prevVal3 = val3;
}
delay(50);
if(digitalRead(button1) == HIGH){
    button1Pressed++;
    switch(button1Pressed){
      case 1:
        servo1PosSave[0] = prevVal1;
        servo2PosSave[0] = prevVal2;
        servo3PosSave[0] = prevVal3;
        Serial.println("Position #1 Saved");
       break;
       case 2:
        servo1PosSave[1] = prevVal1;
        servo2PosSave[1] = prevVal2;
        servo3PosSave[1] = prevVal3;
        Serial.println("Position #2 Saved");
       break;
       case 3:
        servo1PosSave[2] = prevVal1;
        servo2PosSave[2] = prevVal2;
        servo3PosSave[2] = prevVal3;
        Serial.println("Position #3 Saved");
       break;
       case 4:
        servo1PosSave[3] = prevVal1;
        servo2PosSave[3] = prevVal2;
        servo3PosSave[3] = prevVal3;
        Serial.println("Position #4 Saved");
       break;
       case 5:
        servo1PosSave[4] = prevVal1;
        servo2PosSave[4] = prevVal2;
        servo3PosSave[4] = prevVal3;
        Serial.println("Position #5 Saved");
       break;
    }
  }
  //if button2 pressed (HIGH), the servos move saved position
  if(digitalRead(button2) == HIGH){
    button2Pressed = true;
  }
  if(button2Pressed){
    for(int i=0; i<5; i++){
      servo1.write(servo1PosSave[i]);
      servo2.write(servo2PosSave[i]);
      servo3.write(servo3PosSave[i]);
      delay(2000);
    }
  }
  delay(500);


}


