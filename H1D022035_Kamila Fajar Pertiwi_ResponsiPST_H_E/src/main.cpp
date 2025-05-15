#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

int TRIG_PIN = D0;
int ECHO_PIN = D1;

long duration;
int distance;

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Wire.begin(TRIG_PIN,ECHO_PIN);
  lcd.init(); 
  lcd.backlight(); 
  lcd.setCursor(0,0); 
  lcd.print("AREA BERBAHAYA");
}

void loop() {
  lcd.scrollDisplayLeft();

  duration = pulseIn(ECHO_PIN, HIGH);
  distance = 0.034 * duration / 2;

  if(distance <= 100){
      lcd.scrollDisplayLeft();
  }else{
    lcd.print("AMAN");
    lcd.scrollDisplayLeft();
  }

  delay(1000);
}