
const int ENABLE = 5;
const int INPUT1 = 4;
const int INPUT2 = 3;
void setup()
{
  pinMode(ENABLE,OUTPUT);
  pinMode(INPUT1,OUTPUT);
  pinMode(INPUT2,OUTPUT);
}

void loop()
{

  	analogWrite(ENABLE, 80);
	digitalWrite(INPUT1, LOW);
  	digitalWrite(INPUT2, HIGH);
}