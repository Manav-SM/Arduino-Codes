#include <Blynk.h>
#include <SoftwareSerial.h>
SoftwareSerial SwSerial(10, 11); // RX, TX
    


// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "BdMMVu7bnVmy-nY2tXWcfox1Z61j4FF3";

SoftwareSerial SerialBLE(4, 5); // RX, TX

void setup()
{
  // Debug console
  Serial.begin(9600);

  SerialBLE.begin(9600);
  Blynk.begin(SerialBLE, auth);

  Serial.println("Waiting for connections...");
}

void loop()
{
  Blynk.run();
  // You can inject your own code or combine it with other sketches.
  // Check other examples on how to communicate with Blynk. Remember
  // to avoid delay() function!
}
