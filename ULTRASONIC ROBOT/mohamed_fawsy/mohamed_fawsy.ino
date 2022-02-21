int trigPin = 9;
int echoPin = 10;
int revright = 4;      //REVerse motion of Right motor
int fwdleft = 7;      
int revleft= 6;       
int fwdright= 5;       //ForWarD motion of Right motor
int water = 7 ;  
int x = 0;
void setup() {
  //Serial.begin(9600); 
   pinMode(5, OUTPUT);
   pinMode(6, OUTPUT);
   pinMode(4, OUTPUT);
   pinMode(7, OUTPUT);
   pinMode(water, OUTPUT);
   
   pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  // put your setup code here, to run once:

}

void loop() {
   
 
 
for (x = 0; x <= 500; x += 1) {
  long duration, distance;
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigPin, LOW);
  duration=pulseIn(echoPin, HIGH);
  distance =(duration/2)/29.1;

  if((distance>20))
 {
  digitalWrite(5,HIGH);                               //       If you dont get proper movements of your robot,
   digitalWrite(4,LOW);                               //        then alter the pin numbers
   digitalWrite(6,LOW);                               //
   digitalWrite(7,HIGH);                              //
 }
 
  else if(distance<20)  
 {

   
      digitalWrite(4,LOW); 
   digitalWrite(5,LOW); 
   digitalWrite(6,LOW); 
   digitalWrite(7,LOW); 
delay(1000);
   digitalWrite(5,HIGH);
   digitalWrite(4,LOW);
   digitalWrite(6,HIGH);                                  //HIGH
digitalWrite(7,LOW);
delay(1000);
   digitalWrite(4,LOW); 
   digitalWrite(5,LOW); 
   digitalWrite(6,HIGH); 
   digitalWrite(7,LOW); 
delay(500);

  }  else if(water== HIGH)  
 {

   
    digitalWrite(4,LOW); 
   digitalWrite(5,LOW); 
   digitalWrite(6,LOW); 
   digitalWrite(7,LOW); 
delay(1000);
   digitalWrite(5,HIGH);
   digitalWrite(4,LOW);
   digitalWrite(6,HIGH);                                  //HIGH
digitalWrite(7,LOW);
delay(1000);
   digitalWrite(4,LOW); 
   digitalWrite(5,LOW); 
   digitalWrite(6,HIGH); 
   digitalWrite(7,LOW); 
delay(500);

  }
 

 
  delay(10);

}
}
