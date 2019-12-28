
#include <LiquidCrystal.h>                // include the library code:

LiquidCrystal lcd(11,12,14,15,16,17);  // initialize the library with the numbers of the interface pins

char PhoneNo[]="+918976260275";
int sendStatus=0;

int Device_Status=0;
int current_status=0;

char Input[200];
char Longitude[100];
char Latitude[100];

String serialResponse = "";
String arr[22];

int cnt=0;


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
    lcd.print("Dial to Track........");       //Print the message as metioned cursor location

    Serial.begin(9600);                   //Initialize a serial communication with baud rate 9600
    delay(1000);

    Serial.print("AT+CGNSPWR=1\r\n");
    delay(2000);

    Serial.print("AT+CGNSSEQ=\"RMC\"\r\n");
    delay(2000);

    GetLocation();
    
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
        lcd.print("Getting Location....");        //Print the message as metioned cursor location

        GetLocation();        

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
        
        Serial.print("Tracked Location is: https://www.google.com/maps/search/?api=1&query="); //Test SMS Message Body to Send
        Serial.print(arr[3]);
        Serial.print(",");
        Serial.print(arr[4]);
        
        delay(500);
        Serial.println(char(26)); 
        
      }
    }
  delay(500);
}

void GetLocation()
{
   Serial.print("AT+CGNSINF\r\n");                   // OPERATOR
      
      if (Serial.find("+CGNSINF: "))                    // find operator name between two double quotes
          serialResponse = Serial.readStringUntil('\r\n');
          cnt=0;
          char buf[sizeof(Input)];
      { 
          serialResponse.toCharArray(buf, sizeof(buf));
          char *p = buf;
          char *str;
          while ((str = strtok_r(p, ",", &p)) != NULL)  // delimiter is the semicolon
             {
                Serial.println(str);
                arr[cnt]=str;
                cnt++;
             }

          lcd.clear();
          lcd.setCursor(0,0);                   //Set cursor at first character/coloumn of first line/row
          lcd.print("Lon:");
          lcd.print(arr[3]);                    //Print the message as metioned cursor location

          lcd.setCursor(0,1);                   //Set cursor at first character/coloumn of first line/row
          lcd.print("Lat:");
          lcd.print(arr[4]);                    //Print the message as metioned cursor location
      }  
}
