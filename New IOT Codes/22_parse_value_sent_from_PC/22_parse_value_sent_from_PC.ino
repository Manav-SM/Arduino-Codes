//byte b;
long i = 0;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
//Serial.setTimeout(10);
}

void loop() {
  // put your main code here, to run repeatedly:
while (Serial.available() == 0)
{
}

//b = Serial.read() - 48;
i = Serial.parseInt();

//Serial.print("parsing data")

Serial.print("i = ");
Serial.println(i);

}
