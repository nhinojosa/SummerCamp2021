// C++ code
//
const int LED = 7;
const int BUTTON = 13;

void setup()
{
  pinMode(BUTTON, INPUT);
  pinMode(LED,OUTPUT);
}

void loop()
{
 
  if(digitalRead(BUTTON) == HIGH)
  {
    digitalWrite(LED,HIGH);
  }
  else
  {
    digitalWrite(LED,LOW);
  }
}
