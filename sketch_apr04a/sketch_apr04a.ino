

void setup() {
  pinMode(A1,INPUT);
  pinMode(7,OUTPUT);
  Serial.begin(9600);
  
}

void loop() {
  Serial.println(analogRead(A1));
  delay(100);

if(analogRead(A1)>200){
digitalWrite(7,1);
}
else{
digitalWrite(7,0);
  }
 
}
