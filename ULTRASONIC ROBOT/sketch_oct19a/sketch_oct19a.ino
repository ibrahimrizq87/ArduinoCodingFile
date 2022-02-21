int trigPin = 9;
int echoPin = 3;

void setup() {
 Serial.begin(9600);
   pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

}

void loop() {
   
 
    long duration, distance;
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigPin, LOW);
  duration=pulseIn(echoPin, HIGH);
  distance =(duration/2)/29.1;
Serial.println(distance);
  }
