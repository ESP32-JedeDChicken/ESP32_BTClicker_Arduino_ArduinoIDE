# ESP32_Arduino Bluetooth Clicker

This project utilized the "ESP32-BLE-Keyboard" repository by T-vK- https://github.com/T-vK/ESP32-BLE-Keyboard/tree/master


This BT Clicker can be used for presentations.

*Pressing the top and middle buttons shift the presentation to the previous and next slide, respectively (like left and right keyboard press).

*The bottom button toggles the screen between full and windowed (like F11).

*The buttons were pull-up and feature debounce to deal with noise and unintentional presses.

*There's also an LED to indicate bluetooth connection.

*The prototype used a power bank w/ micro-USB cable as power source.


This project utilized the ESP32-CAM CH340 HW818 development board w/ built-in OV2640 camera sensor, and was implemented using the Arduino Framework and Arduino IDE. The board used has similar pinout as AI Thinker ESP32-CAM and ESP32 WROVER.


To upload the code to the board- 

1. Select the appropriate port, hold the FLASH button and when it starts to write, click the RST button (to reset the board into Firmware Download Mode).

2. When the upload succeeded, clik the RST button again (to reset the board into Execution Mode).