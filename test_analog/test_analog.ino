void setup() {
Serial.begin (9600); // put your setup code here, to run once:
pinMode(A1,INPUT);
}

void loop() {
  int d = analogRead(A1);
Serial.println (d);
delay(50);
  if (d<200){
    digitalWrite(8,1);
    digitalWrite(10,0);
  }
  else{
    digitalWrite(8,0);
    digitalWrite(10,1);
  }
}
