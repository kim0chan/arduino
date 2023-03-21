int RED = 7;
int GRN = 8;
int TRIG = 12;
int ECHO = 13;
const int distance_max = 256;
const int distance_line = 100;
const int measuring_interval = 1000;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(RED, OUTPUT);
  pinMode(GRN, OUTPUT);
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  long duration, distance;
  int count = 0;

  Serial.println("DOOR OPENED");
  digitalWrite(RED, HIGH);
  delay(2000);

  while(count < 3) {
    digitalWrite(TRIG, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG, HIGH);
    delayMicroseconds(20);
    digitalWrite(TRIG, LOW);
    
    duration = pulseIn(ECHO, HIGH);
    distance = duration / 58.2;

    //Codes for monitoring sensor values
    Serial.println(duration );
    Serial.print("\nDIstance : ");
    Serial.print(distance);
    Serial.println(" Cm");

    if(distance > distance_line)  count++;
    else                          count = 0;

    delay(measuring_interval);
  }

  digitalWrite(RED, LOW);
  while(1) {
    digitalWrite(GRN, HIGH);
    delay(500);
    digitalWrite(GRN, LOW);
    delay(500);
  }
}
