
#include <LiquidCrystal.h>                // include the library code:

LiquidCrystal lcd(11,12,14,15,16,17);  // initialize the library with the numbers of the interface pins

int analogPin = A4;     // potentiometer wiper (middle terminal) connected to analog pin 3
                       // outside leads to ground and +5V
float val = 0;           // variable to store the value read

void setup()
{
    lcd.begin(16, 2);                     //Initialize the LCD in 16x2 mode
    delay(1000);            
    lcd.setCursor(0,0);                   //Set cursor at first character/coloumn of first line/row
    lcd.print("IomaTic : ADC   ");    //Print the message as metioned cursor location
}

void loop()
{
  val = analogRead(analogPin);    // read the input pin
  lcd.setCursor(0,1);                   //Set cursor at first character/coloumn of first line/row
  lcd.print("Moisture:");    //Print the message as metioned cursor location
  lcd.print(val);    //Print the message as metioned cursor location
  lcd.print("  ");    //Print the message as metioned cursor location
  delay(1000);
}
