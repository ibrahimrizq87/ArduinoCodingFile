#include <adios>
int time = 6000000 
void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  
}

void loop() {
  int analogValue = analogRead(analogPin);

  if (time => 6000000) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }

  
  Serial.println(analogValue);
  delay(1);       
}

