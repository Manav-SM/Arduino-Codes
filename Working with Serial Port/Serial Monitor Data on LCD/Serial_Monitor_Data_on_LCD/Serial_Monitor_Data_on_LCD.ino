// including LCD Library
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(11, 12, 14, 15, 16, 17);

void setup()
{
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  Serial.begin(9600);
}

void loop()
{
  if(Serial.available())
  {
    delay(200);
    lcd.clear();
    while(Serial.available() > 0)
    {
      lcd.write(Serial.read());
    }
  } 
}
