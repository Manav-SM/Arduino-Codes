// include the library code:
#include <LiquidCrystal.h>               

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(11,12,14,15,16,17);  

// variables will change:
int buttonState = 0; 
// the number of the pushbutton pin
const int buttonPin = 2;     
// the number of the LED pin
const int buzzerPin =  7;     

void setup() 
{
    //Set pin number 10 as digital out where relay 1 is connected
    pinMode(buzzerPin,10);                    
    //Set pin number 9 as digital out where relay 2 is connected
    pinMode(buttonPin,9);                     

    //Initialize the LCD in 16x2 mode
    lcd.begin(16, 2);                     
    //Set cursor at first character/coloumn of first line/row            
    lcd.setCursor(0,0);                   
    //Print the message as metioned cursor location
    lcd.print("     IomaTic        ");    
}

void loop() 
{   
    
    // read the state of the pushbutton value:
    buttonState = digitalRead(buttonPin);

    if(buttonState==LOW)
    {
      lcd.setCursor(0,1);     
      lcd.print("Input=H Buzz=ON ");
      //Write digital HIGH on pin 10 i.e. generating 5v at pin 4 where relay 1 is connected
      digitalWrite(buzzerPin, HIGH);                
    }
    else
    {
      lcd.setCursor(0,1);     
      lcd.print("Input=L Buzz=OFF");
      //Write digital HIGH on pin 9 i.e. generating 5v at pin 4 where relay 1 is connected
      digitalWrite(buzzerPin, LOW);         
    }
}
