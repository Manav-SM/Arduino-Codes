#include <LiquidCrystal.h>
LiquidCrystal lcd(11,12,14,15,16,17);


void setup() {
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  lcd.begin(16,2);
  delay(1000);
  lcd.setCursor(0,0);
  
  lcd.print(" Lighting ");
  
}

void loop() {
  
  
    
    
    digitalWrite(8,HIGH);
    delay(500);
    digitalWrite(8,LOW);
    digitalWrite(9,HIGH);
    delay(500);
    
    digitalWrite(9,LOW);
    digitalWrite(10,HIGH);
    delay(500);
    digitalWrite(10,LOW);
   
  

}
