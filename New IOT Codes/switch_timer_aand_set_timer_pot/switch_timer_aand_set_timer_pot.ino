#include <LiquidCrystal.h>                 //includes the library code of LCD in aurdino
int pot=A4;
unsigned long time;

long int seconds=0;

int minutes=0;

int hours=0;
float val=0;
LiquidCrystal lcd(11,12,14,15,16,17);  //RS,EN,D4,D5,D6,D7 pin of LCD respectively

int buttonPin=2; 

void setup()

{
  pinMode(pot,INPUT);
pinMode(2,INPUT_PULLUP);
Serial.begin(9600);                   //initiates serial communication

lcd.begin(16, 2);     //sets the number of columns and rows

}

void loop()

{
void(* resetFunc) (void) = 0;   //reset function
        //function
      val = analogRead(pot);
     //Serial.print(val);
if(digitalRead(buttonPin)==LOW)
       {
        setClock(); 
lcd.setCursor(0,1);     //sets the cursor to 0th column and 1st row,numbering starts from 0

    {
       
         if(hours<10)        //suppose 4
            {
              lcd.print("0");     //LCD first prints 0 and stopwatch shows 0
              lcd.print(hours);       //LCD then prints 4. So value printed is 04 stopwatch shows 04
            }
          else
            {
            lcd.print(hours);
             }
          }

lcd.print(":");

{

if(minutes<10)

{

lcd.print("0");

lcd.print(minutes);

lcd.print(":");

}

else

{

lcd.print(minutes);

lcd.print(":");

}


}

 

{

if(seconds<10)

{

lcd.print("0");

lcd.print(seconds);

}

else

{

lcd.print(seconds);

}


}

}
else {
  lcd.setCursor(0,0);
      delay(5000);
      lcd.print("stop");
      lcd.clear();
      resetFunc();
      delay(1000);
      
      }


}

void setClock()

{
 
seconds++;       //counts seconds from 0

delay(1000);     //a delay of 1000 milliseconds is given for each second count
 
          
      
if (seconds>59)

{

seconds=0;      //whenever second is greater than 59 than second is made equal to

minutes++;

Serial.print(val);// zero and a minute is counted for it
if(val > 100)
     
      {
        minutes++;
        
      }
}
      
if (minutes>59)

{hours++;

minutes=0;

}

 

if(hours>23)

{

hours=0;

}

 

}
