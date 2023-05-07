#include <Wire.h>
#include <BH1750.h>
#include "DHT.h"

#define DHTTYPE DHT22

const int LED = 2;
const int DHTPIN = 3;
const int RELAY = 4;
const int SOIL = A1;

BH1750 lightMeter;
DHT dht(DHTPIN, DHTTYPE);

const float lightThreshold = 100.0f;
const float humidityThreshold = 80.0f;
const float temperatureThreshold = 30.0f;
int moistureThreshold = 900;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  lightMeter.begin();
  dht.begin();

  pinMode(LED, OUTPUT);
  pinMode(RELAY, OUTPUT);
  pinMode(SOIL, INPUT);

  pinMode(5, OUTPUT); // ENA
  pinMode(9, OUTPUT); // IN1
  pinMode(10, OUTPUT);// IN2
}

void loop() {
  // put your main code here, to run repeatedly:
  float lux = lightMeter.readLightLevel();
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();
  int moisture = analogRead(SOIL);
  
  Serial.print("Light: ");
  Serial.print(lux);
  Serial.println(" lx");
  if(lux < lightThreshold) digitalWrite(LED, HIGH);
  else          digitalWrite(LED, LOW);

  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("Failed to read from DHT");
  } else {
    Serial.print("Humidity: "); 
    Serial.print(humidity);
    Serial.print(" %\t");
    Serial.print("Temperature: "); 
    Serial.print(temperature);
    Serial.println(" *C");
  }  
  if(humidity > humidityThreshold ||
    temperature > temperatureThreshold) digitalWrite(RELAY, HIGH);
  else digitalWrite(RELAY, LOW);      

  if(moisture > moistureThreshold) {
    analogWrite(5, 128);
    Serial.println("Motor ON");
    }
  else analogWrite(5, 0);

  Serial.println(moisture);
  digitalWrite(9, LOW);
  digitalWrite(10, HIGH);

  delay(1000);
}
