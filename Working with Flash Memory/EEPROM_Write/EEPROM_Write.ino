// including LCD Library
#include <LiquidCrystal.h>
#include <EEPROM.h>
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(11,12, 14, 15, 16, 17);
// declaring Potentiometer interface pins and input variable
int pot = A4;
int counter;
void setup()
{
// set up the LCD's number of columns and rows:
lcd.begin(16, 2);
lcd.setCursor(0,0);
lcd.print("EEPROM Write");
lcd.setCursor(0,1);
lcd.print("EEPROM: ");
lcd.print(analogRead(pot));

//lcd.clear();
// accept potentiometer input
pinMode(pot, INPUT);
counter = analogRead(pot);
EEPROM.write(0,counter);
}
void loop()
{
 
}
/*
void loop()
{
lcd.setCursor(0,0); // set the cursor to col 0 and row 0 of LCD
lcd.print("Pot Value:"); // prints potentiometer value to LCD
lcd.print(analogRead(pot)); // prints value on variable: pot to LCD
delay(10);
lcd.clear();
counter++;
EEPROM.write(0,counter);
Serial.print("Counter: ");
Serial.println(counter);
}
*/


/*void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}////////*/
