const int trigPin = 11;
const int echoPin = 12;
long duration;
int distanceCm, distanceInch;
int sensorPin = A4; 
int pirPin = 3;  
int sensorPin1 = A5; 
int Val = 0;  
void setup() {
Serial.begin(9600);
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
pinMode(pirPin, INPUT);
pinMode(5, OUTPUT);
pinMode(6, OUTPUT);
pinMode(7, OUTPUT);
pinMode(2, OUTPUT);
pinMode(4, OUTPUT);
pinMode(8, OUTPUT);
pinMode(12, OUTPUT);
}

void loop() {
  digitalWrite(8,HIGH);
  Val = analogRead(sensorPin1);  
Serial.println(Val);
delay(100); 
 
       if(digitalRead(pirPin) == HIGH  && Val>200){
       digitalWrite(5, HIGH);  
         delay(1000);
         }else{
          digitalWrite(5, LOW);
          
          }  
          if(digitalRead(pirPin) == HIGH  && Val>300 ){
       digitalWrite(6, HIGH);  
         delay(1000);
         }else{
          digitalWrite(6, LOW);
          
          }         
       
if(digitalRead(pirPin) == HIGH  && Val>400){
       digitalWrite(7, HIGH);  
         delay(1000);
         }else{
          digitalWrite(7, LOW);
          
          }         
 int reading = analogRead(sensorPin);
 float voltage = reading * 5.0;
 voltage /= 1024.0;
 Serial.print(voltage); Serial.println(" volts");
float temperatureC = (voltage - 0.5) * -100 ; 
 Serial.print(temperatureC); 
 Serial.println(" degrees C");
 float temperatureF = (temperatureC * 9.0 / 5.0) + 32.0;
 Serial.print(temperatureF); Serial.println(" degrees F");
if ( temperatureC >18&&temperatureC <19){
  
digitalWrite(2, HIGH);  
         delay(10);
         }else{
          digitalWrite(2, LOW);
          
          }         
if ( temperatureC >1&&temperatureC <20){
  
digitalWrite(4, HIGH);  
         delay(10);
         }else{
          digitalWrite(4, LOW);
          
          }         
if ( temperatureC >20&&temperatureC <22){
  
digitalWrite(11, HIGH);  
         delay(10);
         }else{
          digitalWrite(11, LOW);
          
          }         
if ( temperatureC >22){
  
digitalWrite(8, HIGH);  
         delay(10);
         }else{
          digitalWrite(8, LOW);
          
          }         

    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    distanceCm= duration*0.034/2;
    distanceInch = duration*0.0133/2;
    Serial.println("Distance: "); // Prints string "Distance" on the LCD
    Serial.println(distanceCm); // Prints the distance value from the sensor
    Serial.println(" cm");
    delay(10);
    Serial.println("Distance: ");
    Serial.println(distanceInch);
    Serial.println(" inch");
    delay(1000);
    if (distanceCm<20){
      digitalWrite(13,HIGH);
      }else{
        digitalWrite(13,HIGH);
        }
    }
