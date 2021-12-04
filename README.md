# Arduino Temperature and Humidity sensor

## Description
Measures temperature and humidity with HTU21D + SD/microSD module + Arduino.
Arduino measures temperature and humidity each 10seconds, the result is written to SD card to the file values.csv
WARNING: File and folder names can have only 8 characters and extension only 3 characters (old school names)


## Used components:
- Arduino UNO
- HTU21D sensor (I2C humidity and temperatude sensor)
- SD card reader

## Project structure
- TempAndHumiditySensor (Arduino code)
- datasheets (datashetts of used components)
- libraries (3rd party libraries)
- schematic (wiring diagram)

## TODO
- Add Real-Time Clock module
- Add timestamps to CSV

