
#include <FastLED.h>

//#define _SS_MAX_RX_BUFF 360 // RX buffer size //BEFORE WAS 64

#define LED_PIN 4
#define NUM_LEDS 10
#define LED_TYPE WS2811
#define COLOR_ORDER RGB
CRGB leds [NUM_LEDS];

void setup()

{
  Serial.begin(115200);
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
  FastLED.setBrightness(255);
  //FastLED.show();
}

void loop()
{

  int i = 0;
  while (i <= NUM_LEDS - 1) {
    if (Serial.available() >= 3) {
      //Serial.write(Serial.read());
      leds[i].red   = Serial.read();
      leds[i].green = Serial.read();
      leds[i].blue  = Serial.read();
      i++;
    }
  }
  Serial.write("f");
  FastLED.show();
}

