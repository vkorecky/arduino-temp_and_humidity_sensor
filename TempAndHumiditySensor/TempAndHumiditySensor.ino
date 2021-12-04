/*
Measures temperature and humidity with HTU21D + SD/microSD module + Arduino.
Arduino measures temperature and humidity each 10seconds, the result is written to SD card to the file values.csv
WARNING: File and folder names can have only 8 characters and extension only 3 characters (old school names)

modified on 4 Dec 2021
by Vladislav Korecky
*/

#include <Wire.h>
#include "SparkFunHTU21D.h"
#include <SPI.h>
#include <SD.h>

HTU21D HTU21Dsensor;  // HTU21D sensor initialization
const int sd_CS = 10; // CS pin number on SD card

void setup() {  
  Wire.begin(); 
    
  // Setup of serial link communication
  Serial.begin(9600); //  Speed 9600 baud
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  // Setup of communication with HTU21D sensor
  HTU21Dsensor.begin();

  // Setup of SD card module
  if (!SD.begin(sd_CS))
  {
      Serial.println("ERROR: Initialization of SD card failed. SD card is not connected or card is corrupted.");
      return;
  }
  Serial.println("SD card successfully initialized.");
}

void saveTemperatureAndHumidity() {
  // Reading of temperature and humidity from HTU21D sensor
  float temperature = HTU21Dsensor.readTemperature();
  float humidity = HTU21Dsensor.readHumidity();
  if (temperature > 125 | humidity > 100) {
    Serial.println("ERROR: HTU21D communication error.");
  } else {
    // Print to Serial output
    Serial.print(temperature, 1);
    Serial.print("°C,");
    Serial.print(humidity, 0);
    Serial.print("%");
    Serial.println();    
    // Print to CSV File
    File csvFile = SD.open("values.csv", FILE_WRITE);        
    if (csvFile) {
      csvFile.print(temperature, 1);
      csvFile.print("°C,");
      csvFile.print(humidity, 0);
      csvFile.print("%");
      csvFile.println();
      csvFile.close();
    } else {
      Serial.println("ERROR: Can't write data to SD card.");
    }
  }
}

void loop() {
  saveTemperatureAndHumidity();
  delay(10000);
}
