#include <ILI9341_t3n.h>
#include <XPT2046_Touchscreen.h>
#include <SPI.h>

#define TX_MIN 500
#define TX_MAX 3750
#define TY_MIN 400
#define TY_MAX 3660

#define CS_PIN  8
#define TIRQ_PIN 2

#define TFT_DC  9
#define TFT_CS 10
#define TFT_RST 3

XPT2046_Touchscreen ts(CS_PIN, TIRQ_PIN);
ILI9341_t3n tft = ILI9341_t3n(TFT_CS, TFT_DC, TFT_RST);

DMAMEM uint16_t fb1[320 * 240]; //frame buffer

void setup() {
  Serial.begin(38400);
  tft.begin();
  tft.setRotation(3);
  tft.setFrameBuffer(fb1);
  tft.useFrameBuffer(true);
  tft.fillScreen(ILI9341_BLACK);
  tft.updateScreen();

  ts.begin();
  ts.setRotation(1);
  while (!Serial && (millis() <= 1000));
}

void loop() {
  tft.updateScreen();
}

word ConvertRGB( byte R, byte G, byte B)
{
  return ( ((R & 0xF8) << 8) | ((G & 0xFC) << 3) | (B >> 3) );
}
