//including DHT11 Library
#include <SimpleDHT.h>

// including LCD Library
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(11,12, 14, 15, 16, 17);
// declaring Potentiometer interface pins and input variable
int pot = A4;
int dhtval = 6;
SimpleDHT11 dht11(dhtval);

void setup()
{
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  lcd.clear();
  // accept potentiometer and DHT11 input
  pinMode(pot, INPUT);
  pinMode(dhtval, INPUT);
}

void loop()
{
  byte temperature = 0;
  byte humidity = 0;
  int err = SimpleDHTErrSuccess;
  if ((err = dht11.read(&temperature, &humidity, NULL)) != SimpleDHTErrSuccess) 
  {
    Serial.print("Read DHT11 failed, err=");
    Serial.println(err);
    delay(1000);
    return;
  }
  if(pot<400)
  {
    lcd.print("blank");
  }
  if(pot>400)
  {
    lcd.setCursor(0,0); // set the cursor to col 0 and row 0 of LCD
    lcd.print("Pot Value:"); // prints potentiometer value to LCD
    lcd.print(analogRead(pot)); // prints value on variable: pot to LCD
    lcd.setCursor(0, 1);
    lcd.print((int)temperature);
    lcd.print(" *C, ");
    lcd.print((int)humidity);
    lcd.println(" H");
    delay(1500);
  }
}
