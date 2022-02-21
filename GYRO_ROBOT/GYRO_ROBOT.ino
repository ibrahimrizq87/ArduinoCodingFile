#include "I2Cdev.h"
#include "MPU6050.h"
#include "IRremote.h"
#include "SPI.h"
#include "Wire.h"
#include <Servo.h>




#define trigPin 6
#define echoPin 5 
#define OUTPUT_READABLE_ACCELGYRO 

#define in1  3
#define in2  4
#define in3  7
#define in4  8
#define RECV_PIN  11

#if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
#endif 

MPU6050 accelgyro(0x68);
int16_t ax, ay, az;
int16_t gx, gy, gz;
Servo ultrasonic; 
int degree = 0;
int rightdistance;
int leftdistance;
IRrecv irrecv(RECV_PIN);
decode_results results;


void setup () {
    ultrasonic.attach(0);
    Serial.begin(9600);
    #if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
    Wire.begin();
    #elif I2CDEV_IMPLEMENTATION == I2CDEV_BUILTIN_FASTWIRE
    Fastwire::setup(400, true);
    #endif
     ultrasonic.attach(0);
    Serial.println("Initializing I2C devices...");
    accelgyro.initialize();
    Serial.println("Testing device connections...");
    Serial.println(accelgyro.testConnection() ? "MPU6050 connection successful" : "MPU6050 connection failed");
    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);
    pinMode(in3, OUTPUT);
    pinMode(in4, OUTPUT);
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);

  Serial.println("Enabling IRin");
  irrecv.enableIRIn(); 
  Serial.println("Enabled IRin");
  
    } 

void loop () {
        accelgyro.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
        Serial.println("a/g:\t");
        Serial.print("x:");
        Serial.print(ax); Serial.print("\t");
        Serial.print("y:");
        Serial.print(ay); Serial.print("\t");
        Serial.print("z:");
        Serial.print(az); Serial.print("\t");
        Serial.print(gx); Serial.print("\t");
        Serial.print(gy); Serial.print("\t");
        Serial.print(gz); Serial.print("\t");
        Serial.print("");
        #ifdef OUTPUT_BINARY_ACCELGYRO
        Serial.write((uint8_t)(ax >> 8)); Serial.write((uint8_t)(ax & 0xFF));
        Serial.write((uint8_t)(ay >> 8)); Serial.write((uint8_t)(ay & 0xFF));
        Serial.write((uint8_t)(az >> 8)); Serial.write((uint8_t)(az & 0xFF));
        Serial.write((uint8_t)(gx >> 8)); Serial.write((uint8_t)(gx & 0xFF));
        Serial.write((uint8_t)(gy >> 8)); Serial.write((uint8_t)(gy & 0xFF));
        Serial.write((uint8_t)(gz >> 8)); Serial.write((uint8_t)(gz & 0xFF));
        #endif

    if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    irrecv.resume(); 
    }

  long duration, distance; 
  digitalWrite(trigPin, LOW);  
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);

  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  Serial.println("distance:");
  Serial.print(distance);


    

       if (distance <25 ) {
        digitalWrite(in1, LOW);
        digitalWrite(in2, LOW);
        digitalWrite(in3, LOW);
        digitalWrite(in4, LOW);
       if (az >10000)  {
        digitalWrite(in1, LOW);
        digitalWrite(in2, LOW);
        digitalWrite(in3, LOW);
        digitalWrite(in4, LOW);
         }
       if (az <10000 && ay >10000 && 50000> ax >-10000)  {
        digitalWrite(in1, LOW);
        digitalWrite(in2, HIGH);
        digitalWrite(in3, LOW);
        digitalWrite(in4, HIGH);
         }
       
   for(degree=90;degree>=0;degree -1){
    ultrasonic.write(degree);
    delay(15);
   }
  digitalWrite(trigPin, LOW);  
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  rightdistance = (duration/2) / 29.1;


  for(degree=0;degree<=180;degree+1){
    ultrasonic.write(degree);
    delay(15);
  }
  for (degree = 180; degree >= 90; degree -= 1) { 
    ultrasonic.write(degree);              
    delay(15);                       
  }
  digitalWrite(trigPin, LOW);  
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  leftdistance = (duration/2) / 29.1;

 if(rightdistance>25){
   if(az <10000 && ay <10000 &&  ax >10000) {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
 }
 if (az >10000)  {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  
      }
 if (az <10000 && ay >10000 && 50000> ax >-10000)  {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  
      }
 }

 if(leftdistance>25){
  
 }
 if (az >10000)  {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  
      }
 if(az <10000 && ay <10000 &&   ax <-10000){
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
       }
       
 if (az <10000 && ay >10000 && 50000> ax >-10000)  {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  
      }

 if(rightdistance>25 && leftdistance>25){
  if (az >10000)  {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  
      }
 if (az <10000 && ay >10000 && 50000> ax >-10000)  {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  
      }
 if(az <10000 && ay <10000 &&  ax >10000) {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
       }
 if(az <10000 && ay <10000 &&   ax <-10000){
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
       }
 }
 }
  
         
         
       else { 
 if (az >10000)  {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  
      }
 if (az <10000 && ay >10000 && 50000> ax >-10000)  {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  
      }
           
 if (az <10000 && ay <10000 &&  ax <10000  &&  ax>-10000)  {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
       }
 if(az <10000 && ay <10000 &&  ax >10000) {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
       }
 if(az <10000 && ay <10000 &&   ax <-10000){
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
       }
       }

    switch(results.value) {

      case 0xFF38C7 :
      digitalWrite(in1, LOW);
      digitalWrite(in2, LOW);
      digitalWrite(in3, LOW);
      digitalWrite(in4, LOW);
      break;

      case 0xFF18E7 :
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);
      break;

      case 0xFF4AB5 :
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
      digitalWrite(in3, LOW);
      digitalWrite(in4, HIGH);
      break;

      case 0xFF5AA5 :
      digitalWrite(in1, LOW);
      digitalWrite(in2, LOW);
      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);
      break;

      case 0xFF10EF :
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      digitalWrite(in3, LOW);
      digitalWrite(in4, LOW);
    }
}
