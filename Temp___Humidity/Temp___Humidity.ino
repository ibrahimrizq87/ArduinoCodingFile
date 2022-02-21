#include <dht.h>

dht DHT;

#define DHT11_PIN 7
int val = 0 ;
int water_pump = 8;
void setup(){
  Serial.begin(9600);
pinMode(water_pump,OUTPUT);
}

void loop()
{

  val = analogRead(A0);
  int chk = DHT.read11(DHT11_PIN);
 Serial.print("soil moisture = ");
  Serial.println(val);
  Serial.print("Temperature = ");
  Serial.println(DHT.temperature);
  Serial.print("Humidity = ");
  Serial.println(DHT.humidity);
 
 if (val<= 500 and DHT.temperature >= 25 and DHT.humidity >= 20 ){
  
  digitalWrite(water_pump,HIGH);
  delay(2000);
  }else if(val<= 400 and DHT.temperature >= 25 and DHT.humidity >= 30){
  
  digitalWrite(water_pump,HIGH);
  delay(3000);
  }else if(val<= 300 and DHT.temperature >= 25 and DHT.humidity >= 40){
  
  digitalWrite(water_pump,HIGH);
  delay(4000);
  }else if(val<= 500 and DHT.temperature >= 20 and DHT.humidity >= 20){
  
  digitalWrite(water_pump,HIGH);
  delay(500);
  }else if(val<= 400 and DHT.temperature >= 20 and DHT.humidity >= 30){
  
  digitalWrite(water_pump,HIGH);
  delay(1000);
  }else if(val<= 300 and DHT.temperature >= 20 and DHT.humidity >= 40){
  
  digitalWrite(water_pump,HIGH);
  delay(1500);
  }else{
    digitalWrite(water_pump,LOW);
    } 
 
 delay(1000);
}

