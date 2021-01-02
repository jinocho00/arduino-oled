#ifndef _OLED_DISPLAY_TEMPCONTROL_H_
#define _OLED_DISPLAY_TEMPCONTROL_H_

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "Config.h"

class OledDisplay {
public:
  OledDisplay(int width, int height, int pin_reset);
  ~OledDisplay();
  bool begin();
  void display();
  void update();
  void update(float temperature);
  void update(float temperature, bool onoff);
  void setCurrentTemperature(float temperature);
  void setTargetTemperature(float temperature);
  void setOffset(float offset);
  void setSwitchActive(bool high);
  void setSwitchStatus(float onoff);
  void setConfig(Config conf);
  Adafruit_SSD1306 *getDisplay();

  Adafruit_SSD1306 *display_;
  int width_;
  int height_;
  int pin_reset_;
  float currentTemperature_;
  float targetTemperature_;
  float offset_;
  bool switchActive_;
  bool switchStatus_;
};

#endif /* _OLED_DISPLAY_TEMPCONTROL_H_ */
