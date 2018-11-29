int v [4];
int i=0;
int old_v=v[i];
int MAX;
int MIN;
void setup() {
  Serial.begin(9600);
 while(i<=4){
  v[i]=random(0,10);;
  i++;
 }
 i=0;
 while(i<=4){
  Serial.print(v[i]);
  Serial.print(", ");
  i++;
 }
 i=0;
  Serial.print("   ");
 MAX=v[0];
 while(i<=4){
  if(MAX>v[i]){
    
  }else{
    MAX = v[i];
  }
  i++;
 }
  Serial.print(MAX);
  MIN=v[0];
  i=0;
  while(i<=4){
   if(MIN<v[i]){
    
   }
   else{
    MIN=v[i];
   }
   i++;
  }
  Serial.print("   ");
  Serial.println(MIN);
 }

void loop() {

}
