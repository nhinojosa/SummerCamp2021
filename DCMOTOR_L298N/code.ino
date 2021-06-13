//Code Goes here
// C++ code
//

//const int ENABLE = 5;
const int INPUT1 = 2;
const int INPUT2 = 3;
void setup()
{
  //pinMode(ENABLE,OUTPUT);
  pinMode(INPUT1,OUTPUT);
  pinMode(INPUT2,OUTPUT);
}

void loop()
{
    //digitalWrite(ENABLE,HIGH);
    digitalWrite(INPUT1, LOW);
    digitalWrite(INPUT2, HIGH);
}
