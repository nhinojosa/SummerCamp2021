#include <LiquidCrystal_PCF8574.h>


const int LEFT_TRIG = 13;
const int FRONT_TRIG = 12;
const int RIGHT_TRIG = 11;

const int LEFT_ECHO = 10;
const int RIGHT_ECHO = 8;
const int FRONT_ECHO = 9;


LiquidCrystal_PCF8574 lcd(0x27); // set the LCD address to 0x27 for a 16 chars and 2 line display

void setup()
{
  Serial.begin(9600);
  pinMode(LEFT_TRIG,OUTPUT);
  pinMode(RIGHT_TRIG,OUTPUT);
  pinMode(FRONT_TRIG,OUTPUT);
  pinMode(LEFT_ECHO, INPUT);
  pinMode(RIGHT_ECHO, INPUT);
  pinMode(FRONT_ECHO, INPUT);
  lcd.setBacklight(255);  
  lcd.begin(16,2);
  lcd.clear();
}

void loop()
{
  lcd.setCursor(0, 0);
  double left_distance = 100, right_distance = 100, front_distance = 100;
  left_distance = ping(LEFT_TRIG, LEFT_ECHO);
  right_distance = ping(RIGHT_TRIG, RIGHT_ECHO);
  front_distance = ping(FRONT_TRIG, FRONT_ECHO);
  
  if(left_distance < 3)
  {
    Serial.print("LEFT: ");
    Serial.print(left_distance);
    Serial.println();
    lcd.print("Keep 6ft left!");
  }
  else if(right_distance < 3)
  {
    Serial.print("RIGHT: ");
    Serial.print(right_distance);
    Serial.println();
    lcd.print("Keep 6ft right!");
  }
  else if(front_distance < 3)
  {
    Serial.print("FRONT: ");
    Serial.print(front_distance);
    Serial.println();
    lcd.print("Keep 6ft front!");
  }
  else
  {
    Serial.println("Good Distance!");
    lcd.print("Good Distance!");
  }
  
  delay(1000);
  
}

double ping(int TRIG, int ECHO)
{
    double duration, in;
  digitalWrite(TRIG, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG, LOW);
    duration = pulseIn(ECHO, HIGH);

    in = duration / 74 / 2;

    delay(100);
  
    return in;
}
