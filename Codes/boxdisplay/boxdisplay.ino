#include <Adafruit_GFX.h>
#include <MCUFRIEND_kbv.h>

// Pin definitions for TFT display
#define LCD_CS A3
#define LCD_CD A2
#define LCD_WR A1
#define LCD_RD A0
#define LCD_RST A4

// Initialize the TFT display
MCUFRIEND_kbv tft;

// Image dimensions
#define TFT_WIDTH 320
#define TFT_HEIGHT 240

// Image data (smiley face)
const uint16_t image_data[] PROGMEM = {
  // Image pixel data in 16-bit color format
  // ...
};

void setup() {
  // Initialize the TFT display
  tft.begin(0x9341); // Pass the display controller ID

  // Set the rotation of the display (optional)
  tft.setRotation(1);
}

void loop() {
  // Display the smiley face on the TFT display
  tft.fillScreen(0x0000); // Clear the screen

  int offsetX = (TFT_WIDTH - 48) / 2; // Center the smiley face horizontally
  int offsetY = (TFT_HEIGHT - 48) / 2; // Center the smiley face vertically

  for (int y = 0; y < 48; y++) {
    for (int x = 0; x < 48; x++) {
      uint16_t pixel = pgm_read_word(&image_data[y * 48 + x]);
      tft.drawPixel(offsetX + x, offsetY + y, pixel);
    }
  }

  while (true) {} // Optional: Stop the loop to display the image once
}