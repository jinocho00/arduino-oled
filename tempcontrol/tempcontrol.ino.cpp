# 1 "C:\\Users\\Public\\Documents\\ESTsoft\\CreatorTemp\\tmp74wxebka"
#include <Arduino.h>
# 1 "C:/Users/Administrator/Documents/PlatformIO/Projects/210102-025200-sparkfun_promicro16/src/tempcontrol.ino"
# 21 "C:/Users/Administrator/Documents/PlatformIO/Projects/210102-025200-sparkfun_promicro16/src/tempcontrol.ino"
#include <OneWire.h>
#include <DS18B20.h>
#include "OledDisplay.h"
#include "OledTest.h"

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET 4
#define ONE_WIRE_BUS 7

OledDisplay display(SCREEN_WIDTH, SCREEN_HEIGHT, OLED_RESET);
OledTest oledTest(display.getDisplay());
OneWire oneWire(ONE_WIRE_BUS);
DS18B20 sensor(&oneWire);
void setup();
void loop();
#line 36 "C:/Users/Administrator/Documents/PlatformIO/Projects/210102-025200-sparkfun_promicro16/src/tempcontrol.ino"
void setup() {
  Serial.begin (115200);


  sensor.begin();

  display.setTargetTemperature(30);
  display.setOffset(1);

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }



  display.display();
  delay(2000);

  Serial.println ("Start test ...");
}

void loop() {
  sensor.requestTemperatures();
  while (!sensor.isConversionComplete());
  display.update(sensor.getTempC());
}