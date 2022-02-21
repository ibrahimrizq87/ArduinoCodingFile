int sensorPin = 12; 
int sensorPin2 = 13;
int x=0; 

int relay1 = 2;
int relay2 = 3;
int relay3 = 4;
int relay4 = 5;
int relay5 = 6;
int relay6 = 7;
int relay7 = 8;
int relay8 = 9;

String readString;
void setup() {
  Serial.begin(9600);
  pinMode(sensorPin,INPUT);
  pinMode(sensorPin2,INPUT);

  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(relay3, OUTPUT);
  pinMode(relay4, OUTPUT);

}
void loop() {
  while (Serial.available()) {
    delay(3);
    char c = Serial.read();
    readString += c;
  }
  if (readString.length() > 0) {
    Serial.println(readString);
    
    if (digitalRead(sensorPin)== LOW)
 {
  x=x+1;
 Serial.println(x);
  delay(2000);

 }
if (digitalRead(sensorPin2)== LOW )
 {
  x=x-1;
   Serial.println(x);
  delay(2000);
 }

if (x >= 0 ){
  
     digitalWrite(relay1, HIGH);
   
  
  
  }

    if ( x <=0 ){
      
   digitalWrite(relay1, LOW);
      
      
      }
    if (readString == "1 ON" )
    {
      digitalWrite(relay1, HIGH);
    }
    if (readString == "1 OFF")
    {
      digitalWrite(relay1, LOW);
    }
    //relay2
    if (readString == "2 ON")
    {
      digitalWrite(relay2, HIGH);
    }
    if (readString == "2 OFF")
    {
      digitalWrite(relay2, LOW);
    }
    //relay3
    if (readString == "3 ON")
    {
      digitalWrite(relay3, HIGH);
    }
    if (readString == "3 OFF")
    {
      digitalWrite(relay3, LOW);
    }
    //relay4
    if (readString == "4 ON")
    {
      digitalWrite(relay4, HIGH);
    }

   

    //All on / off
    if (readString == "ALL ON")
    {
      digitalWrite(relay1, HIGH);
      digitalWrite(relay2, HIGH);
      digitalWrite(relay3, HIGH);
      digitalWrite(relay4, HIGH);
   
    }
    if (readString == "ALL OFF")
    {
      digitalWrite(relay1, LOW);
      digitalWrite(relay2, LOW);
      digitalWrite(relay3, LOW);
      digitalWrite(relay4, LOW);
    }
    //next
    readString = "";
  }
}
