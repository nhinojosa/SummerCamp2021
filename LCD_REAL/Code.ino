#include <LiquidCrystal_PCF8574.h>


LiquidCrystal_PCF8574 lcd(0x27); // set the LCD address to 0x27 for a 16 chars and 2 line display

void setup()
{
  lcd.setBacklight(255);  
  lcd.begin(16,2);
  
  randomSeed(analogRead(0));
  int reply = random(8);
  lcd.clear();
  switch (reply) 
  {
        case 0:
          lcd.print("Yes");
          break;

        case 1:
          lcd.print("Most likely");
          break;

        case 2:
          lcd.print("Certainly");
          break;

        case 3:
          lcd.print("Outlook good");
          break;

        case 4:
          lcd.print("Unsure");
          break;

        case 5:
          lcd.print("Ask again");
          break;

        case 6:
          lcd.print("Doubtful");
          break;

        case 7:
          lcd.print("No");
          break;
   }

}


void loop()
{

}
