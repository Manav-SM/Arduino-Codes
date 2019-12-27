
#include <LiquidCrystal.h>                // include the library code:

LiquidCrystal lcd(11,12,14,15,16,17);  // initialize the library with the numbers of the interface pins

int signal_level;
char network_name[10] = "";
char c;

//Variable to hold last line of serial output from SIM800
char currentLine[500] = "";
int currentLineIndex = 0;
 
//Boolean to be set to true if message notificaion was found and next
//line of serial output is the actual SMS message content
bool nextLineIsMessage = false;

int OverRide=0;

void setup() 
{
    pinMode(8,OUTPUT);                    //Set pin number 4 as digital out where relay 1 is connected
    pinMode(9,OUTPUT);                    //Set pin number 5 as digital out where relay 2 is connected
    pinMode(10,OUTPUT);                    //Set pin number 6 as digital out where relay 3 is connected
  
    pinMode(13,OUTPUT);              //SIM808 wakeup connected on pin 13 in IomaTic board
    digitalWrite(13, HIGH);          //Initialize the SIM808 Module 
    delay(1000);
    digitalWrite(13, LOW);           //Sending wake up signal to SIM808 Module
    delay(1000);
    digitalWrite(13, HIGH);          //Keeping SIM808 in active/wakeup state
    delay(5000);

    
  
    lcd.begin(16, 2);                     //Initialize the LCD in 16x2 mode
    delay(1000);            
    lcd.setCursor(0,0);                   //Set cursor at first character/coloumn of first line/row
    lcd.print("     IomaTic        ");    //Print the message as metioned cursor location

    lcd.setCursor(0,1);                   //Set cursor at first character/coloumn of first line/row
    lcd.print("GSM Modem Test....");     //Print the message as metioned cursor location

    Serial.begin(9600);                   //Initialize a serial communication with baud rate 9600
    delay(1000);

    Serial.println("AT");                 //check if sim800 module responds
    delay(100);
    if (Serial.find("OK")) 
    {
      lcd.setCursor(0,1);               //Set cursor at first character/coloumn of first line/row
      lcd.print("Modem OK............");        //Print the message as metioned cursor location
    }
    else
    {
      lcd.setCursor(0,1);               //Set cursor at first character/coloumn of first line/row
      lcd.print("Modem Not OK........");        //Print the message as metioned cursor location
    }
    
    delay(2000);                        // wait for sim800 to settle a bit

    Serial.println("AT+CSMINS?"); // check if SIM card inserted
    delay(300);
    if (Serial.find("CSMINS: 0,0")) 
    {
      lcd.setCursor(0,1);               //Set cursor at first character/coloumn of first line/row
      lcd.print("SIM Card Not OK....    ");        //Print the message as metioned cursor location
    }
    else
    {
      lcd.setCursor(0,1);               //Set cursor at first character/coloumn of first line/row
      lcd.print("SIM Card OK....");        //Print the message as metioned cursor location
    }

    delay(2000);                        // wait for sim800 to settle a bit

    Serial.println("AT+CSMINS?"); // check if SIM card inserted
    delay(300);
    if (Serial.find("CSMINS: 0,0")) 
    {
      lcd.setCursor(0,1);               //Set cursor at first character/coloumn of first line/row
      lcd.print("SIM Card Not OK....    ");        //Print the message as metioned cursor location
    }
    else
    {
      lcd.setCursor(0,1);               //Set cursor at first character/coloumn of first line/row
      lcd.print("SIM Card OK....");        //Print the message as metioned cursor location
    }

    Serial.println("AT+CSQ");         // SIGNAL STRENGTH
    delay(100);
    if (Serial.find(":")) 
    { 
      signal_level = Serial.parseInt();
      
      lcd.setCursor(0,1);               //Set cursor at first character/coloumn of first line/row
      
    
      if(signal_level==0) lcd.print("Network: Poor      ");       
      if(signal_level==1) lcd.print("Network: Average      ");       
      if(signal_level>=2 && signal_level<=30 ) lcd.print("Network: Good        ");       
      if(signal_level==31) lcd.print("Network: Excellent      ");       
      if(signal_level==99) lcd.print("Network: Unknown      ");       
    }
    else
    {
        lcd.setCursor(0,1);               //Set cursor at first character/coloumn of first line/row
        lcd.print("No Network.......");        //Print the message as metioned cursor location
    }

    delay(2000);

      Serial.println("AT+COPS?");       // OPERATOR
      delay(100);
      if (Serial.find("\""))            // find operator name between two double quotes
      { 
        c = Serial.read();
        int u = 0;
        while (c != '"' && u < 10) 
          {
          network_name[u] = c;
          c = Serial.read();
          u++;
          }
       lcd.setCursor(0,1);               //Set cursor at first character/coloumn of first line/row
       lcd.print("Operator:");
       lcd.print(network_name);
      }
    
     
     
     
     Serial.print("AT+CGSN?");
     delay(100);
     if(Serial.find("\""))
     {
     
       lcd.setCursor(0,1);               //Set cursor at first character/coloumn of first line/row
       lcd.print("IMEI:");
       lcd.print(":");
      }

      
     // configure modem - remember! modem didn't remeber Your's configuration!
     Serial.print("AT+CMGF=1\r\n"); // use full functionality (calls, sms, gprs) - see app note
     delay(1000);
     Serial.print("AT+CLIP=1\r\n"); // enable presentation number
     delay(1000);
     Serial.print("AT+CSCS=\"GSM\"\r\n"); // configure sms as standard text messages
     delay(1000);
     Serial.print("AT+CNMI=1,2,0,0,0\r"); // show received sms and store in sim (probobly, I don't compre this settings with app note but it's working :)
     delay(1000);  
         
}

void loop()
{
  if(Serial.available()){
    char lastCharRead = Serial.read();
    //Read each character from serial output until \r or \n is reached (which denotes end of line)
    if(lastCharRead == '\r' || lastCharRead == '\n'){
        String lastLine = String(currentLine);
         
        //If last line read +CMT, New SMS Message Indications was received.
        //Hence, next line is the message content.
        if(lastLine.startsWith("+CMT:")){
           
          Serial.println(lastLine);
          nextLineIsMessage = true;
           
        } else if (lastLine.length() > 0) {
           
          if(nextLineIsMessage) {
            Serial.println(lastLine);
             
            //Read message content and set status according to SMS content
            if(lastLine.indexOf("RELAY 1 ON") >= 0){
              lcd.setCursor(0,1);               //Set cursor at first character/coloumn of first line/row
              lcd.print("RELAY 1 ON.......");
              digitalWrite(8,HIGH);
            }
            else if(lastLine.indexOf("RELAY 1 OFF") >= 0) {
              lcd.setCursor(0,1);               //Set cursor at first character/coloumn of first line/row
              lcd.print("RELAY 1 OFF.......");
              digitalWrite(8,LOW);
            }
            else if(lastLine.indexOf("RELAY 2 ON") >= 0) {
              lcd.setCursor(0,1);               //Set cursor at first character/coloumn of first line/row
              lcd.print("RELAY 2 ON.......");
              digitalWrite(9,HIGH);
            }
            else if(lastLine.indexOf("RELAY 2 OFF") >= 0) {
              lcd.setCursor(0,1);               //Set cursor at first character/coloumn of first line/row
              lcd.print("RELAY 2 OFF.......");
              digitalWrite(9,LOW);
            }
            else if(lastLine.indexOf("RELAY 3 ON") >= 0) {
              lcd.setCursor(0,1);               //Set cursor at first character/coloumn of first line/row
              lcd.print("RELAY 3 ON.......");
              digitalWrite(10,HIGH);
            }
            else if(lastLine.indexOf("RELAY 3 OFF") >= 0) {
              lcd.setCursor(0,1);               //Set cursor at first character/coloumn of first line/row
              lcd.print("RELAY 3 OFF.......");
              digitalWrite(10,LOW);
            }
           
             
            nextLineIsMessage = false;
          }
           
        }
         
        //Clear char array for next line of read
        for( int i = 0; i < sizeof(currentLine);  ++i ) {
         currentLine[i] = (char)0;
        }
        currentLineIndex = 0;
    } else {
      currentLine[currentLineIndex++] = lastCharRead;
    }
  }

}


//String gsmAnswer(){
//   String answer;
//   while(!gsm.available());
//   while(gsm.available()){
//     delay(5);
//     if(Serial.available() > 0){
//       char s = (char)gsm.read();
//       answer += s;
//     }
//  }
//  return answer;
//}
