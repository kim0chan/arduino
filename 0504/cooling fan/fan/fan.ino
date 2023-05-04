int relay=4;
 
void setup() {
  pinMode(relay, OUTPUT);
  
}
 
void loop() {
  digitalWrite(relay, HIGH);
  delay(5000);
  digitalWrite(relay, LOW);
  delay(3000);
}