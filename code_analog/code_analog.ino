int d = 11;
int y = 10;
int g = 9;
int k = 6;
int u = 5;
int f = 3;
void setup() {
  
pinMode (d, OUTPUT);
pinMode (y, OUTPUT);
pinMode (f, OUTPUT);
pinMode (u, OUTPUT);
pinMode (g, OUTPUT);
pinMode (k, OUTPUT);
}

void loop() {
digitalWrite (d,1);
digitalWrite (y,0);
digitalWrite (g,1);
digitalWrite (k,0);
analogWrite (f,66);
analogWrite (u,66);
delay (5000);
analogWrite (f,102);
analogWrite (u,102);
delay (5000);
analogWrite (f,200);
analogWrite (u,200);
delay (5000);
analogWrite (f,255);
analogWrite (u,255);
delay (10000);
digitalWrite (d,0);
digitalWrite (y,1);
digitalWrite (g,0);
digitalWrite (k,1);
analogWrite (f,255);
analogWrite (u,255);


}
