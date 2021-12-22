// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// Released under the GPLv3 license to match the rest of the
// Adafruit NeoPixel library

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

// définition des pin
#define LED_PIN1        2
#define LED_PIN2        3
#define LED_PIN3        4
#define LED_PIN4        5
#define LED_PIN5        6
#define LED_PIN6        7
#define LED_PIN7        8
#define LED_PIN8        9
#define LED_PIN9        10
#define LED_PIN10       11


#define PIR_PIN1        22
#define PIR_PIN2        24
#define PIR_PIN3        26
#define PIR_PIN4        28
#define PIR_PIN5        30
#define PIR_PIN6        32
#define PIR_PIN7        34
#define PIR_PIN8        36
#define PIR_PIN9        38
#define PIR_PIN10       40

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 24 // Popular NeoPixel ring size


Adafruit_NeoPixel strip1 = Adafruit_NeoPixel(NUMPIXELS, LED_PIN1, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip2 = Adafruit_NeoPixel(NUMPIXELS, LED_PIN2, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip3 = Adafruit_NeoPixel(NUMPIXELS, LED_PIN3, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip4 = Adafruit_NeoPixel(NUMPIXELS, LED_PIN4, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip5 = Adafruit_NeoPixel(NUMPIXELS, LED_PIN5, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip6 = Adafruit_NeoPixel(NUMPIXELS, LED_PIN6, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip7 = Adafruit_NeoPixel(NUMPIXELS, LED_PIN7, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip8 = Adafruit_NeoPixel(NUMPIXELS, LED_PIN8, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip9 = Adafruit_NeoPixel(NUMPIXELS, LED_PIN9, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip10 = Adafruit_NeoPixel(NUMPIXELS, LED_PIN10, NEO_GRB + NEO_KHZ800);
// Argument 1 = Number of pixels in NeoPixel strip
// Argument 2 = Arduino pin number (most are valid)
// Argument 3 = Pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
//   NEO_RGBW    Pixels are wired for RGBW bitstream (NeoPixel RGBW products)


#define DELAYVAL 10 // Time (in milliseconds) to pause between pixels


enum {
  INIT,
  WAIT_BALL,
  CHANGE_LED,
  STOP
} state;

int led1 = 0;
int led2 = 0;
int led3 = 0;
int led4 = 0;
int led5 = 0;
int led6 = 0;
int led7 = 0;
int led8 = 0;
int led9 = 0;
int led10 = 0;

void setup() {


  // These lines are specifically to support the Adafruit Trinket 5V 16 MHz.
  // Any other board, you can remove this part (but no harm leaving it):
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif
  // END of Trinket-specific code.


  strip1.begin();// INITIALIZE NeoPixel strip object (REQUIRED)
  strip2.begin();
  strip3.begin();
  strip4.begin();
  strip5.begin();
  strip6.begin();
  strip7.begin();
  strip8.begin();
  strip9.begin();
  strip10.begin();

  strip1.clear();
  strip2.clear();
  strip3.clear();
  strip4.clear();
  strip5.clear();
  strip6.clear();
  strip7.clear();
  strip8.clear();
  strip9.clear();;
  strip10.clear();

  pinMode(PIR_PIN1, INPUT); //définir la pin 2 comme une entré
  pinMode(PIR_PIN2, INPUT);
  pinMode(PIR_PIN3, INPUT);
  pinMode(PIR_PIN4, INPUT);
  pinMode(PIR_PIN5, INPUT);
  pinMode(PIR_PIN6, INPUT);
  pinMode(PIR_PIN7, INPUT);
  pinMode(PIR_PIN8, INPUT);
  pinMode(PIR_PIN9, INPUT);
  pinMode(PIR_PIN10, INPUT);



}

void loop() {

  //rainbow(1);             // Flowing rainbow cycle along the whole strip
  //theaterChaseRainbow(50); // Rainbow-enhanced theaterChase variant
  switch (state) {
    case INIT:
      Serial.println("INIT");

      strip1.clear();
      strip2.clear();
      strip3.clear();
      strip4.clear();
      strip5.clear();
      strip6.clear();
      strip7.clear();
      strip8.clear();
      strip9.clear();
      strip10.clear();

      // The first NeoPixel in a strand is #0, second is 1, all the way up
      // to the count of pixels minus one.


      for (int i = 0; i < NUMPIXELS; i++) { // For each pixel...

        // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
        // Here we're using a moderately bright green color:

        strip1.setPixelColor(i, strip1.Color(0, 255, 0));
        strip2.setPixelColor(i, strip2.Color(0, 255, 0));
        strip3.setPixelColor(i, strip3.Color(0, 255, 0));
        strip4.setPixelColor(i, strip4.Color(0, 255, 0));
        strip5.setPixelColor(i, strip5.Color(0, 255, 0));
        strip6.setPixelColor(i, strip6.Color(0, 255, 0));
        strip7.setPixelColor(i, strip7.Color(0, 255, 0));
        strip8.setPixelColor(i, strip8.Color(0, 255, 0));
        strip9.setPixelColor(i, strip9.Color(0, 255, 0));
        strip10.setPixelColor(i, strip10.Color(0, 255, 0));

        strip1.show();// Send the updated pixel colors to the hardware.
        strip2.show();
        strip3.show();
        strip4.show();
        strip5.show();
        strip6.show();
        strip7.show();
        strip8.show();
        strip9.show();
        strip10.show();


        delay(DELAYVAL); // Pause before next pass through loop


      }




      state = WAIT_BALL;

      break;

    case WAIT_BALL:
      Serial.println("WAIT_BALL");

      if (digitalRead(PIR_PIN1) == HIGH && led1 == 0) { //le capteur détecte un mouvement
        Serial.println("mouvement detecte 1 ");
        strip1.clear();
        theaterChase(LED_PIN1, strip1.Color(127, 127, 127), 50); // White, half brightness
        for (int i = 0; i < NUMPIXELS; i++) {
          strip1.setPixelColor(i, strip1.Color(255, 0, 0));
          strip1.show();
        }
        led1 = 1;
      }

      if (digitalRead(PIR_PIN2) == HIGH && led2 == 0) { //le capteur détecte un mouvement
        Serial.println("mouvement detecte 2 ");
        strip2.clear();
        for (int i = 0; i < NUMPIXELS; i++) {
          strip2.setPixelColor(i, strip2.Color(255, 0, 0));
          strip2.show();
        }
        led2 = 1;
      }

      if (digitalRead(PIR_PIN3) == HIGH && led3 == 0) { //le capteur détecte un mouvement
        Serial.println("mouvement detecte 3 ");
        strip3.clear();
        for (int i = 0; i < NUMPIXELS; i++) {
          strip3.setPixelColor(i, strip3.Color(255, 0, 0));
          strip3.show();
        }
        led3 = 1;
      }

      if (digitalRead(PIR_PIN4) == HIGH && led4 == 0) { //le capteur détecte un mouvement
        Serial.println("mouvement detecte 4 ");
        strip4.clear();
        for (int i = 0; i < NUMPIXELS; i++) {
          strip4.setPixelColor(i, strip4.Color(255, 0, 0));
          strip4.show();
        }
        led4 = 1;
      }

      if (digitalRead(PIR_PIN5) == HIGH && led5 == 0) { //le capteur détecte un mouvement
        Serial.println("mouvement detecte 5 ");
        strip5.clear();
        for (int i = 0; i < NUMPIXELS; i++) {
          strip5.setPixelColor(i, strip5.Color(255, 0, 0));
          strip5.show();
        }
        led5 = 1;
      }

      if (digitalRead(PIR_PIN6) == HIGH && led6 == 0) { //le capteur détecte un mouvement
        Serial.println("mouvement detecte 6 ");
        strip6.clear();
        for (int i = 0; i < NUMPIXELS; i++) {
          strip6.setPixelColor(i, strip6.Color(255, 0, 0));
          strip6.show();
        }
        led6 = 1;
      }

      if (digitalRead(PIR_PIN7) == HIGH && led7 == 0) { //le capteur détecte un mouvement
        Serial.println("mouvement detecte 7 ");
        strip7.clear();
        for (int i = 0; i < NUMPIXELS; i++) {
          strip7.setPixelColor(i, strip7.Color(255, 0, 0));
          strip7.show();
        }
        led7 = 1;
      }

      if (digitalRead(PIR_PIN8) == HIGH && led8 == 0) { //le capteur détecte un mouvement
        Serial.println("mouvement detecte 8 ");
        strip8.clear();
        for (int i = 0; i < NUMPIXELS; i++) {
          strip8.setPixelColor(i, strip8.Color(255, 0, 0));
          strip8.show();
        }
        led8 = 1;
      }

      if (digitalRead(PIR_PIN9) == HIGH && led9 == 0) { //le capteur détecte un mouvement
        Serial.println("mouvement detecte 9 ");
        strip9.clear();
        for (int i = 0; i < NUMPIXELS; i++) {
          strip9.setPixelColor(i, strip9.Color(255, 0, 0));
          strip9.show();
        }
        led9 = 1;
      }

      if (digitalRead(PIR_PIN10) == HIGH && led10 == 0) { //le capteur détecte un mouvement
        Serial.println("mouvement detecte 10 ");
        strip10.clear();
        for (int i = 0; i < NUMPIXELS; i++) {
          strip10.setPixelColor(i, strip10.Color(255, 0, 0));
          strip10.show();
        }
        led10 = 1;
      }

      break;

    case CHANGE_LED:
      Serial.println("CHANGE_LED");

      break;

    case STOP:
      Serial.println("STOP");


      break;

    default:
      // statements
      break;
  }
  Serial.println("Sortie switch case");


}

/*
  void BallIn(){

  theaterChase(strip0.Color(127, 127, 127), 50); // White, half brightness
  colorWipe(strip0.Color(255,   0,   0), 50);

  }

  // Some functions of our own for creating animated effects -----------------

  // Fill strip pixels one after another with a color. Strip is NOT cleared
  // first; anything there will be covered pixel by pixel. Pass in color
  // (as a single 'packed' 32-bit value, which you can get by calling
  // strip.Color(red, green, blue) as shown in the loop() function above),
  // and a delay time (in milliseconds) between pixels.
  void colorWipe(uint32_t color, int wait) {
  for(int i=0; i<strip0.numPixels(); i++) { // For each pixel in strip...
    strip0.setPixelColor(i, color);         //  Set pixel's color (in RAM)
    strip0.show();                          //  Update strip to match
    delay(wait);                           //  Pause for a moment
  }
  }
*/
  // Theater-marquee-style chasing lights. Pass in a color (32-bit value,
  // a la strip.Color(r,g,b) as mentioned above), and a delay time (in ms)
  // between frames.
  void theaterChase(int led_pin, uint32_t color, int wait) {
    Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMPIXELS, led_pin, NEO_GRB + NEO_KHZ800);
  for(int a=0; a<10; a++) {  // Repeat 10 times...
    for(int b=0; b<3; b++) { //  'b' counts from 0 to 2...
      strip.clear();         //   Set all pixels in RAM to 0 (off)
      // 'c' counts up from 'b' to end of strip in steps of 3...
      for(int c=b; c<strip.numPixels(); c += 3) {
        strip.setPixelColor(c, color); // Set pixel 'c' to value 'color'
      }
      strip.show(); // Update strip with new contents
      delay(wait);  // Pause for a moment
    }
  }
  }
/*

  // Rainbow-enhanced theater marquee. Pass delay time (in ms) between frames.
  void theaterChaseRainbow(int wait) {
  int firstPixelHue = 0;     // First pixel starts at red (hue 0)
  for(int a=0; a<30; a++) {  // Repeat 30 times...
    for(int b=0; b<3; b++) { //  'b' counts from 0 to 2...
      strip.clear();         //   Set all pixels in RAM to 0 (off)
      // 'c' counts up from 'b' to end of strip in increments of 3...
      for(int c=b; c<strip.numPixels(); c += 3) {
        // hue of pixel 'c' is offset by an amount to make one full
        // revolution of the color wheel (range 65536) along the length
        // of the strip (strip.numPixels() steps):
        int      hue   = firstPixelHue + c * 65536L / strip.numPixels();
        uint32_t color = strip.gamma32(strip.ColorHSV(hue)); // hue -> RGB
        strip.setPixelColor(c, color); // Set pixel 'c' to value 'color'
      }
      strip.show();                // Update strip with new contents
      delay(wait);                 // Pause for a moment
      firstPixelHue += 65536 / 90; // One cycle of color wheel over 90 frames
    }
  }
  }



  // Rainbow cycle along whole strip. Pass delay time (in ms) between frames.
  void rainbow(int wait) {
  // Hue of first pixel runs 5 complete loops through the color wheel.
  // Color wheel has a range of 65536 but it's OK if we roll over, so
  // just count from 0 to 5*65536. Adding 256 to firstPixelHue each time
  // means we'll make 5*65536/256 = 1280 passes through this loop:
  for(long firstPixelHue = 0; firstPixelHue < 5*65536; firstPixelHue += 256) {
    // strip.rainbow() can take a single argument (first pixel hue) or
    // optionally a few extras: number of rainbow repetitions (default 1),
    // saturation and value (brightness) (both 0-255, similar to the
    // ColorHSV() function, default 255), and a true/false flag for whether
    // to apply gamma correction to provide 'truer' colors (default true).

    strip1.rainbow(firstPixelHue);
    strip2.rainbow(firstPixelHue);
    strip3.rainbow(firstPixelHue);
    strip4.rainbow(firstPixelHue);
    strip5.rainbow(firstPixelHue);
    strip6.rainbow(firstPixelHue);
    strip7.rainbow(firstPixelHue);
    strip8.rainbow(firstPixelHue);
    strip9.rainbow(firstPixelHue);
    strip10.rainbow(firstPixelHue);
    // Above line is equivalent to:
    // strip.rainbow(firstPixelHue, 1, 255, 255, true);

    strip1.show();// Update strip with new contents
    strip2.show();
    strip3.show();
    strip4.show();
    strip5.show();
    strip6.show();
    strip7.show();
    strip8.show();
    strip9.show();
    strip0.show();


  }
  }
*/
