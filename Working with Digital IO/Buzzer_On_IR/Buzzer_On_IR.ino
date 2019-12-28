//include library coode
#include <LiquidCrystal.h>

int irPin = 3;  // This is our input pin (IR LED at pin D2)
int sensorOut = HIGH;  // HIGH at No Obstacle

const int buzzerPin = 7;

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(11, 12, 14, 15, 16, 17);

void setup() 
{
  //Initialize the LCD in 16x2 mode
  lcd.begin(16, 2);                        
  delay(1000);            
  //Set cursor at first character/coloumn of first line/ro
  lcd.setCursor(0,0);                   
  //Print the message as metioned cursor location
  lcd.print("     IomaTic        ");    

  //Initialize a serial communication with baud rate 9600
  Serial.begin(9600);                   
  delay(1000);
  pinMode(irPin, INPUT);
 
  Serial.begin(9600);
 
}
 
void loop() 
{
 
  sensorOut = digitalRead(irPin);
 
  if (sensorOut == LOW)
 
  {
 
    lcd.print("Obstacle Detected");
    //Set cursor at first character/coloumn of first line/row
    lcd.setCursor(0,1);                   
    //Print the message as metioned cursor location
    digitalWrite(buzzerPin, HIGH);                
  
  }
 
  else
 
  {
 
    lcd.println("No Obstacle");
    //Set cursor at first character/coloumn of first line/row
    lcd.setCursor(0,1);                   
    //Print the message as metioned cursor location
    digitalWrite(buzzerPin, LOW);
  
  }
 
 delay(100);
 lcd.clear();
 
}
