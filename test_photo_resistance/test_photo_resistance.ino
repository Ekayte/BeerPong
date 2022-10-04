#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif


#define RPHOTO_1        A1 
#define RPHOTO_2        A2 
#define RPHOTO_3        A3
#define RPHOTO_4        A4
#define RPHOTO_5        A5 
#define RPHOTO_6        A6
#define RPHOTO_7        A7  
#define RPHOTO_8        A8  
#define RPHOTO_9        A9
#define RPHOTO_10        A10 

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

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 24 // Popular NeoPixel ring size

#define PAUSE_R         10000
#define VALUE_RESET     30

#define DELAYVAL 10 // Time (in milliseconds) to pause between pixels


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

void setup() {
  Serial.begin(9600);

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

  for (int i = 0; i < NUMPIXELS; i++) { // Finit couleurs des bandeaux

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
  
  pinMode(RPHOTO_1, INPUT);
  pinMode(RPHOTO_2, INPUT);
  pinMode(RPHOTO_3, INPUT);
  pinMode(RPHOTO_4, INPUT);
  pinMode(RPHOTO_5, INPUT);
  pinMode(RPHOTO_6, INPUT);
  pinMode(RPHOTO_7, INPUT);
  pinMode(RPHOTO_8, INPUT);
  pinMode(RPHOTO_9, INPUT);
  pinMode(RPHOTO_10, INPUT);
  

}

void loop() {
  int value_RPHOTO_1 = analogRead(RPHOTO_1);
  int value_RPHOTO_2 = analogRead(RPHOTO_2);
  int value_RPHOTO_3 = analogRead(RPHOTO_3);
  int value_RPHOTO_4 = analogRead(RPHOTO_4);
  int value_RPHOTO_5 = analogRead(RPHOTO_5);
  int value_RPHOTO_6 = analogRead(RPHOTO_6);
  int value_RPHOTO_7 = analogRead(RPHOTO_7);
  int value_RPHOTO_8 = analogRead(RPHOTO_8);
  int value_RPHOTO_9 = analogRead(RPHOTO_9);
  int value_RPHOTO_10 = analogRead(RPHOTO_10);
  
  Serial.print("R1 : ");
  Serial.print(value_RPHOTO_1);
  Serial.print(" R2 : ");
  Serial.print(value_RPHOTO_2);
  Serial.print(" R3 : ");
  Serial.print(value_RPHOTO_3);
  Serial.print(" R4 : ");
  Serial.print(value_RPHOTO_4);
  Serial.print(" R5 : ");
  Serial.print(value_RPHOTO_5);
  Serial.print(" R6 : ");
  Serial.print(value_RPHOTO_6);
  Serial.print(" R7 : ");
  Serial.print(value_RPHOTO_7);
  Serial.print(" R8 : ");
  Serial.print(value_RPHOTO_8);
  Serial.print(" R9 : ");
  Serial.print(value_RPHOTO_9);
  Serial.print(" R10 : ");
  Serial.println(value_RPHOTO_10);

}
