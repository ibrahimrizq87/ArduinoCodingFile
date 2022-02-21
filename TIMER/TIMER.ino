
int water_pump =12;

void setup() 
{
  pinMode(12, OUTPUT);
  } void loop()
  { digitalWrite(water_pump, HIGH);
  delay(5000); 
  digitalWrite(water_pump, LOW);
  delay(1000);  
} 

