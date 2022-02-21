int sensorPin = 8; 
int sensorPin2 = A1;
int Val = 0;  
int Val2 = 0; 
int x=0; 

void setup() {
  Serial.begin(9600);
  pinMode(7,OUTPUT);
  pinMode(8,INPUT);
}

void loop() {
Val = digitalRead(sensorPin);  
Val2 = analogRead(sensorPin2);
 

if (Val== LOW)
 {
  x=x+1;
 Serial.println(x);
  delay(2000);

 }
if ( Val2 >=800 )
 {
  x=x-1;
   Serial.println(x);
  delay(2000);
 }



}

