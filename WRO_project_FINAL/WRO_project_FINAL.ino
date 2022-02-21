int redLed = 2 ;
int greenLed = 3 ;
int motor1 = 9;
int motor2 = 10;
int buzzer= 12;
int smokeA0 = A0;
int smokeA1 = A1;
int smokeA2 = A2;
int sensorThres = 1400;

void setup() {
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(smokeA0, INPUT);
  pinMode(smokeA1, INPUT);
  pinMode(smokeA2, INPUT);

  Serial.begin(9600);
}

void loop() {

  int analogSensor = analogRead(smokeA0);
  int analogSensor2 = analogRead(smokeA1);
  int analogSensor3 = analogRead(smokeA2);
  int total = (analogSensor+analogSensor2+analogSensor3);
  Serial.print("total gas = ");
  Serial.println(total);
  
  // Checks if it has reached the threshold value
  if(total > sensorThres)
  {
    digitalWrite(redLed, LOW);
    digitalWrite(greenLed, HIGH);
    analogWrite(motor1 , 0);
    analogWrite(motor2, 0);
    digitalWrite(buzzer, LOW);
  }
    else
  {
    digitalWrite(redLed, HIGH);
    digitalWrite(greenLed, LOW);
    analogWrite(motor1, 250);
    analogWrite(motor2,250);
    digitalWrite(buzzer,HIGH);
  }
  delay(100);
  
}
