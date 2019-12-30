// include the library code:
#include <LiquidCrystal.h>
#include <SimpleDHT.h>
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(11,12,14,15,16,17);
int pinDHT11 = 6;
SimpleDHT11 dht11;

char Input[200];
char Longitude[100];
char Latitude[100];

String serialResponse = "";
String arr[22];

float Lon1=79.047274;
float Lat1=21.121621;
float Lon2=79.045697;
float Lat2=21.113453;

// In Kilometers
float radius_of_earth = 6378.1;

int cnt=0;

char PhoneNo[]="+918976260275";
char PhoneNo2[]="+918361241626";
int sendStatus=0;

void setup()
{
    //SIM808 wakeup connected on pin 13 in IomaTic board
    pinMode(13,OUTPUT);
    //Initialize the SIM808 Module
    digitalWrite(13, HIGH);
    delay(1000);
    //Sending wake up signal to SIM808 Module
    digitalWrite(13, LOW);
    delay(1000);
    //Keeping SIM808 in active/wakeup state
    digitalWrite(13, HIGH);
    delay(3000);
    //Initialize the LCD in 16x2 mode
    lcd.begin(16, 2);
    delay(100);
    //Set cursor at first character/coloumn of first line/row
    lcd.setCursor(0,0);
    //Print the message as metioned cursor location
    lcd.print("     IomaTic        ");
    //Set cursor at first character/coloumn of first line/row
    lcd.setCursor(0,1);
    //Print the message as metioned cursor location
    lcd.print("GPS Location.........");
    //Initialize a serial communication with baud rate 9600
    Serial.begin(9600);
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
   // OPERATOR (GPS Location)
   Serial.print("AT+CGNSINF\r\n");
      // find operator name between two double quotes
      if (Serial.find("+CGNSINF: "))
      {
          serialResponse = Serial.readStringUntil('\r\n');
          cnt=0;
          char buf[sizeof(Input)];
          serialResponse.toCharArray(buf, sizeof(buf));
          char *p = buf;
          char *str;
          // delimiter is the semicolon
          while ((str = strtok_r(p, ",", &p)) != NULL)
             {
                Serial.println(str);
                arr[cnt]=str;
                cnt++;
             }

          lcd.clear();
          //Set cursor at first character/coloumn of first line/row
          //lcd.setCursor(0,0);
          //lcd.print("Lon1:");
          //lcd.print("Lon2:");
          //Print the message as metioned cursor location
          //lcd.print(arr[3]);
          //Set cursor at first character/coloumn of first line/row
          //lcd.setCursor(0,1);
          //lcd.print("Lat1:");
          //lcd.print("Lat2:");
          //Print the message as metioned cursor location
          //lcd.print(arr[4]);


          delay(3000);
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print(distance_in_km1(Lat1, Lon1, arr[3].toFloat(), arr[4].toFloat()));
          float d1 = distance_in_km1(Lat1, Lon1, arr[3].toFloat(), arr[4].toFloat());
          lcd.setCursor(8,0);
          lcd.print(distance_in_km2(Lat2, Lon2, arr[3].toFloat(), arr[4].toFloat()));
          float d2 = distance_in_km2(Lat2, Lon2, arr[3].toFloat(), arr[4].toFloat());
          delay(3000);

          byte temperature = 0;
          byte humidity = 0;
          int err = SimpleDHTErrSuccess;
          if ((err = dht11.read(pinDHT11, &temperature, &humidity, NULL)) != SimpleDHTErrSuccess)
            {
              Serial.print("Read DHT11 failed, err="); Serial.println(err);delay(1000);
              return;
             }

           //Set cursor at first character/coloumn of first line/row
           lcd.setCursor(0,1);
           //Print the message as metioned cursor location
           lcd.print("Val:");

           lcd.print((int)temperature);
            //Print the message as metioned cursor location
           lcd.print(" *C, ");

           lcd.print((int)humidity);
           lcd.print(" H");

           delay(1000);

      if ((int)temperature>=23)
      {
      if(sendStatus==0)


      digitalWrite(4,HIGH);
      lcd.print(" H");

      //Set cursor at first character/coloumn of first line/row
      lcd.setCursor(0,1);
      //Print the message as metioned cursor location
      lcd.print("Triggering SMS....");

      //Initialize a serial communication with baud rate 9600
      Serial.begin(9600);
      delay(1000);
      //Initialize the GSM modem
      //Serial.println("AT+CMGF=1\r");
      //delay(2000);
      //Send dial a phone AT command
      //Serial.print("AT+CMGS=\"+918976260275\"\r");
      //Serial.print(PhoneNo);
      //Hex code equivalent to "
      //Serial.write(0x22);
      //Hex code equivalent to carraige return i.e. \r
      //Serial.write(0x0D);
      //Hex code equivalent to new line char i.e. \n
      //Serial.write(0x0A);
      //delay(2000);
      //Test SMS Message Body to Send
      //Serial.print("You are nearest, Temperature is High: ");
      //Serial.print((int)temperature);
      //delay(500);
      //Serial.write(0x1A);
      //Serial.println(char(26));

      if(distance_in_km1 > distance_in_km2)
          {
              lcd.setCursor(0,1);
              Serial.println("AT+CMGF=1\r");
              Serial.print("AT+CMGS=\"+918976260275\"\r");
              lcd.print("D1 closer than D2");
              Serial.print("You are nearest, Temperature is High: ");
              Serial.print((int)temperature);
              Serial.print("Closer:");
              Serial.print(d1);
              Serial.print("Farther:");
              Serial.print(d2);
              delay(500);
              Serial.write(0x1A);
              Serial.println(char(26));
              delay(2000);
              lcd.clear();
            }
      else {
              lcd.setCursor(0,1);
              lcd.print("D1 not closer than D2");
              lcd.setCursor(0,1);
              Serial.println("AT+CMGF=1\r");
              Serial.print("AT+CMGS=\"+918369241626\"\r");
              Serial.print("You are nearest, Temperature is High: ");
              Serial.print((int)temperature);
              Serial.print("Closer:");
              Serial.print(d1);
              Serial.print("Farther:");
              Serial.print(d2);
              delay(500);
              Serial.write(0x1A);
              Serial.println(char(26));
              delay(2000);
              lcd.clear();
          }

    }
    else
    {
      lcd.print(" L");
      sendStatus=0;
      digitalWrite(4,LOW);
      lcd.setCursor(0,1);
      lcd.print("Temp not high");
    }
    }
}



double distance_in_km1(float start_lat1, float start_long1, float end_lat1, float end_long1) {
      // / 180 / PI converts degrees to radians
      start_lat1/= 180 / PI;
      start_long1/= 180 / PI;
      end_lat1/= 180 / PI;
      end_long1/= 180 / PI;
      // haversine formula - based on implementation at http://www.movable-type.co.uk/scripts/latlong.html
      float a = pow(sin((end_lat1-start_lat1)/2), 2) + cos(start_lat1) * cos(end_lat1) * pow(sin((end_long1-start_long1)/2), 2);
      float answer = radius_of_earth * 2 * atan2(sqrt(a), sqrt(1-a));
      return double(answer * 1000);
    }

double distance_in_km2(float start_lat2, float start_long2, float end_lat2, float end_long2) {
      // / 180 / PI converts degrees to radians
      start_lat2/= 180 / PI;
      start_long2/= 180 / PI;
      end_lat2/= 180 / PI;
      end_long2/= 180 / PI;
      // haversine formula - based on implementation at http://www.movable-type.co.uk/scripts/latlong.html
      float a = pow(sin((end_lat2-start_lat2)/2), 2) + cos(start_lat2) * cos(end_lat2) * pow(sin((end_long2-start_long2)/2), 2);
      float answer = radius_of_earth * 2 * atan2(sqrt(a), sqrt(1-a));
      return double(answer * 1000);
    }
