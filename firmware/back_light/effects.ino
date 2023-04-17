// effects

void Dim() {  //  LED off function
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB(0, 0, 0);  
  }
  FastLED.show();  
}

void LeftBlinker() {
  switch (STYLE) {
    case 1:
      for (int i = (BlinkerLEDs - 1); i >= 0; i--) {
        leds[i] = CRGB(255, 40, 0);  
        FastLED.show();              
        delay(BlinkerSpeed);          
      }
      break;

    case 2:
      for (int i = (NUM_LEDS - 1); i >= 0; i--) {
        leds[i] = CRGB(255, 40, 0);
        FastLED.show();       
        delay(BlinkerSpeed);   
      }
      break;
  }
}

void RightBlinker() {
  switch (STYLE) {
    case 1:
      for (int i = (NUM_LEDS - BlinkerLEDs); i < NUM_LEDS; i++) {
        leds[i] = CRGB(255, 40, 0);
        FastLED.show();       
        delay(BlinkerSpeed);   
      }
      break;

    case 2:
      for (int i = 0; i < NUM_LEDS; i++) {

        leds[i] = CRGB(255, 40, 0);
        FastLED.show();       
        delay(BlinkerSpeed);   
      }
      break;
  }
}

void White_ON() {
  for (int j = 0; j <= 255; j++) {
    for (int i = 0; i < NUM_LEDS; i++) {
      leds[i] = CRGB(j, j, j);
    }
    FastLED.show();  
    delay(StartupSpeed);
  }
}

void RED_ON() {
  for (int j = 0; j <= 25; j++) {
    for (int i = 0; i < NUM_LEDS; i++) {
      leds[i] = CRGB(j, 0, 0);
    }
    FastLED.show();  
    delay(StartupSpeed);
  }
}

void Police() {
  for (int k = 0; k < 2; k++) {
    for (int j = 0; j < 4; j++) {
      for (int i = 0; i < BlinkerLEDs + 1; i++) {
        leds[i] = CRGB(255, 0, 0);
      }
      FastLED.show();  
      delay(100);
      Dim();
      delay(100);
    }
    for (int j = 0; j < 4; j++) {
      for (int i = BlinkerLEDs; i < NUM_LEDS; i++) {
        leds[i] = CRGB(0, 0, 255);
      }
      FastLED.show();  
      delay(100);
      Dim();
      delay(100);
    }
  }
  for (int j = 0; j < 4; j++) {
    for (int i = 0; i < BlinkerLEDs; i++) {
      leds[i] = CRGB(255, 0, 0);
    }
    for (int i = BlinkerLEDs + 1; i < NUM_LEDS; i++) {
      leds[i] = CRGB(0, 0, 255);
    }
    leds[BlinkerLEDs] = CRGB(255, 255, 255);
    FastLED.show();  
    delay(100);
    Dim();
    delay(100);
  }
}

void Stop() {
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB(60, 0, 0);
  }
  FastLED.show();  
  for (int i = (NUM_LEDS - 1); i >= 0; i--) {
    leds[i] = CRGB(255, 0, 0);
    leds[NUM_LEDS - 1 - i] = CRGB(255, 0, 0);
    FastLED.show();  
    delay(BlinkerSpeed / 4);
  }
}

void AlarmBlinker() {
  for (int i = (NUM_LEDS - 1); i >= 0; i--) {
    leds[i] = CRGB(255, 40, 0);
    leds[NUM_LEDS - 1 - i] = CRGB(255, 40, 0);
    FastLED.show();  
    delay(BlinkerSpeed);
  }
}
