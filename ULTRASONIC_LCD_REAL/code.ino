#include <LiquidCrystal_PCF8574.h>

const int trigPin = 12;
const int echoPin = 11;

LiquidCrystal_PCF8574 lcd(0x27); // set the LCD address to 0x27 for a 16 chars and 2 line display

void setup()
{
  lcd.setBacklight(255);  
  lcd.begin(16, 2);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);


}

void loop()
{
    double duration, in, cm;
  //lcd.clear();
    digitalWrite(trigPin,LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin,HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    
    duration = pulseIn(echoPin, HIGH);
    in = duration / 74 / 2;
    cm = duration / 29 / 2;
  
    lcd.setCursor(0, 0);
    lcd.print("Inches: ");
    lcd.print(in);
    lcd.setCursor(0,1);
    lcd.print("Cent: ");
    lcd.print(cm);
    delay(500);
}
