//soil moisture sensor
const int soilpin=A0;
int ledsoil=12;
void setup()
 {
  Serial.begin(9600);
  pinMode(10,OUTPUT);
pinMode(9,OUTPUT);

}

void loop()
 {
  int moisture=analogRead(soilpin);
  Serial.println(moisture);
  if(moisture>1000)
  {
    digitalWrite(ledsoil,HIGH);
    delay(100);
  }
else
{
  digitalWrite(ledsoil,LOW);
  delay(100);
}
}





























