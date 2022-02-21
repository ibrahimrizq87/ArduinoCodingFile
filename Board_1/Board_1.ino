
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Stepper.h>

const int stepsPerRevolution = 400;
Stepper myStepper(stepsPerRevolution, D4, D0, D8, D7);
int xVal=512;
int IR1= D5;    //people get out of the room
int IR2= D6;    //people get inside the room
int LED1= 1;
int LED2= 2;
int LED3= 3;
int numPersons=0;
const int analogchannel = 0; //Connect current sensor with A0 of Arduino
int sensitivity = 185; // use 100 for 20A Module and 66 for 30A Module
float adcvalue= 0;
int offsetvoltage = 2500; 
double Voltage = 0; //voltage measuring
double ecurrent = 0;// Current measurin
float z=0.0;
float consumed_power =0;

//Start GPS 

//End GPS


void setup()
{
  // Debug console
  Serial.begin(9600);
  pinMode(D1,OUTPUT);
  pinMode(D2,OUTPUT);
  pinMode(D3,OUTPUT);

  pinMode (IR1,INPUT);          
pinMode (IR2,INPUT);          

  digitalWrite(D1,HIGH);
  digitalWrite(D2,HIGH);
  digitalWrite(D3,HIGH);
}


void loop()
{
  int val1 = digitalRead(IR1);
  int val2 = digitalRead(IR2);
  if(!val1)
  {
    numPersons--; 
    Serial.println(numPersons);
        if(numPersons<=0)
  {
    digitalWrite(LED1,HIGH);     
    digitalWrite(LED2,HIGH);     
    digitalWrite(LED3,HIGH);     
  }
  else
  {
    digitalWrite(LED1,LOW);
    digitalWrite(LED2,LOW);
    digitalWrite(LED3,LOW);
  }
  delay(1000);
  }
    
  val1 = digitalRead(IR1);
  val2 = digitalRead(IR2);
  if(!val2)
  {
    numPersons++; 
    Serial.println(numPersons); 
       if(numPersons<=0)
  {
    digitalWrite(LED1,HIGH);     
    digitalWrite(LED2,HIGH);     
    digitalWrite(LED3,HIGH);     
  }
  else
  {
    digitalWrite(LED1,LOW);
    digitalWrite(LED2,LOW);
    digitalWrite(LED3,LOW);
  delay(500);
  }
// current sensor
unsigned int temp=0;
 float maxpoint = 0;
 int i=0;
 for(i=0;i<500;i++)
 {
 if(temp = analogRead(analogchannel),temp>maxpoint)
 {
 maxpoint = temp;
 }
 }
 adcvalue = maxpoint; 
 Voltage = (adcvalue / 1024.0) * 5000; // Gets you mV
 ecurrent = ((Voltage - offsetvoltage) / sensitivity);
 ecurrent = ( ecurrent ) / ( sqrt(2) );
//Prints on the serial port



Serial.print("ac Current = ");
Serial.print(ecurrent+4.1);
Serial.print("A"); //unit for the current to be measured
  z = z+ecurrent+4.1;
  consumed_power = z*(-0.0001);
  Serial.print(consumed_power);
  delay(1000);//delay of 1 sec
//end current
}

if( (xVal < 500) ){
  myStepper.step(1);
  delayMicroseconds(3000);
}
else if ( xVal > 550 ){
  myStepper.step(-1);
  delayMicroseconds(3000);

}
