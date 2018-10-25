const int pinRed    = 9;
const int pinGreen  = 10;
const int pinBlue   = 11;
const int swPin = 8; 
const int pinX      = A1; // X 
const int pinY      = A2; // Y 
const int ledPin    = 13;
boolean ledOn = false;  // текущее состояние кнопки
boolean prevSw = false; // предыдущее состояние кнопки

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(pinRed, OUTPUT);
  pinMode(pinGreen, OUTPUT);
  pinMode(pinBlue, OUTPUT);
  pinMode(pinX, INPUT);
  pinMode(pinY, INPUT);
  pinMode(swPin, INPUT);  
  digitalWrite(swPin, HIGH); // включаем встроенный подтягивающий резистор
}                                                                                      

void loop() {
  if (isLedOn()) freeMode(); // если нажата кнопка и горит светодиод на пине 13, включаем режим "фонарик"
  else discoMode(); // иначе включаем "цветомузыку"
}

boolean isLedOn() { // ОПРЕДЕЛЯЕМ НАЖАТИЕ КНОПКИ
  if (digitalRead(swPin) == HIGH && prevSw == LOW) {
    ledOn = !ledOn;                                                                                                                                                                                                                                                                                                                            
    prevSw = HIGH;
  }
  else  prevSw = digitalRead(swPin); 
  digitalWrite(ledPin, ledOn); // включаем светодиод на пине 13
  return ledOn;
}

void freeMode() { // РЕЖИМ "ФОНАРИК"
  int X = analogRead(pinX); // считываем положение джойстика
  int Y = analogRead(pinY);
  int RED = map(Y, 512, 1023, 0, 255); // маппинг значений
  int GREEN = map(X, 512, 1023, 0, 255);
  int BLUE = map(X, 511, 0, 0, 255);
  analogWrite(pinRed, RED);     // включение каналов R,G,B
  analogWrite(pinGreen, GREEN);
  analogWrite(pinBlue, BLUE);
}

void discoMode() { // РЕЖИМ "ЦВЕТОМУЗЫКА"
    for (int i=0; i <= 255; i++) {
      if (isLedOn()) { break; } // при нажатии кнопки выходим из цикла
      analogWrite(pinRed, i); // работает канал RED
      analogWrite(pinGreen, 0);
      analogWrite(pinBlue, 0);  
      delay(5);
    }
    for (int i=0; i <= 255; i++) {
      if (isLedOn()) { break; } // при нажатии кнопки выходим из цикла
      analogWrite(pinRed, 0);
      analogWrite(pinGreen, 0);
      analogWrite(pinBlue, i);  // работает канал BLUE
      delay(5);
    }
    for (int i=0; i <= 255; i++) {
      if (isLedOn()) { break; } // при нажатии кнопки выходим из цикла
      analogWrite(pinRed, 0);
      analogWrite(pinGreen, i); // работает канал GREEN
      analogWrite(pinBlue, 0);  
      delay(5);
    }
}
