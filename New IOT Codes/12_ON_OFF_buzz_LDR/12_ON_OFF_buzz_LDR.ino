
#include<LiquidCrystal.h>
LiquidCrystal lcd(11,12,14,15,16,17);

int LDRValue1 = 0; // result of reading the digital pin
int LDRpin1 = A4;


void setup() {
  Serial.begin(9600); // sets serial port for communication
  lcd.begin(16,2);
}

void loop() {
 
  LDRValue1 = Analogread(LDRpin1);// read the value from the LDR
 
  if((LDRValue1==1)) {
    Serial.print(" HIGH");
    lcd.setCursor(0,0);
    lcd.print("LDR HIGH");
    digitalWrite(7,LOW);
    delay(1000);
    }
  else if ((LDRValue1==0)) {
    Serial.print(" LOW"); 
    lcd.setCursor(0,0);
    lcd.print("LDR  LOW");
    digitalWrite(7,HIGH);
    delay(1000);
    }
  
  //Serial.println(" lighting");
 
  delay(100);                    // wait a little
}
