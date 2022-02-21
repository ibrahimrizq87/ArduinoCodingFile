int TEMPsensorPin = A1;  
int IRsensorPin = A0;  
int errorVal = 0 ;  
int Val = 0;

 void setup()
 {
Serial.begin(9600); 
 }
 void loop() 
 {

 
 int TEMP = analogRead(TEMPsensorPin);
 int IR = analogRead(IRsensorPin);
 
 float voltage = TEMP * 5.0;
 voltage /= 1024.0;

 
 float temperatureC = (voltage - 0.5) * 100 ; 
 Serial.print(temperatureC+errorVal); 
 Serial.println(" degrees C");
    

Serial.print(IR); 
 Serial.println(" IR intensty reading");
 delay(2000);
 
 Serial.println(" ");
 Serial.println(" ");
 Serial.println(" ");
 
 }
