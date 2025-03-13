#include <Arduino.h>

int RED = D2;
int YELLOW = D3;
int GREEN = D4;

void setup() {
  pinMode(RED,OUTPUT);
  pinMode(YELLOW,OUTPUT);
  pinMode(GREEN,OUTPUT);
}

void loop() {
  digitalWrite(RED, HIGH);
  delay(100);
  digitalWrite(RED, LOW);
  digitalWrite(YELLOW, HIGH);
  delay(100);
  digitalWrite(YELLOW, LOW);
  digitalWrite(GREEN, HIGH);
  delay(100);
  digitalWrite(GREEN, LOW);
}
