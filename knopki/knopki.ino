int x=500 ;
int z=0 ;
void setup() {
Serial.begin(9600);
pinMode(13,OUTPUT);

}

void loop() {
 z=Serial.read();
if(z=='1'){
 for(int y=20;y<1000;y+=20){
  z=Serial.read();
  digitalWrite(13,1);
 delay(x+y);
 digitalWrite(13,0);
 delay(x+y);
  if(z=='0')
  for(int y=20;y<1000;y-=20){
 digitalWrite(13,1);
 delay(x+y);
 digitalWrite(13,0);
 delay(x+y);
   }
  }
 }
}

