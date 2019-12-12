// include the library code:
#include <LiquidCrystal.h>
#include <SimpleDHT.h>

//DTH11 connected on pin D6 in IomaTic
int pinDHT11 = 6;     
SimpleDHT11 dht11;

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(11,12,14,15,16,17);  

void setup() 
{
    //Initialize the LCD in 16x2 mode
    lcd.begin(16, 2);                     
    delay(1000);            
    //Set cursor at first character/coloumn of first line/row
    lcd.setCursor(0,0);                   
    //Print the message as metioned cursor location
    lcd.print("     IomaTic    ");    
    //Initialize a serial communication with baud rate 9600
    Serial.begin(9600);                   
    delay(1000);

}

void loop() 
{   
  byte temperature = 0;
  byte humidity = 0;
  int err = SimpleDHTErrSuccess;
  if ((err = dht11.read(pinDHT11, &temperature, &humidity, NULL)) != SimpleDHTErrSuccess) 
{
    //Serial.print("Read DHT11 failed, err="); Serial.println(err);delay(1000);
    return;
  }
    //Set cursor at first character/coloumn of first line/row
    lcd.setCursor(0,1);      
    //Print the message as metioned cursor location             
    lcd.print("Val:");       
    lcd.print((int)temperature);
    lcd.print(" *C, ");      
    lcd.print((int)humidity); 
    lcd.print(" H");

    delay(500);
}
