#include <Arduino.h>
#include <Wire.h>

int SCL_pin = D3;
int SDA_pin = D4;

void setup() {
  Wire.begin(SDA_pin,SCL_pin);  //Mulai komunikasi I2C dengan pin yang terhubung dengan nodemcu
  Serial.begin(9600); // Mulai komunikasi serial untuk debugging
}

void loop() {
  byte error,address;
  int nDevices; //untuk hitung perangkat yang terhubung

  Serial.print("Scanning...");
  nDevices = 0;

  for(address = 1; address < 127; address++){ //127 karena jumlah alamat yang ada dialat sekitar segitu
    Wire.beginTransmission(address);
    error = Wire.endTransmission();

    if(error == 0){ 
      Serial.print("I2C terbaca pada alamat 0x");
      if(address< 16){
        Serial.print("0");
      }
      Serial.print(address,HEX);
      Serial.println("...!");

      nDevices++;
    }else if(error == 4){
      Serial.print("Ada error yang tidak diketahui di alamat 0x");

      if(address< 16){
        Serial.print("0");
      }
      Serial.print(address,HEX);
    }
  }
  if(nDevices == 0){
    Serial.println("tidak alamat I2C satupun yang terdeteksi");
  }else{
    Serial.print("selesai");
  }
  delay(5000);
}

