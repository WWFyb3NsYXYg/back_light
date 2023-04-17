# Bicycle/car lamp with addressable LEDs

  <p align="center">
  <img src="https://user-images.githubusercontent.com/87089735/232594540-9d2a4889-7ce9-4bf9-b4e6-430f3cde121d.jpg" height="300px"> 
  <p>
  
## Project description
I present to your attention a flashlight on addressable LEDs with effects.
### Feature 
- Smooth turning on of the lamp, whether it is white, in the case of the front lamp, or red, if the rear lamp mode is on.
- Universal firmware, for the front light and for the rear. The mode is changed by the value of `TYPE`
- In tail light mode, when the switch is pressed, the brake will flash red. If you press the button in the front light mode, the effect of police flashers will turn on. This can be commented out with `//` on [line 74](https://user-images.githubusercontent.com/87089735/232593620-75b9aa7b-ed1e-411e-a577-7f69bb86da2a.png).

- The turn signal turns on like in modern cars (from right to left in the case of a left turn signal).
- You can configure how smooth the turn signal setting is `BlinkerSpeed`
- The turn signal can be turned on both on the entire plane and on half. Setting by `STYLE`

## Folders
- **libraries** - project libraries.
- **firmware** - Firmware for Arduino
- **schemes** - component connection diagrams


## Scheme
![SCHEME](https://github.com/WWFyb3NsYXYg/back_light/blob/main/schemes/scheme1.png)


## Settings in code

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
