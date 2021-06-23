#include <IRremote.h>

// C++ code

const int pingPin = 7; // Trigger Pin of Ultrasonic Sensor
const int echoPin = 6; // Echo Pin of Ultrasonic Sensor
const int irPin = 8;

IRrecv receiver(irPin); 
decode_results results;

void setup()
{
  pinMode(2, OUTPUT); //R1
  pinMode(3, OUTPUT); //R2
  pinMode(4, OUTPUT); //L1
  pinMode(5, OUTPUT); //L2
  Serial.begin(9600);
  pinMode(pingPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(irPin, INPUT);
  receiver.enableIRIn();
}

void loop()
{
  int cm;
  
  //cm = sensor_front();
  
  //find codes.
  if (receiver.decode(&results)) // decode the received signal and store it in results
  { 
    Serial.println(results.value, HEX); // print the values in the Serial Monitor
    receiver.resume(); // reset the receiver for the next code
  }
  
  if(results.value == 0xFD807F)
  {
    forward();
  }
  else if(results.value == 0xFDA05F)
  {
    stop();
  }
  else if(results.value == 0xFD906F)
  {
    backwards();
  }  
  else if(results.value == 0xFD20DF)
  {
    left();
  }
  else if(results.value == 0xFD609F)
  {
    right();
  }
}

void stop()
{
    digitalWrite(2, LOW);
  	digitalWrite(3, LOW);
  
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
}

void forward()
{
    digitalWrite(2, HIGH);
  	digitalWrite(3, LOW);
  
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);
}
void backwards()
{
    digitalWrite(2, LOW);
  	digitalWrite(3, HIGH);
  
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
}
void right()
{
    digitalWrite(2, LOW);
  	digitalWrite(3, LOW);
  
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);
}

void left()
{
    digitalWrite(2, HIGH);
  	digitalWrite(3, LOW);
  
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
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


