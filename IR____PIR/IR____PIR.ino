void setup() {
 Serial.begin(9600);
 pinMode(7,INPUT);
pinMode(8,OUTPUT);
}

void loop() {
  
  
if (  digitalRead(7) == LOW){
  digitalWrite(8,HIGH);
  Serial.println(" pir is high ");
  
  }else{
  digitalWrite(8,LOW);
    Serial.println(" pir is low ");
  
    }


}
