#include <MCUFRIEND_kbv.h> // Include the MCUFRIEND_kbv Library
#include <Adafruit_GFX.h>  // Include the Adafruit Graphics Library

// Pin definitions for TFT display
#define LCD_CS A3
#define LCD_CD A2
#define LCD_WR A1
#define LCD_RD A0
#define LCD_RST A4

// Initialize the TFT display
MCUFRIEND_kbv tft;

void setup()
{
    // Initialize the TFT display
    tft.begin(0x9341); // Pass the display controller ID

    // Set the rotation of the display (optional)
    tft.setRotation(1);

    // Set the background color
    tft.fillScreen(0xFFD000); // Royal red

    // Set the text color
    tft.setTextColor(0x878623); // Royal gold

    // Set the text size
    tft.setTextSize(2);
}

void loop()
{
    // Clear the screen
    tft.fillScreen(0xFFD000); // Royal red

    // Set the cursor position
    tft.setCursor(50, 50);

    // Display a character
    tft.print("Hello World\n");
    delay(2000); // Delay for 2 seconds
}
