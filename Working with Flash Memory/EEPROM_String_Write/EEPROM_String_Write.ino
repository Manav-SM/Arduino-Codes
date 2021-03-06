/*
 * Circuits4you.com
 * Reading and Writing String to EEPROM Example Code
 * Oct 2018
 */
#include <LiquidCrystal.h>
#include <EEPROM.h>
LiquidCrystal lcd(11,12, 14, 15, 16, 17);

void writeString(char add,String data);
String read_String(char add);

void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  //EEPROM.begin(512);
  String data = "IOMATIC@hooli.xyz";
  lcd.setCursor(0,0);
  lcd.print("Writing Data:");
  lcd.setCursor(0,1);
  lcd.println(data);
  writeString(10, data);  //Address 10 and String type data
  delay(1000);
  lcd.clear();
}

void loop() {
  // put your main code here, to run repeatedly:
  String recivedData;
  recivedData = read_String(10);
  lcd.setCursor(0,0);
  lcd.print("Read Data:");
  lcd.setCursor(0,1);
  lcd.println(recivedData);
  delay(1000);
  lcd.clear();
}

void writeString(char add,String data)
{
  int _size = data.length();
  int i;
  for(i=0;i<_size;i++)
  {
    EEPROM.write(add+i,data[i]);
  }
  EEPROM.write(add+_size,'\0');   //Add termination null character for String Data
  //EEPROM.commit();
}


String read_String(char add)
{
  int i;
  char data[100]; //Max 100 Bytes
  int len=0;
  unsigned char k;
  k=EEPROM.read(add);
  while(k != '\0' && len<500)   //Read until null character
  {    
    k=EEPROM.read(add+len);
    data[len]=k;
    len++;
  }
  data[len]='\0';
  return String(data);
}
