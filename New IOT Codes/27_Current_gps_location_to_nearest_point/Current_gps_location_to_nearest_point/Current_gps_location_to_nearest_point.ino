  float SambhajiChowk[2] = {21.113212, 79.045812};
    float Persistant[2] = {21.121509, 79.047258};
    float ANV[2] = {21.117812, 79.047105};

    float ash,ash2;
     
    float radius_of_earth = 6378.1; // km
     
    void setup() {
      Serial.begin(9600);
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
      return double(answer);
    }
     
    void loop() {

      ash=distance_in_km(SambhajiChowk[0], SambhajiChowk[1], ANV[0], ANV[1]);
      
      ash2=distance_in_km(Persistant[0], Persistant[1], ANV[0], ANV[1]);

     
      Serial.print("Shortest Distance: ");
      
      
     

    if(ash>ash2){
      Serial.print(ash2);
      Serial.println(" km");
    }
    else
    {
      Serial.print(ash);
      Serial.println(" km");
    }
      
      delay(1000);
    }
