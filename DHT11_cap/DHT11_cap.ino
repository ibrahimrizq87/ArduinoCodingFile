#include "dht.h"
int IRsensorpin = A0;
#define DHT11 7 
dht DHT;
void setup() {
    Serial.begin(9600);
}

void loop() {
   DHT.read11(DHT11);
   int IR = analogRead(IRsensorpin);
   Serial.print("IR reading = ");
   Serial.println(IR); 
    Serial.print("temperature = ");
    Serial.print(DHT.temperature); 
    Serial.println("C  ");
    Serial.println("  ");
    Serial.println("  ");
    Serial.println("   ");
delay(2000);
}
