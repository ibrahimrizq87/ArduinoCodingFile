
void setup() {
 Serial.begin(9600);
}

void loop() {
 if (digitalRead(7)==HIGH)
  {
    Serial.println("7 high");
    }
 
 if (digitalRead(12)==HIGH);
  {
    Serial.println("12 high");
  }
 if (digitalRead(13)==HIGH);
 
  {
    Serial.println("13 high");
  }  
  delay(100);
}
