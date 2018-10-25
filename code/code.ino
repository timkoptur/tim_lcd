int d = 11;
int y = 10;
int f = 3;
void setup() {
  
pinMode (d, OUTPUT);
pinMode (y, OUTPUT);
pinMode (f, OUTPUT);

}

void loop() {
digitalWrite (d,1);
digitalWrite (y,0);
analogWrite (f,66);
delay (5000);
analogWrite (f,102);
delay (5000);
analogWrite (f,200);
delay (5000);
analogWrite (f,255);
delay (10000);


}
