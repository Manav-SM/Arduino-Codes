#include <SimpleDHT.h>
String a;
int pinDHT11 = 6;      //DTH11 connected on Pin 12 i.e. B4 in IomaTic
SimpleDHT11 dht11;
int analogpin=A4;
float val = 0;  
int buzz=7;


void setup() {
  // put your setup code here, to run once:
  pinMode(7,OUTPUT);
  pinMode(6,OUTPUT);
 
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
 byte temperature = 0;
  byte humidity = 0;
  int err = SimpleDHTErrSuccess;
  val = analogRead(analogpin); 
  if ((err = dht11.read(pinDHT11, &temperature, &humidity, NULL)) != SimpleDHTErrSuccess) {
  // Serial.print("Read DHT11 failed, err="); Serial.println(err);delay(1000);
    return;
  }
//    lcd.setCursor(0,1);                   //Set cursor at first character/coloumn of first line/row
    Serial.print("Val:");       //Print the message as metioned cursor location

    Serial.print((int)temperature);
    Serial.print(" C, ");       //Print the message as metioned cursor location

    Serial.print((int)humidity); 
    Serial.print(" H");
    //a = a+temperature+","+humidity+",";
Serial.println(a);
  // delay(500);

  if(temperature>24)
   {
    if(val>100)
    {
      digitalWrite(buzz,HIGH);
      Serial.print("buzz on\n");
   }
   else{
    digitalWrite(buzz,LOW);
      Serial.print("buzz off\n");
   }
   }
   else
   {
    digitalWrite(buzz,LOW);
     Serial.print("buzz off\n");
   }  
}