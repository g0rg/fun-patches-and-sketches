#include <Adafruit_NeoPixel.h>

#define _SS_MAX_RX_BUFF 360 // RX buffer size //BEFORE WAS 64
#define PIN            6
#define NUMPIXELS      120

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup()
{
  SerialUSB.begin(48000000);
  pixels.begin(); // This initializes the NeoPixel library.

}

void loop()
{
  SerialUSB.flush();
  int i = 0;
  while (i <= NUMPIXELS - 1) {
    if (SerialUSB.available() >= 3) {
      pixels.setPixelColor(i, pixels.Color(SerialUSB.read(), SerialUSB.read(), SerialUSB.read()));
      i++;
    }
  }
  pixels.show();
}
