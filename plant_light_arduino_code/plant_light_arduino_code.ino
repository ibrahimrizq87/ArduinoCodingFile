
#include <SoftwareSerial.h>
 
SoftwareSerial blue(2,3);
float volt;
float res;
float percentage;

const int RED = 11;
const int GREEN = 10;
const int BLUE = 9;

unsigned long curTime;
unsigned long desiredTime;
unsigned long waitTime;

String state;

void setup() {
  Serial.begin(9600);
 blue.begin(9600); 
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);

}

void loop() {
  turnRGB(1,1,1);
  
  

  curTime = millis();
  
  while(1){
  if (blue.available() > 0) {
        state = blue.readString();
        Serial.print(state);
  }
  if(state[1] == '1'){
        Serial.print("11111");
    
    desiredTime = curTime + 36,000,000;
    waitTime = desiredTime + 50,400,000;
  } else if(state[1] == '2'){
    
        Serial.print("222222");
    desiredTime = curTime + 43,200,000;
    waitTime = desiredTime + 42,400,000;
  } else if(state[1] == '3'){
    
    desiredTime = curTime + 54,000,000;
    waitTime = desiredTime + 32,400,000;
  } else {
    

  
    volt = analogRead(0)/1024.0*5.0;
    blue.print("Voltage : ");
    blue.println(volt);
    
    Serial.print("Voltage : ");
    Serial.println(volt);
    res = (510000/(5+volt))*volt;
    blue.print(" LDR : ");
    blue.println(res);
    
    
    Serial.print(" LDR : ");
    Serial.println(res);
    
    percentage = res/250000.0;
    
    percentage = 100.0 - percentage * 100.0;
    blue.print(" Percentage : ");
    blue.print(percentage);
    blue.println("%");
    blue.println("-----------------");
    
    continue;
    delay(1000);
  }

  
    volt = analogRead(0)/1024.0*5.0;
    blue.print("Voltage : ");
    blue.print(volt);
    Serial.print("Voltage : ");
    Serial.print(volt);
    res = (510000/(5+volt))*volt;
    blue.print(" LDR : ");
    blue.print(res);
    Serial.print(" LDR : ");
    Serial.print(res);
    percentage = res/250000.0;
    
    if(state[0]=='a'){
       Serial.print(" aaaa");
      turnRGB(38.51*percentage,0.462*percentage, 215.9*percentage);
    }
    else if(state[0]=='b'){
       Serial.print(" bbbb");
       Serial.print(200.48*percentage);
      turnRGB(200.48*percentage, 1.069*percentage, 53.448*percentage);
    }else if(state[0]=='c'){
       Serial.print(" ccccc");
      turnRGB(112.68*percentage, 2.1165*percentage, 140.2*percentage);
    }

    percentage = 100.0 - percentage * 100.0;
    Serial.print(" Percentage : ");
    Serial.print(percentage);
    Serial.println("%");
    Serial.println("-----------------");
    blue.print(" Percentage : ");
    blue.print(percentage);
    blue.println("%");
    blue.println("-----------------");
    
    delay(10);
  
  }
    turnRGB(0,0,0);
    while(millis() < waitTime){
      if (blue.available() > 0) {
        state = blue.readString();
        break;
  }
  }
  }

   


void turnRGB(int R, int G, int B){
  analogWrite(RED, R);
  analogWrite(GREEN, G);
  analogWrite(BLUE, B);
}
