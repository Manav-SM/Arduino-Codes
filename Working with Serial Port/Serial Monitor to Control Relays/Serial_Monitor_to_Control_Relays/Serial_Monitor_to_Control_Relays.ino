// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins 
LiquidCrystal lcd(11,12,14,15,16,17);

void setup()
{
  //Set pin number 10 as digital out where relay 1 is connected 
  pinMode(10,OUTPUT);
  //Set pin number 9 as digital out where relay 2 is connected 
  pinMode(9,OUTPUT);
  //Set pin number 8 as digital out where relay 3 is connected 
  pinMode(8,OUTPUT);
  //Initialize the LCD in 16x2 mode
  lcd.begin(16, 2);
  Serial.begin(9600);
}

void loop()
{
   if(Serial.available())
  {
    delay(200);
    lcd.clear();
    int inpval = Serial.parseInt();
    if(inpval == 1)
    {
      lcd.setCursor(1,1);
      lcd.print("RELAY 1 ON ");
      //Write digital HIGH on pin 10 i.e. generating 5v at pin 10 where relay 1 is connected 
      digitalWrite(10, HIGH);
      delay(2000);
      digitalWrite(10, LOW);
      delay(2000);
    }
    if(inpval == 2)
    {
      lcd.setCursor(1,1);
      lcd.print("RELAY 2 ON ");
      //Write digital HIGH on pin 9 i.e. generating 5v at pin 9 where relay 2 is connected 
      digitalWrite(9, HIGH);
      delay(2000);
      digitalWrite(9, LOW);
      delay(2000);
    }
    if(inpval == 3)
    {
      lcd.setCursor(1,1);
      lcd.print("RELAY 3 ON ");
      //Write digital HIGH on pin 8 i.e. generating 5v at pin 8 where relay 3 is connected 
      digitalWrite(8, HIGH);
      delay(2000);
      digitalWrite(8, LOW);
      delay(2000);
    }
  } 
}

