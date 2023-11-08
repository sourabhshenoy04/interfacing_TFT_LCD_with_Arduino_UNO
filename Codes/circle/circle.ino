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

void setup() {
  // Initialize the TFT display
  tft.begin(0x9341); // Pass the display controller ID

  // Set the rotation of the display (optional)
  tft.setRotation(1);
}

void loop() {
  // Display the circle pixel on the TFT display
  tft.fillScreen(0x0000); // Clear the screen

  int centerX = TFT_WIDTH / 2; // X-coordinate of the center of the circle
  int centerY = TFT_HEIGHT / 2; // Y-coordinate of the center of the circle
  int radius = 50; // Radius of the circle

  for (int y = centerY - radius; y <= centerY + radius; y++) {
    for (int x = centerX - radius; x <= centerX + radius; x++) {
      if ((x - centerX) * (x - centerX) + (y - centerY) * (y - centerY) <= radius * radius) {
        tft.drawPixel(x, y, 0xFFFF); // White color for circle pixels
      }
    }
  }

  while (true) {} // Optional: Stop the loop to display the image once
}
/*circle*/