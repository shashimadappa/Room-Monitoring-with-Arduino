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

























//void setup() {
//  // initialize serial communication at 9600 bits per second:
//  Serial.begin(9600);
//}
//
//void loop() {
//  // reads the input on analog pin A0 (value between 0 and 1023)
//  int analogValue = analogRead(A0);
//
//  Serial.print("Analog reading: ");
//  Serial.print(analogValue);   // the raw analog reading
//
//  // We'll have a few threshholds, qualitatively determined
//  if (analogValue < 10) {
//    Serial.println(" - Dark");
//  } else if (analogValue < 200) {
//    Serial.println(" - Dim");
//  } else if (analogValue < 500) {
//    Serial.println(" - Light");
//  } else if (analogValue < 800) {
//    Serial.println(" - Bright");
//  } else {
//    Serial.println(" - Very bright");
//  
//  }
//  delay(1000);
//}
//
//
//
//
//
//#include <dht.h>
////
////
//#define dht_apin A0 // Analog Pin sensor is connected to
//// 
//dht DHT;
// 
//void setup(){
// 
//  Serial.begin(9600);
//  delay(500);//Delay to let system boot
//  Serial.println("DHT11 Humidity & temperature Sensor\n\n");
//  delay(1000);//Wait before accessing Sensor
// 
//}//end "setup()"
// 
//void loop(){
//  //Start of Program 
// 
//    DHT.read11(dht_apin);
//    
//    Serial.print("Current humidity = ");
//    Serial.print(DHT.humidity);
//    Serial.print("%  ");
//    Serial.print("temperature = ");
//    Serial.print(DHT.temperature); 
//    Serial.println("C  ");
//    
//    delay(5000);//Wait 5 seconds before accessing sensor again.
// 
//  //Fastest should be once every two seconds.
// 
//} end loop(
//
//
//
//
//
//
////                // LED 
//int pirPin = 2;                 // PIR Out pin 
//int pirStat = 0;                   // PIR status
//void setup() {     
// pinMode(pirPin, INPUT);     
// Serial.begin(9600);
//}
//void loop(){
// pirStat = digitalRead(pirPin); 
// if (pirStat == HIGH) {            // if motion detected
//   Serial.println("Hey I got you!!!");
// } 
// 
//} 
//const int pingPin = 7; // Trigger Pin of Ultrasonic Sensor
//const int echoPin = 6; // Echo Pin of Ultrasonic Sensor
//
//void setup() {
//   Serial.begin(9600); // Starting Serial Terminal
//}
//
//void loop() {
//   long duration, inches, cm;
//   pinMode(pingPin, OUTPUT);
//   digitalWrite(pingPin, LOW);
//   delayMicroseconds(2);
//   digitalWrite(pingPin, HIGH);
//   delayMicroseconds(10);
//   digitalWrite(pingPin, LOW);
//   pinMode(echoPin, INPUT);
//   duration = pulseIn(echoPin, HIGH);
//   inches = microsecondsToInches(duration);
//   cm = microsecondsToCentimeters(duration);
//   Serial.print(inches);
//   Serial.print("in, ");
//   Serial.print(cm);
//   Serial.print("cm");
//   Serial.println();
//   delay(100);
//}
//
//long microsecondsToInches(long microseconds) {
//   return microseconds / 74 / 2;
//}
//
//long microsecondsToCentimeters(long microseconds) {
//   return microseconds / 29 / 2;
//}
