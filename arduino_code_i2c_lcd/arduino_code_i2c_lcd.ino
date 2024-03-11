#include <LiquidCrystal_I2C.h>

// Set the address of the LCD
#define LCD_ADDRESS 0x27  // Change this to the address of your LCD module

// Set the number of columns and rows of the LCD
#define LCD_COLUMNS 16
#define LCD_ROWS 2

// Initialize the LCD object with the I2C address and LCD dimensions
LiquidCrystal_I2C lcd(LCD_ADDRESS, LCD_COLUMNS, LCD_ROWS);

void setup() {
  pinMode(7, OUTPUT);
  digitalWrite(7, LOW);
  // Initialize serial communication at 9600 baud rate
  Serial.begin(9600);

  // Initialize the LCD
  lcd.init();

  // Turn on the backlight
  lcd.backlight();

  // Clear the LCD screen
  lcd.clear();
  lcd.print("Ready...");
}

void loop() {
  // Check if data is available to read from serial port
  if (Serial.available() > 0) {
    digitalWrite(7, HIGH);
    // Read the incoming string from serial port
    String receivedString = Serial.readStringUntil('\n');
    digitalWrite(7, LOW);

    // Display the received string on the LCD
    lcd.clear();  // Clear the LCD screen before displaying the new string
    lcd.print(receivedString);
  }
  delay(100);
}
