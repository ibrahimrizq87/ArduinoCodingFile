
#include <DHT.h>
#define DHTPIN 9     
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);


int chk;
float hum;  
float temp; 

void setup()
{
  pinMode(9,INPUT);
  pinMode(13,OUTPUT);
    Serial.begin(9600);
  dht.begin();
    
}

void loop()
{
   
    hum = dht.readHumidity();
    temp= dht.readTemperature();
if (temp =<1000 and hum =<1000)
{
  digitalWrite(13, LOW);
  Serial.print(temp,hum);
}
else
{
  digitalWrite(13, HIGH);
  Serial.print(temp,hum);
}

    delay(2000); 
}

   
