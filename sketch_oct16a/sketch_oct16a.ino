int x;
int y;
int z;
void setup() {
 Serial.begin(9600);
 pinMode(A0,INPUT);
 pinMode(12,INPUT);
 pinMode(A2,INPUT);
 pinMode(A3,INPUT);
}

void loop() {
 x=analogRead(A0);
 y=analogRead(A1);
 z=digitalRead(12);
 Serial.print("x=");
 Serial.print(x);
 Serial.print("   ");
 Serial.print("y=");
 Serial.print(y);
 Serial.print("   ");
 Serial.print("z=");
 Serial.println(z);
 delay(100);
while(z=1){
 x=analogRead(A0);
 y=analogRead(A1);
 z=digitalRead(12);
 Serial.print("x=");
 Serial.println(x);
 Serial.print("   ");
 Serial.print("y=");
 Serial.print(y);
 Serial.print("   ");
 Serial.print("z=");
 Serial.println(z);
 delay(100);
 analogWrite(A3,x-514);
 delay(100);

 
 
 }
}
