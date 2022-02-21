
#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "54dc80c5fd094a1e805b419cead2dda4"; //You will get this Auth Token in Gmail if you signin Blynk app with your Gmail ID

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Error 404"; //Enter your WIFI Name
char pass[] = "0882360263";//Enter your WIFI Password

int methanesensor = D8 ;
int Val3 = 0;
int Val = 0;  
int Val2 = 0; 
int x=0; 
int sensorPin = A0;




BLYNK_WRITE(V5  ) {
  GpsParam gps(param);

  // Print 6 decimal places for Lat, Lon
  Serial.print("Lat: ");
  Serial.println(gps.getLat(), 7);


  if (gps.getLat()< 31.0773083)
 {
 Serial.println("turn on all devices");
  delay(500);
    Blynk.virtualWrite(6, "you are too near, turning on all devices");
 }

  Serial.print("Lon: ");
  Serial.println(gps.getLon(), 7);

  // Print 2 decimal places for Alt, Speed
  Serial.print("Altitute: ");
  Serial.println(gps.getAltitude(), 2);

  Serial.print("Speed: ");
  Serial.println(gps.getSpeed(), 2);

  Serial.println();
}




void setup()
{
  // Debug console
  Serial.begin(9600);
  pinMode(D1,OUTPUT);
  pinMode(D2,OUTPUT);
  pinMode(D3,OUTPUT);
  pinMode(D4,OUTPUT);

pinMode(methanesensor,INPUT);
  pinMode(D5,INPUT);
  pinMode(D6,INPUT);

  digitalWrite(D1,HIGH);
  digitalWrite(D2,HIGH);
  digitalWrite(D3,HIGH);
  digitalWrite(D4,HIGH);
  
  

  Blynk.begin(auth, ssid, pass);
  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 8442);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8442);
}

void loop()
{
  Blynk.run();




  Val = digitalRead(D5);  
  Val2 = digitalRead(D6);
  Val3 = digitalRead(methanesensor);
if (Val3 == LOW)
 {
  
    Blynk.virtualWrite(3,"HIGH" );
 }
if (Val3== HIGH)
 {
   Blynk.virtualWrite(3, " LOW ");
}


if (Val== LOW)
 {
  x=x+1;
 Serial.println(x);
  delay(500);
    Blynk.virtualWrite(0, x);
 }
if (Val2== LOW)
 {
  x=x-1;
   Serial.println(x);
  delay(500);
   Blynk.virtualWrite(0, x);
}


int reading = analogRead(sensorPin);
 // converting that reading to voltage, for 3.3v arduino use 3.3
 float voltage = reading * 5.0;
 voltage /= 1024.0;

 // now print out the temperature
 float temperatureC = (voltage - 0.5) * 100 ; //converting from 10 mv per degree wit 500 mV offset
 //to degrees ((voltage - 500mV) times 100)
 Serial.print(temperatureC+40); Serial.println(" degrees C");
 Blynk.virtualWrite(1, temperatureC);
 delay(2000); //waiting a second

}
