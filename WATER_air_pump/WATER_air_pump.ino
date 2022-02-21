int motor = 13;// water pump motor
int MOTOR2 = 12;//air motor
void setup() {
  pinMode(13,OUTPUT);// water pump pin
  pinMode(12,OUTPUT);//air pump motor pin
}

void loop() {
  digitalWrite(motor,HIGH);// switch on water pump

delay(300000);//5 min 
digitalWrite(motor,LOW);
digitalWrite(MOTOR2,HIGH);
delay(300000);
}
