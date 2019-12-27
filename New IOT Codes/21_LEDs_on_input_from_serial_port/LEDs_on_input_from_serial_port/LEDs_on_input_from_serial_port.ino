


char c;
void setup()
{
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
 
  Serial.begin(9600);
}
void loop()
{
  if(Serial.available())
  {
    c=Serial.read();
    if(c=='a')
    {
      digitalWrite(8,HIGH);
      

    }
    if(c=='b')
    { 
      digitalWrite(8,LOW);
      
    }
    if(c=='d')
    {
      digitalWrite(9,HIGH);
    }
    if(c=='e')
    {
      digitalWrite(9,LOW);
    } 
    if(c=='f')
    { 
      digitalWrite(10,HIGH);
    }
    if(c=='g')
    {
      digitalWrite(10,LOW);
    }
    }
    }
  

   




    
   
  
