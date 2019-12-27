
#include <LiquidCrystal.h>
LiquidCrystal lcd(11,12, 14, 15, 16, 17);

void setup()
{
  lcd.begin(16, 2);
}

void loop()
{
  lcd.print("ANV INFOTECH");
  delay(500);
  lcd.clear();  //To Blink
  delay(500);
}
