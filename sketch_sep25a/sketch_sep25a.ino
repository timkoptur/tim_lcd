int kt ;   // переменная для хранения полученного байта
 
void setup() {
    Serial.begin(9600); // устанавливаем последовательное соединение
    pinMode(13,OUTPUT);
}
 
 
void loop() {
  kt = Serial.read();
    if (kt=='1') {  
    digitalWrite(13,1);
    }
    if(kt=='0'){
    digitalWrite(13,0);  
    }
}

