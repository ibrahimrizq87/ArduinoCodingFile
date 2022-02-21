void setup() {
Serial.begin(9600);
}

void loop() {
  Serial.print (1);Serial.print ("L");Serial.print (" ");Serial.print (0.19);Serial.print ("L.E");
delay(2000);
  Serial.print (2);Serial.print ("L");Serial.print (" ");Serial.print ( 2*0.19);Serial.print ("L.E");
delay(2000);

  Serial.print (3);Serial.print ("L");Serial.print (" ");Serial.print (3*0.19);Serial.print ("L.E");
delay(2000);
  Serial.print (4);Serial.print ("L");Serial.print (" ");Serial.print (4*0.19);Serial.print ("L.E");
delay(2000);
  Serial.print (5);Serial.print ("L");Serial.print (" ");Serial.print (5*0.19);Serial.print ("L.E");
delay(2000);

}
