#include<LiquidCrystal.h>
LiquidCrystal lcd(11,12,14,15,16,17);
//const int buttonPin=2;
const int PotentioPin=A4;
//int buttonState=0;
int val;

void setup() {
  // put your setup code here, to run once:
pinMode(A4,INPUT);

//pinMode(2,INPUT_PULLUP);
lcd.begin(16,2);
Serial.begin(9600);


}

void loop() 
  // put your main code here, to run repeatedly:
{
val=analogRead(PotentioPin);
Serial.print(val);
delay(1000);
if(val<300)
{
  
  lcd.setCursor(0,0);
  lcd.print(" Miss ");
  Serial.print("Miss");
  
}
delay(1000);
if(val>300 && val<700)
{
 
  lcd.setCursor(0,0);
  lcd.print(" GSM ");
  Serial.print("gsm");
 
  
}
delay(1000);
if(val>700)
{
  //lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(" GPS ");
  Serial.print("gps");
 
}
}
