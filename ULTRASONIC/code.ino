// C++ code
//
const int triggerPin = 12;
const int echoPin = 11;

void setup()
{
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
  Serial.print("Hello, I am WALL-E!");
  Serial.println();
}

void loop()
{
    double duration, cm, in;
	digitalWrite(triggerPin, LOW);
  	delayMicroseconds(2);
  	digitalWrite(triggerPin, HIGH);
    delayMicroseconds(10);
  	digitalWrite(triggerPin, LOW);
  	duration = pulseIn(echoPin, HIGH);
  	cm = duration / 29 / 2;
  	in = duration / 74 / 2;
    Serial.print( "Distance: ");
    Serial.print(in);
 	Serial.print(" IN/ ");
  	Serial.print(cm);
 	Serial.println(" CM");
  	delay(100);
    
}
