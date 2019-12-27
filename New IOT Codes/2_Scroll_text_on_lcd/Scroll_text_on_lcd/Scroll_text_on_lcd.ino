#include <LiquidCrystal.h>
LiquidCrystal lcd(11,12,14,15,16,17);

void setup()
{

  lcd.begin(16,2);
  /* try to keep this stationary*/
  lcd.setCursor(5,0);
  lcd.print("TEST STRING");

}

void loop()
{

  String myString = "Just a string";
  lcd.setCursor(16,1);
  lcd.print(myString);

  for (int scrollCounter = 0; scrollCounter < 28; scrollCounter++)
  {

    lcd.scrollDisplayLeft();

    delay(250);
  }

  lcd.clear();

}
