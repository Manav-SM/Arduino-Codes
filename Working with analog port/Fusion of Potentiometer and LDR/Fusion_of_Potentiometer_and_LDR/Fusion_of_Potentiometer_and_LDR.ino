// including LCD Library
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(11,12, 14, 15, 16, 17);
// declaring Potentiometer and LDR interface pins and input variable
int pot = A4;
int LDR = A5;
int thresh = 800;

void setup()
{
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  lcd.clear();
  // accept potentiometer and LDR input
  pinMode(pot, INPUT);
  pinMode(LDR, INPUT);
}

void loop()
{
  lcd.setCursor(0,0); // set the cursor to col 0 and row 0 of LCD
  lcd.print("Pot Value:"); // prints potentiometer value to LCD
  lcd.print(analogRead(pot)); // prints value on variable: pot to LCD
  lcd.setCursor(0,1); // set the cursor to col 0 and row 1 of LCD
  lcd.print("LDR Value:"); // prints LDR value to LCD
  lcd.print(analogRead(LDR)); // prints value on variable: LDR to LCD
  if(LDR>pot)
  {
    digitalWrite(7, HIGH);
    delay(1000);
    //digitalWrite(7,LOW);
  }
  else
  {
    digitalWrite(7, LOW);
  }
}
