#include <LiquidCrystal.h>                // include the library code:
LiquidCrystal lcd(11,12,14,15,16,17);  // initialize the library with the numbers of the interface pins

int current_status;
int DTMF_Code;
char c;

void setup() 
{
    pinMode(8,OUTPUT);                    //Set pin number 4 as digital out where relay 1 is connected
    pinMode(9,OUTPUT);                    //Set pin number 5 as digital out where relay 2 is connected
    pinMode(10,OUTPUT);                    //Set pin number 6 as digital out where relay 3 is connected
    
    pinMode(13,OUTPUT);                   //SIM808 wakeup connected on pin 13 in IomaTic board
    digitalWrite(13, HIGH);               //Initialize the SIM808 Module 
    delay(1000);
    digitalWrite(13, LOW);                //Sending wake up signal to SIM808 Module
    delay(1000);
    digitalWrite(13, HIGH);               //Keeping SIM808 in active/wakeup state
    delay(5000);
  
    lcd.begin(16, 2);                     //Initialize the LCD in 16x2 mode
    delay(1000);            
    lcd.setCursor(0,0);                   //Set cursor at first character/coloumn of first line/row
    lcd.print("     IomaTic        ");    //Print the message as metioned cursor location

    lcd.setCursor(0,1);                   //Set cursor at first character/coloumn of first line/row
    lcd.print("GSM DTMF Test....");       //Print the message as metioned cursor location

    Serial.begin(9600);                   //Initialize a serial communication with baud rate 9600
    delay(1000);

    Serial.println("AT");                 //Automatically answer call after 1 ring
    delay(300);
    Serial.println("ATS0=1");             //Automatically answer call after 1 ring
    delay(300);
    Serial.println("AT+DDET=1,1000,0,0"); //Activate DMTF decoding
    delay(300);

}

void loop() 
{   
    Serial.println("AT+CPAS");            //Phone activity status: 0= ready, 2= unknown, 3= ringing, 4= in call
    delay(100);
    if (Serial.find("+CPAS: "))           //Decode reply
    { 
      char c = Serial.read();             // gives ascii code for status number
      current_status = c - 48;            // return integer value of ascii code

      if (current_status == 0) 
      {
        lcd.setCursor(0,1);                   //Set cursor at first character/coloumn of first line/row
        lcd.print("Waiting For Call...");     //Print the message as metioned cursor location
      }

      if (current_status == 3) 
      {
        lcd.setCursor(0,1);                   //Set cursor at first character/coloumn of first line/row
        lcd.print("Ringing............");     //Print the message as metioned cursor location
        delay(3000);
      }

      if (current_status == 4) 
      {
        lcd.setCursor(0,1);                   //Set cursor at first character/coloumn of first line/row
        lcd.print("Call Received.......");     //Print the message as metioned cursor location

        if (Serial.find("+DTMF:")) 
        {
          DTMF_Code= Serial.parseInt();
          
          switch (DTMF_Code) 
          {
              case 1:                       
                digitalWrite(8, HIGH);
                lcd.setCursor(0,1);                  
                lcd.print("DTMF:1   R1:ON    ");     
                break;
              case 2:                       
                digitalWrite(8, LOW);
                lcd.setCursor(0,1);                  
                lcd.print("DTMF:2   R1:OFF    ");    
                break;
              case 3:                       
                digitalWrite(9, HIGH);
                lcd.setCursor(0,1);                  
                lcd.print("DTMF:3   R2:ON    ");     
                break;
              case 4:                       
                digitalWrite(9, LOW);
                lcd.setCursor(0,1);                  
                lcd.print("DTMF:4  R2:OFF    ");    
                break;
              case 5:                       
                digitalWrite(10, HIGH);
                lcd.setCursor(0,1);                  
                lcd.print("DTMF:5  R3:ON    ");     
                break;
              case 6:                       
                digitalWrite(10, LOW);
                lcd.setCursor(0,1);                  
                lcd.print("DTMF:6  R1:OFF    ");    
                break;
           }
        } 
        delay(100);
      }
    }
  delay(500);
}
