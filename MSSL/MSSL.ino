int pirPin = 3;
int pirPin2 = 5;  
int ledPin = 7;
int ledPin2 = 8;
int sensorPin = A0; 
int Val = 0;  
void setup() {
Serial.begin(9600);
  pinMode(pirPin, INPUT);
  pinMode(pirPin2, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(ledPin2, OUTPUT);

}

void loop() {
  Val = analogRead(sensorPin);  
Serial.println(Val);
delay(100); 
 
if(digitalRead(pirPin) == HIGH  && Val>500){
       digitalWrite(ledPin, HIGH);  
         delay(500);
         }else{
          digitalWrite(ledPin, LOW);
          
          }         
         if(digitalRead(pirPin2) == HIGH&& Val>500){
       digitalWrite(ledPin2, HIGH);  
         delay(500);
         }else{
          digitalWrite(ledPin2, LOW);
          
          } 
}
