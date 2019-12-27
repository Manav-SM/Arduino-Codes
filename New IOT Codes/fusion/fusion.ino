
const int analogPin = A4;    // pin that the sensor is attached to
const int led= 8;       // pin that the LED is attached to
const int threshold = 400;   // an arbitrary threshold level that's in the range of the analog input

void setup() {
  // initialize the LED pin as an output:
  pinMode(led, OUTPUT);
  // initialize serial communications:
  Serial.begin(9600);
}

void loop() {
  // read the value of the potentiometer:
  int analogValue = analogRead(analogPin);

  // if the analog value is high enough, turn on the LED:
 
  if (analogValue > threshold)
  {
        
         
    digitalWrite(led, HIGH);
    Serial.print("light on");
    delay(1000);
  
  }
  else {
    digitalWrite(led, LOW);
    Serial.print("light off");
    delay(1000);
  }
  
  // print the analog value:
  Serial.println(analogValue);
  delay(1);        // delay in between reads for stability
}
