 int water_pump = 13; //pin13 built-in led
 int sensorPin = 7; //the ir obstacle sensor attach to pin 7
void setup()
{
  pinMode(water_pump, OUTPUT); //set the ledPin as OUTPUT
  pinMode(sensorPin, INPUT); //set the avoidPin as INPUT
}

  void loop()
{
  boolean avoidVal = digitalRead(sensorPin); //read the value of pin7

  if(sensorPin == LOW) //if the value is LOW level
  {
    digitalWrite(water_pump, LOW); //turn on the led
  }
  else //else
  {
    digitalWrite(water_pump, HIGH); //turn off the led
  }
}
