
#include <LiquidCrystal.h>                // include the library code:

LiquidCrystal lcd(11,12,14,15,16,17);  // initialize the library with the numbers of the interface pins

char Input[200];
char Longitude[100];
char Latitude[100];

String serialResponse = "";
String arr[22];

float Lon=79.047274;     // 21.121621,79.047274
float Lat=21.121621;     // 21.117797,79.047075

    //float london[2] = {51.507222,-0.1275};
    //float nyc[2] = {40.757267,-73.985839};
     
    float radius_of_earth = 6378.1; // km

int cnt=0;

void setup()
{
    pinMode(13,OUTPUT);              //SIM808 wakeup connected on pin 13 in IomaTic board
    digitalWrite(13, HIGH);          //Initialize the SIM808 Module 
    delay(1000);
    digitalWrite(13, LOW);           //Sending wake up signal to SIM808 Module
    delay(1000);
    digitalWrite(13, HIGH);          //Keeping SIM808 in active/wakeup state
    delay(3000);
  
    lcd.begin(16, 2);                     //Initialize the LCD in 16x2 mode
    delay(100);   
             
    lcd.setCursor(0,0);                   //Set cursor at first character/coloumn of first line/row
    lcd.print("     IomaTic        ");    //Print the message as metioned cursor location

    lcd.setCursor(0,1);                   //Set cursor at first character/coloumn of first line/row
    lcd.print("GPS Location.........");     //Print the message as metioned cursor location

    Serial.begin(9600);                   //Initialize a serial communication with baud rate 9600
    delay(500);

    Serial.print("AT+CGNSPWR=1\r\n");
    delay(2000);
  
//    Serial.print("AT+CGNSTST=1\r\n");
//    delay(2000);

    Serial.print("AT+CGNSSEQ=\"RMC\"\r\n");
    delay(2000);
    
  }


void loop() 
{   

    GetLocation();
    
    delay(1000);
}


void GetLocation()
{
   Serial.print("AT+CGNSINF\r\n");                   // OPERATOR (GPS Location)
      
      if (Serial.find("+CGNSINF: "))                    // find operator name between two double quotes
      { 
          serialResponse = Serial.readStringUntil('\r\n');
          cnt=0;
          char buf[sizeof(Input)];
          serialResponse.toCharArray(buf, sizeof(buf));
          char *p = buf;
          char *str;
          while ((str = strtok_r(p, ",", &p)) != NULL)  // delimiter is the semicolon
             {
                Serial.println(str);
                arr[cnt]=str;
                cnt++;
             }

          lcd.clear();
          lcd.setCursor(0,0);                   //Set cursor at first character/coloumn of first line/row
          lcd.print("Lon:");
          lcd.print(arr[3]);                    //Print the message as metioned cursor location

          lcd.setCursor(0,1);                   //Set cursor at first character/coloumn of first line/row
          lcd.print("Lat:");
          lcd.print(arr[4]);                    //Print the message as metioned cursor location

          
          delay(2000);
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print(distance_in_km(Lat, Lon, arr[3].toFloat(), arr[4].toFloat()));

          delay(2000);
      }  
}



double distance_in_km(float start_lat, float start_long, float end_lat, float end_long) {
      // / 180 / PI converts degrees to radians
      start_lat/= 180 / PI; 
      start_long/= 180 / PI;
      end_lat/= 180 / PI;
      end_long/= 180 / PI;
      // haversine formula - based on implementation at http://www.movable-type.co.uk/scripts/latlong.html
      float a = pow(sin((end_lat-start_lat)/2), 2) + cos(start_lat) * cos(end_lat) * pow(sin((end_long-start_long)/2), 2);
      float answer = radius_of_earth * 2 * atan2(sqrt(a), sqrt(1-a));
      return double(answer * 1000);
    }