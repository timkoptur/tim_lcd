#include <Wire.h>
#include <LiquidCrystal_I2C.h>
int x;
int y;
void setup() {
  lcd.backlight();
   lcd.init();
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
}

void loop() {
  
if(x<512){
  lcd.print("down");
}
else if (x>512){
 lcd.print("up");
}
if (y<512){
  lcd.print("left");
}
else {
  lcd.print("right");
}
}
