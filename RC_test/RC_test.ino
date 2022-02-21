int outPin1 = 2;     //motor1 
int outPin2 = 3;    //motor1 
int outPin3 = 4;   //motor2 
int outPin4 = 5;   //motor2 

void setup() 
{ 
Serial.begin(9600); 
pinMode(outPin1,OUTPUT); 
pinMode(outPin2,OUTPUT); 
pinMode(outPin3,OUTPUT); 
pinMode(outPin4,OUTPUT);

} 
void loop() {
   digitalWrite(outPin1,HIGH); 
   digitalWrite(outPin2,LOW); 
   digitalWrite(outPin3,HIGH); 
   digitalWrite(outPin4,LOW); 
}
