#include <SimpleDHT.h>
int dhtval = 6;
SimpleDHT11 dht11(dhtval);

void setup()
{
  Serial.begin(9600);
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
  Serial.print((int)temperature);
  Serial.print(" *C, "); 
  Serial.print((int)humidity);
  Serial.println(" H");  
  // DHT11 sampling rate is 1HZ.
  delay(1500);
}
