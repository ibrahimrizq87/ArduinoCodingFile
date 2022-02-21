
void setup() {
Serial.begin (9600);
}

void loop() {
int   x = analogRead(A1);
  if (x < 100){
    Serial.print('a');
    delay(200);
    }else if (x > 100 && x<200 ){
      Serial.print('b');
      delay (200);
      }else if (x > 200 && x<300 ){
      Serial.print('c');
      delay (200);
      }else if (x > 300 && x<400 ){
      Serial.print('d');
      delay (200);
      }else if (x > 400 && x<500 ){
      Serial.print('f');
      delay (200);
      }else if (x > 500 && x<600 ){
      Serial.print('g');
      delay (200);
      }
      
delay(1000);
}
