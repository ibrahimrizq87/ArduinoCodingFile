
#include <Servo.h>



//Setup the variables for the HC-SR04

const int trigPin = 9;

const int echoPin = 10;

// create servo object to control a servo

// a maximum of eight servo objects can be created

Servo myservo;

        

// variable to store the servo position

int pos = 0;  

void setup() {

 // initialize serial communication:

 Serial.begin(9600);



// attaches the servo on pin 9 to the servo object

 myservo.attach(5); 



}

void loop()

{

 // establish variables for duration of the ping,

 // and the distance result in inches and centimeters:

 long duration, inches, cm;



 // The sensor is triggered by a HIGH pulse of 10 or 
 // more microseconds.

 // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:

 pinMode(trigPin, OUTPUT);

 digitalWrite(trigPin, LOW);

 delayMicroseconds(2);

 digitalWrite(trigPin, HIGH);

 delayMicroseconds(10);

 digitalWrite(trigPin, LOW);



 // Read the signal from the sensor: a HIGH pulse whose

 // duration is the time (in microseconds) from the sending

 // of the ping to the reception of its echo off of an object.

 pinMode(echoPin, INPUT);

 duration = pulseIn(echoPin, HIGH);



 // convert the time into a distance

 inches = microsecondsToInches(duration);

 cm = microsecondsToCentimeters(duration);



 //Tell the Arduino to print the measurement in the serial console

 Serial.print(inches);

 Serial.print("in, ");

 Serial.print(cm);

 Serial.print("cm");

 Serial.println();



 // This if-else statement tells the Arduino at what distance

 // it should trigger the servo, what the servo should do,

 // and what it should do if the distance is too far away.

 if (inches <= 24) {sweep(3);

  

 }

 else if (inches >= 24) {myservo.write(pos);

 }

 

 // Tell the Arduino to wait 0.10 seconds before pinging the

 // Ultrasonic Sensor again.

 delay(100);

}

