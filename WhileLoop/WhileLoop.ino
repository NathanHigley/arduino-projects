#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN 6

#define NUM_LEDS 21

#define BRIGHTNESS 20

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, PIN, NEO_GRBW + NEO_KHZ800);


void setup() {
  Serial.begin(115200);
  strip.setBrightness(BRIGHTNESS);
  strip.begin();
  strip.show();
}

int red = 0, green= 0, blue = 0, white = 1;
int wait = 25;
int led = -1;
int i;

void loop() {
  strip.setPixelColor(led, red, green , blue, white);
  led++;
  while (blue < 150){  
    blue = blue + 20;
  }
    red = red + 35;
    green = green + 30;
    blue = blue + 35;
    strip.show();
    delay(wait);
}


