#include <Servo.h>

Servo myservo;

int pos = 0;
const int pingPin = 9; // Trigger Pin of Ultrasonic Sensor
const int echoPin = 8; // Echo Pin of Ultrasonic Sensor

void setup()
{
  myservo.attach(7);
  
  pinMode(pingPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  Serial.begin(9600);
  
}

void loop()
{
  int cm = 0;
  
  cm = sensor_front();
  
  if( cm < 40 )
  {
    pos = 90;    
    //delay(3000);
  }
  else
  {
    pos = 180;
    
    //delay(3000);
  }
  
  myservo.write(pos);
  delay(15);
  
}




int sensor_front()
{
   long duration,cm;
   
   digitalWrite(pingPin, LOW);
   delayMicroseconds(2);
  
   digitalWrite(pingPin, HIGH);
   delayMicroseconds(10);
   digitalWrite(pingPin, LOW);
   
   duration = pulseIn(echoPin, HIGH);
   //Serial.print(duration);
   cm = duration / 29 / 2;
   Serial.print(pos);
   Serial.print(" pos ");
   Serial.print(cm);
   Serial.print(" cm ");
   Serial.println();
   delay(100);
   return cm;
}
