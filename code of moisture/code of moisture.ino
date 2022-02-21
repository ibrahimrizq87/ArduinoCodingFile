int WATER_PUMP = 9;
int sensor = 13;
int val;
void setup() {
Serial.begin(9600);
pinMode(9, OUTPUT);
pinMode(13, INPUT);

}
void loop() {
val = digitalRead(8);
if (val == LOW)
{
  digitalWrite(9, LOW);
  Serial.print(val);
}
else
{
  digitalWrite(9, HIGH);
  Serial.print(val);
}
delay(400);
}
