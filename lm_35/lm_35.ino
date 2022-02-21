int TEMPsensorPin = A1;  
int Val = 0;

 void setup()
 {
Serial.begin(9600); 
 }
 void loop() 
 {

 
 int TEMP = analogRead(TEMPsensorPin);
 
 float voltage = TEMP * 5.0;
 voltage /= 1024.0;

 
 float temperatureC = (voltage - 0.5) * 100 ; 
 Serial.print(temperatureC+errorVal); 
 Serial.println(" degrees C");
 
 delay (1000);}
