void setup() {
  Serial.begin(9600);
  pinMode(5, OUTPUT); // ENA
  pinMode(9, OUTPUT); // IN1
  pinMode(10, OUTPUT);// IN2
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
}
 
void loop() {
  digitalWrite(9, LOW);
  digitalWrite(10, HIGH);
  digitalWrite(11, HIGH);
  digitalWrite(12, LOW);
  analogWrite(5, 255);
  delay(1000);
  analogWrite(5, 0);
  delay(5000);
  
}