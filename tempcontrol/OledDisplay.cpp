#include <SPI.h>
#include <Wire.h>
#include "OledDisplay.h"

OledDisplay::OledDisplay(int width, int height, int pin_reset) {
  display_ = new Adafruit_SSD1306(width, height, &Wire, pin_reset);
  width_ = width;
  height_ = height;
  pin_reset_ = pin_reset;
  currentTemperature_ = 0;
  targetTemperature_ = 30;
  offset_ = 1;
}

OledDisplay::~OledDisplay() {
  delete display_;
}

bool OledDisplay::begin() {
  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display_->begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    //Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }
  return true;
}

void OledDisplay::display() {
  display_->display();
}

void OledDisplay::update() {
  display_->clearDisplay();
  display_->setTextSize(2);             // Normal 1:1 pixel scale
  display_->setTextColor(SSD1306_WHITE);        // Draw white text
  display_->setCursor(0,0);             // Start at top-left corner
  display_->print("TAR: ");
  display_->println(targetTemperature_);
  display_->print("CUR: ");
  display_->println(currentTemperature_);
  display_->display();
}

void OledDisplay::update(float temperature) {
  currentTemperature_ = temperature;
  update();
}

void OledDisplay::setCurrentTemperature(float temperature) {
  currentTemperature_ = temperature;
}

void OledDisplay::setTargetTemperature(float temperature) {
  targetTemperature_ = temperature;
}

void OledDisplay::setOffset(float offset) {
   offset_ = offset; 
}

Adafruit_SSD1306 *OledDisplay::getDisplay() {
  return display_;
}
