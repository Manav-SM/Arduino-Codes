char inchar;
//int relay=8;
//int relay=9;
void setup()
{

    pinMode(8,OUTPUT);
    pinMode(9,OUTPUT);
    digitalWrite(8,LOW);
    digitalWrite(9,LOW);
    pinMode(13,OUTPUT);              //SIM808 wakeup connected on pin 13 in IomaTic board
    digitalWrite(13, HIGH);          //Initialize the SIM808 Module 
    delay(1000);
    digitalWrite(13, LOW);           //Sending wake up signal to SIM808 Module
    delay(1000);
    digitalWrite(13, HIGH);          //Keeping SIM808 in active/wakeup state
    delay(10000);
    Serial.begin(9600);
    delay(2000);
    Serial.println("AT+CMGF=1");
    delay(100);
    Serial.println("AT+CNMI=2,2,0,0,0");
    delay(100);
}
void loop()
{
 

    
  
 if(Serial.available()>0)
  {
    inchar = Serial.read();
    if(inchar=='$')
    {
      delay(10);
      inchar  = Serial.read();
      if(inchar=='a')
      {
        delay(10);
        inchar=Serial.read();
        if(inchar=='0')
        {
          digitalWrite(8,LOW);
          digitalWrite(9,LOW);
          
          Serial.println("Relay OFF");
          }
          else if(inchar=='1')
          {
        Serial.println("Relay ON");
        digitalWrite(8,HIGH);
        }else if(inchar=='2')
        {
        Serial.println("Relay ON");
        digitalWrite(9,HIGH);
        }

        delay(100);
        Serial.println("AT+CMGD=1,4");
        delay(2000);


       /*if(inchar=='$')
    {
      delay(10);
      inchar  = Serial.read();
      if(inchar=='a')
      {
        delay(10);
        inchar=Serial.read();
        if(inchar=='3')
        {
          digitalWrite(9,LOW);
          Serial.println("Relay OFF");
          }
           else if(inchar=='2')
          {
        Serial.println("Relay ON");
        digitalWrite(9,HIGH);
        }
        delay(100);
        Serial.println("AT+CMGD=1,4");
        delay(2000);
      }
    }*/
}
}
  }
}
