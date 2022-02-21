float A ;
float V ;
float h ;
int R1 = 4;
int R2 = 4;
int R3 = 4;
int R4 = 4;
int R5 = 4;
int R6 = 4; 
void setup() {
  Serial.begin(9600);
pinMode(A0,INPUT_PULLUP);
pinMode(A1,INPUT_PULLUP);
pinMode(R1,OUTPUT);
pinMode(R2,OUTPUT);
pinMode(R3,OUTPUT);
pinMode(R4,OUTPUT);
pinMode(R5,OUTPUT);
pinMode(R6,OUTPUT);

}
void loop() {
V = (analogRead(A0)-156)*0.0229492;
A = (analogRead(A1)-67)*0.005;
if (V <= 1){
  LED1FromB2();
  LED2FromB2();
  
  }else{
  LED1FromB1();
  LED2FromB2();
    
    }
 }
 void LED1FromB1(){
  
  }
  
 void LED2FromB1(){
  
  }
  
 void LED1FromB2(){
  
  }
  
 void LED2FromB2(){
  
  }
