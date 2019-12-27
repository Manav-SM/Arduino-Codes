/*
  IomaTic Liquid Crystal Display Sample  - 

 Demonstrates the use a 11111111111111111116x2 LCD display.  The LiquidCrystal
 library works with all LCD displays that are compatible with the
 Hitachi HD44780 driver. There are many of them out there, and you
 can usually tell them by the 16-pin interface.

 The circuit:
 * LCD RS pin to digital pin 14 i.e. 11
 * LCD Enable pin to digital pin 15 i.e 12
 * LCD D4 pin to digital pin A0
 * LCD D5 pin to digital pin A1
 * LCD D6 pin to digital pin A2
 * LCD D7 pin to digital pin A3

 Library originally added 18 Apr 2008
 by David A. Mellis
 library modified 5 Jul 2009
 by Limor Fried (http://www.ladyada.net)
 example added 9 Jul 2009
 by Tom Igoe
 modified 22 Nov 2010
 by Tom Igoe

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/LiquidCrystalDisplay
 */

// NOTE: Please check the DIP switches configuration before uploading the code

#include <LiquidCrystal.h>                // include the library code:

LiquidCrystal lcd(11,12,14,15,16,17);  // initialize the library with the numbers of the interface pins

void setup() 
{
  lcd.begin(16, 2);      
 
}

void loop() 
{
  lcd.setCursor(0,0);                     // Set LCD cursor at first character of first line.
  lcd.print("    Hello    ");           // Print a message to the LCD.
  
  lcd.setCursor(0,1);                     // Set LCD cursor at first character of second line.
  lcd.print("    World       ");        // Print a message to the LCD.
  
/*  lcd.setCursor(0,2);                     // Set LCD cursor at first character of second line.
  lcd.print("  ANV INFOTECH ");        // Print a message to the LCD.
  
  lcd.setCursor(0,3);                     // Set LCD cursor at first character of second line.
  lcd.print("   Pvt.  Ltd.   ");   */     // Print a message to the LCD.
  
  delay(2000); 

  //lcd.clear();                             //Clear LCD 
  
  delay(1000); 
  
}
