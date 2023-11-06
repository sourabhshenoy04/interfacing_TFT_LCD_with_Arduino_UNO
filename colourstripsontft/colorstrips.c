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

    // Set the text color
    tft.setTextColor(0x878623); // Royal gold

    // Set the text size
    tft.setTextSize(2);

    // Fill the screen with rainbow (VIBGYOR) colors
    rainbowBackground();
    delay(2000);
}

void loop()
{
    // Empty loop
}

void rainbowBackground()
{
    int colors[] = {0xF800, 0xFF8000, 0xFFFF00, 0x00FF00, 0x0000FF, 0x4B0082, 0xEE82EE}; // Rainbow (VIBGYOR) colors

    int sectionSize = tft.height() / 7; // Divide the screen height into 7 sections for each color

    for (int y = 0; y < tft.height(); y++)
    {
        int section = y / sectionSize;
        int color = colors[section];

        tft.drawFastHLine(0, y, tft.width(), color);
    }
}
