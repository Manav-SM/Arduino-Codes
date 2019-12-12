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
    //SIM808 wakeup connected on pin 13 in IomaTic board
    pinMode(13,OUTPUT);                   
   
    lcd.setCursor(0,0);                   
    //Print the message as metioned cursor location
    lcd.print("     IomaTic        ");    
    //Set cursor at first character/coloumn of first line/row
    lcd.setCursor(0,1);                   
    //Print the message as metioned cursor location
    lcd.print("LED Test....");       
    //Initialize a serial communication with baud rate 9600
    Serial.begin(9600);                   
    delay(1000);

}

void loop() 
{   
    digitalWrite(10, HIGH);
    delay(500);
    digitalWrite(10, LOW);
    delay(500);
    digitalWrite(9, HIGH);
    delay(500);
    digitalWrite(9, LOW);
    delay(500);
    digitalWrite(8, HIGH);
    delay(500);
    digitalWrite(8, LOW);
    delay(500);
}
