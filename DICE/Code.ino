int randNumber;
// variable to hold the value of the switch pin
int switchState = 0;

// variable to hold previous value of the switch pin
int prevSwitchState = 0;

void setup()
{
  randomSeed(analogRead(0));
  Serial.begin(9600);
  pinMode(13, INPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
}

void loop()
{
  switchState = digitalRead(13);
  //Serial.println(switchState);
  
  if (switchState != prevSwitchState) 
  {
    if( switchState == LOW )
    {
      randNumber = random(1,7);
      Serial.println(randNumber);
      
      switch(randNumber)
      {
        case 1:
        	digitalWrite(2, HIGH);
  			digitalWrite(3, LOW);
  			digitalWrite(4, LOW);
  			digitalWrite(5, LOW);
  			digitalWrite(6, LOW);
  			digitalWrite(7, LOW);
        break;
        
        case 2:
        	digitalWrite(2, HIGH);
  			digitalWrite(3, HIGH);
  			digitalWrite(4, LOW);
  			digitalWrite(5, LOW);
  			digitalWrite(6, LOW);
  			digitalWrite(7, LOW);
        break;
        
        case 3:
        	digitalWrite(2, HIGH);
  			digitalWrite(3, HIGH);
  			digitalWrite(4, HIGH);
  			digitalWrite(5, LOW);
  			digitalWrite(6, LOW);
  			digitalWrite(7, LOW);
        break;
        
        case 4:
        	digitalWrite(2, HIGH);
  			digitalWrite(3, HIGH);
  			digitalWrite(4, HIGH);
  			digitalWrite(5, HIGH);
  			digitalWrite(6, LOW);
  			digitalWrite(7, LOW);
        break;
        
        case 5:
        	digitalWrite(2, HIGH);
  			digitalWrite(3, HIGH);
  			digitalWrite(4, HIGH);
  			digitalWrite(5, HIGH);
  			digitalWrite(6, HIGH);
  			digitalWrite(7, LOW);
        break;
        
      	case 6:
        	digitalWrite(2, HIGH);
  			digitalWrite(3, HIGH);
  			digitalWrite(4, HIGH);
  			digitalWrite(5, HIGH);
  			digitalWrite(6, HIGH);
  			digitalWrite(7, HIGH);
        break;
      }
      
    }
  }
  
  prevSwitchState = switchState;
  
}
