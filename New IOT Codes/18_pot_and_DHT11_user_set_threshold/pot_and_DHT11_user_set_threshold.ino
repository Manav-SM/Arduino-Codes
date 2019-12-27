#include<LiquidCrystal.h>

#include <SimpleDHT.h>

LiquidCrystal lcd (11,12,14,15,16,17);
String a;
int pinDHT11 = 6;      //DTH11 connected on Pin 12 i.e. B4 in IomaTic
int buzz=7;
SimpleDHT11 dht11;
const int analogPin = A4;
int LDRPin = A5;
char thr ;
int LDRvalue = 0;
  byte temperature = 0;
  byte humidity = 0;
  int err = SimpleDHTErrSuccess;
  int val;


void setup() {
  pinMode(6,OUTPUT);
   pinMode(7,OUTPUT);
  
  pinMode(A4,INPUT);// put your setup code here, to run once:
  Serial.begin(9600);
  lcd.begin(16,2);
  
  if (Serial.available() > 0)
  {
    thr = Serial.read();
  }
}

void loop() {
  // put your main code here, to run repeatedly:
 int analogValue = analogRead(analogPin); 
 val = analogRead(analogPin); 
 if(analogValue > thr)
 {
   LDRvalue=analogRead(LDRPin);
  if (val>thr)
   {
        
  if ((err = dht11.read(pinDHT11, &temperature, &humidity, NULL)) != SimpleDHTErrSuccess) {
  // Serial.print("Read DHT11 failed, err="); Serial.println(err);delay(1000);
    return;
  }
//    lcd.setCursor(0,1);                   //Set cursor at first character/coloumn of first line/row
    Serial.print("Val:");    //Print the message as metioned cursor location
    lcd.setCursor(0,0);
    lcd.print("val:");

    Serial.print((int)temperature);//Print the message as metioned cursor location
    Serial.print(" C, "); 
    lcd.print((int)temperature);
    lcd.print(" C, ");

    Serial.print((int)humidity); 
    Serial.print(" H\n ");
    
    lcd.print((int)humidity);
    lcd.print(" H ");
    if(temperature>25 && temperature<=28)
    {

      digitalWrite(7,HIGH);
      
      delay(2000);
      digitalWrite(7,LOW);
      delay(5000);
      
    }

    else if(temperature>=29)
    {

   digitalWrite(7,HIGH);
   }
   }
   }
 }
