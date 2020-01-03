// including LCD Library
#include <LiquidCrystal.h>
#include <EEPROM.h>
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(11,12, 14, 15, 16, 17);
// declaring Potentiometer interface pins and input variable
//int pot = A4;
void writeString(char add,String data);


void setup()
{
  writeString(10, data);  //Address 10 and String type data
}

void loop()
{

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
