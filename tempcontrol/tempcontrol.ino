/**************************************************************************
 This is an example for our Monochrome OLEDs based on SSD1306 drivers

 Pick one up today in the adafruit shop!
 ------> http://www.adafruit.com/category/63_98

 This example is for a 128x64 pixel display using I2C to communicate
 3 pins are required to interface (two I2C and one reset).

 Adafruit invests time and resources providing this open
 source code, please support Adafruit and open-source
 hardware by purchasing products from Adafruit!

 Written by Limor Fried/Ladyada for Adafruit Industries,
 with contributions from the open source community.
 BSD license, check license.txt for more information
 All text above, and the splash screen below must be
 included in any redistribution.
 **************************************************************************/

#include <OneWire.h>
#include <DS18B20.h>
#include "OledDisplay.h"
#include "OledTest.h"

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
#define ONE_WIRE_BUS 7

OledDisplay disp(SCREEN_WIDTH, SCREEN_HEIGHT, OLED_RESET);
OledTest oledTest(disp.getDisplay());
OneWire oneWire(ONE_WIRE_BUS);
DS18B20 sensor(&oneWire);

float targetTemperature = 30;
float currentTemperature = 0;
float offset = 1;

void setup() {
  Serial.begin (115200);
  //while (!Serial){}

  sensor.begin();
  disp.begin();

  disp.setTargetTemperature(targetTemperature);
  disp.setOffset(offset);
  //disp.display();
  //delay(2000); // Pause for 2 seconds
  //Serial.println ("Start test ...");
}

void loop() {
  sensor.requestTemperatures();
  while (!sensor.isConversionComplete());  // wait until sensor is ready
  currentTemperature = sensor.getTempC();
  disp.update(currentTemperature);
}
