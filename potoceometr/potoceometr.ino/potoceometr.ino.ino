int w=1;
void setup() {
 Serial.begin(9600);
 pinMode(A0,INPUT); 
 while(w<100){
  delay(100);
  Serial.println(analogRead(A0));
  w++;
  }
  Serial.print("Readed  ");
  Serial.print(w);
  Serial.print("   values.");
}

void loop() {


}
