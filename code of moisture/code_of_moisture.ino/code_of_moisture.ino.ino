int sensor=8;
int WATER_PUMP=13;
int val;
void setup() 
{
Serial.begin(9600);
pinMode(13,OUTPUT);
pinMode(12,INPUT);
}
void loop()
{
  val = digitalRead(8);
if(val==0)
{
  digitalWrite(13,HIGH);
Serial.print(val);
}
else
{
  digitalWrite(13,LOW);
Serial.print(val);
}

delay(400);
}
