// include the library code:
#include <LiquidCrystal.h>                
#include <SimpleDHT.h>

//DTH11 connected on Pin 6 i.e. D6 in IomaTic
int pinDHT11 = 6;      
SimpleDHT11 dht11;

// initialize the library with the numbers of the interface pins


LiquidCrystal lcd(11, 12, 14, 15, 16, 17);  
char PhoneNo[]="+918976260275";
int sendStatus=0;

void setup() 
{
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
    delay(10000);

    //Initialize the LCD in 16x2 mode
    lcd.begin(16, 2);                     
    delay(1000);            
    //Set cursor at first character/coloumn of first line/row
    lcd.setCursor(0,0);                   
    //Print the message as metioned cursor location
    lcd.print("     IomaTic        ");    

    //Initialize a serial communication with baud rate 9600
    Serial.begin(9600);                   
    delay(1000);

    //Keeping SIM808 in active/wakeup state
    pinMode(4, OUTPUT);               
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

    //Set cursor at first character/coloumn of first line/row
    lcd.setCursor(0,1);      
    //Print the message as metioned cursor location             
    lcd.print("Val:");       

    lcd.print((int)temperature);
    //Print the message as metioned cursor location
    lcd.print(" *C, ");       

      lcd.print((int)humidity); 
      lcd.print(" H");
      
    delay(500);

    if ((int)temperature>=22)
    {
      if(sendStatus==0)
      {

      digitalWrite(4,HIGH);
      lcd.print(" H"); 

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
      //Test SMS Message Body to Send
      Serial.print("Temperature is High: "); 
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
      digitalWrite(4,LOW);
    }

//    if()
//    {
//      lcd.setCursor(0,1);                   //Set cursor at first character/coloumn of first line/row
//      lcd.print("Triggering SMS....");        //Print the message as metioned cursor location
//
//      Serial.begin(9600);                   //Initialize a serial communication with baud rate 9600
//      delay(1000);
//      Serial.println("AT+CMGF=1");          //Initialize the GSM modem
//      delay(2000);
//      Serial.print("AT+CMGS=\"");           //Send dial a phone AT command
//      Serial.print(PhoneNo);                //Send SMS receiver's phone number
//      Serial.write(0x22);                   //Hex code equivalent to "
//      Serial.write(0x0D);                   //Hex code equivalent to carraige return i.e. \r
//      Serial.write(0x0A);                   //Hex code equivalent to new line char i.e. \n
//      delay(2000);
//      Serial.print("IomaTic Send SMS Test...."); //Test SMS Message Body to Send
//      delay(500);
//      Serial.println(char(26)); 
//    }

    
}
