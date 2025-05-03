#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

int SDA_pin = D4;
int SCL_pin = D3;
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Wire.begin(SDA_pin,SCL_pin);
  lcd.init(); // Inisialisasi LCD
  lcd.backlight(); // Menyalakan lampu latar LCD
  lcd.setCursor(0,0); // Set posisi kursor ke baris 0 kolom 0
  lcd.print("Balerina Cappucina");
  lcd.setCursor(0,1); // Set posisi kursor ke baris 1 kolom 0
  lcd.print("mimimimi");
}

void loop() {
  lcd.scrollDisplayLeft(); // Menggeser seluruh isi LCD ke kiri
  delay(500); // Delay 0.5 detik sebelum geser lagi
}

