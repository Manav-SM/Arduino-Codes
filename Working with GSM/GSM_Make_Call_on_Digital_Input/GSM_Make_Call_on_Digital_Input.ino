
// include the library code:
#include <LiquidCrystal.h>                

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(11,12,14,15,16,17);  

// Phone number with country code like +915555555555
char PhoneNo[]="";
int DialStatus=0;

// variables will change:
int buttonState = 0; 

// the number of the pushbutton pin
const int buttonPin = 2;     

void setup() 
{
    pinMode(buttonPin,INPUT_PULLUP);

    //SIM800 wakeup connected on pin 13 in IomaTic board
    pinMode(13,OUTPUT);              
    //Initialize the SIM800 Module
    digitalWrite(13, HIGH);           
    delay(1000);
    //Sending wake up signal to SIM800 Module
    digitalWrite(13, LOW);           
    delay(1000);
    //Keeping SIM800 in active/wakeup state
    digitalWrite(13, HIGH);          
    delay(10000);

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
    lcd.print("GSM Dial on Input....");     

    //Initialize a serial communication with baud rate 9600
    Serial.begin(9600);                   
    delay(1000);
    
}

void loop() 
{   
    //This is single task program hence nothing to do in loop,
    //everything will be executed in setup function only.

    // read the state of the pushbutton value:
    buttonState = digitalRead(buttonPin);

    if(buttonState==LOW)
    {
       //Set cursor at first character/coloumn of first line/row
       lcd.setCursor(0,1);                   
       //Print the message as metioned cursor location
       lcd.print("Input State=HIGH   ....");     

        if(DialStatus==0)
        {
          //Initialize the GSM modem
          Serial.println("AT");                 
          delay(2000);
          //Send dial a phone AT command
          Serial.print("ATD");                
          //Send phone number to dial  
          Serial.print(PhoneNo);              
          Serial.print(";");
          Serial.print("\r\n");

          DialStatus=1;
        }  
       
    }
    else
    {
       //Set cursor at first character/coloumn of first line/row
       lcd.setCursor(0,1);                   
       //Print the message as metioned cursor location
       lcd.print("Input State=LOW   ....");       

       DialStatus=0;
    }
}
