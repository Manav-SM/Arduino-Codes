
#include <LiquidCrystal.h>                // include the library code:
#include <SimpleDHT.h>

int pinDHT11 = 6;      //DTH11 connected on Pin 12 i.e. B4 in IomaTic
SimpleDHT11 dht11;

LiquidCrystal lcd(11,12,14,15,16,17);  // initialize the library with the numbers of the interface pins

char PhoneNo[]="+917741041050";
int sendStatus=0;

void setup() 
{
    pinMode(13,OUTPUT);                   //SIM808 wakeup connected on pin 13 in IomaTic board
    digitalWrite(13, HIGH);               //Initialize the SIM808 Module 
    delay(1000);
    digitalWrite(13, LOW);                //Sending wake up signal to SIM808 Module
    delay(1000);
    digitalWrite(13, HIGH);               //Keeping SIM808 in active/wakeup state
    delay(10000);
    
    lcd.begin(16, 2);                     //Initialize the LCD in 16x2 mode
    delay(1000);            
    lcd.setCursor(0,0);                   //Set cursor at first character/coloumn of first line/row
    lcd.print("     IomaTic        ");    //Print the message as metioned cursor location

    Serial.begin(9600);                   //Initialize a serial communication with baud rate 9600
    delay(1000);

    pinMode(8, OUTPUT);               //Keeping SIM808 in active/wakeup state
}

void loop() 
{   
 
  byte temperature = 0;
  byte humidity = 0;
  int err = SimpleDHTErrSuccess;
  if ((err = dht11.read(pinDHT11, &temperature, &humidity, NULL)) != SimpleDHTErrSuccess) 
  {
    Serial.print("Read DHT11 failed, err="); Serial.println(err);delay(1000);
    return;
  }
  
    lcd.setCursor(0,1);                   //Set cursor at first character/coloumn of first line/row
    lcd.print("Val:");       //Print the message as metioned cursor location

    lcd.print((int)temperature);
    lcd.print(" *C, ");       //Print the message as metioned cursor location

      lcd.print((int)humidity); 
      lcd.print(" H");
      
    delay(500);

    if ((int)temperature>=26)
    {
      if(sendStatus==0)
      {

      digitalWrite(4,HIGH);
      lcd.print(" H"); 

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
      Serial.print("Temperature is High: "); //Test SMS Message Body to Send
      Serial.print((int)temperature);
      delay(500);
      Serial.println(char(26)); 

      sendStatus=1;
      }
    }
    else
    {
      lcd.print(" L"); 
      sendStatus=0;
      digitalWrite(8,LOW);
    }
   /*if(temp
    {
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
      Serial.print("IomaTic Send SMS Test...."); //Test SMS Message Body to Send
      delay(500);
      Serial.println(char(26)); 
    }*/
}
   
