long t = 0;
void setup()
{
  Serial.begin(9600);
}
void loop()
{
  while(Serial.available() <= 0)
  {
    int t = Serial.parseInt();
    Serial.print("t =");
    Serial.println(t);
  }  
}
