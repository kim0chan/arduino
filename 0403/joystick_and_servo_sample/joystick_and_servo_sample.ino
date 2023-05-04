#include <Servo.h>
Servo x_servo;
Servo y_servo;
int buzzerPin = 9;
int GRN = 5;
int RED = 6;

int state = random(0, 2);

unsigned long prev_time = 0;
unsigned long INTERVAL = 5000;

void setup() {
  Serial.begin(9600);
  pinMode(12, INPUT_PULLUP);
  pinMode(buzzerPin, OUTPUT);
  pinMode(GRN, OUTPUT);
  pinMode(RED, OUTPUT);
  x_servo.attach(10);
  y_servo.attach(11);
}

void loop() {
  unsigned long cur_time = millis();
  if(cur_time - prev_time >= INTERVAL) {
        prev_time = cur_time;
        state = random(0, 2);
  }

  int xAxis = analogRead(A0);
  int yAxis = analogRead(A1);
  int dx = map(xAxis, 0, 1023, 0, 180);
  int dy = map(yAxis, 0, 1023, 0, 180);
  x_servo.write(dx);
  y_servo.write(dy);

  if(state) {
    digitalWrite(GRN, LOW);
    digitalWrite(RED, HIGH);
    if(abs(dx - 90) > 10 || abs(dy - 90) > 10) ring();
  }
  else {
    digitalWrite(RED, LOW);
    digitalWrite(GRN, HIGH);
  }
  
  delay(10);
}

void ring() {
  tone(buzzerPin, 523, 500);
}