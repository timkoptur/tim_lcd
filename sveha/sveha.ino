int x ;
int y ;
void setup() {
 pinMode(A0,OUTPUT);

}

void loop() {
 x=random(100,150); 
 y=random(100,300);
 analogWrite (A0,x);
 x=x-10;
 delay(y);
 analogWrite (A0,x);
 x=x-30;
 delay(y);
 analogWrite (A0,x);
 delay(y);
 analogWrite (A0,0);
 delay(y);
}
