#include <LiquidCrystal.h>

const int trigPin = 12;
const int echoPin = 11;

const int RS = 9;
const int EN = 8;
const int DB4 = 4;
const int DB5 = 5;
const int DB6 = 6;
const int DB7 = 7;

LiquidCrystal lcd(RS, EN, DB4, DB5, DB6, DB7);

void setup()
{
  
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
