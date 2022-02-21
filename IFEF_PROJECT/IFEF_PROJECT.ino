    const int trigPin = 9;       // يسطا البايتين دول ()بتوع السنسور بتاع الالتراسويك اللى بيقيس المسافة 
    const int echoPin = 10;
    long duration;
    int distanceCm, distanceInch;
    void setup() {
    Serial.begin(9600); // Initializes the interface to the LCD screen, and specifies the dimensions (width and height) of the display
    pinMode(trigPin, OUTPUT);// دى تعريفات البننننات الداتا داخلة اللاردوينو ولا خارجة 
    pinMode(echoPin, INPUT);
   pinMode(7, OUTPUT);// بنايت المتوررقم واحد 
    pinMode(8, INPUT);//دا سنسور السويل 
    pinMode(6, OUTPUT);//موتور رقم اتنين 
    
    }
    void loop() {
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    distanceCm= duration*0.034/2;
    distanceInch = duration*0.0133/2;
    Serial.println("Distance: "); // Prints string "Distance" on the LCD
    Serial.println(distanceCm); // Prints the distance value from the sensor
    Serial.println(" cm");
    delay(10);
    Serial.println("Distance: ");
    Serial.println(distanceInch);
    Serial.println(" inch");
    delay(1000);// سوابت قياس المسافة
    if(distanceCm >= 10 ){
      
      digitalWrite(7,HIGH);
    Serial.println(" high");  
      }else{
        digitalWrite(7,LOW);
      Serial.println(" low");
      }
    
    if(digitalRead(8)== LOW){
      
      digitalWrite(6,LOW);
      }else{
        digitalWrite(6,HIGH);
        }
    }
