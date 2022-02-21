int sensorPin = A0;  
int Val = 0;
int state = 0;
void setup() {
  pinMode(9, OUTPUT);
  pinMode(8, INPUT);
  pinMode(7, INPUT);
  Serial.begin(9600); 
}
void loop() {
    
 if(Serial.available() > 0){
    state = Serial.read(); 
 }
   Val = analogRead(sensorPin);
  if (digitalRead(8) == LOW and Val>= 10) {
  digitalWrite(9, HIGH); // LED ON 
   Serial.write('1');
  state = 0;
 }
 else if (digitalRead(8) == HIGH and Val>= 10) {
  digitalWrite(9, LOW); // LED off
 Serial.write('2');
  state = 0;
 }else{
Serial.write('0'); 
 }
 delay(130);
 }
 
