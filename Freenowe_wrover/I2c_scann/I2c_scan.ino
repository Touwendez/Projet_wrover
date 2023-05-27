#include <Wire.h>

void setup() {
  Serial.begin(9600);
  Wire.begin();
  delay(2000); // Attendez que le port série soit prêt

  Serial.println("\nI2C Scanner");
}

void loop() {
  i2cScanner();
  delay(5000); // Scanner I2C toutes les 5 secondes
}

void i2cScanner() {
  byte error, address;
  int devices = 0;

  Serial.println("Scanning...");

  for(address = 1; address < 127; address++ ) {
    Wire.beginTransmission(address);
    error = Wire.endTransmission();

    if (error == 0) {
      Serial.print("I2C device found at address 0x");
      if (address < 16) {
        Serial.print("0");
      }
      Serial.print(address, HEX);
      Serial.println("");
      devices++;
    }
  }

  if (devices == 0) {
    Serial.println("No I2C devices found\n");
  }
  else {
    Serial.println("Done\n");
  }
}
