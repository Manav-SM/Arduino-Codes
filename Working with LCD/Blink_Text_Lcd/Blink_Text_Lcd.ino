#include <LiquidCrystal.h>                 //includes the library code of LCD in aurdino

unsigned long time;

long int seconds=0;

int minutes=0;

int hours=0;

LiquidCrystal LCD(11, 12, 14, 15, 16, 17);  //RS,EN,D4,D5,D6,D7 pin of LCD respectively

 

void setup()

{

Serial.begin(9600);                   //initiates serial communication

LCD.begin(16, 2);     //sets the number of columns and rows

}

void loop()

{

setClock();         //function

LCD.setCursor(0,1);     //sets the cursor to 0th column and 1st row,numbering starts from 0

{

if(hours<10)        //suppose 4

{

LCD.print(“0”);     //LCD first prints 0 and stopwatch shows 0

LCD.print(hours);       //LCD then prints 4. So value printed is 04 stopwatch shows 04

}

else

{

LCD.print(hours);

}

}

LCD.print(“:”);

{

if(minutes<10)

{

LCD.print(“0”);

LCD.print(minutes);

LCD.print(“:”);

}

else

{

LCD.print(minutes);

LCD.print(“:”);

}

}

 

{

if(seconds<10)

{

LCD.print(“0”);

LCD.print(seconds);

}

else

{

LCD.print(seconds);

}

 

}

}

void setClock()

{

seconds++;       //counts seconds from 0

delay(1000);     //a delay of 1000 milliseconds is given for each second count

if (seconds>59)

{

seconds=0;      //whenever second is greater than 59 than second is made equal to

minutes++;     // zero and a minute is counted for it

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
