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
    tft.fillScreen(0x0000); // Black

    // Set the text color
    tft.setTextColor(0xFFFF); // White

    // Set the text size
    tft.setTextSize(2);
}
void loop()
{
    // Clear the screen
    tft.fillScreen(0x0000); // Black

    // Set the cursor position
    tft.setCursor(50, 50);

    // Display rainbow colors
    for (int i = 0; i < 360; i += 10)
    {
        // Convert the hue to RGB values
        int r, g, b;
        HSVtoRGB(i, 255, 255, r, g, b);

        // Set the text color
        tft.setTextColor(tft.color565(r, g, b));

        // Display a character
        tft.print("hello world\n");

        delay(200); // Delay for 200 milliseconds
    }
}

// Function to convert HSV color to RGB color
void HSVtoRGB(int hue, int saturation, int value, int &r, int &g, int &b)
{
    int h = hue / 60;
    int f = hue % 60;
    int p = (255 * (255 - saturation)) >> 8;
    int q = (255 * (255 - (saturation * f) / 60)) >> 8;
    int t = (255 * (255 - (saturation * (60 - f)) / 60)) >> 8;

    switch (h)
    {
    case 0:
        r = value;
        g = t;
        b = p;
        break;
    case 1:
        r = q;
        g = value;
        b = p;
        break;
    case 2:
        r = p;
        g = value;
        b = t;
        break;
    case 3:
        r = p;
        g = q;
        b = value;
        break;
    case 4:
        r = t;
        g = p;
        b = value;
        break;
    case 5:
        r = value;
        g = p;
        b = q;
        break;
    default:
        r = 0;
        g = 0;
        b = 0;
        break;
    }
}
