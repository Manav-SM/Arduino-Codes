int IRPin = 3; // declaring pin 3 to read digital input

//Variables:
int value; //save the digital value sent by ir led
int buzz=7;

void setup(){
  pinMode(7, OUTPUT);
  pinMode(IRPin, INPUT);  //Set pin 3 as 'input'
  Serial.begin(9600);       //Begin serial communication

}

void loop(){
  
  value = digitalRead(IRPin);//Read and save digital value from ir sensor 
  if(value==0)
  {
   digitalWrite(7,HIGH); 
  }
  else if(value==1)
  {
     digitalWrite(7,LOW); 
  }
  Serial.println(value);               //Print value
 
}
