#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(11,12,14,15,16,17);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("hello, world!");
  
  Serial.begin(9600);
}

void loop() {
  if(Serial.available()){
    lcd.setCursor(0, 1);
    lcd.print(  "                "   );
    //delay(100);
    lcd.setCursor(0, 1);
    while(Serial.available() > 0){
      lcd.write(Serial.read( ));
      Serial.print("  ");
    }
  }
}
