// ================ SETTINGS ================

// ------ Strip ------
#define LED_PIN 2   //Connecting the LED Strip Signal
#define NUM_LEDS 5  //Number of LEDs
#define STYLE 2     //Turn signal style. 1 - On half of the tape, 2 - on the entire surface
#define TYPE 1     // Lantern type. 1 - front, 2 - rear


// ------ Buttons -------
#define L_BTN_PIN 3      //Signal (button) left turn signal
#define R_BTN_PIN 4      //Signal (button) turn signal right
#define STOP_BTN_PIN 6   //Stop signal (button)

// ------ Speed/Display duration ------
int BlinkerSpeed = 100;      //Turn signal speed indicator.
int BlinkerOffDelay = 250;  //Turn signal off time.
int StartupSpeed = 5;       //Normal mode off time

// ================ FOR DEVELOPERS ================

#include "Arduino.h"
#include <FastLED.h>

#define BlinkerLEDs NUM_LEDS / 2

bool is_on = true;

CRGB leds[NUM_LEDS];  // Creating an array of LEDs

void setup() {
  // Button initialization
  pinMode(L_BTN_PIN, INPUT_PULLUP);
  pinMode(R_BTN_PIN, INPUT_PULLUP);
  pinMode(STOP_BTN_PIN, INPUT_PULLUP);

  // Strip initialization
  FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, NUM_LEDS);  //
}

void loop() {

  // Handling events for the left turn signal
  if (!digitalRead(L_BTN_PIN) == 1 && digitalRead(R_BTN_PIN) == 1) {
    Dim();          // Turning off the LEDs
    LeftBlinker();  // Turn on the left turn signal
    Dim();          // Turning off the LEDs
    delay(BlinkerOffDelay);

    is_on = true;
  }
  // Handling events for the right turn signal
  if (!digitalRead(R_BTN_PIN) == 1 && digitalRead(L_BTN_PIN) == 1) {
    Dim();           // Turning off the LEDs
    RightBlinker();  // Turn on the right turn signal
    Dim();           // Turning off the LEDs
    delay(BlinkerOffDelay);

    is_on = true;
  }
  //  Event handling for alarms
  if (!digitalRead(R_BTN_PIN) == 1 && !digitalRead(L_BTN_PIN) == 1) {
    Dim();           // Turning off the LEDs
    AlarmBlinker();  // Turn on the emergency flasher (blinking both turn signals)
    Dim();           // Turning off the LEDs
    delay(BlinkerOffDelay);

    is_on = true;
  }
  // Event handling for a stoplight
  if (!digitalRead(STOP_BTN_PIN) == 1) {
    switch (TYPE) {
    case 1:
        Police(); // This line can be commented out, it's for fun)
      break;

    case 2:
      Dim();  // Turning off the LEDs
      Stop();
      break;
  }
    is_on = true;
  }

  if (is_on == true && digitalRead(STOP_BTN_PIN) == 1 && digitalRead(R_BTN_PIN) == 1 && digitalRead(L_BTN_PIN) == 1) {
    is_on = false;
    
    switch (TYPE) {
    case 1:
        White_ON();
      break;

    case 2:
        RED_ON();
      break;
  }
  }

}
