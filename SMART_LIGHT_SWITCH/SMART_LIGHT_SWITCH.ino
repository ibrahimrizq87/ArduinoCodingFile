int sensorPin = 8; 
int sensorPin2 = 7;
int Val = 0;  
int Val2 = 0; 
int x=0; 

void setup() {
  Serial.begin(9600);
  pinMode(7,INPUT);
  pinMode(8,INPUT);
}

void loop() {
Val = digitalRead(sensorPin);  
Val2 = digitalRead(sensorPin2);
 

if (Val== LOW)
 {
  x=x+1;
 Serial.println(x);
  delay(2000);

 }
if (Val2== LOW)
 {
  x=x-1;
   Serial.println(x);
  delay(2000);

 }

