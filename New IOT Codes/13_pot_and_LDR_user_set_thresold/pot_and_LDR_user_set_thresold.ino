const int analogPin = A4;
int LDRPin = A5;
char thr ;
int LDRvalue = 0;


void setup() {
  pinMode(A4,INPUT);// put your setup code here, to run once:
  Serial.begin(9600);
  if (Serial.available() > 0)
  {
    thr = Serial.read();
  }
}

void loop() {
  // put your main code here, to run repeatedly:
 int analogValue = analogRead(analogPin); 
 
 if(analogValue > thr)
 {
   LDRvalue=analogRead(LDRPin);
  if (LDRvalue>thr)
   {
   
    Serial.print("LDR Start \n ");
    LDRvalue=digitalRead(LDRPin);
    if(LDRvalue ==1)
      {
        Serial.print("High\n");
      }
      else if(LDRvalue ==0)
      {
        Serial.print("Low\n");
      }
     delay(1000);
    
    
   }
 }
}
