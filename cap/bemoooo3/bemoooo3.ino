#include <LiquidCrystal.h>
String nameofteam ="BEMO" ; // اكتبو اسم التيم مبين علامتين التنصيص دول بظل كلمة ""
const double price= 0 ; // اكتبو سعر اللتر مكان الزيرو
int led1 = 7 ;
int led2 = 8 ;
int led3 = 9 ;
int IRsensor = 10 ;
int valve = 13 ;
int Y = 0 ;

int flowsensor = 2 ;  
const int rs = 12, en = 11, d4 = 6, d5 = 5, d6 = 4, d7 = 3 ;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7) ;
volatile int FlowPulse ; 
int calc;                               
void setup() {     
   pinMode(IRsensor, INPUT);
   pinMode(led1, OUTPUT);
   pinMode(led2, OUTPUT);
   pinMode(led3, OUTPUT);
   pinMode(valve, OUTPUT);
   pinMode(flowsensor, INPUT); //initializes digital pin 2 as an input
   Serial.begin(9600);         //This is the setup function where the serial port is initialised,
   attachInterrupt(0, rpm, RISING); //and the interrupt is attached on Pin 2 (INT 0)
   lcd.begin(16, 2);
   }
 
void loop() {
   
   delay (1000);
   digitalWrite(led1,LOW);
   digitalWrite(led2,LOW);
   digitalWrite(led3,LOW);
   digitalWrite(valve,LOW);
  
  int x =0;
   lcd.print(nameofteam);
   lcd.setCursor(0, 1);
   lcd.println("Smart Tap       ");
  digitalWrite(valve,LOW);
 
  
  while (digitalRead(IRsensor)== LOW){
    double Time = Y/3600;
    double value = calc *  Time ;
    double totalprice = price * value ;
    Serial.print(value ,+"L"); 
    Serial.print(totalprice ,+"L.E");
    x++;
    Y++;
 FlowPulse = 0;      
 
 sei();            
 
 delay (1000);      
 
 cli();            
 
 calc = (FlowPulse * 60 / 7.5);  

if ( x<=10 && calc >0 ){
 
  digitalWrite(led1,HIGH);
  
  digitalWrite(valve,HIGH);
  
  digitalWrite(led2,LOW);
  
  digitalWrite(led3,LOW);   
  
   lcd.begin(16, 2);
   
   lcd.print("Water Running....");
   
   lcd.setCursor(0, 1);
   
   lcd.println("Normal time     ");
  }
  else if (x>=10 && x<=15 && calc >0 )    
{    
  
  digitalWrite(led2,HIGH);
  
  digitalWrite(valve,HIGH);

  
  
  digitalWrite(led1,LOW);
  
  digitalWrite(led3,LOW);  
  
   lcd.begin(16, 2);
   
   lcd.print("Water Running....");
   
   lcd.setCursor(0, 1);
   
   lcd.println("long time       ");

    
    
    }else if(x>=15 && calc >0 ){ 
   
   digitalWrite(led3,HIGH);
   
   digitalWrite(led2,LOW);
   
   digitalWrite(led1,LOW);  
   
   lcd.begin(16, 2);
   
   lcd.print("Water Running....");
   
   lcd.setCursor(0, 1);
   
   lcd.println("WARNING WASTED  ");
   
   digitalWrite(valve,LOW);
   
     }else{
   
   digitalWrite(led1,LOW);
   
   digitalWrite(led2,LOW);
   
   digitalWrite(led3,LOW);
   
   digitalWrite(valve,LOW);
   
   lcd.begin(16, 2);
   
   lcd.print("NO Water Running");
   
   lcd.setCursor(0, 1);
   
   lcd.println("Open The Tap");

 
  }

  }
  
  }
  
void rpm ()     
{ 
  FlowPulse++;  
}
