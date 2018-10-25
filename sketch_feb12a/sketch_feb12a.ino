byte i;
byte LedMax=6;
byte LedMin=1;

void setup() {for (i=LedMin;i<LedMax;i++){
  pinMode (i,OUTPUT);
 }
}
void loop() {for (i=LedMin;i<LedMax;i++){
  digitalWrite ( i,HIGH);
  delay (60);
 }

for  (i=LedMax;i>LedMin;i--){
  digitalWrite (i,LOW);
  delay (60);
}
delay (500);
}
