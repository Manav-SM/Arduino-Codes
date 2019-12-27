
#include <LiquidCrystal.h>                // include the library code:

LiquidCrystal lcd(11, 12, 14, 15, 16, 17);  // initialize the library with the numbers of the interface pins

//char PhoneNo[]="+917021237256";

void setup() 
{
    pinMode(13,OUTPUT);              //SIM808 wakeup connected on pin 13 in IomaTic board
    digitalWrite(13, HIGH);          //Initialize the SIM808 Module 
    delay(1000);
    digitalWrite(13, LOW);           //Sending wake up signal to SIM808 Module
    delay(1000);
    digitalWrite(13, HIGH);          //Keeping SIM808 in active/wakeup state
    delay(10000);
  
    lcd.begin(16, 2);                     //Initialize the LCD in 16x2 mode
    delay(1000);            
    lcd.setCursor(0,0);                   //Set cursor at first character/coloumn of first line/row
    lcd.print("Display Test");    //Print the message as metioned cursor location

    //lcd.setCursor(0,1);                   //Set cursor at first character/coloumn of first line/row
    //lcd.print("GSM Dial Test....");     //Print the message as metioned cursor location

    Serial.begin(9600);                   //Initialize a serial communication with baud rate 9600
    delay(1000);
    Serial.println("AT");                 //Initialize the GSM modem
    delay(200);
    //Serial.print("ATD");                 //Send dial a phone AT command
    //Serial.print(PhoneNo);              //Send phone number to dial
    //Serial.print("AT+CLIP=1");
    lcd.setCursor(0,1);
    lcd.print("AT+CLIP=[]");
    //Serial.print(";");
    //Serial.print("\r\n");
    delay(200);
    //Serial.println("ATH");                 //Hang up the call
}

void loop() 
{   
    //This is single task program hence nothing to do in loop,
    //everything will be executed in setup function only.
}
