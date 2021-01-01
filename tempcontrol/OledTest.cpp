#include "OledTest.h"

#define NUMFLAKES     10 // Number of snowflakes in the animation example
#define LOGO_HEIGHT   16
#define LOGO_WIDTH    16

static const unsigned char PROGMEM logo_bmp[] =
{ B00000000, B11000000,
  B00000001, B11000000,
  B00000001, B11000000,
  B00000011, B11100000,
  B11110011, B11100000,
  B11111110, B11111000,
  B01111110, B11111111,
  B00110011, B10011111,
  B00011111, B11111100,
  B00001101, B01110000,
  B00011011, B10100000,
  B00111111, B11100000,
  B00111111, B11110000,
  B01111100, B11110000,
  B01110000, B01110000,
  B00000000, B00110000 };

OledTest::OledTest(Adafruit_SSD1306 *display) {
  display_ = display;
}


void OledTest::drawline() {
  int16_t i;

  display_->clearDisplay(); // Clear display buffer

  for(i=0; i<display_->width(); i+=4) {
    display_->drawLine(0, 0, i, display_->height()-1, SSD1306_WHITE);
    display_->display(); // Update screen with each newly-drawn line
    delay(1);
  }
  for(i=0; i<display_->height(); i+=4) {
    display_->drawLine(0, 0, display_->width()-1, i, SSD1306_WHITE);
    display_->display();
    delay(1);
  }
  delay(250);

  display_->clearDisplay();

  for(i=0; i<display_->width(); i+=4) {
    display_->drawLine(0, display_->height()-1, i, 0, SSD1306_WHITE);
    display_->display();
    delay(1);
  }
  for(i=display_->height()-1; i>=0; i-=4) {
    display_->drawLine(0, display_->height()-1, display_->width()-1, i, SSD1306_WHITE);
    display_->display();
    delay(1);
  }
  delay(250);

  display_->clearDisplay();

  for(i=display_->width()-1; i>=0; i-=4) {
    display_->drawLine(display_->width()-1, display_->height()-1, i, 0, SSD1306_WHITE);
    display_->display();
    delay(1);
  }
  for(i=display_->height()-1; i>=0; i-=4) {
    display_->drawLine(display_->width()-1, display_->height()-1, 0, i, SSD1306_WHITE);
    display_->display();
    delay(1);
  }
  delay(250);

  display_->clearDisplay();

  for(i=0; i<display_->height(); i+=4) {
    display_->drawLine(display_->width()-1, 0, 0, i, SSD1306_WHITE);
    display_->display();
    delay(1);
  }
  for(i=0; i<display_->width(); i+=4) {
    display_->drawLine(display_->width()-1, 0, i, display_->height()-1, SSD1306_WHITE);
    display_->display();
    delay(1);
  }

  delay(2000); // Pause for 2 seconds
}

void OledTest::drawrect(void) {
  display_->clearDisplay();

  for(int16_t i=0; i<display_->height()/2; i+=2) {
    display_->drawRect(i, i, display_->width()-2*i, display_->height()-2*i, SSD1306_WHITE);
    display_->display(); // Update screen with each newly-drawn rectangle
    delay(1);
  }

  delay(2000);
}

void OledTest::fillrect(void) {
  display_->clearDisplay();

  for(int16_t i=0; i<display_->height()/2; i+=3) {
    // The INVERSE color is used so rectangles alternate white/black
    display_->fillRect(i, i, display_->width()-i*2, display_->height()-i*2, SSD1306_INVERSE);
    display_->display(); // Update screen with each newly-drawn rectangle
    delay(1);
  }

  delay(2000);
}

void OledTest::drawcircle(void) {
  display_->clearDisplay();

  for(int16_t i=0; i<max(display_->width(),display_->height())/2; i+=2) {
    display_->drawCircle(display_->width()/2, display_->height()/2, i, SSD1306_WHITE);
    display_->display();
    delay(1);
  }

  delay(2000);
}

void OledTest::fillcircle(void) {
  display_->clearDisplay();

  for(int16_t i=max(display_->width(),display_->height())/2; i>0; i-=3) {
    // The INVERSE color is used so circles alternate white/black
    display_->fillCircle(display_->width() / 2, display_->height() / 2, i, SSD1306_INVERSE);
    display_->display(); // Update screen with each newly-drawn circle
    delay(1);
  }

  delay(2000);
}

void OledTest::drawroundrect(void) {
  display_->clearDisplay();

  for(int16_t i=0; i<display_->height()/2-2; i+=2) {
    display_->drawRoundRect(i, i, display_->width()-2*i, display_->height()-2*i,
      display_->height()/4, SSD1306_WHITE);
    display_->display();
    delay(1);
  }

  delay(2000);
}

void OledTest::fillroundrect(void) {
  display_->clearDisplay();

  for(int16_t i=0; i<display_->height()/2-2; i+=2) {
    // The INVERSE color is used so round-rects alternate white/black
    display_->fillRoundRect(i, i, display_->width()-2*i, display_->height()-2*i,
      display_->height()/4, SSD1306_INVERSE);
    display_->display();
    delay(1);
  }

  delay(2000);
}

void OledTest::drawtriangle(void) {
  display_->clearDisplay();

  for(int16_t i=0; i<max(display_->width(),display_->height())/2; i+=5) {
    display_->drawTriangle(
      display_->width()/2  , display_->height()/2-i,
      display_->width()/2-i, display_->height()/2+i,
      display_->width()/2+i, display_->height()/2+i, SSD1306_WHITE);
    display_->display();
    delay(1);
  }

  delay(2000);
}

void OledTest::filltriangle(void) {
  display_->clearDisplay();

  for(int16_t i=max(display_->width(),display_->height())/2; i>0; i-=5) {
    // The INVERSE color is used so triangles alternate white/black
    display_->fillTriangle(
      display_->width()/2  , display_->height()/2-i,
      display_->width()/2-i, display_->height()/2+i,
      display_->width()/2+i, display_->height()/2+i, SSD1306_INVERSE);
    display_->display();
    delay(1);
  }

  delay(2000);
}

void OledTest::drawchar(void) {
  display_->clearDisplay();

  display_->setTextSize(1);      // Normal 1:1 pixel scale
  display_->setTextColor(SSD1306_WHITE); // Draw white text
  display_->setCursor(0, 0);     // Start at top-left corner
  display_->cp437(true);         // Use full 256 char 'Code Page 437' font

  // Not all the characters will fit on the display_-> This is normal.
  // Library will draw what it can and the rest will be clipped.
  for(int16_t i=0; i<256; i++) {
    if(i == '\n') display_->write(' ');
    else          display_->write(i);
  }

  display_->display();
  delay(2000);
}

void OledTest::drawstyles(void) {
  display_->clearDisplay();

  display_->setTextSize(1);             // Normal 1:1 pixel scale
  display_->setTextColor(SSD1306_WHITE);        // Draw white text
  display_->setCursor(0,0);             // Start at top-left corner
  display_->println(F("Hello, world!"));

  display_->setTextColor(SSD1306_BLACK, SSD1306_WHITE); // Draw 'inverse' text
  display_->println(3.141592);

  display_->setTextSize(2);             // Draw 2X-scale text
  display_->setTextColor(SSD1306_WHITE);
  display_->print(F("0x")); display_->println(0xDEADBEEF, HEX);

  display_->display();
  delay(2000);
}

void OledTest::scrolltext(void) {
  display_->clearDisplay();

  display_->setTextSize(2); // Draw 2X-scale text
  display_->setTextColor(SSD1306_WHITE);
  display_->setCursor(10, 0);
  display_->println(F("scroll"));
  display_->display();      // Show initial text
  delay(100);

  // Scroll in various directions, pausing in-between:
  display_->startscrollright(0x00, 0x0F);
  delay(2000);
  display_->stopscroll();
  delay(1000);
  display_->startscrollleft(0x00, 0x0F);
  delay(2000);
  display_->stopscroll();
  delay(1000);
  display_->startscrolldiagright(0x00, 0x07);
  delay(2000);
  display_->startscrolldiagleft(0x00, 0x07);
  delay(2000);
  display_->stopscroll();
  delay(1000);
}

void OledTest::drawbitmap(void) {
  display_->clearDisplay();

  display_->drawBitmap(
    (display_->width()  - LOGO_WIDTH ) / 2,
    (display_->height() - LOGO_HEIGHT) / 2,
    logo_bmp, LOGO_WIDTH, LOGO_HEIGHT, 1);
  display_->display();
  delay(1000);
}

#define XPOS   0 // Indexes into the 'icons' array in function below
#define YPOS   1
#define DELTAY 2

void OledTest::animate(const uint8_t *bitmap, uint8_t w, uint8_t h) {
  int8_t f, icons[NUMFLAKES][3];

  // Initialize 'snowflake' positions
  for(f=0; f< NUMFLAKES; f++) {
    icons[f][XPOS]   = random(1 - LOGO_WIDTH, display_->width());
    icons[f][YPOS]   = -LOGO_HEIGHT;
    icons[f][DELTAY] = random(1, 6);
    Serial.print(F("x: "));
    Serial.print(icons[f][XPOS], DEC);
    Serial.print(F(" y: "));
    Serial.print(icons[f][YPOS], DEC);
    Serial.print(F(" dy: "));
    Serial.println(icons[f][DELTAY], DEC);
  }

  for(;;) { // Loop forever...
    display_->clearDisplay(); // Clear the display buffer

    // Draw each snowflake:
    for(f=0; f< NUMFLAKES; f++) {
      display_->drawBitmap(icons[f][XPOS], icons[f][YPOS], bitmap, w, h, SSD1306_WHITE);
    }

    display_->display(); // Show the display buffer on the screen
    delay(200);        // Pause for 1/10 second

    // Then update coordinates of each flake...
    for(f=0; f< NUMFLAKES; f++) {
      icons[f][YPOS] += icons[f][DELTAY];
      // If snowflake is off the bottom of the screen...
      if (icons[f][YPOS] >= display_->height()) {
        // Reinitialize to a random position, just off the top
        icons[f][XPOS]   = random(1 - LOGO_WIDTH, display_->width());
        icons[f][YPOS]   = -LOGO_HEIGHT;
        icons[f][DELTAY] = random(1, 6);
      }
    }
  }
}
