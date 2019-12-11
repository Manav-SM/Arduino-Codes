// include the library code:
#include <LiquidCrystal.h>
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(11,12,14,15,16,17);
void setup() {
// set up the LCD's number of rows and columns:
lcd.begin(16, 2);
// Print a message to the LCD.
lcd.print("Running Text"); // 12 huruf
delay(1000);
}
void loop() {
// scroll 12 positions (string length) to the left
// to move it offscreen left:
for (int positionCounter = 0; positionCounter < 12; positionCounter++) {
// scroll one position left:
lcd.scrollDisplayLeft();
// wait a bit:
delay(300);
}
// scroll 28 positions (string length + display length) to the right
// to move it offscreen right: 12+16 = 28
for (int positionCounter = 0; positionCounter < 28; positionCounter++) {
// scroll one position right:
lcd.scrollDisplayRight();
// wait a bit:
delay(300);
}
// scroll 16 positions (display length + string length) to the left
// to move it back to center:
for (int positionCounter = 0; positionCounter < 16; positionCounter++) {
// scroll one position left:
lcd.scrollDisplayLeft();
// wait a bit:
delay(300);
}
// delay at the end of the full loop:
delay(1000);
}
