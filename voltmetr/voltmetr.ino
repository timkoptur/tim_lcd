float z;
int val;
int oldval=0;
void setup() {
 pinMode(A0,INPUT);
 Serial.begin(9600);
}

void loop() {
 z=analogRead(A0);
 z=z*0.00488758553;
 val=analogRead(A0);
if(val>oldval+10||val<oldval-10){
}
else{
 Serial.print(z);
 Serial.print("  ");
 Serial.println("V ");
 delay(100);
}
 oldval=val;
}
