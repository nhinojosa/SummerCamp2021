// C++ code
//
void setup()
{
  pinMode(2, OUTPUT); //R1
  pinMode(3, OUTPUT); //R2
  pinMode(4, OUTPUT); //L1
  pinMode(5, OUTPUT); //L2
  Serial.begin(9600);
}

void loop()
{
  int inches;
  
  inches = sensor_front();
  
  //left();
  
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
    digitalWrite(2, LOW);
    digitalWrite(3, HIGH);
  
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
}

void right()
{
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
  
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
}

void left()
{
    digitalWrite(2, LOW);
    digitalWrite(3, HIGH);
  
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
}

const int pingPin = 7; // Trigger Pin of Ultrasonic Sensor
const int echoPin = 6; // Echo Pin of Ultrasonic Sensor

int sensor_front()
{
   long duration, inches, cm;
   pinMode(pingPin, OUTPUT);
   digitalWrite(pingPin, LOW);
   delayMicroseconds(2);
   digitalWrite(pingPin, HIGH);
   delayMicroseconds(10);
   digitalWrite(pingPin, LOW);
   pinMode(echoPin, INPUT);
   duration = pulseIn(echoPin, HIGH);
   inches = microsecondsToInches(duration);
   Serial.print(inches);
   Serial.print("in ");
   Serial.println();
   delay(100);
   return inches;
}

long microsecondsToInches(long microseconds) {
   return microseconds / 74 / 2;
}
