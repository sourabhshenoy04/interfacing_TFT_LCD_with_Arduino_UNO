#include <MCUFRIEND_kbv.h> // Include the MCUFRIEND_kbv Library
#include <Adafruit_GFX.h>  // Include the Adafruit Graphics Library
#include <TouchScreen.h>   // Include the TouchScreen Library

// Pin definitions for TFT display
#define LCD_CS A3
#define LCD_CD A2
#define LCD_WR A1
#define LCD_RD A0
#define LCD_RST A4

// Initialize the TFT display
MCUFRIEND_kbv tft;

// Pin definitions for touch screen
#define YP A3
#define XM A2
#define YM 9
#define XP 8

// Touch screen calibration constants
#define TS_MINX 75
#define TS_MINY 74
#define TS_MAXX 946
#define TS_MAXY 914

// Touch screen object
TouchScreen ts = TouchScreen(XP, YP, XM, YM, 300);

void setup() {
  // Initialize the TFT display
  tft.begin(0x9341); // Pass the display controller ID

  // Set the rotation of the display (optional)
  tft.setRotation(1);

  // Set the background color
  tft.fillScreen(0x0000); // Black

  // Set the text color
  tft.setTextColor(0xFFFF); // White

  // Set the text size
  tft.setTextSize(2);
}

void loop() {
  // Check for touch input
  TSPoint touch = ts.getPoint();
  pinMode(XM, OUTPUT);
  pinMode(YP, OUTPUT);

  // Only proceed if a valid touch is detected
  if (touch.z >= 10 && touch.z <= 1000) {
    // Invert and map the touch coordinates to screen coordinates
    int16_t x = map(touch.y, TS_MINY, TS_MAXY, tft.width(), 0);
    int16_t y = map(touch.x, TS_MINX, TS_MAXX, tft.height(), 0);

    // Increase thickness of lines
    tft.drawLine(x, y, x + 1, y + 1, 0xFFFF);

    // Draw a filled rectangle for increased line thickness
    tft.fillRect(x - 1, y - 1, 3, 3, 0xFFFF);
  }

  //delay(10); // Delay to debounce touch input
}