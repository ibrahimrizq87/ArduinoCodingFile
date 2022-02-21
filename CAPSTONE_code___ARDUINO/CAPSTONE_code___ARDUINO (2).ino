int sensorPin = A0;  

 int buzzer = 8 ;
 
 int led1 = 4;

 int led2 = 5;
 
 int led3 = 6;
 
 int led4 = 3; 
 
 int relay = 7;
 
 int val = 0;


String readString ;

void setup() {

Serial.begin(9600);

pinMode(buzzer,OUTPUT);

pinMode(led1,OUTPUT);

pinMode(led2,OUTPUT);

pinMode(led3,OUTPUT);

pinMode(led4,OUTPUT);

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

Serial.write( 'a' );

digitalWrite(led4,LOW);
     

delay(100);  
  
  }else if (val >= 250 && val <= 300 ) {
 
  digitalWrite(buzzer,HIGH);

  
    digitalWrite(led2,HIGH);
  
    if ( readString == "off" ){

digitalWrite(relay,LOW);

digitalWrite(led4,LOW);
     
}
Serial.write( 'b' );

    delay(100);  
    
    }else if (val >= 300 ){

      
  digitalWrite(buzzer,HIGH);

  
    digitalWrite(led3,HIGH);
  
        digitalWrite(relay,LOW);

     digitalWrite(led4,LOW);
       
        
        Serial.write( 'c' );

      
      delay(100);  
      
      }else {
      
        digitalWrite(buzzer,LOW);
        
        digitalWrite(led1,LOW);
        
        digitalWrite(led2,LOW);

        digitalWrite(led3,LOW);

        digitalWrite(led4,HIGH);
        
        digitalWrite(relay ,HIGH);



delay(100);
          
        
        } 

delay(100);  

}
