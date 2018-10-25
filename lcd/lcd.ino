#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
byte smile[8]={       
  B00000,
  B01110,
  B10101,
  B10101,
  B11011,
  B01110,
  B10001,
  B01110,
  };
  byte smile2[8]={       
  B11000,
  B11000,
  B11000,
  B11110,
  B11110,
  B11110,
  B11111,
  B00000,
  };
  byte smile3[8]={       
  B01110,
  B11111,
  B10101,
  B00100,
  B00100,
  B01010,
  B10001,
  B10001,
};
void setup() {
  lcd.init();
  lcd.backlight();
  lcd.createChar(1,smile);
  lcd.setCursor(1,0);
  lcd.print(char(1));
  lcd.createChar(2,smile2);
  lcd.setCursor(7,0);
  lcd.print(char(2));
  lcd.createChar(3,smile3);
  lcd.setCursor(15,0);
  lcd.print(char(3));
  
  }

void loop() {

  
  }


