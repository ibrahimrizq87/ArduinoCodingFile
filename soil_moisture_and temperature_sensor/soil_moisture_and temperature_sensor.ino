 int temp_sensor = A0;
 int soil_moisture = A1;
 int Val=0;
 void setup()
 {
 Serial.begin(9600);
 pinMode(8,OUTPUT);
 }
 
 void loop() 
 {
 int Val=analogRead(soil_moisture);
 Serial.println(Val);
 int reading = analogRead(temp_sensor);
 float voltage = reading * 5.0;
 voltage /= 1024.0;
 Serial.print(voltage); Serial.println(" volts");
 float temperatureC = (voltage - 0.5) * -100 ; 
 Serial.print(temperatureC); 
 Serial.println(" degrees C");
 float temperatureF = (temperatureC * 9.0 / 5.0) + 32.0;
 Serial.print(temperatureF); Serial.println(" degrees F");

 if (Val<= 500 and temperatureC >= 25 ){
  
  digitalWrite(8,LOW);
  delay(2000);
  }else if(Val<= 400 and temperatureC >= 25 ){
  
  digitalWrite(8,LOW);
  delay(3000);
  }else if(Val<= 300 and temperatureC >= 25 ){
  
  digitalWrite(8,LOW);
  delay(4000);
  }else if(Val<= 500 and temperatureC >= 20 ){
  
  digitalWrite(8,LOW);
  delay(500);
  }else if(Val<= 400 and temperatureC >= 20 ){
  
  digitalWrite(8,LOW);
  delay(1000);
  }else if(Val<= 300 and temperatureC >= 20 ){
  
  digitalWrite(8,LOW);
  delay(1500);
  }else{
    digitalWrite(8,HIGH);
    } 
 
 
 
 delay(1000);  


 }
