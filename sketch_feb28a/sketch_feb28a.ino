#include <Wire.h> // библиотека для управления устройствами по I2C 
#include <LiquidCrystal_I2C.h> // подключаем библиотеку для LCD 1602

LiquidCrystal_I2C lcd(0x27,20,2); // присваиваем имя lcd для дисплея 20х2

// создаем символ сердца и четырех букв на кириллице

byte heart[8] = { 0b00000, 0b01010, 0b11111, 0b11111, 0b11111, 0b01110, 0b00100, 0b00000 };

byte I[8] = { 0b01111,
0b10001,
0b10001,
0b01111,
0b00101,
0b01001,
0b10001,
0b00000 };
byte B[8] = { 0b11111,
0b10000,
0b10000,
0b11110,
0b10001,
0b10001,
0b11110,
0b00000 };
byte N[8] = { 
0b10001,
0b10001, 
0b10011, 
0b10101, 
0b11001,
0b10001, 
0b10001, 
0b00000 };
byte F[8] = { 
0b01110,
0b10101, 
0b10101, 
0b10101,
0b01110, 
0b00100,
0b00100,
0b00000 };
byte u[8] = { 
0b10001,
0b10001, 
0b10001, 
0b01111,
0b00001, 
0b10001,
0b01110,
0b00000 };

void setup() // процедура setup
{
  lcd.init(); // инициализация LCD дисплея
  lcd.backlight(); // включение подсветки дисплея

// присваиваем символам порядковый номер

  lcd.createChar(1, heart);
  lcd.createChar(2, I);
  lcd.createChar(3, B);
  lcd.createChar(4, N);
  lcd.createChar(5, F);
  lcd.createChar(6, u);
  
  lcd.setCursor(6,0); // устанавливаем курсор на 6 символ первой строки
  
  lcd.print(char(2));
  lcd.print(" ");
  lcd.print(char(1));
  
  lcd.setCursor(1,1); // устанавливаем курсор на начало второй строки
  
  lcd.print("P");
  lcd.print("O");
  lcd.print(char(3));
  lcd.print("O");
  lcd.print("T");
  lcd.print("E");
  lcd.print("X");
  lcd.print("H");
  lcd.print(char(4));
  lcd.print("K");
  lcd.print(char(6));
  lcd.print(".");
  lcd.print("P");
  lcd.print(char(3));


  lcd.setCursor(12,0);
  lcd.print("2018");
  
}

void loop() // процедура loop
{
}

