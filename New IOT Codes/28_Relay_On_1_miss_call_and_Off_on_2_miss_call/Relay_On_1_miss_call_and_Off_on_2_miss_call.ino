

#include <LiquidCrystal.h>                // include the library code
LiquidCrystal lcd(11,12,14,15,16,17);  // initialize the library with the numbers of the interface pins

char PhoneNo[]="+917741041050";
int sendStatus=0;

int Device_Status=0;
int current_status=0;

void setup() 
{
    pinMode(8,OUTPUT);                    //Set pin number 4 as digital out where relay 1 is connected
 
    pinMode(13,OUTPUT);                   //SIM808 wakeup connected on pin 13 in IomaTic board
    digitalWrite(13, HIGH);               //Initialize the SIM808 Module 
    delay(1000);
    digitalWrite(13, LOW);                //Sending wake up signal to SIM808 Module
    delay(1000);
    digitalWrite(13, HIGH);               //Keeping SIM808 in active/wakeup state
    delay(1000);
    
    lcd.begin(16, 2);                     //Initialize the LCD in 16x2 mode
    delay(1000);            
    lcd.setCursor(0,0);                   //Set cursor at first character/coloumn of first line/row
    lcd.print("     IomaTic        ");    //Print the message as metioned cursor location

    lcd.setCursor(0,1);                   //Set cursor at first character/coloumn of first line/row
    lcd.print("Dial to ON OFF........");       //Print the message as metioned cursor location

    Serial.begin(9600);                   //Initialize a serial communication with baud rate 9600
    delay(1000);
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
        delay(4000);
                
        Serial.println("ATH");                 //Automatically answer call after 1 ring
        delay(300);

        lcd.setCursor(0,1);                   //Set cursor at first character/coloumn of first line/row
        lcd.print("Triggering SMS....");        //Print the message as metioned cursor location

        Serial.begin(9600);                   //Initialize a serial communication with baud rate 9600
        delay(1000);
        Serial.println("AT+CMGF=1");          //Initialize the GSM modem
        delay(2000);
        Serial.print("AT+CMGS=\"");           //Send dial a phone AT command
        Serial.print(PhoneNo);                //Send SMS receiver's phone number
        Serial.write(0x22);                   //Hex code equivalent to "
        Serial.write(0x0D);                   //Hex code equivalent to carraige return i.e. \r
        Serial.write(0x0A);                   //Hex code equivalent to new line char i.e. \n
        delay(2000);
        
        /* if(Device_Status==0)
        {
           if(digitalWrite(8,HIGH))
          {
            
        Serial.print("Device Shutdown Sucessfully: "); //Test SMS Message Body to Send
        digitalWrite(8,LOW);
          }
          else if(digitalWrite(8,LOW))
          {
            Serial.print("Device Shutdown Sucessfully: "); //Test SMS Message Body to Send
        digitalWrite(8,HIGH);
          }
       // Serial.print("Device Started Sucessfully: "); //Test SMS Message Body to Send
        //digitalWrite(8,HIGH);
        //Device_Status=1;
        }*/
      /* if(Device_Status==0)
        {
        Serial.print("Device Shutdown Sucessfully: "); //Test SMS Message Body to Send
        digitalWrite(8,LOW);
        Device_Status=0;       
        }*/
        if(Device_Status==0)
        {
        Serial.print("Device Started Sucessfully: "); //Test SMS Message Body to Send
        digitalWrite(8,HIGH);
        Device_Status=1;
          
        }else if(Device_Status==1)
        {
          Serial.print("Device Shutdown Sucessfully: "); //Test SMS Message Body to Send
        digitalWrite(8,LOW);
        Device_Status=0;
        }
        delay(500);
        Serial.println(char(26));  
      }
    }
  delay(500);
}
