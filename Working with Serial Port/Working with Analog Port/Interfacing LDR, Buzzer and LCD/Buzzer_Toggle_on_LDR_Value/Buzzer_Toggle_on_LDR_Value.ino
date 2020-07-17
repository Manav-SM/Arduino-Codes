// including LCD Library
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(11,12, 14, 15, 16, 17);
// declaring ldr interface pins and input variable
int ldrPin = A5;

void setup()
{
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  lcd.clear();
  lcd.setCursor(0,0); // set the cursor to col 0 and row 0 of LCD
  // accept ldr input
  pinMode(ldrPin, INPUT);
  Serial.begin(9600);
}

void loop()
{
  int ldrStatus = analogRead(ldrPin);
  lcd.print("LDR Value:"); // prints LDR value to LCD
  lcd.print(ldrStatus); // prints value on variable: ldrStatus to LCD
  if(ldrStatus <= 1000)
  {
    digitalWrite(7, HIGH);// toggle buzzer high on ldr value less than or equal to 1000
    delay(1000);
  }
  else
  {
    digitalWrite(7, LOW);// toggle buzzer low on ldr value more than 1000
    delay(1000);
  }
}
