#include<LiquidCrystal.h>
LiquidCrystal lcd(11,12,14,15,16,17);


const int PotentioPin=A4;
const int buzzerPin=7;


int val;

void setup() {
  // put your setup code here, to run once:
  pinMode(A4,INPUT);
   pinMode(buzzerPin,OUTPUT);
  pinMode(2,INPUT_PULLUP);
lcd.begin(16,2);
//delay(1000);
//d.print("= MODE =");
}

void loop() {
  // put your main code here, to run repeatedly:


val=analogRead(PotentioPin);
delay(1000);

  if(val<300)
  {
    lcd.clear();
  
    //delay(1000);
    lcd.setCursor(0,1);
    lcd.print(" Miss ");
    delay(1000);
    digitalWrite(buzzerPin,LOW);
    
  }
if(val>300 && val<=700)
{
   lcd.clear();

 //delay(1000);
    lcd.setCursor(0,1);
    lcd.print(" GSM ");
    delay(2000);
   digitalWrite(buzzerPin,HIGH);
   
   delay(5000);
   digitalWrite(buzzerPin,LOW);
}
if(val>700)
{
   lcd.clear();

 // delay(1000);
    lcd.setCursor(0,1);
    lcd.print(" GPS ");
    delay(1000);
    digitalWrite(buzzerPin,HIGH);
   
}
}

void setup1()
{
  
}
void loop1()
{
  while(1)
  {
}
}
