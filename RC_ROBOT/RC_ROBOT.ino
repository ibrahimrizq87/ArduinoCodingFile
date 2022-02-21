int trigPin = 9;
int echoPin = 10;
int x=0;
int outPin1 = 4;     //motor1 
int outPin2 = 5;    //motor1 
int outPin3 = 6;
int outPin4 = 7;   //motor2  
char bt = 0;  
void setup() 
{ 
Serial.begin(9600); 
pinMode(outPin1,OUTPUT); 
pinMode(outPin2,OUTPUT); 
pinMode(outPin3,OUTPUT); 
pinMode(outPin4,OUTPUT);
   pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

} 
void loop() 
{ 
if (Serial.available() > 0) 
{ 
 bt = Serial.read(); 
 if(bt == '1')        //move forwards 
 { 
   digitalWrite(outPin1,HIGH); 
   digitalWrite(outPin2,LOW); 
   digitalWrite(outPin3,HIGH); 
   digitalWrite(outPin4,LOW); 
 Serial.println("1");
 } 
 else if (bt == '2')       //move backwards 
 { 
   digitalWrite(outPin1,LOW); 
   digitalWrite(outPin2,HIGH); 
   digitalWrite(outPin3,LOW); 
   digitalWrite(outPin4,HIGH); 
 Serial.println("2");
 } 
 else if (bt == '5')     //stop!! 
 {    
   digitalWrite(outPin1,LOW); 
   digitalWrite(outPin2,LOW); 
   digitalWrite(outPin3,LOW); 
   digitalWrite(outPin4,LOW); 
 
Serial.println("0");
} 
 else if (bt == '4')    //right 
 { 
   digitalWrite(outPin1,HIGH); 
   digitalWrite(outPin2,LOW); 
   digitalWrite(outPin3,LOW); 
   digitalWrite(outPin4,LOW); 
 Serial.println("4");
 } 
 else if (bt == '3')     //left  
 { 
   digitalWrite(outPin1,LOW); 
   digitalWrite(outPin2,LOW); 
   digitalWrite(outPin3,HIGH); 
   digitalWrite(outPin4,LOW); 
 Serial.println("3");
 } 
    else if (bt == '6'){
 
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
   digitalWrite(5,HIGH);
   digitalWrite(4,LOW);
   digitalWrite(6,HIGH);                                  //HIGH
   digitalWrite(7,LOW);
  }
 
  delay(10);

}

  

 
  
  } 
}} 

