

         // Made by Nigga <3


int firstdelay  = 3;   // el water pump ht4t8al kam second 
int seconddelay  = 3; // el water pump m4 ht4t8al kam second

void setup() {
pinMode(2,OUTPUT);
pinMode(3,OUTPUT);
pinMode(4,OUTPUT);
}

void loop() {
 digitalWrite(2 ,LOW);
 digitalWrite(3 ,HIGH);
 digitalWrite(4 ,HIGH);
delay(firstdelay  * 1000 );

 digitalWrite(2 ,HIGH);
 digitalWrite(3 ,LOW);
 digitalWrite(4 ,LOW);
delay(seconddelay  * 1000 );
}
