
void setup() {
 Serial.begin(9600);
 pinMode(13,OUTPUT);
 pinMode(12,OUTPUT);
 pinMode(11,OUTPUT);
 pinMode(10,OUTPUT);
}

void loop() {
 if(Serial.readString() = "Right"){
  digitalWrite(13,1);
  digitalWrite(12,0);
  digitalWrite(11,0);
  digitalWrite(10,1);
 }
 else if(Serial.readString() = "Left"){
  digitalWrite(13,0);
  digitalWrite(12,1);
  digitalWrite(11,1);
  digitalWrite(10,0);
 }
 else if(Serial.readString() = "Back"){
  digitalWrite(13,0);
  digitalWrite(12,1);
  digitalWrite(11,0);
  digitalWrite(10,1);
 }
 else if(Serial.readString() = "Forward"){
  digitalWrite(13,1);
  digitalWrite(12,0);
  digitalWrite(11,1);
  digitalWrite(10,0);
 }

}
