

#include <LiquidCrystal.h>                // include the library code:
#include <SimpleDHT.h>
String a;
int pinDHT11 = 6;      //DTH11 connected on Pin 12 i.e. B4 in IomaTic
SimpleDHT11 dht11;
int buzzerpin=7;
LiquidCrystal lcd(11, 12, 14, 15, 16, 17);  // initiali+ze the library with the numbers of the interface pins

void setup() 
{
  pinMode(6,OUTPUT);
    lcd.begin(16, 2);                     //Initialize the LCD in 16x2 mode
    delay(1000);            
    lcd.setCursor(0,0);                   //Set cursor at first character/coloumn of first line/row
    lcd.print("     IomaTic        ");    //Print the message as metioned cursor location

    Serial.begin(9600);  
    //Initialize a serial communication with baud rate 9600
    delay(1000);

}

void loop() 
{  
  
  byte temperature = 0;
  byte humidity = 0;
  int err = SimpleDHTErrSuccess;
  if ((err = dht11.read(pinDHT11, &temperature, &humidity, NULL)) != SimpleDHTErrSuccess) {
  // Serial.print("Read DHT11 failed, err="); Serial.println(err);delay(1000);
    return;
  }
    lcd.setCursor(0,1);                   //Set cursor at first character/coloumn of first line/row
    lcd.print("Val:");       //Print the message as metioned cursor location

    lcd.print((int)temperature);
    lcd.print(" C, ");       //Print the message as metioned cursor location

    lcd.print((int)humidity); 
    lcd.print(" H");
    a = a+temperature+","+humidity+",";
Serial.println(a);
   delay(500);

   if(temperature>30)
   {
      digitalWrite(buzzerpin,HIGH);
   }
   else
   {
    digitalWrite(buzzerpin,LOW);
   }  
}
