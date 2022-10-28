
#include "Adafruit_NeoPixel.h"
#include "strip.h"
#ifdef __AVR__
#include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif


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

#define NB_STRIPS       10 // nombre de bandeau de leds
#define NUMPIXELS       24 // Popular NeoPixel ring size

#define STRIP_0         0
#define STRIP_1         1
#define STRIP_2         2
#define STRIP_3         3
#define STRIP_4         4
#define STRIP_5         5
#define STRIP_6         6
#define STRIP_7         7 
#define STRIP_8         8
#define STRIP_9         9

#define DELAYVAL       10 // Time (in milliseconds) to pause between pixels

Adafruit_NeoPixel strip0 = Adafruit_NeoPixel(NUMPIXELS, LED_PIN1, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip1 = Adafruit_NeoPixel(NUMPIXELS, LED_PIN2, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip2 = Adafruit_NeoPixel(NUMPIXELS, LED_PIN3, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip3 = Adafruit_NeoPixel(NUMPIXELS, LED_PIN4, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip4 = Adafruit_NeoPixel(NUMPIXELS, LED_PIN5, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip5 = Adafruit_NeoPixel(NUMPIXELS, LED_PIN6, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip6 = Adafruit_NeoPixel(NUMPIXELS, LED_PIN7, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip7 = Adafruit_NeoPixel(NUMPIXELS, LED_PIN8, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip8 = Adafruit_NeoPixel(NUMPIXELS, LED_PIN9, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip9 = Adafruit_NeoPixel(NUMPIXELS, LED_PIN10, NEO_GRB + NEO_KHZ800);

Adafruit_NeoPixel Table_strips[NB_STRIPS] = {strip0, strip1, strip2, strip3, strip4, strip5, strip6, strip7, strip8, strip9};


void clear_all_strip(){
  for(int i = 0; i<NB_STRIPS; i++){
    Table_strips[i].clear();
  } 
}

void init_strips(){ //initialisation du bd(bandeau de leds) 
  for(int i = 0; i<NB_STRIPS; i++){
    Table_strips[i].begin();
  }  
}

void set_all_strips_green(){
    for(int i = 0; i<NB_STRIPS; i++){
        for(int y = 0; y<NUMPIXELS; y++){
            Table_strips[i].setPixelColor(y,Table_strips[i].Color(0, 255, 0));
            Table_strips[i].show();
        }
    }
}
void set_all_strips_red(){
    for(int i = 0; i<NB_STRIPS; i++){
        for(int y = 0; y<NUMPIXELS; y++){
            Table_strips[i].setPixelColor(y,Table_strips[i].Color(255, 0, 0));
            Table_strips[i].show();
        }
    }
}

void set_strip_red(int num_strip){
    for(int y = 0; y<NUMPIXELS; y++){
        Table_strips[num_strip].setPixelColor(y, Table_strips[num_strip].Color(255, 0, 0));
        Table_strips[num_strip].show();
        delay(DELAYVAL);
    }
}

void set_strip_green(int num_strip){
    for(int y = 0; y<NUMPIXELS; y++){
        Table_strips[num_strip].setPixelColor(y, Table_strips[num_strip].Color(0, 255, 0));
        Table_strips[num_strip].show();
        delay(DELAYVAL);
    }
}

void set_strip_yello(int num_strip){
    for(int y = 0; y<NUMPIXELS; y++){
        Table_strips[num_strip].setPixelColor(y, Table_strips[num_strip].Color(251, 255, 0));
        Table_strips[num_strip].show();
        delay(DELAYVAL);
    }
}
// Rainbow-enhanced theater marquee. Pass delay time (in ms) between frames.
void rainbowRoad(int wait) {
    int firstPixelHue = 0;     // First pixel starts at red (hue 0)
    
    
      for(int a=0; a<30; a++) {  // Repeat 30 times...
          for(int b=0; b<3; b++) { //  'b' counts from 0 to 2...
            for(int i = 0; i<NB_STRIPS; i++){
                Table_strips[i].clear();         //   Set all pixels in RAM to 0 (off)
            
                // 'c' counts up from 'b' to end of strip in increments of 3...
                for(int c=b; c<Table_strips[i].numPixels(); c += 3) {
                    // hue of pixel 'c' is offset by an amount to make one full
                    // revolution of the color wheel (range 65536) along the length
                    // of the strip (strip.numPixels() steps):
                    int hue = firstPixelHue + c * 65536L / Table_strips[i].numPixels();
                    uint32_t color = Table_strips[i].gamma32(Table_strips[i].ColorHSV(hue)); // hue -> RGB
                    Table_strips[i].setPixelColor(c, color); // Set pixel 'c' to value 'color'
                  
                    
                }
                Table_strips[i].show();                // Update strip with new contents
                delay(wait);                 // Pause for a moment
                firstPixelHue += 65536 / 90; // One cycle of color wheel over 90 frames
            }
        }
    }
}

void rainbow(int wait)
{  
      for (long firstPixelHue = 0; firstPixelHue < 5 * 65536; firstPixelHue += 256)
      {
      for(int i = 0; i<NB_STRIPS; i++){
        for (int y = 0; y < Table_strips[i].numPixels(); y++)
        { 
          
            int pixelHue = firstPixelHue + (y * 65536L / Table_strips[i].numPixels());
           
            Table_strips[i].setPixelColor(y, Table_strips[i].gamma32(Table_strips[i].ColorHSV(pixelHue)));
        }
        Table_strips[i].show(); // Update strip with new contents
        delay(wait);  // Pause for a moment
      }        
    }
}

