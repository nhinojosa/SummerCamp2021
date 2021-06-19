#include <Servo.h>


const int pingPin = 12; // Trigger Pin of Ultrasonic Sensor
const int echoPin = 11; // Echo Pin of Ultrasonic Sensor
const int servoPin = 13;
const int LeftMotorForward = 9;
const int LeftMotorBackward = 8;
const int RightMotorForward = 7;
const int RightMotorBackward = 6;
int distance = 100;
Servo myservo;
void setup()
{
  pinMode(10,OUTPUT);
  pinMode(3, OUTPUT);
  digitalWrite(10,HIGH);
  digitalWrite(3,HIGH);
  
  pinMode(LeftMotorForward, OUTPUT); 
  pinMode(LeftMotorBackward, OUTPUT); 
  pinMode(RightMotorForward, OUTPUT); 
  pinMode(RightMotorBackward, OUTPUT);
  
  Serial.begin(9600);
  
  pinMode(pingPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  
  myservo.attach(servoPin);
  myservo.write(115);
}

void loop()
{
  int distanceRight = 0;
  int distanceLeft = 0;
  delay(50);
  
  distance = sensor_front();
  
  if( distance <= 20 )
  {
    Serial.println("object detected");
    stop();
    delay(1000);
    back();
    delay(1000);
    stop();
    distanceRight = lookRight();
    delay(300);
    distanceLeft = lookLeft();
    delay(300);
    
    if(distance >= distanceLeft)
    {
      right();
      stop();
    }
    else
    {
      left();
      stop();
    }
  }
  else
  {
    forward();
  }
  distance = sensor_front();
  
}

void stop()
{
  	Serial.println("I stopped");
    digitalWrite(LeftMotorForward, LOW);
  	digitalWrite(LeftMotorBackward, LOW);
  
    digitalWrite(RightMotorForward, LOW);
    digitalWrite(RightMotorBackward, LOW);
}

void forward()
{
    Serial.println("I moving forward");
    digitalWrite(LeftMotorForward, HIGH);
  	digitalWrite(LeftMotorBackward, LOW);
  
    digitalWrite(RightMotorForward, LOW);
    digitalWrite(RightMotorBackward, HIGH);
}

void back()
{
    Serial.println("I am moving back");
    digitalWrite(LeftMotorForward, LOW);
  	digitalWrite(LeftMotorBackward, HIGH);
  
    digitalWrite(RightMotorForward, HIGH);
    digitalWrite(RightMotorBackward, LOW);
}

void right()
{
    Serial.println("I am turning right");
    digitalWrite(LeftMotorForward, LOW);
  	digitalWrite(LeftMotorBackward, LOW);
  
    digitalWrite(RightMotorForward, LOW);
    digitalWrite(RightMotorBackward, HIGH);
}

void left()
{
    Serial.println("I am turning left");
    digitalWrite(LeftMotorForward, HIGH);
  	digitalWrite(LeftMotorBackward, LOW);
  
    digitalWrite(RightMotorForward, LOW);
    digitalWrite(RightMotorBackward, LOW);
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
  
   cm = duration * 0.034 / 2;
   Serial.print(cm);
   Serial.print(" cm ");
   Serial.println();
   delay(100);
   return cm;
}

int lookRight(){ 
  Serial.println("I am looking to the right");
  myservo.write(50);
  delay(500);
  int distance = sensor_front();
  delay(100);
  myservo.write(115);
  return distance;
}

int lookLeft(){
  Serial.println("I am looking to the left");
  myservo.write(170);
  delay(500);
  int distance = sensor_front();
  delay(100);
  myservo.write(115);
  return distance;
  delay(100);
}
