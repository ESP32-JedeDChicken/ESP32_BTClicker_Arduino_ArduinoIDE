// Hold Flash... > Upload > Connecting... (Click RST) > Writing @ 0x00... (Release Flash)
// Click RST to start program...

/*
 * ESP32 BLE Presentation Clicker
 * Button Pins:
 *   13 = Previous Slide (Left Arrow)
 *   14 = Next Slide     (Right Arrow)
 *   15 = Fullscreen     (F11)
 * 
 * LED (dim):
 *   LED_PIN = 2  (or any available GPIO)
 *   LED -> resistor (10k) -> GPIO
 *   Other side of LED -> GND
 */

#include "BleKeyboard.h"

BleKeyboard bleKeyboard("ESP32 Clicker");

#define BTN_PREV 13
#define BTN_NEXT 14
#define BTN_FULL 15

#define LED_PIN 2   // change if you want other pin

const int debounceDelay = 150;

void setup() {
  Serial.begin(115200);

  pinMode(BTN_PREV, INPUT_PULLUP);
  pinMode(BTN_NEXT, INPUT_PULLUP);
  pinMode(BTN_FULL, INPUT_PULLUP);

  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);  // LED initially off

  Serial.println("Starting BLE Keyboard...");
  bleKeyboard.begin();
}

void loop() {
  if (!bleKeyboard.isConnected()) {
    // Not connected: LED OFF
    digitalWrite(LED_PIN, LOW);
    Serial.println("Not connected...");
    delay(100);
    return;
  }

  // Connected: LED ON (dim because of 10k resistor)
  digitalWrite(LED_PIN, HIGH);

  // Button logic (active LOW)
  if (digitalRead(BTN_PREV) == LOW) {
    bleKeyboard.write(KEY_LEFT_ARROW);
    Serial.println("Left");
    delay(debounceDelay);
    while (digitalRead(BTN_PREV) == LOW);  // wait for release
  }

  if (digitalRead(BTN_NEXT) == LOW) {
    bleKeyboard.write(KEY_RIGHT_ARROW);
    Serial.println("Right");
    delay(debounceDelay);
    while (digitalRead(BTN_NEXT) == LOW);
  }

  if (digitalRead(BTN_FULL) == LOW) {
    bleKeyboard.write(KEY_F11);
    Serial.println("F11");
    delay(debounceDelay);
    while (digitalRead(BTN_FULL) == LOW);
  }

  delay(10); // small idle delay
}
