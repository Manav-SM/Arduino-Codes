
// include the library code
#include <LiquidCrystal.h>                
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(11, 12, 14, 15, 16, 17);  

char PhoneNo[]="+918976260275";
int sendStatus=0;

int Device_Status=0;
int current_status=0;

void setup() 
{
    //Set pin number 10 as digital out where relay 1 is connected
    pinMode(10,OUTPUT);                    
    //SIM808 wakeup connected on pin 13 in IomaTic board
    pinMode(13,OUTPUT);                   
    //Initialize the SIM808 Module
    digitalWrite(13, HIGH);                
    delay(1000);
    //Sending wake up signal to SIM808 Module
    digitalWrite(13, LOW);                
    delay(1000);
    //Keeping SIM808 in active/wakeup state
    digitalWrite(13, HIGH);               
    delay(1000);
    //Initialize the LCD in 16x2 mode
    lcd.begin(16, 2);                     
    delay(1000);            
    //Set cursor at first character/coloumn of first line/row
    lcd.setCursor(0,0);                   
    //Print the message as metioned cursor location
    lcd.print("     IomaTic        ");    
    //Set cursor at first character/coloumn of first line/row
    lcd.setCursor(0,1);                   
    //Print the message as metioned cursor location
    lcd.print("Dial to ON OFF........");       

    //Initialize a serial communication with baud rate 9600
    Serial.begin(9600);                   
    delay(1000);
}

void loop() 
{ 
    //Phone activity status: 0= ready, 2= unknown, 3= ringing, 4= in call
    Serial.println("AT+CPAS");            
    delay(100);
    //Decode reply
    if (Serial.find("+CPAS: "))           
    { 
      // gives ascii code for status number
      char c = Serial.read();             
      // return integer value of ascii code
      current_status = c - 48;            

      if (current_status == 0) 
      {
        //Set cursor at first character/coloumn of first line/row
        lcd.setCursor(0,1);                   
        //Print the message as metioned cursor location
        lcd.print("Waiting For Call...");     
      }

      if (current_status == 3) 
      {
        //Set cursor at first character/coloumn of first line/row
        lcd.setCursor(0,1);                   
        //Print the message as metioned cursor location
        lcd.print("Ringing............");     
        delay(4000);

        //Automatically answer call after 1 ring
        Serial.println("ATH");                 
        delay(300);

        //Set cursor at first character/coloumn of first line/row
        lcd.setCursor(0,1);                   
        //Print the message as metioned cursor location
        lcd.print("Triggering SMS....");        

        //Initialize a serial communication with baud rate 9600
        Serial.begin(9600);                   
        delay(1000);
        //Initialize the GSM modem
        Serial.println("AT+CMGF=1");          
        delay(2000);
        //Send dial a phone AT command
        Serial.print("AT+CMGS=\"");           
        //Send SMS receiver's phone number
        Serial.print(PhoneNo);                
        //Hex code equivalent to "
        Serial.write(0x22);                   
        //Hex code equivalent to carraige return i.e. \r
        Serial.write(0x0D);                   
        //Hex code equivalent to new line char i.e. \n
        Serial.write(0x0A);                   
        delay(2000);
        
        if(Device_Status==0)
        {
        //Test SMS Message Body to Send
        Serial.print("Device Started Sucessfully: "); 
        digitalWrite(10,HIGH);
        Device_Status=1;
        }
        else
        {
        //Test SMS Message Body to Send
        Serial.print("Device Shutdown Sucessfully: "); 
        digitalWrite(10,LOW);
        Device_Status=0;       
        }
        
        delay(500);
        Serial.println(char(26));  
      }
    }
  delay(500);
}
