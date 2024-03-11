// Pins for the LEDs
const int ledPin1 = 13; // Pin connected to the first LED
const int ledPin2 = 12; // Pin connected to the second LED

void setup()
{
    // Initialize serial communication at 9600 baud rate
    Serial.begin(9600);

    // Set the LED pins as outputs
    pinMode(ledPin1, OUTPUT);
    pinMode(ledPin2, OUTPUT);
}

void loop()
{
    // Check if data is available to read from serial port
    if (Serial.available() > 0)
    {
        // Read the incoming byte from serial port
        char command = Serial.read();

        // Respond to different commands
        if (command == '1')
        {
            digitalWrite(ledPin1, HIGH); // Turn on the first LED
            digitalWrite(ledPin2, LOW);  // Turn off the second LED
        }
        else if (command == '2')
        {
            digitalWrite(ledPin1, LOW);  // Turn off the first LED
            digitalWrite(ledPin2, HIGH); // Turn on the second LED
        }
        else if (command == '0')
        {
            digitalWrite(ledPin1, LOW); // Turn off both LEDs
            digitalWrite(ledPin2, LOW);
        }
    }
}
