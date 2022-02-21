#include "dht.h"
#define DHT11 7 
dht DHT;
void setup() {
    Serial.begin(9600);
}

void loop() {
   DHT.read11(DHT11);
    Serial.print("temperature = ");
    Serial.print(DHT.temperature); 
    Serial.println("C  ");


delay(2000);
}
