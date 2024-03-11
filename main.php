<?php
require_once 'arduino_serial.php';

// Create an instance of ArduinoSerial with the default device
$arduino = new ArduinoSerial();

// Send data to the Arduino
$dataToSend = "Hello Arduino!";
$success = $arduino->sendData($dataToSend);
if ($success) {
    echo "Data sent successfully.<br>";
} else {
    echo "Failed to send data.<br>";
}

// Receive data from the Arduino
$receivedData = $arduino->receiveData();
if ($receivedData !== false) {
    echo "Received data from Arduino: " . $receivedData . "<br>";
} else {
    echo "Failed to receive data from Arduino.<br>";
}
?>