#ifndef _OLED_TEST_H_
#define _OLED_TEST_H_

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

class OledTest {
public:
  OledTest(Adafruit_SSD1306 *display);
  void drawline();
  void drawrect(void);
  void fillrect(void);
  void drawcircle(void);
  void fillcircle(void);
  void drawroundrect(void);
  void fillroundrect(void);
  void drawtriangle(void);
  void filltriangle(void);
  void drawchar(void);
  void drawstyles(void);
  void scrolltext(void);
  void drawbitmap(void);
  void animate(const uint8_t *bitmap, uint8_t w, uint8_t h);

  Adafruit_SSD1306 *display_;
};

#endif /* _OLED_TEST_H_ */