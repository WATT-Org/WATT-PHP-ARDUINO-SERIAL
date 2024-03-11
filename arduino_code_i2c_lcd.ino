#include <LiquidCrystal_I2C.h>

// Set the address of the LCD
#define LCD_ADDRESS 0x27 // Change this to the address of your LCD module

// Set the number of columns and rows of the LCD
#define LCD_COLUMNS 16
#define LCD_ROWS 2

// Initialize the LCD object with the I2C address and LCD dimensions
LiquidCrystal_I2C lcd(LCD_ADDRESS, LCD_COLUMNS, LCD_ROWS);

void setup()
{
    // Initialize serial communication at 9600 baud rate
    Serial.begin(9600);

    // Initialize the LCD
    lcd.init();

    // Turn on the backlight
    lcd.backlight();

    // Clear the LCD screen
    lcd.clear();
}

void loop()
{
    // Check if data is available to read from serial port
    if (Serial.available() > 0)
    {
        // Read the incoming byte from serial port
        char receivedChar = Serial.read();

        // Display the received character on the LCD
        lcd.print(receivedChar);

        // Check if the LCD cursor reached the end of the line
        if (lcd.getCursorCol() == LCD_COLUMNS - 1 && lcd.getCursorRow() == LCD_ROWS - 1)
        {
            // Move the cursor to the beginning of the second line
            lcd.setCursor(0, 1);
        }
    }
}
