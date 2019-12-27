  
#include <LiquidCrystal.h>                // include the library code:

LiquidCrystal lcd(11,12,14,15,16,17);  // initialize the library with the numbers of the interface pins

// variables will change:
int buttonState = 0; 

const int buttonPin = 2;     // the number of the pushbutton pin
const int buzzerPin =  7;      // the number of the LED pin

void setup() 
{
    pinMode(buzzerPin,OUTPUT);                    //Set pin number 4 as digital out where relay 1 is connected
    pinMode(buttonPin,INPUT_PULLUP);                     //Set pin number 5 as digital out where relay 2 is connected
    
    lcd.begin(16, 2);                     //Initialize the LCD in 16x2 mode
    delay(1000);            
    lcd.setCursor(0,0);                   //Set cursor at first character/coloumn of first line/row
    lcd.print("     Helloooooooo        ");    //Print the message as metioned cursor location
}

void loop() 
{   
    
    // read the state of the pushbutton value:
    buttonState = digitalRead(buttonPin);

    if(buttonState==LOW)
    {
      lcd.setCursor(0,1);     
      lcd.print("Input=H Buzz=ON ");
      digitalWrite(buzzerPin, HIGH);                //Write digital HIGH on pin 4 i.e. generating 5v at pin 4 where relay 1 is connected
    }
    else
    {
      lcd.setCursor(0,1);     
      lcd.print("Input=L Buzz=OFF");
      digitalWrite(buzzerPin, LOW);                 //Write digital HIGH on pin 4 i.e. generating 5v at pin 4 where relay 1 is connected
    }
    
    
}
