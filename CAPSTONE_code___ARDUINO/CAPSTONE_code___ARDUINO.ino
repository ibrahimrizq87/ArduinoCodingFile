int sensorPin = A0;  

 int buzzer = 2 ;
 
 int led1 = 3;

 int led2 = 4;
  
 int relay = 5;
 
 int val = 0;


String readString ;

void setup() {

Serial.begin(9600);

pinMode(buzzer,OUTPUT);

pinMode(led1,OUTPUT);

pinMode(led2,OUTPUT);

pinMode(relay ,OUTPUT);

}

void loop() {
   while ( Serial.available()) {
    delay(3);
    char c = Serial.read();
    readString += c;
  }


val = analogRead(sensorPin); 

if ( val >= 200 && val <= 250 ){
  
digitalWrite(buzzer,HIGH);

  digitalWrite(led1,HIGH);

Serial.print( " low " );


delay(100);  
  
  }else if (val >= 250 && val <= 300 ) {
    if ( readString == "2" ){

digitalWrite(relay,LOW);

}
  digitalWrite(buzzer,HIGH);

  digitalWrite(led1,HIGH);  
  
    digitalWrite(led2,HIGH);
  
Serial.print( " medium " );

    delay(100);  
    
    }else if (val >= 300 ){

      
  digitalWrite(buzzer,HIGH);

  digitalWrite(led1,HIGH);  
  
    digitalWrite(led2,HIGH);
  
        digitalWrite(relay,LOW);
    
        
        Serial.print( " high " );

      
      delay(100);  
      
      }else {
      
        digitalWrite(buzzer,LOW);
        
        digitalWrite(led1,LOW);
        
        digitalWrite(led2,LOW);

        digitalWrite(relay ,HIGH);

           Serial.print( " normal " );


delay(100);
          
        
        } 

delay(100);  

}
