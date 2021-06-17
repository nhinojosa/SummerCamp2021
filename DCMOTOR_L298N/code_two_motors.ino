//Code Goes here
// C++ code
//

//const int ENABLE = 5;
const int INPUT1 = 2;
const int INPUT2 = 3;
const int INPUT3 = 4;
const int INPUT4 = 5;
void setup()
{
  //pinMode(ENABLE,OUTPUT);
  pinMode(INPUT1,OUTPUT);
  pinMode(INPUT2,OUTPUT);
  pinMode(INPUT3,OUTPUT);
  pinMode(INPUT4,OUTPUT);
}

void loop()
{
    //digitalWrite(ENABLE,HIGH);
    digitalWrite(INPUT1, HIGH);
    digitalWrite(INPUT2, LOW);
    
    digitalWrite(INPUT3, HIGH);
    digitalWrite(INPUT4, LOW);
}
