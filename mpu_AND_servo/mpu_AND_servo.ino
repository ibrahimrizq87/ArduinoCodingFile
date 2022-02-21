  
#include "Wire.h"

#include "MPU6050.h"
#include "Servo.h"

MPU6050 mpu;
int16_t ax, ay, az;
int16_t gx, gy, gz;
Servo servo1;
Servo servo2;
Servo servo3;


int val1;
int val2;
int val3;

int prevVal1;
int prevVal2;
int prevVal3;

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

}

void loop()
{
mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
val1 = map(ax, -17000, 17000, 0, 120);
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



}
