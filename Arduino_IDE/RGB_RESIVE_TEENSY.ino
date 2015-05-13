#include <OctoWS2811.h>

const int ledsPerStrip = 120;

DMAMEM int displayMemory[ledsPerStrip * 6];
int drawingMemory[ledsPerStrip * 6];

const int config = WS2811_GRB | WS2811_800kHz;

OctoWS2811 leds(ledsPerStrip, displayMemory, drawingMemory, config);

void setup()
{
  Serial.begin(48000000);
  leds.begin();
  leds.show();

}

void loop()
{

  int i = 0;
  while (i < NUMPIXELS) {
    if (Serial.available() >= 3) {
      leds.setPixel(i, Serial.read(), Serial.read(), Serial.read());

      i++;
    }
  }
  /*
   while (i < 2*NUMPIXELS) {
    if (Serial.available() >= 3) {
      leds.setPixel(i, Serial.read(), Serial.read(), Serial.read());

      i++;
    }
  }
  while (i < 2*NUMPIXELS) {
    if (Serial.available() >= 3) {
      leds.setPixel(i, Serial.read(), Serial.read(), Serial.read());

      i++;
    }
  }
  while (i < 2*NUMPIXELS) {
    if (Serial.available() >= 3) {
      leds.setPixel(i, Serial.read(), Serial.read(), Serial.read());

      i++;
    }
  }
  while (i < 2*NUMPIXELS) {
    if (Serial.available() >= 3) {
      leds.setPixel(i, Serial.read(), Serial.read(), Serial.read());

      i++;
    }
  }
  while (i < 2*NUMPIXELS) {
    if (Serial.available() >= 3) {
      leds.setPixel(i, Serial.read(), Serial.read(), Serial.read());

      i++;
    }
  }
  */
  leds.show();
  Serial.flush();
}
