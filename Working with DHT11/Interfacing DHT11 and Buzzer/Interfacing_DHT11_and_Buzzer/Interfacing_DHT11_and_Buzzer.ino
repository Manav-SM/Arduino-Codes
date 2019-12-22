#include <SimpleDHT.h>
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins 
LiquidCrystal lcd(11,12,14,15,16,17);
int dhtval = 6;
SimpleDHT11 dht11(dhtval);

void setup() {
  lcd.begin(16, 2);
  
  Serial.begin(9600);
}

void loop() 
{
  lcd.clear();
  byte temperature = 0;
  byte humidity = 0;
  int err = SimpleDHTErrSuccess;
  if ((err = dht11.read(&temperature, &humidity, NULL)) != SimpleDHTErrSuccess) 
  {
    lcd.print("Read DHT11 failed, err=");
    lcd.println(err);
    delay(1000);
    return;
  }
  lcd.setCursor(0, 0);
  lcd.print((int)temperature); lcd.print(" *C, "); 
  lcd.setCursor(0, 1);
  lcd.print((int)humidity); lcd.println(" H");  
  // DHT11 sampling rate is 1HZ.
  delay(1500);
  if(temperature>28)
  {
    digitalWrite(7, HIGH);
    delay(2000);
    digitalWrite(7, LOW);
    delay(2000);
  }
}
