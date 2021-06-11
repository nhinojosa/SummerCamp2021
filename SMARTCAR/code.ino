// C++ code
//
const int pingPin = 7; // Trigger Pin of Ultrasonic Sensor
const int echoPin = 6; // Echo Pin of Ultrasonic Sensor

void setup()
{
  pinMode(2, OUTPUT); //R1
  pinMode(3, OUTPUT); //R2
  pinMode(4, OUTPUT); //L1
  pinMode(5, OUTPUT); //L2
  Serial.begin(9600);
  pinMode(pingPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop()
{
  int cm;
  
  cm = sensor_front();
  
  left();
  
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


