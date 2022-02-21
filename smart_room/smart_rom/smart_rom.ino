
int relay1 = 2;
int relay2 = 3;
int relay3 = 4;
int relay4 = 5;

int relay5 = 6;
int relay6 = 7;
int relay7 = 8;
int relay8 = 9;

String readString;
void setup() {
  Serial.begin(9600);
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(relay3, OUTPUT);
  pinMode(relay4, OUTPUT);
  pinMode(relay5, OUTPUT);
  pinMode(relay6, OUTPUT);
  pinMode(relay7, OUTPUT);
  pinMode(relay8, OUTPUT);
}
void loop() {

  while (Serial.available()) {
    delay(3);
    char c = Serial.read();
    readString += c;
  }
  if (readString.length() > 0) {
    Serial.println(readString);
    if (readString == "1 ON" )
    {
      digitalWrite(relay1, HIGH);
    }
    if (readString == "1 OFF")
    {
      digitalWrite(relay1, LOW);
    }
    //relay2
    if (readString == "2 ON")
    {
      digitalWrite(relay2, HIGH);
    }
    if (readString == "2 OFF")
    {
      digitalWrite(relay2, LOW);
    }
    //relay3
    if (readString == "3 ON")
    {
      digitalWrite(relay3, HIGH);
    }
    if (readString == "3 OFF")
    {
      digitalWrite(relay3, LOW);
    }
    //relay4
    if (readString == "4 ON")
    {
      digitalWrite(relay4, HIGH);
    }

    if (readString == "5 ON" )
    {
      digitalWrite(relay5, HIGH);
    }
    if (readString == "5 OFF")
    {
      digitalWrite(relay5, LOW);
    }
    //relay2
    if (readString == "6 ON")
    {
      digitalWrite(relay6, HIGH);
    }
    if (readString == "6 OFF")
    {
      digitalWrite(relay6, LOW);
    }
    //relay3
    if (readString == "7 ON")
    {
      digitalWrite(relay7, HIGH);
    }
    if (readString == "7 OFF")
    {
      digitalWrite(relay7, LOW);
    }
    //relay4
    if (readString == "8 ON")
    {
      digitalWrite(relay8, HIGH);
    }
    if (readString == "8 OFF")
    {
      digitalWrite(relay8, LOW);
    }


    //All on / off
    if (readString == "ALL ON")
    {
      digitalWrite(relay1, HIGH);
      digitalWrite(relay2, HIGH);
      digitalWrite(relay3, HIGH);
      digitalWrite(relay4, HIGH);
    }
    if (readString == "ALL OFF")
    {
      digitalWrite(relay1, LOW);
      digitalWrite(relay2, LOW);
      digitalWrite(relay3, LOW);
      digitalWrite(relay4, LOW);
    }
    //next
    readString = "";
  }
}
