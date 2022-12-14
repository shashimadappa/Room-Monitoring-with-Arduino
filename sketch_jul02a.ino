#include <dht.h>
#define dht_apin A0

dht DHT;
int count=0;
void setup(){
pinMode(2,INPUT);
pinMode(4,INPUT);
pinMode(12,OUTPUT);
pinMode(13,OUTPUT);
pinMode(8,OUTPUT);
Serial.begin(115200);
}
void loop(){
DHT.read11(dht_apin);
if(digitalRead(4)==0){
  if(count<10)
  count++;
}  
if(digitalRead(2)==0){
  if(count>0)
  count--;
}
 int luminance = analogRead(A1);
Serial.println(""+String(count)+","+String(DHT.humidity)+","+String(DHT.temperature)+","+String(luminance));
if(DHT.temperature>25 && count>0){
digitalWrite(8,HIGH);
}else{
  digitalWrite(8,LOW);
}
if(luminance<250 && count>0){
  digitalWrite(13,HIGH);
}else{
  digitalWrite(13,LOW);
}
if(count>=10){
  digitalWrite(12,HIGH);
}else{
  digitalWrite(12,LOW);
}
delay(500);
}
