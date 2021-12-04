//Senzor teploty a vlhkosti HTU21D @I2C
// připojení potřebných knihoven
#include <Wire.h>
#include "SparkFunHTU21D.h"

// inicializace senzoru z knihovny
HTU21D mujHTU;

void setup() {
  // komunikace po sériové lince rychlostí 9600 baud
  Serial.begin(9600);
  // zahájení komunikace se senzorem
  mujHTU.begin();
}

void loop() {
  // načtení informací o teplotě a vlhkosti
  // do proměnných
  float teplota = mujHTU.readTemperature();
  float vlhkost = mujHTU.readHumidity();
  if (teplota > 125 | vlhkost > 100) {
    Serial.println("Chyba komunikace se senzorem HTU21D!");
  }
  else {
    // vytištění naměřených údajů, 1 ve výpisu označuje
    // počet desetinných míst
    Serial.print("HTU21D | Teplota: ");
    Serial.print(teplota, 1);
    Serial.print(" st C | ");
    Serial.print("Vlhkost: ");
    Serial.print(vlhkost, 1);
    Serial.print("%");
    Serial.println();
  }
  // pauza 1 sekunda mezi výpisy
  delay(1000);
}
