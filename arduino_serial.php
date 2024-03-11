<?php
class ArduinoSerial
{
    private $device;

    public function __construct($device = "/dev/ttyUSB0")
    {
        $this->device = $device;
    }

    public function sendData($data)
    {
        $handle = fopen($this->device, "w");
        if ($handle) {
            fwrite($handle, $data . "\n");
            fclose($handle);
            return true;
        } else {
            return false;
        }
    }

    public function receiveData()
    {
        $handle = fopen($this->device, "r");
        $receivedData = '';
        if ($handle) {
            while (($line = fgets($handle)) !== false) {
                $receivedData .= $line;
            }
            fclose($handle);
            return $receivedData;
        } else {
            return false;
        }
    }
}
?>