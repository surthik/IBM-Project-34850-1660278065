const int pingPin = 2;
const int echoPin = 6;
int led = 13;
int sensor = 3;
int buzzer =12;
long duration, cm;
void setup() {
  pinMode(led, OUTPUT);
   pinMode(buzzer, OUTPUT);
  pinMode(sensor, INPUT);
   Serial.begin(9600); 
}
    long microsecondsToCentimeters(long microseconds) {
   return microseconds / 29 / 2;
    }

void loop() {
  int sensorval = digitalRead(sensor);
  Serial.println(sensorval);
  
  if (sensorval == HIGH) {
    digitalWrite(led, HIGH);
  }
  else {
    digitalWrite(led, LOW);
  }
   long duration, cm;
   pinMode(pingPin, OUTPUT);
   digitalWrite(pingPin, LOW);
   delayMicroseconds(2);
   digitalWrite(pingPin, HIGH);
   delayMicroseconds(10);
   digitalWrite(pingPin, LOW);
   pinMode(echoPin, INPUT);
   duration = pulseIn(echoPin, HIGH);
   
   cm = microsecondsToCentimeters(duration);
 
   
   Serial.print(cm);
   Serial.print("cm");
   Serial.println();
   delay(100);
   if (cm==50)
   {
    digitalWrite(buzzer,HIGH);
   }
   else
   {
    digitalWrite(buzzer,LOW);
   }
   
  
}
