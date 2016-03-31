// This #include statement was automatically added by the Particle IDE.
#include "CE_BME280.h"

/***************************************************************************
  This is a library for the BME280 humidity, temperature & pressure sensor
  from https://www.controleverything.com

  Designed specifically to work with the Adafruit BME280 Breakout
  ----> http://www.adafruit.com/products/2650

  These sensors use I2C to communicate, 2 are required
  to interface.

  Adafruit invests time and resources providing this open source code,
  please support Adafruit andopen-source hardware by purchasing products
  from Adafruit!

  Written by Limor Fried & Kevin Townsend for Adafruit Industries.
  BSD license, all text above must be included in any redistribution

  This file was modified by Thomas Rockenbauer (https://github.com/hl68fx)
  in order to work with Particle Photon & Core.
 ***************************************************************************/

#define SEALEVELPRESSURE_HPA (1013.25)

CE_BME280 bme; // I2C

void setup() {
  Serial.begin(9600);
  Serial.println(F("BME280 test"));

  if (!bme.begin()) {
    Serial.println("Could not find a valid BME280 sensor, check wiring!");
    while (1);
  }
}

void loop() {
    Serial.print("Temperature = ");
    Serial.print(bme.readTemperature());
    Serial.println(" *C");

    Serial.print("Pressure = ");

    Serial.print(bme.readPressure() / 100.0F);
    Serial.println(" hPa");

    Serial.print("Approx. Altitude = ");
    Serial.print(bme.readAltitude(SEALEVELPRESSURE_HPA));
    Serial.println(" m");

    Serial.print("Humidity = ");
    Serial.print(bme.readHumidity());
    Serial.println(" %");

    Serial.println();
    delay(2000);
}
