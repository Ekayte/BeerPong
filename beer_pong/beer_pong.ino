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

#define RPHOTO_1        A1 
#define RPHOTO_2        A2 
#define RPHOTO_3        A3
#define RPHOTO_4        A4
#define RPHOTO_5        A7 
#define RPHOTO_6        A6
#define RPHOTO_7        A5  
#define RPHOTO_8        A9  
#define RPHOTO_9        A8
#define RPHOTO_10        A10 
// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 24 // Popular NeoPixel ring size

#define PAUSE_R         20000
#define VALUE_RESET     30

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
  WAIT_RESISTANCE,
  TRIANGLE_GAME_1,
  TRIANGLE_GAME_4,
  TRIANGLE_GAME_10,
  STOP
} state;

int triangle_game = 0;
int level_game = 1;


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

uint32_t color_strip1_red = strip1.Color(255, 0, 0);
uint32_t color_strip2_red = strip2.Color(255, 0, 0);
uint32_t color_strip3_red = strip3.Color(255, 0, 0);
uint32_t color_strip4_red = strip4.Color(255, 0, 0);
uint32_t color_strip5_red = strip5.Color(255, 0, 0);
uint32_t color_strip6_red = strip6.Color(255, 0, 0);
uint32_t color_strip7_red = strip7.Color(255, 0, 0);
uint32_t color_strip8_red = strip8.Color(255, 0, 0);
uint32_t color_strip9_red = strip9.Color(255, 0, 0);
uint32_t color_strip10_red = strip10.Color(255, 0, 0);

uint32_t color_strip1_green = strip1.Color(0, 255, 0);
uint32_t color_strip2_green = strip2.Color(0, 255, 0);
uint32_t color_strip3_green = strip3.Color(0, 255, 0);
uint32_t color_strip4_green = strip4.Color(0, 255, 0);
uint32_t color_strip5_green = strip5.Color(0, 255, 0);
uint32_t color_strip6_green = strip6.Color(0, 255, 0);
uint32_t color_strip7_green = strip7.Color(0, 255, 0);
uint32_t color_strip8_green = strip8.Color(0, 255, 0);
uint32_t color_strip9_green = strip9.Color(0, 255, 0);
uint32_t color_strip10_green = strip10.Color(0, 255, 0);

uint32_t color_strip1_blue = strip1.Color(0, 0, 255);
uint32_t color_strip2_blue = strip2.Color(0, 0, 255);
uint32_t color_strip3_blue = strip3.Color(0, 0, 255);
uint32_t color_strip4_blue = strip4.Color(0, 0, 255);
uint32_t color_strip5_blue = strip5.Color(0, 0, 255);
uint32_t color_strip6_blue = strip6.Color(0, 0, 255);
uint32_t color_strip7_blue = strip7.Color(0, 0, 255);
uint32_t color_strip8_blue = strip8.Color(0, 0, 255);
uint32_t color_strip9_blue = strip9.Color(0, 0, 255);
uint32_t color_strip10_blue = strip10.Color(0, 0, 255);


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

      rainbowRoad(50);
      // The first NeoPixel in a strand is #0, second is 1, all the way up
      // to the count of pixels minus one.
      

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

      state = WAIT_BALL;

      break;

    case WAIT_BALL:
      //Serial.println("WAIT_BALL");

      if (digitalRead(PIR_PIN1) == HIGH && led1 == 0) { //le capteur détecte un mouvement
        Serial.println("mouvement detecte 1 ");
          wave1(30);
          int value_RPHOTO_1 = analogRead(RPHOTO_1); //on récupère la valeur de la résisantce 
          Serial.println(value_RPHOTO_1);
          delay(PAUSE_R); // attente de x sec 
          int value_RPHOTO_2 = analogRead(RPHOTO_1); //on récupère la valeur de la résisantce 
          Serial.println(value_RPHOTO_2);
          int value = value_RPHOTO_2 - value_RPHOTO_1;
          Serial.println(value);
          
          if(value < VALUE_RESET){ //sinon on reset la couleur au vert
            for (int i = 0; i < NUMPIXELS; i++) { 
            strip1.setPixelColor(i, color_strip1_green);
            strip1.show();
            delay(DELAYVAL); 
            }
            led1 = 0;
          }else{
            led1 = 1;
          }
      }

      if (digitalRead(PIR_PIN2) == HIGH && led2 == 0) { //le capteur détecte un mouvement
        Serial.println("mouvement detecte 2 ");
        wave2(30);
        int value_RPHOTO_1 = analogRead(RPHOTO_2); //on récupère la valeur de la résisantce 
        Serial.println(value_RPHOTO_1);
        delay(PAUSE_R); // attente de x sec 
        int value_RPHOTO_2 = analogRead(RPHOTO_2); //on récupère la valeur de la résisantce 
        Serial.println(value_RPHOTO_2);
        int value = value_RPHOTO_2 - value_RPHOTO_1;
        Serial.println(value);
        
        if(value < VALUE_RESET){ //sinon on reset la couleur au vert
          for (int i = 0; i < NUMPIXELS; i++) { 
          strip2.setPixelColor(i, color_strip2_green);
          strip2.show();
          delay(DELAYVAL); 
          }
          led2 = 0;
        }else{
          led2 = 1;
          triangle_game = 1;
        }
                
      }

      if (digitalRead(PIR_PIN3) == HIGH && led3 == 0) { //le capteur détecte un mouvement
        Serial.println("mouvement detecte 3 ");
        wave3(30);
        int value_RPHOTO_1 = analogRead(RPHOTO_3); //on récupère la valeur de la résisantce 
        Serial.println(value_RPHOTO_1);
        delay(PAUSE_R); // attente de x sec 
        int value_RPHOTO_2 = analogRead(RPHOTO_3); //on récupère la valeur de la résisantce 
        Serial.println(value_RPHOTO_2);
        int value = value_RPHOTO_2 - value_RPHOTO_1;
        Serial.println(value);
        
        if(value < VALUE_RESET){ //sinon on reset la couleur au vert
          for (int i = 0; i < NUMPIXELS; i++) { 
          strip3.setPixelColor(i, color_strip3_green);
          strip3.show();
          delay(DELAYVAL); 
          }
          led3 = 0;
        }else{
          led3 = 1;
          triangle_game = 1;
        }
        
        
      }

      if (digitalRead(PIR_PIN4) == HIGH && led4 == 0) { //le capteur détecte un mouvement
         Serial.println("mouvement detecte 4 ");
          wave4(30);
          int value_RPHOTO_1 = analogRead(RPHOTO_4); //on récupère la valeur de la résisantce 
          Serial.println(value_RPHOTO_1);
          delay(PAUSE_R); // attente de x sec 
          int value_RPHOTO_2 = analogRead(RPHOTO_4); //on récupère la valeur de la résisantce 
          Serial.println(value_RPHOTO_2);
          int value = value_RPHOTO_2 - value_RPHOTO_1;
          Serial.println(value);
          
          if(value < VALUE_RESET){ //sinon on reset la couleur au vert
            for (int i = 0; i < NUMPIXELS; i++) { 
            strip4.setPixelColor(i, color_strip4_green);
            strip4.show();
            delay(DELAYVAL); 
            }
            led4 = 0;
          }else{
            led4 = 1;
          }

      }

      if (digitalRead(PIR_PIN5) == HIGH && led5 == 0) { //le capteur détecte un mouvement
        Serial.println("mouvement detecte 5 ");
        wave5(30);
         int value_RPHOTO_1 = analogRead(RPHOTO_5); //on récupère la valeur de la résisantce 
        Serial.println(value_RPHOTO_1);
        delay(PAUSE_R); // attente de x sec 
        int value_RPHOTO_2 = analogRead(RPHOTO_5); //on récupère la valeur de la résisantce 
        Serial.println(value_RPHOTO_2);
        int value = value_RPHOTO_2 - value_RPHOTO_1;
        Serial.println(value);
        
        if(value < VALUE_RESET){ //sinon on reset la couleur au vert
          for (int i = 0; i < NUMPIXELS; i++) { 
          strip5.setPixelColor(i, color_strip5_green);
          strip5.show();
          delay(DELAYVAL); 
          }
          led5 = 0;
        }else{
          led5 = 1;
          triangle_game = 1;
        }
      }
      if (digitalRead(PIR_PIN6) == HIGH && led6 == 0) { //le capteur détecte un mouvement
        Serial.println("mouvement detecte 6 ");
        wave6(30);
        int value_RPHOTO_1 = analogRead(RPHOTO_6); //on récupère la valeur de la résisantce 
        Serial.println(value_RPHOTO_1);
        delay(PAUSE_R); // attente de x sec 
        int value_RPHOTO_2 = analogRead(RPHOTO_6); //on récupère la valeur de la résisantce 
        Serial.println(value_RPHOTO_2);
        int value = value_RPHOTO_2 - value_RPHOTO_1;
        Serial.println(value);
        
        if(value < VALUE_RESET){ //sinon on reset la couleur au vert
          for (int i = 0; i < NUMPIXELS; i++) { 
          strip6.setPixelColor(i, color_strip6_green);
          strip6.show();
          delay(DELAYVAL); 
          }
          led6 = 0;
        }else{
          led6 = 1;
          triangle_game = 1;
        }
      }

      if (digitalRead(PIR_PIN7) == HIGH && led7 == 0) { //le capteur détecte un mouvement
        Serial.println("mouvement detecte 7 ");
        wave7(30);
         int value_RPHOTO_1 = analogRead(RPHOTO_7); //on récupère la valeur de la résisantce 
          Serial.println(value_RPHOTO_1);
          delay(PAUSE_R); // attente de x sec 
          int value_RPHOTO_2 = analogRead(RPHOTO_7); //on récupère la valeur de la résisantce 
          Serial.println(value_RPHOTO_2);
          int value = value_RPHOTO_2 - value_RPHOTO_1;
          Serial.println(value);
          
          if(value < VALUE_RESET){ //sinon on reset la couleur au vert
            for (int i = 0; i < NUMPIXELS; i++) { 
            strip7.setPixelColor(i, color_strip7_green);
            strip7.show();
            delay(DELAYVAL); 
            }
            led7 = 0;
          }else{
            led7 = 1;
            triangle_game = 1;
          }
      }

      if (digitalRead(PIR_PIN8) == HIGH && led8 == 0) { //le capteur détecte un mouvement
        Serial.println("mouvement detecte 8 ");
        wave8(30);
        int value_RPHOTO_1 = analogRead(RPHOTO_8); //on récupère la valeur de la résisantce 
        Serial.println(value_RPHOTO_1);
        delay(PAUSE_R); // attente de x sec 
        int value_RPHOTO_2 = analogRead(RPHOTO_8); //on récupère la valeur de la résisantce 
        Serial.println(value_RPHOTO_2);
        int value = value_RPHOTO_2 - value_RPHOTO_1;
        Serial.println(value);
        
        if(value < VALUE_RESET){ //sinon on reset la couleur au vert
          for (int i = 0; i < NUMPIXELS; i++) { 
          strip8.setPixelColor(i, color_strip8_green);
          strip8.show();
          delay(DELAYVAL); 
          }
          led8 = 0;
        }else{
          led8 = 1;
          triangle_game = 1;
        }
      }

      if (digitalRead(PIR_PIN9) == HIGH && led9 == 0) { //le capteur détecte un mouvement
        Serial.println("mouvement detecte 9 ");
        wave9(30);
        int value_RPHOTO_1 = analogRead(RPHOTO_9); //on récupère la valeur de la résisantce 
        Serial.println(value_RPHOTO_1);
        delay(PAUSE_R); // attente de x sec 
        int value_RPHOTO_2 = analogRead(RPHOTO_9); //on récupère la valeur de la résisantce 
        Serial.println(value_RPHOTO_2);
        int value = value_RPHOTO_2 - value_RPHOTO_1;
        Serial.println(value);
        
        if(value < VALUE_RESET){ //sinon on reset la couleur au vert
          for (int i = 0; i < NUMPIXELS; i++) { 
          strip9.setPixelColor(i, color_strip9_green);
          strip9.show();
          delay(DELAYVAL); 
          }
          led9 = 0;
        }else{
          led9 = 1;
          triangle_game = 1;
        }
      }

      if (digitalRead(PIR_PIN10) == HIGH && led10 == 0) { //le capteur détecte un mouvement
        Serial.println("mouvement detecte 10 ");
          wave10(30);
          int value_RPHOTO_1 = analogRead(RPHOTO_10); //on récupère la valeur de la résisantce 
          Serial.println(value_RPHOTO_1);
          delay(PAUSE_R); // attente de x sec 
          int value_RPHOTO_2 = analogRead(RPHOTO_10); //on récupère la valeur de la résisantce 
          Serial.println(value_RPHOTO_2);
          int value = value_RPHOTO_2 - value_RPHOTO_1;
          Serial.println(value);
          
          if(value < VALUE_RESET){ //sinon on reset la couleur au vert
            for (int i = 0; i < NUMPIXELS; i++) { 
            strip10.setPixelColor(i, color_strip10_green);
            strip10.show();
            delay(DELAYVAL); 
            }
            led10 = 0;
          }else{
            led10 = 1;
          }
      }

      break;
  

    case STOP:
      Serial.println("STOP");


      break;

    default:
      // statements
      break;
  }
  //Serial.println("Sortie switch case");


}

void red(int led_pin){
  Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMPIXELS, led_pin, NEO_GRB + NEO_KHZ800);
  for (int i = 0; i < NUMPIXELS; i++) {
    strip.setPixelColor(i, strip.Color(255, 0, 0));
    strip.show();
    
  }
}

void green(int led_pin){
  Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMPIXELS, led_pin, NEO_GRB + NEO_KHZ800);
  for (int i = 0; i < NUMPIXELS; i++) {
    strip.setPixelColor(i, strip.Color(0, 255, 0));
    strip.show();
    
  }
}
/* 
 *  vague rouge led 1
 */
void wave1(int wait){
  /*
   * description de la composition des variable
   * [position de la vague de coleur sur l'anneau]_[position de l'anneau]
   */
  //variable ring gauche
  int top_left = 18;
  int bot_left = 18;

  //variable ring haut gauche
  int top_topLeft = 23;
  int bot_topLeft = 23;


  for(int i = 0; i<13; i++){
    
    if(led2 == 0){  
      strip2.setPixelColor(top_left, strip2.Color(255, 0, 0));          //ring gauche top
      top_left--;
  
       strip2.setPixelColor(bot_left, strip2.Color(255, 0, 0));         //ring gauche bot
      if(bot_left == 24){
        bot_left = -1;
      }
      bot_left++;
    }
    if(led2 == 1){  
      strip2.setPixelColor(top_left, strip2.Color(0, 0, 255));          //ring gauche top
      top_left--;
  
       strip2.setPixelColor(bot_left, strip2.Color(0, 0, 255));         //ring gauche bot
      if(bot_left == 24){
        bot_left = -1;
      }
      bot_left++;
    }
    
   if(led7 == 0){
      strip7.setPixelColor(top_topLeft,strip7.Color(255, 0, 0));          //ring haut gauche top
      top_topLeft--;
  
      strip7.setPixelColor(bot_topLeft, strip7.Color(255, 0, 0));         //ring haut gauche bot
      if(bot_topLeft == 24){
        bot_topLeft = -1;
      }
      bot_topLeft++;
   }
   if(led7 == 1){
      strip7.setPixelColor(top_topLeft, strip7.Color(0, 0, 255));          //ring haut gauche top
      top_topLeft--;
  
      strip7.setPixelColor(bot_topLeft, strip7.Color(0, 0, 255));         //ring haut gauche bot
      if(bot_topLeft == 24){
        bot_topLeft = -1;
      }
      bot_topLeft++;
   }
    
    strip2.show();                          //  Update strip 4(gauche)
    strip7.show();                          //  Update strip 5(haut gauche)
    delay(wait);                           //  Pause for a moment
  }


delay(wait); 
 
/* 
 *  reverse
 */

  //variable ring gauche 2
  int revers_top_left = 6;
  int revers_bot_left = 6;

  //variable ring haut gauche 7
  int revers_top_topLeft = 10;
  int revers_bot_topLeft = 10;

  int bot1 = 0;
  int bot2 = 24;
  
  int left1 = 6;
  int left2 = 6;
  
  int top1 = 12;
  int top2 = 12;
  
  int right1 = 18;
  int right2 = 18;

  int compteur = 0;
  
  for(int i = 0; i<13; i++){
    if(led2 == 0){
      strip2.setPixelColor(revers_top_left, strip2.Color(0, 255, 0));         //ring gauche top
      revers_top_left++;
      
      strip2.setPixelColor(revers_bot_left, strip2.Color(0, 255, 0));         //  ring gauche bot
      if(revers_bot_left == 0){
        revers_bot_left = 24;
      }
      revers_bot_left--;
    }
    if(led2 == 1){
      strip2.setPixelColor(revers_top_left, strip2.Color(255, 0, 0));         //ring gauche top
      revers_top_left++;
      
      strip2.setPixelColor(revers_bot_left, strip2.Color(255, 0, 0));         //  ring gauche bot
      if(revers_bot_left == 0){
        revers_bot_left = 24;
      }
      revers_bot_left--;
    }
  if(led7 == 0){
    strip7.setPixelColor(revers_top_topLeft, strip7.Color(0, 255, 0));          //ring haut gauche top
    revers_top_topLeft++;

    strip7.setPixelColor(revers_bot_topLeft, strip7.Color(0, 255, 0));         //ring haut gauche bot
    if(revers_bot_topLeft == 0){
      revers_bot_topLeft = 24;
    }
    revers_bot_topLeft--;
  }
  if(led7 == 1){
    strip7.setPixelColor(revers_top_topLeft, strip2.Color(255, 0, 0));          //ring haut gauche top
    revers_top_topLeft++;

    strip7.setPixelColor(revers_bot_topLeft, strip2.Color(255, 0, 0));         //ring haut gauche bot
    if(revers_bot_topLeft == 0){
      revers_bot_topLeft = 24;
    }
    revers_bot_topLeft--;
  }
     
    strip2.show();
    strip7.show();                          //  Update strip 5(haut gauche)
    
    compteur++;
    if( compteur >=10){
      strip1.setPixelColor(bot1, strip1.Color(255, 0, 0));         //ring haut gauche bot
      bot1++;
      strip1.setPixelColor(bot2, strip1.Color(255, 0, 0));         //ring haut gauche bot
      bot2--;
      
      strip1.setPixelColor(left1, strip1.Color(255, 0, 0));         //ring haut gauche bot
      left1++;
      strip1.setPixelColor(left2, strip1.Color(255, 0, 0));         //ring haut gauche bot
      left2--;
     
      strip1.setPixelColor(top1, strip1.Color(255, 0, 0));         //ring haut gauche bot
      top1++;
      strip1.setPixelColor(top2, strip1.Color(255, 0, 0));         //ring haut gauche bot
      top2--;
      
      strip1.setPixelColor(right1, strip1.Color(255, 0, 0));         //ring haut gauche bot
      right1++;
      strip1.setPixelColor(right2, strip1.Color(255, 0, 0));         //ring haut gauche bot
      right2--;
  
      strip1.show();                          //  Update strip 6(haut droite)
    
    }
     delay(wait);  
  }
   
 }

/*
 * vague rouge led 2 
 */

void wave2(int wait){
  
  //variable ring droite
  int top_right = 6; 
  int bot_right = 6;

  //variable ring gauche
  int top_left = 18;
  int bot_left = 18;

  //variable ring haut gauche
  int top_topLeft = 23;
  int bot_topLeft = 23;

  //variable ring haut droite
  int top_topRight = 2;
  int bot_topRight = 2;

  for(int i = 0; i<13; i++){
    if(led1 == 0){
      strip1.setPixelColor(top_right, strip1.Color(255, 0, 0));         //ring droite top
      top_right++;
      
      strip1.setPixelColor(bot_right, strip1.Color(255, 0, 0));         //ring droite bot
      if(bot_right == 0){
        bot_right = 24;
      }
      bot_right--;
    }
     if(led1 == 1){
      strip1.setPixelColor(top_right, strip1.Color(0, 0, 255));         //ring droite top
      top_right++;
      
      strip1.setPixelColor(bot_right, strip1.Color(0, 0, 255));         //ring droite bot
      if(bot_right == 0){
        bot_right = 24;
      }
      bot_right--;
    }
    if(led3 == 0){  
      strip3.setPixelColor(top_left, strip3.Color(255, 0, 0));          //ring gauche top
      top_left--;
  
       strip3.setPixelColor(bot_left, strip3.Color(255, 0, 0));         //ring gauche bot
      if(bot_left == 24){
        bot_left = -1;
      }
      bot_left++;
    }
    if(led3 == 1){  
      strip3.setPixelColor(top_left, strip3.Color(0, 0, 255));          //ring gauche top
      top_left--;
  
       strip3.setPixelColor(bot_left, strip3.Color(0, 0, 255));         //ring gauche bot
      if(bot_left == 24){
        bot_left = -1;
      }
      bot_left++;
    }
   if(led6 == 0){
      strip6.setPixelColor(top_topLeft, strip6.Color(255, 0, 0));          //ring haut gauche top
      top_topLeft--;
  
      strip6.setPixelColor(bot_topLeft, strip6.Color(255, 0, 0));         //ring haut gauche bot
      if(bot_topLeft == 24){
        bot_topLeft = -1;
      }
      bot_topLeft++;
   }
    if(led6 == 1){
      strip6.setPixelColor(top_topLeft, strip6.Color(0, 0, 255));          //ring haut gauche top
      top_topLeft--;
  
      strip6.setPixelColor(bot_topLeft, strip6.Color(0, 0, 255));         //ring haut gauche bot
      if(bot_topLeft == 24){
        bot_topLeft = -1;
      }
      bot_topLeft++;
   }
   if(led7 == 0){
    strip7.setPixelColor(top_topRight, strip7.Color(255, 0, 0));          //ring haut droite top
    if(top_topRight == 0){
      top_topRight = 24;
    }
    top_topRight--;

    strip7.setPixelColor(bot_topRight, strip7.Color(255, 0, 0));         //ring haut droite bot
    bot_topRight++;
   } 
   if(led7 == 1){
    strip7.setPixelColor(top_topRight, strip7.Color(0, 0, 255));          //ring haut droite top
    if(top_topRight == 0){
      top_topRight = 24;
    }
    top_topRight--;

    strip7.setPixelColor(bot_topRight, strip7.Color(0, 0, 255));         //ring haut droite bot
    bot_topRight++;
   } 
    strip1.show();                          //  Update strip 2(droite)
    strip3.show();                          //  Update strip 4(gauche)
    strip6.show();                          //  Update strip 5(haut gauche)
    strip7.show();                          //  Update strip 6(haut droite)
    delay(wait);                           //  Pause for a moment
  }


delay(wait); 
 
/* 
 *  reverse
 */

  //variable ring droite 2
  int revers_top_right = 18;
  int revers_bot_right = 18;

  //variable ring gauche 4
  int revers_top_left = 6;
  int revers_bot_left = 6;

  //variable ring haut gauche 5
  int revers_top_topLeft = 10;
  int revers_bot_topLeft = 10;

  //variable ring haut droite 6
  int revers_top_topRight = 14;
  int revers_bot_topRight = 14;

  int bot1 = 0;
  int bot2 = 24;
  
  int left1 = 6;
  int left2 = 6;
  
  int top1 = 12;
  int top2 = 12;
  
  int right1 = 18;
  int right2 = 18;

  int compteur = 0;
  
  for(int i = 0; i<13; i++){
    if(led1 == 0){
      strip1.setPixelColor(revers_top_right, strip1.Color(0, 255, 0));         //ring droite top
      revers_top_right--;
      
      strip1.setPixelColor(revers_bot_right, strip1.Color(0, 255, 0));         //ring droite bot
      if(revers_bot_right == 24){
        revers_bot_right = -1;
      }
      revers_bot_right++;
    }
    if(led1 == 1){
      strip1.setPixelColor(revers_top_right, strip1.Color(255, 0, 0));         //ring droite top
      revers_top_right--;
      
      strip1.setPixelColor(revers_bot_right, strip1.Color(255, 0, 0));         //ring droite bot
      if(revers_bot_right == 24){
        revers_bot_right = -1;
      }
      revers_bot_right++;
    }
    if(led3 == 0){
      strip3.setPixelColor(revers_top_left, strip3.Color(0, 255, 0));         //ring gauche top
      revers_top_left++;
      
      strip3.setPixelColor(revers_bot_left, strip3.Color(0, 255, 0));         //  ring gauche bot
      if(revers_bot_left == 0){
        revers_bot_left = 24;
      }
      revers_bot_left--;
    }
    if(led3 == 1){
      strip3.setPixelColor(revers_top_left, strip3.Color(255, 0, 0));         //ring gauche top
      revers_top_left++;
      
      strip3.setPixelColor(revers_bot_left, strip3.Color(255, 0, 0));         //  ring gauche bot
      if(revers_bot_left == 0){
        revers_bot_left = 24;
      }
      revers_bot_left--;
    }
    if(led6 == 0){
      strip6.setPixelColor(revers_top_topLeft, strip6.Color(0, 255, 0));          //ring haut gauche top
      revers_top_topLeft++;
  
      strip6.setPixelColor(revers_bot_topLeft, strip6.Color(0, 255, 0));         //ring haut gauche bot
      if(revers_bot_topLeft == 0){
        revers_bot_topLeft = 24;
      }
      revers_bot_topLeft--;
    }
    if(led6 == 1){
      strip6.setPixelColor(revers_top_topLeft, strip6.Color(255, 0, 0));          //ring haut gauche top
      revers_top_topLeft++;
  
      strip6.setPixelColor(revers_bot_topLeft, strip6.Color(255, 0, 0));         //ring haut gauche bot
      if(revers_bot_topLeft == 0){
        revers_bot_topLeft = 24;
      }
      revers_bot_topLeft--;
    }
    if(led7 == 0){
      strip7.setPixelColor(revers_top_topRight, strip7.Color(0, 255, 0));          //ring haut droite top
      if(revers_top_topRight == 24){
        revers_top_topRight = -1;
      }
      revers_top_topRight++;
  
      strip7.setPixelColor(revers_bot_topRight, strip7.Color(0, 255, 0));         //ring haut droite bot
      revers_bot_topRight--;
    }
    if(led7 == 1){
      strip7.setPixelColor(revers_top_topRight, strip7.Color(255, 0, 0));          //ring haut droite top
      if(revers_top_topRight == 24){
        revers_top_topRight = -1;
      }
      revers_top_topRight++;
  
      strip7.setPixelColor(revers_bot_topRight, strip7.Color(255, 0, 0));         //ring haut droite bot
      revers_bot_topRight--;
    }
    strip1.show();                          //  Update strip to match
    strip3.show();
    strip6.show();                          //  Update strip 5(haut gauche)
    strip7.show();                          //  Update strip 6(haut droite)
    
    
    compteur++;
    if( compteur >=10){
      strip2.setPixelColor(bot1, strip2.Color(255, 0, 0));         //ring haut gauche bot
      bot1++;
      strip2.setPixelColor(bot2, strip2.Color(255, 0, 0));         //ring haut gauche bot
      bot2--;
      
      strip2.setPixelColor(left1, strip2.Color(255, 0, 0));         //ring haut gauche bot
      left1++;
      strip2.setPixelColor(left2, strip2.Color(255, 0, 0));         //ring haut gauche bot
      left2--;
     
      strip2.setPixelColor(top1, strip2.Color(255, 0, 0));         //ring haut gauche bot
      top1++;
      strip2.setPixelColor(top2, strip2.Color(255, 0, 0));         //ring haut gauche bot
      top2--;
      
      strip2.setPixelColor(right1, strip2.Color(255, 0, 0));         //ring haut gauche bot
      right1++;
      strip2.setPixelColor(right2, strip2.Color(255, 0, 0));         //ring haut gauche bot
      right2--;
  
      strip2.show();                          //  Update strip 6(haut droite)
    
    }
     delay(wait);  
  }

    
 }
 
/*
 * vague rouge led 3 
 */

void wave3(int wait){
  
  //variable ring droite
  int top_right = 6; 
  int bot_right = 6;

  //variable ring gauche
  int top_left = 18;
  int bot_left = 18;

  //variable ring haut gauche
  int top_topLeft = 23;
  int bot_topLeft = 23;

  //variable ring haut droite
  int top_topRight = 2;
  int bot_topRight = 2;

  for(int i = 0; i<13; i++){
    if(led2 == 0){
      strip2.setPixelColor(top_right, strip2.Color(255, 0, 0));         //ring droite top
      top_right++;
      
      strip2.setPixelColor(bot_right, strip2.Color(255, 0, 0));         //ring droite bot
      if(bot_right == 0){
        bot_right = 24;
      }
      bot_right--;
    }  
    if(led2 == 1){
      strip2.setPixelColor(top_right, strip2.Color(0, 0, 255));         //ring droite top
      top_right++;
      
      strip2.setPixelColor(bot_right, strip2.Color(0, 0, 255));         //ring droite bot
      if(bot_right == 0){
        bot_right = 24;
      }
      bot_right--;
    }  
    if(led4 == 0){
      strip4.setPixelColor(top_left, strip4.Color(255, 0, 0));          //ring gauche top
      top_left--;
  
       strip4.setPixelColor(bot_left, strip4.Color(255, 0, 0));         //ring gauche bot
      if(bot_left == 24){
        bot_left = -1;
      }
      bot_left++;
    }
    if(led4 == 1){
      strip4.setPixelColor(top_left, strip4.Color(0, 0, 255));          //ring gauche top
      top_left--;
  
       strip4.setPixelColor(bot_left, strip4.Color(0, 0, 255));         //ring gauche bot
      if(bot_left == 24){
        bot_left = -1;
      }
      bot_left++;
    }
   if(led5 == 0){
      strip5.setPixelColor(top_topLeft, strip5.Color(255, 0, 0));          //ring haut gauche top
      top_topLeft--;
  
      strip5.setPixelColor(bot_topLeft, strip5.Color(255, 0, 0));         //ring haut gauche bot
      if(bot_topLeft == 24){
        bot_topLeft = -1;
      }
      bot_topLeft++;
   }
   if(led5 == 1){
      strip5.setPixelColor(top_topLeft, strip5.Color(0, 0, 255));          //ring haut gauche top
      top_topLeft--;
  
      strip5.setPixelColor(bot_topLeft, strip5.Color(0, 0, 255));         //ring haut gauche bot
      if(bot_topLeft == 24){
        bot_topLeft = -1;
      }
      bot_topLeft++;
   }
   if(led6 == 0){
      strip6.setPixelColor(top_topRight, strip6.Color(255, 0, 0));          //ring haut gauche top
      if(top_topRight == 0){
        top_topRight = 24;
      }
      top_topRight--;
  
      strip6.setPixelColor(bot_topRight, strip6.Color(255, 0, 0));         //ring haut gauche bot
      bot_topRight++;
   }
   if(led6 == 1){
      strip6.setPixelColor(top_topRight, strip6.Color(0, 0, 255));          //ring haut gauche top
      if(top_topRight == 0){
        top_topRight = 24;
      }
      top_topRight--;
  
      strip6.setPixelColor(bot_topRight, strip6.Color(0, 0, 255));         //ring haut gauche bot
      bot_topRight++;
   }
    strip2.show();                          //  Update strip 2(droite)
    strip4.show();                          //  Update strip 4(gauche)
    strip5.show();                          //  Update strip 5(haut gauche)
    strip6.show();                          //  Update strip 6(haut droite)
    delay(wait);                           //  Pause for a moment
  }


delay(wait); 
 
/* 
 *  reverse
 */

  //variable ring droite 2
  int revers_top_right = 18;
  int revers_bot_right = 18;

  //variable ring gauche 4
  int revers_top_left = 6;
  int revers_bot_left = 6;

  //variable ring haut gauche 5
  int revers_top_topLeft = 10;
  int revers_bot_topLeft = 10;

  //variable ring haut droite 6
  int revers_top_topRight = 14;
  int revers_bot_topRight = 14;

  int bot1 = 0;
  int bot2 = 24;
  
  int left1 = 6;
  int left2 = 6;
  
  int top1 = 12;
  int top2 = 12;
  
  int right1 = 18;
  int right2 = 18;

  int compteur = 0;
  
  for(int i = 0; i<13; i++){
    if(led2 == 0){
      strip2.setPixelColor(revers_top_right, strip2.Color(0, 255, 0));         //ring droite top
      revers_top_right--;
      
      strip2.setPixelColor(revers_bot_right, strip2.Color(0, 255, 0));         //ring droite bot
      if(revers_bot_right == 24){
        revers_bot_right = -1;
      }
      revers_bot_right++;
    }
    if(led2 == 1){
      strip2.setPixelColor(revers_top_right, strip2.Color(255, 0, 0));         //ring droite top
      revers_top_right--;
      
      strip2.setPixelColor(revers_bot_right, strip2.Color(255, 0, 0));         //ring droite bot
      if(revers_bot_right == 24){
        revers_bot_right = -1;
      }
      revers_bot_right++;
    }
    if(led4 == 0){
      strip4.setPixelColor(revers_top_left, strip4.Color(0, 255, 0));         //ring gauche top
      revers_top_left++;
      
      strip4.setPixelColor(revers_bot_left, strip4.Color(0, 255, 0));         //  ring gauche bot
      if(revers_bot_left == 0){
        revers_bot_left = 24;
      }
      revers_bot_left--;
    }
    if(led4 == 1){
      strip4.setPixelColor(revers_top_left, strip4.Color(255, 0, 0));         //ring gauche top
      revers_top_left++;
      
      strip4.setPixelColor(revers_bot_left, strip4.Color(255, 0, 0));         //  ring gauche bot
      if(revers_bot_left == 0){
        revers_bot_left = 24;
      }
      revers_bot_left--;
    }
  if(led5 == 0){
    strip5.setPixelColor(revers_top_topLeft, strip5.Color(0, 255, 0));          //ring haut gauche top
    revers_top_topLeft++;

    strip5.setPixelColor(revers_bot_topLeft, strip5.Color(0, 255, 0));         //ring haut gauche bot
    if(revers_bot_topLeft == 0){
      revers_bot_topLeft = 24;
    }
    revers_bot_topLeft--;
  }
  if(led5 == 1){
    strip5.setPixelColor(revers_top_topLeft, strip5.Color(255, 0, 0));          //ring haut gauche top
    revers_top_topLeft++;

    strip5.setPixelColor(revers_bot_topLeft, strip5.Color(255,0 , 0));         //ring haut gauche bot
    if(revers_bot_topLeft == 0){
      revers_bot_topLeft = 24;
    }
    revers_bot_topLeft--;
  }
  if(led6 == 0){
    strip6.setPixelColor(revers_top_topRight, strip6.Color(0, 255, 0));          //ring haut gauche top
    if(revers_top_topRight == 24){
      revers_top_topRight = -1;
    }
    revers_top_topRight++;

    strip6.setPixelColor(revers_bot_topRight, strip6.Color(0, 255, 0));         //ring haut gauche bot
    revers_bot_topRight--;
  }  
  if(led6 == 1){
    strip6.setPixelColor(revers_top_topRight, strip6.Color(255, 0, 0));          //ring haut gauche top
    if(revers_top_topRight == 24){
      revers_top_topRight = -1;
    }
    revers_top_topRight++;

    strip6.setPixelColor(revers_bot_topRight, strip6.Color(255, 0, 0));         //ring haut gauche bot
    revers_bot_topRight--;
  } 
    strip2.show();                          //  Update strip to match
    strip4.show();
    strip5.show();                          //  Update strip 5(haut gauche)
    strip6.show();                          //  Update strip 6(haut droite)
    
    
    compteur++;
    if( compteur >=10){
      strip3.setPixelColor(bot1, strip3.Color(255, 0, 0));         //ring haut gauche bot
      bot1++;
      strip3.setPixelColor(bot2, strip3.Color(255, 0, 0));         //ring haut gauche bot
      bot2--;
      
      strip3.setPixelColor(left1, strip3.Color(255, 0, 0));         //ring haut gauche bot
      left1++;
      strip3.setPixelColor(left2, strip3.Color(255, 0, 0));         //ring haut gauche bot
      left2--;
     
      strip3.setPixelColor(top1, strip3.Color(255, 0, 0));         //ring haut gauche bot
      top1++;
      strip3.setPixelColor(top2, strip3.Color(255, 0, 0));         //ring haut gauche bot
      top2--;
      
      strip3.setPixelColor(right1, strip3.Color(255, 0, 0));         //ring haut gauche bot
      right1++;
      strip3.setPixelColor(right2, strip3.Color(255, 0, 0));         //ring haut gauche bot
      right2--;
  
      strip3.show();                          //  Update strip 6(haut droite)
    
    }
     delay(wait);  
  }
 
 }

 /*
 * vague rouge led 4 
 */

void wave4(int wait){
  
  //variable ring droite
  int top_right = 6; 
  int bot_right = 6;

  //variable ring haut droite
  int top_topRight = 2;
  int bot_topRight = 2;

  for(int i = 0; i<13; i++){
    if(led3 == 0){
      strip3.setPixelColor(top_right, strip3.Color(255, 0, 0));         //ring droite top
      top_right++;
      
      strip3.setPixelColor(bot_right, strip3.Color(255, 0, 0));         //ring droite bot
      if(bot_right == 0){
        bot_right = 24;
      }
      bot_right--;
    }  
    if(led3 == 1){
      strip3.setPixelColor(top_right, strip3.Color(0, 0, 255));         //ring droite top
      top_right++;
      
      strip3.setPixelColor(bot_right, strip3.Color(0, 0, 255));         //ring droite bot
      if(bot_right == 0){
        bot_right = 24;
      }
      bot_right--;
    } 
    
   if(led5 == 0){
      strip5.setPixelColor(top_topRight, strip5.Color(255, 0, 0));          //ring haut gauche top
      if(top_topRight == 0){
        top_topRight = 24;
      }
      top_topRight--;
  
      strip5.setPixelColor(bot_topRight, strip5.Color(255, 0, 0));         //ring haut gauche bot
      bot_topRight++;
   }
   if(led5 == 1){
      strip5.setPixelColor(top_topRight, strip5.Color(0, 0, 255));          //ring haut gauche top
      if(top_topRight == 0){
        top_topRight = 24;
      }
      top_topRight--;
  
      strip5.setPixelColor(bot_topRight, strip5.Color(0, 0, 255));         //ring haut gauche bot
      bot_topRight++;
   }
    
    strip3.show();                          //  Update strip 5(haut gauche)
    strip5.show();                          //  Update strip 6(haut droite)
    delay(wait);                           //  Pause for a moment
  }

delay(wait); 
 
/* 
 *  reverse
 */

  //variable ring droite 2
  int revers_top_right = 18;
  int revers_bot_right = 18;

  //variable ring haut droite 6
  int revers_top_topRight = 14;
  int revers_bot_topRight = 14;

  int bot1 = 0;
  int bot2 = 24;
  
  int left1 = 6;
  int left2 = 6;
  
  int top1 = 12;
  int top2 = 12;
  
  int right1 = 18;
  int right2 = 18;

  int compteur = 0;
  
  for(int i = 0; i<13; i++){
    if(led3 == 0){
      strip3.setPixelColor(revers_top_right, strip3.Color(0, 255, 0));         //ring droite top
      revers_top_right--;
      
      strip3.setPixelColor(revers_bot_right, strip3.Color(0, 255, 0));         //ring droite bot
      if(revers_bot_right == 24){
        revers_bot_right = -1;
      }
      revers_bot_right++;
    }
    if(led3 == 1){
      strip3.setPixelColor(revers_top_right, strip3.Color(255, 0, 0));         //ring droite top
      revers_top_right--;
      
      strip3.setPixelColor(revers_bot_right, strip3.Color(255, 0, 0));         //ring droite bot
      if(revers_bot_right == 24){
        revers_bot_right = -1;
      }
      revers_bot_right++;
    }
  
  if(led5 == 0){
    strip5.setPixelColor(revers_top_topRight, strip5.Color(0, 255, 0));          //ring haut gauche top
    if(revers_top_topRight == 24){
      revers_top_topRight = -1;
    }
    revers_top_topRight++;

    strip5.setPixelColor(revers_bot_topRight, strip5.Color(0, 255, 0));         //ring haut gauche bot
    revers_bot_topRight--;
  }
  if(led5 == 1){
    strip5.setPixelColor(revers_top_topRight, strip5.Color(255, 0, 0));          //ring haut gauche top
    if(revers_top_topRight == 24){
      revers_top_topRight = -1;
    }
    revers_top_topRight++;

    strip5.setPixelColor(revers_bot_topRight, strip5.Color(255, 0, 0));         //ring haut gauche bot
    revers_bot_topRight--;
  }   
   
    strip3.show();                          //  Update strip 3(haut gauche)
    strip5.show();                          //  Update strip 5(haut droite)
    
    
    compteur++;
    if( compteur >=10){
      strip4.setPixelColor(bot1, strip4.Color(255, 0, 0));         //ring haut gauche bot
      bot1++;
      strip4.setPixelColor(bot2, strip4.Color(255, 0, 0));         //ring haut gauche bot
      bot2--;
      
      strip4.setPixelColor(left1, strip4.Color(255, 0, 0));         //ring haut gauche bot
      left1++;
      strip4.setPixelColor(left2, strip4.Color(255, 0, 0));         //ring haut gauche bot
      left2--;
     
      strip4.setPixelColor(top1, strip4.Color(255, 0, 0));         //ring haut gauche bot
      top1++;
      strip4.setPixelColor(top2, strip4.Color(255, 0, 0));         //ring haut gauche bot
      top2--;
      
      strip4.setPixelColor(right1, strip4.Color(255, 0, 0));         //ring haut gauche bot
      right1++;
      strip4.setPixelColor(right2, strip4.Color(255, 0, 0));         //ring haut gauche bot
      right2--;
  
      strip4.show();                          //  Update strip 6(haut droite)
    
    }
     delay(wait);  
  }
 
 }

 
/*
 * vague rouge led 5 
 */

void wave5(int wait){
  
  //variable ring droite
  int top_right = 6; 
  int bot_right = 6;

  //variable ring haut droite
  int top_topRight = 2;
  int bot_topRight = 2;

  //variable ring bas gauche
  int top_botLeft = 14;
  int bot_botLeft = 14;

  //variable ring bas droite
  int top_botRight = 10;
  int bot_botRight = 10;

  for(int i = 0; i<13; i++){
    if(led6 == 0){
      strip6.setPixelColor(top_right, strip6.Color(255, 0, 0));         //ring droite top
      top_right++;
      
      strip6.setPixelColor(bot_right, strip6.Color(255, 0, 0));         //ring droite bot
      if(bot_right == 0){
        bot_right = 24;
      }
      bot_right--;
    }
    if(led6 == 1){
      strip6.setPixelColor(top_right, strip6.Color(0, 0, 255));         //ring droite top
      top_right++;
      
      strip6.setPixelColor(bot_right, strip6.Color(0, 0, 255));         //ring droite bot
      if(bot_right == 0){
        bot_right = 24;
      }
      bot_right--;
    }  
   
   if(led9 == 0){
      strip9.setPixelColor(top_topRight, strip9.Color(255, 0, 0));          //ring haut droite top
      if(top_topRight == 0){
        top_topRight = 24;
      }
      top_topRight--;
  
      strip9.setPixelColor(bot_topRight, strip9.Color(255, 0, 0));         //ring haut droite bot
      bot_topRight++;
   }
   if(led9 == 1){
      strip9.setPixelColor(top_topRight, strip9.Color(0, 0, 255));          //ring haut droite top
      if(top_topRight == 0){
        top_topRight = 24;
      }
      top_topRight--;
  
      strip9.setPixelColor(bot_topRight, strip9.Color(0, 0, 255));         //ring haut droite bot
      bot_topRight++;
   }
   if(led3 == 0){
    strip3.setPixelColor(top_botRight, strip3.Color(255, 0, 0));          //ring bas droite top
      top_botRight++;
  
      strip3.setPixelColor(bot_botRight, strip3.Color(255, 0, 0));         //ring bas droite bot
      if(bot_botRight == 0){
        bot_botRight = 24;
      }
      bot_botRight--;
   }
   if(led3 == 1){
    strip3.setPixelColor(top_botRight, strip3.Color(0, 0, 255));          //ring bas droite top
      top_botRight++;
  
      strip3.setPixelColor(bot_botRight, strip3.Color(0, 0, 255));         //ring bas droite bot
      if(bot_botRight == 0){
        bot_botRight = 24;
      }
      bot_botRight--;
   }
   if(led4 == 0){
    strip4.setPixelColor(top_botLeft, strip4.Color(255, 0, 0));          //ring bas gauche top
    if(top_botLeft == 24){
        top_botLeft = -1;
      }
      top_botLeft++;
  
      strip4.setPixelColor(bot_botLeft, strip4.Color(255, 0, 0));         //ring bas gauche bot
      bot_botLeft--;
   }
   if(led4 == 1){
    strip4.setPixelColor(top_botLeft, strip4.Color(0, 0, 255));          //ring bas gauche top
    if(top_botLeft == 24){
        top_botLeft = -1;
      }
      top_botLeft++;
  
      strip4.setPixelColor(bot_botLeft, strip4.Color(0, 0, 255));         //ring bas gauche bot
      bot_botLeft--;
   }
    strip6.show();                          
    strip9.show();                          
    strip3.show();                          
    strip6.show();      
                       
    delay(wait);                         
  }


delay(wait); 
 
/* 
 *  reverse
 */

  //variable ring droite 2
  int revers_top_right = 18;
  int revers_bot_right = 18;

  //variable ring haut droite 6
  int revers_top_topRight = 14;
  int revers_bot_topRight = 14;

  //variable ring bas gauche
  int revers_top_botLeft = 2;
  int revers_bot_botLeft = 2;

  //variable ring bas droite
  int revers_top_botRight = 23;
  int revers_bot_botRight = 23;

  int bot1 = 0;
  int bot2 = 24;
  
  int left1 = 6;
  int left2 = 6;
  
  int top1 = 12;
  int top2 = 12;
  
  int right1 = 18;
  int right2 = 18;

  int compteur = 0;
  
  for(int i = 0; i<13; i++){
    
    if(led6 == 0){
      strip6.setPixelColor(revers_top_right, strip6.Color(0, 255, 0));         //ring droite top
      revers_top_right--;
      
      strip6.setPixelColor(revers_bot_right, strip6.Color(0, 255, 0));         //ring droite bot
      if(revers_bot_right == 24){
        revers_bot_right = -1;
      }
      revers_bot_right++;
    }
    if(led6 == 1){
      strip6.setPixelColor(revers_top_right, strip6.Color(255, 0, 0));         //ring droite top
      revers_top_right--;
      
      strip6.setPixelColor(revers_bot_right, strip6.Color(255, 0, 0));         //ring droite bot
      if(revers_bot_right == 24){
        revers_bot_right = -1;
      }
      revers_bot_right++;
    }
  if(led9 == 0){
    strip9.setPixelColor(revers_top_topRight, strip9.Color(0, 255, 0));          //ring haut droite top
    if(revers_top_topRight == 24){
      revers_top_topRight = -1;
    }
    revers_top_topRight++;

    strip9.setPixelColor(revers_bot_topRight, strip9.Color(0, 255, 0));         //ring haut droite bot
    revers_bot_topRight--;
  }  
  if(led9 == 1){
    strip9.setPixelColor(revers_top_topRight, strip9.Color(255, 0, 0));          //ring haut droite top
    if(revers_top_topRight == 24){
      revers_top_topRight = -1;
    }
    revers_top_topRight++;

    strip9.setPixelColor(revers_bot_topRight, strip9.Color(255, 0, 0));         //ring haut droite bot
    revers_bot_topRight--;
  }
  if(led3 == 0){
    strip3.setPixelColor(revers_top_botRight, strip3.Color(0, 255, 0));          //ring bas droite top
      revers_top_botRight--;
  
      strip3.setPixelColor(revers_bot_botRight, strip3.Color(0, 255, 0));         //ring bas droite bot
       if( revers_bot_botRight == 24){
         revers_bot_botRight = -1;
      }
      revers_bot_botRight++;
   }
   if(led3 == 1){
    strip3.setPixelColor(revers_top_botRight, strip3.Color(255, 0, 0));          //ring bas droite top
      revers_top_botRight--;
  
      strip3.setPixelColor(revers_bot_botRight, strip3.Color(255, 0, 0));         //ring bas droite bot
       if( revers_bot_botRight == 24){
         revers_bot_botRight = -1;
      }
      revers_bot_botRight++;
   }
   if(led4 == 0){
    strip4.setPixelColor(revers_top_botLeft, strip4.Color(0, 255, 0));          //ring bas gauche top
    if(revers_top_botLeft == 0){
        revers_top_botLeft = 24;
      }
      revers_top_botLeft--;
  
      strip4.setPixelColor(revers_bot_botLeft, strip4.Color(0, 255, 0));         //ring bas gauche bot
      revers_bot_botLeft++;
   }
   if(led4 == 1){
    strip4.setPixelColor(revers_top_botLeft, strip4.Color(255, 0, 0));          //ring bas gauche top
    if(revers_top_botLeft == 0){
        revers_top_botLeft = 24;
      }
      revers_top_botLeft--;
  
      strip4.setPixelColor(revers_bot_botLeft, strip4.Color(255, 0, 0));         //ring bas gauche bot
      revers_bot_botLeft++;
   }
    strip6.show();                          //  Update strip to match
    strip9.show();
    strip3.show();                          //  Update strip 5(haut gauche)
    strip4.show();                          //  Update strip 6(haut droite)
    
   
    compteur++;
    if( compteur >=10){
      strip5.setPixelColor(bot1, strip5.Color(255, 0, 0));         //ring haut gauche bot
      bot1++;
      strip5.setPixelColor(bot2, strip5.Color(255, 0, 0));         //ring haut gauche bot
      bot2--;
      
      strip5.setPixelColor(left1, strip5.Color(255, 0, 0));         //ring haut gauche bot
      left1++;
      strip5.setPixelColor(left2, strip5.Color(255, 0, 0));         //ring haut gauche bot
      left2--;
     
      strip5.setPixelColor(top1, strip5.Color(255, 0, 0));         //ring haut gauche bot
      top1++;
      strip5.setPixelColor(top2, strip5.Color(255, 0, 0));         //ring haut gauche bot
      top2--;
      
      strip5.setPixelColor(right1, strip5.Color(255, 0, 0));         //ring haut gauche bot
      right1++;
      strip5.setPixelColor(right2, strip5.Color(255, 0, 0));         //ring haut gauche bot
      right2--;
  
      strip5.show();                          //  Update strip 6(haut droite)
    
    }
     delay(wait);  
  }
 
 }  
/*
 * vague rouge led 6
 */
 void wave6(int wait){
  
  //variable ring droite
  int top_right = 6; 
  int bot_right = 6;

  //variable ring gauche
  int top_left = 18;
  int bot_left = 18;

  //variable ring haut gauche
  int top_topLeft = 23;
  int bot_topLeft = 23;

  //variable ring haut droite
  int top_topRight = 2;
  int bot_topRight = 2;

  //variable ring bas gauche
  int top_botLeft = 14;
  int bot_botLeft = 14;

  //variable ring bas droite
  int top_botRight = 10;
  int bot_botRight = 10;

  for(int i = 0; i<13; i++){
    if(led7 == 0){
      strip7.setPixelColor(top_right, strip7.Color(255, 0, 0));         //ring droite top
      top_right++;
      
      strip7.setPixelColor(bot_right, strip7.Color(255, 0, 0));         //ring droite bot
      if(bot_right == 0){
        bot_right = 24;
      }
      bot_right--;
    } 
    if(led7 == 1){
      strip7.setPixelColor(top_right, strip7.Color(0, 0, 255));         //ring droite top
      top_right++;
      
      strip7.setPixelColor(bot_right, strip7.Color(0, 0, 255));         //ring droite bot
      if(bot_right == 0){
        bot_right = 24;
      }
      bot_right--;
    } 
    if(led5 == 0){
      strip5.setPixelColor(top_left, strip5.Color(255, 0, 0));          //ring gauche top
      top_left--;
  
       strip5.setPixelColor(bot_left, strip5.Color(255, 0, 0));         //ring gauche bot
      if(bot_left == 24){
        bot_left = -1;
      }
      bot_left++;
    }
    if(led5 == 1){
      strip5.setPixelColor(top_left, strip5.Color(0, 0, 255));          //ring gauche top
      top_left--;
  
       strip5.setPixelColor(bot_left, strip5.Color(0, 0, 255));         //ring gauche bot
      if(bot_left == 24){
        bot_left = -1;
      }
      bot_left++;
    }
    
   if(led9 == 0){
      strip9.setPixelColor(top_topLeft, strip9.Color(255, 0, 0));          //ring haut gauche top
      top_topLeft--;
  
      strip9.setPixelColor(bot_topLeft, strip9.Color(255, 0, 0));         //ring haut gauche bot
      if(bot_topLeft == 24){
        bot_topLeft = -1;
      }
      bot_topLeft++;
   }
   if(led9 == 1){
      strip9.setPixelColor(top_topLeft, strip9.Color(0, 0, 255));          //ring haut gauche top
      top_topLeft--;
  
      strip9.setPixelColor(bot_topLeft, strip9.Color(0, 0, 255));         //ring haut gauche bot
      if(bot_topLeft == 24){
        bot_topLeft = -1;
      }
      bot_topLeft++;
   }
   
   if(led8 == 0){
      strip8.setPixelColor(top_topRight, strip8.Color(255, 0, 0));          //ring haut droite top
      if(top_topRight == 0){
        top_topRight = 24;
      }
      top_topRight--;
  
      strip8.setPixelColor(bot_topRight, strip8.Color(255, 0, 0));         //ring haut droite bot
      bot_topRight++;
   }
   if(led8 == 1){
      strip8.setPixelColor(top_topRight, strip8.Color(0, 0, 255));          //ring haut droite top
      if(top_topRight == 0){
        top_topRight = 24;
      }
      top_topRight--;
  
      strip8.setPixelColor(bot_topRight, strip8.Color(0, 0, 255));         //ring haut droite bot
      bot_topRight++;
   }
   if(led2 == 0){
    strip2.setPixelColor(top_botRight, strip2.Color(255, 0, 0));          //ring bas droite top
      top_botRight++;
  
      strip2.setPixelColor(bot_botRight, strip2.Color(255, 0, 0));         //ring bas droite bot
      if(bot_botRight == 0){
        bot_botRight = 24;
      }
      bot_botRight--;
   }
   if(led2 == 1){
    strip2.setPixelColor(top_botRight, strip2.Color(0, 0, 255));          //ring bas droite top
      top_botRight++;
  
      strip2.setPixelColor(bot_botRight, strip2.Color(0, 0, 255));         //ring bas droite bot
      if(bot_botRight == 0){
        bot_botRight = 24;
      }
      bot_botRight--;
   }
   if(led3 == 0){
    strip3.setPixelColor(top_botLeft, strip3.Color(255, 0, 0));          //ring bas gauche top
    if(top_botLeft == 24){
        top_botLeft = -1;
      }
      top_botLeft++;
  
      strip3.setPixelColor(bot_botLeft, strip3.Color(255, 0, 0));         //ring bas gauche bot
      bot_botLeft--;
   }
   if(led3 == 1){
    strip3.setPixelColor(top_botLeft, strip3.Color(0, 0, 255));          //ring bas gauche top
    if(top_botLeft == 24){
        top_botLeft = -1;
      }
      top_botLeft++;
  
      strip3.setPixelColor(bot_botLeft, strip3.Color(0, 0, 255));         //ring bas gauche bot
      bot_botLeft--;
   }
    strip5.show();                          
    strip7.show();                          
    strip8.show();                          
    strip9.show(); 
    strip3.show();                          
    strip2.show();      
                       
    delay(wait);                         
  }


delay(wait); 
 
/* 
 *  reverse
 */

  //variable ring droite 2
  int revers_top_right = 18;
  int revers_bot_right = 18;

  //variable ring gauche 4
  int revers_top_left = 6;
  int revers_bot_left = 6;

  //variable ring haut gauche 5
  int revers_top_topLeft = 10;
  int revers_bot_topLeft = 10;

  //variable ring haut droite 6
  int revers_top_topRight = 14;
  int revers_bot_topRight = 14;

  //variable ring bas gauche
  int revers_top_botLeft = 2;
  int revers_bot_botLeft = 2;

  //variable ring bas droite
  int revers_top_botRight = 23;
  int revers_bot_botRight = 23;

  int bot1 = 0;
  int bot2 = 24;
  
  int left1 = 6;
  int left2 = 6;
  
  int top1 = 12;
  int top2 = 12;
  
  int right1 = 18;
  int right2 = 18;

  int compteur = 0;
  
  for(int i = 0; i<13; i++){
    
    if(led7 == 0){
      strip7.setPixelColor(revers_top_right, strip7.Color(0, 255, 0));         //ring droite top
      revers_top_right--;
      
      strip7.setPixelColor(revers_bot_right, strip7.Color(0, 255, 0));         //ring droite bot
      if(revers_bot_right == 24){
        revers_bot_right = -1;
      }
      revers_bot_right++;
    }
    if(led7 == 1){
      strip7.setPixelColor(revers_top_right, strip7.Color(255, 0, 0));         //ring droite top
      revers_top_right--;
      
      strip7.setPixelColor(revers_bot_right, strip7.Color(255, 0, 0));         //ring droite bot
      if(revers_bot_right == 24){
        revers_bot_right = -1;
      }
      revers_bot_right++;
    }
    if(led5 == 0){
      strip5.setPixelColor(revers_top_left, strip5.Color(0, 255, 0));         //ring gauche top
      revers_top_left++;
      
      strip5.setPixelColor(revers_bot_left, strip5.Color(0, 255, 0));         //  ring gauche bot
      if(revers_bot_left == 0){
        revers_bot_left = 24;
      }
      revers_bot_left--;
    }
    if(led5 == 1){
      strip5.setPixelColor(revers_top_left, strip5.Color(255, 0, 0));         //ring gauche top
      revers_top_left++;
      
      strip5.setPixelColor(revers_bot_left, strip5.Color(255, 0, 0));         //  ring gauche bot
      if(revers_bot_left == 0){
        revers_bot_left = 24;
      }
      revers_bot_left--;
    }
  if(led9 == 0){
    strip9.setPixelColor(revers_top_topLeft, strip9.Color(0, 255, 0));          //ring haut gauche top
    revers_top_topLeft++;

    strip9.setPixelColor(revers_bot_topLeft, strip9.Color(0, 255, 0));         //ring haut gauche bot
    if(revers_bot_topLeft == 0){
      revers_bot_topLeft = 24;
    }
    revers_bot_topLeft--;
  }
  if(led9 == 1){
    strip9.setPixelColor(revers_top_topLeft, strip9.Color(255, 0, 0));          //ring haut gauche top
    revers_top_topLeft++;

    strip9.setPixelColor(revers_bot_topLeft, strip9.Color(255, 0, 0));         //ring haut gauche bot
    if(revers_bot_topLeft == 0){
      revers_bot_topLeft = 24;
    }
    revers_bot_topLeft--;
  }
  if(led8 == 0){
    strip8.setPixelColor(revers_top_topRight, strip8.Color(0, 255, 0));          //ring haut droite top
    if(revers_top_topRight == 24){
      revers_top_topRight = -1;
    }
    revers_top_topRight++;

    strip8.setPixelColor(revers_bot_topRight, strip8.Color(0, 255, 0));         //ring haut droite bot
    revers_bot_topRight--;
  }  
  if(led8 == 1){
    strip8.setPixelColor(revers_top_topRight, strip8.Color(255, 0, 0));          //ring haut droite top
    if(revers_top_topRight == 24){
      revers_top_topRight = -1;
    }
    revers_top_topRight++;

    strip8.setPixelColor(revers_bot_topRight, strip8.Color(255, 0, 0));         //ring haut droite bot
    revers_bot_topRight--;
  }
  if(led2 == 0){
    strip2.setPixelColor(revers_top_botRight, strip2.Color(0, 255, 0));          //ring bas droite top
      revers_top_botRight--;
  
      strip2.setPixelColor(revers_bot_botRight, strip2.Color(0, 255, 0));         //ring bas droite bot
       if( revers_bot_botRight == 24){
         revers_bot_botRight = -1;
      }
      revers_bot_botRight++;
   }
   if(led2 == 1){
    strip2.setPixelColor(revers_top_botRight, strip2.Color(255, 0, 0));          //ring bas droite top
      revers_top_botRight--;
  
      strip2.setPixelColor(revers_bot_botRight, strip2.Color(255, 0, 0));         //ring bas droite bot
       if( revers_bot_botRight == 24){
         revers_bot_botRight = -1;
      }
      revers_bot_botRight++;
   }
   if(led3 == 0){
    strip3.setPixelColor(revers_top_botLeft, strip3.Color(0, 255, 0));          //ring bas gauche top
    if(revers_top_botLeft == 0){
        revers_top_botLeft = 24;
      }
      revers_top_botLeft--;
  
      strip3.setPixelColor(revers_bot_botLeft, strip3.Color(0, 255, 0));         //ring bas gauche bot
      revers_bot_botLeft++;
   }
   if(led3 == 1){
    strip3.setPixelColor(revers_top_botLeft, strip3.Color(255, 0, 0));          //ring bas gauche top
    if(revers_top_botLeft == 0){
        revers_top_botLeft = 24;
      }
      revers_top_botLeft--;
  
      strip3.setPixelColor(revers_bot_botLeft, strip3.Color(255, 0, 0));         //ring bas gauche bot
      revers_bot_botLeft++;
   }
    strip5.show();                          //  Update strip to match
    strip7.show();
    strip8.show();                          //  Update strip 5(haut gauche)
    strip9.show();                          //  Update strip 6(haut droite)
    strip2.show();                          //  Update strip 5(haut gauche)
    strip3.show();                          //  Update strip 6(haut droite)
    
   
    compteur++;
    if( compteur >=10){
      strip6.setPixelColor(bot1, strip6.Color(255, 0, 0));         //ring haut gauche bot
      bot1++;
      strip6.setPixelColor(bot2, strip6.Color(255, 0, 0));         //ring haut gauche bot
      bot2--;
      
      strip6.setPixelColor(left1, strip6.Color(255, 0, 0));         //ring haut gauche bot
      left1++;
      strip6.setPixelColor(left2, strip6.Color(255, 0, 0));         //ring haut gauche bot
      left2--;
     
      strip6.setPixelColor(top1, strip6.Color(255, 0, 0));         //ring haut gauche bot
      top1++;
      strip6.setPixelColor(top2, strip6.Color(255, 0, 0));         //ring haut gauche bot
      top2--;
      
      strip6.setPixelColor(right1, strip6.Color(255, 0, 0));         //ring haut gauche bot
      right1++;
      strip6.setPixelColor(right2, strip6.Color(255, 0, 0));         //ring haut gauche bot
      right2--;
  
      strip6.show();                          //  Update strip 6(haut droite)
    
    }
     delay(wait);  
  }
 
 } 

/*
 * vague rouge led 7
 */
 void wave7(int wait){
  
  
  //variable ring gauche
  int top_left = 18;
  int bot_left = 18;

  //variable ring haut gauche
  int top_topLeft = 23;
  int bot_topLeft = 23;

  //variable ring bas gauche
  int top_botLeft = 14;
  int bot_botLeft = 14;

  //variable ring bas droite
  int top_botRight = 10;
  int bot_botRight = 10;

  for(int i = 0; i<13; i++){
    
    if(led6 == 0){
      strip6.setPixelColor(top_left, strip6.Color(255, 0, 0));          //ring gauche top
      top_left--;
  
       strip6.setPixelColor(bot_left, strip6.Color(255, 0, 0));         //ring gauche bot
      if(bot_left == 24){
        bot_left = -1;
      }
      bot_left++;
    }
    if(led6 == 1){
      strip6.setPixelColor(top_left, strip6.Color(0, 0, 255));          //ring gauche top
      top_left--;
  
       strip6.setPixelColor(bot_left, strip6.Color(0, 0, 255));         //ring gauche bot
      if(bot_left == 24){
        bot_left = -1;
      }
      bot_left++;
    }
    
   if(led8 == 0){
      strip8.setPixelColor(top_topLeft, strip8.Color(255, 0, 0));          //ring haut gauche top
      top_topLeft--;
  
      strip8.setPixelColor(bot_topLeft, strip8.Color(255, 0, 0));         //ring haut gauche bot
      if(bot_topLeft == 24){
        bot_topLeft = -1;
      }
      bot_topLeft++;
   }
   if(led8 == 1){
      strip8.setPixelColor(top_topLeft, strip8.Color(0, 0, 255));          //ring haut gauche top
      top_topLeft--;
  
      strip8.setPixelColor(bot_topLeft, strip8.Color(0, 0, 255));         //ring haut gauche bot
      if(bot_topLeft == 24){
        bot_topLeft = -1;
      }
      bot_topLeft++;
   }
   
   if(led1 == 0){
    strip1.setPixelColor(top_botRight, strip1.Color(255, 0, 0));          //ring bas droite top
      top_botRight++;
  
      strip1.setPixelColor(bot_botRight, strip1.Color(255, 0, 0));         //ring bas droite bot
      if(bot_botRight == 0){
        bot_botRight = 24;
      }
      bot_botRight--;
   }
   if(led1 == 1){
    strip1.setPixelColor(top_botRight, strip1.Color(0, 0, 255));          //ring bas droite top
      top_botRight++;
  
    strip1.setPixelColor(bot_botRight, strip1.Color(0, 0, 255));         //ring bas droite bot
      if(bot_botRight == 0){
        bot_botRight = 24;
      }
      bot_botRight--;
   }
   if(led2 == 0){
    strip2.setPixelColor(top_botLeft, strip2.Color(255, 0, 0));          //ring bas gauche top
    if(top_botLeft == 24){
        top_botLeft = -1;
      }
      top_botLeft++;
  
      strip2.setPixelColor(bot_botLeft, strip2.Color(255, 0, 0));         //ring bas gauche bot
      bot_botLeft--;
   }
   if(led2 == 1){
    strip2.setPixelColor(top_botLeft, strip2.Color(0, 0, 255));          //ring bas gauche top
    if(top_botLeft == 24){
        top_botLeft = -1;
      }
      top_botLeft++;
  
      strip2.setPixelColor(bot_botLeft, strip2.Color(0, 0, 255));         //ring bas gauche bot
      bot_botLeft--;
   }
    strip6.show();                          
    strip8.show();                          
    strip1.show();                          
    strip2.show();    
                       
    delay(wait);                         
  }


delay(wait); 
 
/* 
 *  reverse
 */
 
  //variable ring gauche 4
  int revers_top_left = 6;
  int revers_bot_left = 6;

  //variable ring haut gauche 5
  int revers_top_topLeft = 10;
  int revers_bot_topLeft = 10;

  //variable ring bas gauche
  int revers_top_botLeft = 2;
  int revers_bot_botLeft = 2;

  //variable ring bas droite
  int revers_top_botRight = 23;
  int revers_bot_botRight = 23;

  int bot1 = 0;
  int bot2 = 24;
  
  int left1 = 6;
  int left2 = 6;
  
  int top1 = 12;
  int top2 = 12;
  
  int right1 = 18;
  int right2 = 18;

  int compteur = 0;
  
  for(int i = 0; i<13; i++){
    
    if(led6 == 0){
      strip6.setPixelColor(revers_top_left, strip6.Color(0, 255, 0));         //ring gauche top
      revers_top_left++;
      
      strip6.setPixelColor(revers_bot_left, strip6.Color(0, 255, 0));         //  ring gauche bot
      if(revers_bot_left == 0){
        revers_bot_left = 24;
      }
      revers_bot_left--;
    }
    if(led6 == 1){
      strip6.setPixelColor(revers_top_left, strip6.Color(255, 0, 0));         //ring gauche top
      revers_top_left++;
      
      strip6.setPixelColor(revers_bot_left, strip6.Color(255, 0, 0));         //  ring gauche bot
      if(revers_bot_left == 0){
        revers_bot_left = 24;
      }
      revers_bot_left--;
    }
  if(led8 == 0){
    strip8.setPixelColor(revers_top_topLeft, strip8.Color(0, 255, 0));          //ring haut gauche top
    revers_top_topLeft++;

    strip8.setPixelColor(revers_bot_topLeft, strip8.Color(0, 255, 0));         //ring haut gauche bot
    if(revers_bot_topLeft == 0){
      revers_bot_topLeft = 24;
    }
    revers_bot_topLeft--;
  } 
  if(led8 == 1){
    strip8.setPixelColor(revers_top_topLeft, strip8.Color(255, 0, 0));          //ring haut gauche top
    revers_top_topLeft++;

    strip8.setPixelColor(revers_bot_topLeft, strip8.Color(255, 0, 0));         //ring haut gauche bot
    if(revers_bot_topLeft == 0){
      revers_bot_topLeft = 24;
    }
    revers_bot_topLeft--;
  }
  if(led1 == 0){
    strip1.setPixelColor(revers_top_botRight, strip1.Color(0, 255, 0));          //ring bas droite top
      revers_top_botRight--;
  
      strip1.setPixelColor(revers_bot_botRight, strip1.Color(0, 255, 0));         //ring bas droite bot
       if( revers_bot_botRight == 24){
         revers_bot_botRight = -1;
      }
      revers_bot_botRight++;
   }
   if(led1 == 1){
    strip1.setPixelColor(revers_top_botRight, strip1.Color(255, 0, 0));          //ring bas droite top
      revers_top_botRight--;
  
      strip1.setPixelColor(revers_bot_botRight, strip1.Color(255, 0, 0));         //ring bas droite bot
       if( revers_bot_botRight == 24){
         revers_bot_botRight = -1;
      }
      revers_bot_botRight++;
   }
   if(led2 == 0){
    strip2.setPixelColor(revers_top_botLeft, strip2.Color(0, 255, 0));          //ring bas gauche top
    if(revers_top_botLeft == 0){
        revers_top_botLeft = 24;
      }
      revers_top_botLeft--;
  
      strip2.setPixelColor(revers_bot_botLeft, strip2.Color(0, 255, 0));         //ring bas gauche bot
      revers_bot_botLeft++;
   }
   if(led2 == 1){
    strip2.setPixelColor(revers_top_botLeft, strip2.Color(255, 0, 0));          //ring bas gauche top
    if(revers_top_botLeft == 0){
        revers_top_botLeft = 24;
      }
      revers_top_botLeft--;
  
      strip2.setPixelColor(revers_bot_botLeft, strip2.Color(255, 0, 0));         //ring bas gauche bot
      revers_bot_botLeft++;
   }
    strip6.show();                          //  Update strip to match
    strip8.show();
    strip1.show();                          //  Update strip 5(haut gauche)
    strip2.show();                          //  Update strip 6(haut droite)

    
   
    compteur++;
    if( compteur >=10){
      strip7.setPixelColor(bot1, strip7.Color(255, 0, 0));         //ring haut gauche bot
      bot1++;
      strip7.setPixelColor(bot2, strip7.Color(255, 0, 0));         //ring haut gauche bot
      bot2--;
      
      strip7.setPixelColor(left1, strip7.Color(255, 0, 0));         //ring haut gauche bot
      left1++;
      strip7.setPixelColor(left2, strip7.Color(255, 0, 0));         //ring haut gauche bot
      left2--;
     
      strip7.setPixelColor(top1, strip7.Color(255, 0, 0));         //ring haut gauche bot
      top1++;
      strip7.setPixelColor(top2, strip7.Color(255, 0, 0));         //ring haut gauche bot
      top2--;
      
      strip7.setPixelColor(right1, strip7.Color(255, 0, 0));         //ring haut gauche bot
      right1++;
      strip7.setPixelColor(right2, strip7.Color(255, 0, 0));         //ring haut gauche bot
      right2--;
  
      strip7.show();                          //  Update strip 6(haut droite)
    
    }
     delay(wait);  
  }
 
 } 

/*
 * vague rouge led 8
 */
 void wave8(int wait){
  
  
  //variable ring gauche
  int top_left = 18;
  int bot_left = 18;

  //variable ring haut gauche
  int top_topLeft = 23;
  int bot_topLeft = 23;

  //variable ring bas gauche
  int top_botLeft = 14;
  int bot_botLeft = 14;

  //variable ring bas droite
  int top_botRight = 10;
  int bot_botRight = 10;

  for(int i = 0; i<13; i++){
    
    if(led9 == 0){
      strip9.setPixelColor(top_left, strip9.Color(255, 0, 0));          //ring gauche top
      top_left--;
  
       strip9.setPixelColor(bot_left, strip9.Color(255, 0, 0));         //ring gauche bot
      if(bot_left == 24){
        bot_left = -1;
      }
      bot_left++;
    }
    if(led9 == 1){
      strip9.setPixelColor(top_left, strip9.Color(0, 0, 255));          //ring gauche top
      top_left--;
  
       strip9.setPixelColor(bot_left, strip9.Color(0, 0, 255));         //ring gauche bot
      if(bot_left == 24){
        bot_left = -1;
      }
      bot_left++;
    }
    
   if(led10 == 0){
      strip10.setPixelColor(top_topLeft, strip10.Color(255, 0, 0));          //ring haut gauche top
      top_topLeft--;
  
      strip10.setPixelColor(bot_topLeft, strip10.Color(255, 0, 0));         //ring haut gauche bot
      if(bot_topLeft == 24){
        bot_topLeft = -1;
      }
      bot_topLeft++;
   }
   if(led10 == 1){
      strip10.setPixelColor(top_topLeft, strip10.Color(0, 0, 255));          //ring haut gauche top
      top_topLeft--;
  
      strip10.setPixelColor(bot_topLeft, strip10.Color(0, 0, 255));         //ring haut gauche bot
      if(bot_topLeft == 24){
        bot_topLeft = -1;
      }
      bot_topLeft++;
   }
   
   if(led7 == 0){
    strip7.setPixelColor(top_botRight, strip7.Color(255, 0, 0));          //ring bas droite top
      top_botRight++;
  
      strip7.setPixelColor(bot_botRight, strip7.Color(255, 0, 0));         //ring bas droite bot
      if(bot_botRight == 0){
        bot_botRight = 24;
      }
      bot_botRight--;
   }
   if(led7 == 1){
    strip7.setPixelColor(top_botRight, strip7.Color(0, 0, 255));          //ring bas droite top
      top_botRight++;
  
      strip7.setPixelColor(bot_botRight, strip7.Color(0, 0, 255));         //ring bas droite bot
      if(bot_botRight == 0){
        bot_botRight = 24;
      }
      bot_botRight--;
   }
   if(led6 == 0){
    strip6.setPixelColor(top_botLeft, strip6.Color(255, 0, 0));          //ring bas gauche top
    if(top_botLeft == 24){
        top_botLeft = -1;
      }
      top_botLeft++;
  
      strip6.setPixelColor(bot_botLeft, strip6.Color(255, 0, 0));         //ring bas gauche bot
      bot_botLeft--;
   }
   if(led6 == 1){
    strip6.setPixelColor(top_botLeft, strip6.Color(0, 0, 255));          //ring bas gauche top
    if(top_botLeft == 24){
        top_botLeft = -1;
      }
      top_botLeft++;
  
      strip6.setPixelColor(bot_botLeft, strip6.Color(0, 0, 255));         //ring bas gauche bot
      bot_botLeft--;
   }
    strip9.show();                          
    strip10.show();                          
    strip6.show();                          
    strip7.show();    
                       
    delay(wait);                         
  }


delay(wait); 
 
/* 
 *  reverse
 */
 
  //variable ring gauche 4
  int revers_top_left = 6;
  int revers_bot_left = 6;

  //variable ring haut gauche 5
  int revers_top_topLeft = 10;
  int revers_bot_topLeft = 10;

  //variable ring bas gauche
  int revers_top_botLeft = 2;
  int revers_bot_botLeft = 2;

  //variable ring bas droite
  int revers_top_botRight = 23;
  int revers_bot_botRight = 23;

  int bot1 = 0;
  int bot2 = 24;
  
  int left1 = 6;
  int left2 = 6;
  
  int top1 = 12;
  int top2 = 12;
  
  int right1 = 18;
  int right2 = 18;

  int compteur = 0;
  
  for(int i = 0; i<13; i++){
    
    if(led9 == 0){
      strip9.setPixelColor(revers_top_left, strip9.Color(0, 255, 0));         //ring gauche top
      revers_top_left++;
      
      strip9.setPixelColor(revers_bot_left, strip9.Color(0, 255, 0));         //  ring gauche bot
      if(revers_bot_left == 0){
        revers_bot_left = 24;
      }
      revers_bot_left--;
    }
    if(led9 == 1){
      strip9.setPixelColor(revers_top_left, strip9.Color(255, 0, 0));         //ring gauche top
      revers_top_left++;
      
      strip9.setPixelColor(revers_bot_left, strip9.Color(255, 0, 0));         //  ring gauche bot
      if(revers_bot_left == 0){
        revers_bot_left = 24;
      }
      revers_bot_left--;
    }
  if(led10 == 0){
    strip10.setPixelColor(revers_top_topLeft, strip10.Color(0, 255, 0));          //ring haut gauche top
    revers_top_topLeft++;

    strip10.setPixelColor(revers_bot_topLeft, strip10.Color(0, 255, 0));         //ring haut gauche bot
    if(revers_bot_topLeft == 0){
      revers_bot_topLeft = 24;
    }
    revers_bot_topLeft--;
  } 
  if(led10 == 1){
    strip10.setPixelColor(revers_top_topLeft, strip10.Color(255, 0, 0));          //ring haut gauche top
    revers_top_topLeft++;

    strip10.setPixelColor(revers_bot_topLeft, strip10.Color(255, 0, 0));         //ring haut gauche bot
    if(revers_bot_topLeft == 0){
      revers_bot_topLeft = 24;
    }
    revers_bot_topLeft--;
  } 
  if(led7 == 0){
    strip7.setPixelColor(revers_top_botRight, strip7.Color(0, 255, 0));          //ring bas droite top
      revers_top_botRight--;
  
      strip7.setPixelColor(revers_bot_botRight, strip7.Color(0, 255, 0));         //ring bas droite bot
       if( revers_bot_botRight == 24){
         revers_bot_botRight = -1;
      }
      revers_bot_botRight++;
   }
   if(led7 == 1){
    strip7.setPixelColor(revers_top_botRight, strip7.Color(255, 0, 0));          //ring bas droite top
      revers_top_botRight--;
  
      strip7.setPixelColor(revers_bot_botRight, strip7.Color(255, 0, 0));         //ring bas droite bot
       if( revers_bot_botRight == 24){
         revers_bot_botRight = -1;
      }
      revers_bot_botRight++;
   }
   if(led6 == 0){
    strip6.setPixelColor(revers_top_botLeft, strip6.Color(0, 255, 0));          //ring bas gauche top
    if(revers_top_botLeft == 0){
        revers_top_botLeft = 24;
      }
      revers_top_botLeft--;
  
      strip6.setPixelColor(revers_bot_botLeft, strip6.Color(0, 255, 0));         //ring bas gauche bot
      revers_bot_botLeft++;
   }
   if(led6 == 1){
    strip6.setPixelColor(revers_top_botLeft, strip6.Color(255, 0, 0));          //ring bas gauche top
    if(revers_top_botLeft == 0){
        revers_top_botLeft = 24;
      }
      revers_top_botLeft--;
  
      strip6.setPixelColor(revers_bot_botLeft, strip6.Color(255, 0, 0));         //ring bas gauche bot
      revers_bot_botLeft++;
   }
    strip9.show();                          //  Update strip to match
    strip10.show();
    strip7.show();                          //  Update strip 5(haut gauche)
    strip6.show();                          //  Update strip 6(haut droite)

    
   
    compteur++;
    if( compteur >=10){
      strip8.setPixelColor(bot1, strip8.Color(255, 0, 0));         //ring haut gauche bot
      bot1++;
      strip8.setPixelColor(bot2, strip8.Color(255, 0, 0));         //ring haut gauche bot
      bot2--;
      
      strip8.setPixelColor(left1, strip8.Color(255, 0, 0));         //ring haut gauche bot
      left1++;
      strip8.setPixelColor(left2, strip8.Color(255, 0, 0));         //ring haut gauche bot
      left2--;
     
      strip8.setPixelColor(top1, strip8.Color(255, 0, 0));         //ring haut gauche bot
      top1++;
      strip8.setPixelColor(top2, strip8.Color(255, 0, 0));         //ring haut gauche bot
      top2--;
      
      strip8.setPixelColor(right1, strip8.Color(255, 0, 0));         //ring haut gauche bot
      right1++;
      strip8.setPixelColor(right2, strip8.Color(255, 0, 0));         //ring haut gauche bot
      right2--;
  
      strip8.show();                          //  Update strip 6(haut droite)
    
    }
     delay(wait);  
  }
 
 } 
 /*
 * vague rouge led 9 
 */

void wave9(int wait){
  
  //variable ring droite
  int top_right = 6; 
  int bot_right = 6;

  //variable ring haut droite
  int top_topRight = 2;
  int bot_topRight = 2;

  //variable ring bas gauche
  int top_botLeft = 14;
  int bot_botLeft = 14;

  //variable ring bas droite
  int top_botRight = 10;
  int bot_botRight = 10;

  for(int i = 0; i<13; i++){
    if(led8 == 0){
      strip8.setPixelColor(top_right, strip8.Color(255, 0, 0));         //ring droite top
      top_right++;
      
      strip8.setPixelColor(bot_right, strip8.Color(255, 0, 0));         //ring droite bot
      if(bot_right == 0){
        bot_right = 24;
      }
      bot_right--;
    }  
    if(led8 == 1){
      strip8.setPixelColor(top_right, strip8.Color(0, 0, 255));         //ring droite top
      top_right++;
      
      strip8.setPixelColor(bot_right, strip8.Color(0, 0, 255));         //ring droite bot
      if(bot_right == 0){
        bot_right = 24;
      }
      bot_right--;
    }
   
   if(led10 == 0){
      strip10.setPixelColor(top_topRight, strip10.Color(255, 0, 0));          //ring haut droite top
      if(top_topRight == 0){
        top_topRight = 24;
      }
      top_topRight--;
  
      strip10.setPixelColor(bot_topRight, strip10.Color(255, 0, 0));         //ring haut droite bot
      bot_topRight++;
   }
   if(led10 == 1){
      strip10.setPixelColor(top_topRight, strip10.Color(0, 0, 255));          //ring haut droite top
      if(top_topRight == 0){
        top_topRight = 24;
      }
      top_topRight--;
  
      strip10.setPixelColor(bot_topRight, strip10.Color(0, 0, 255));         //ring haut droite bot
      bot_topRight++;
   }
   if(led6 == 0){
    strip6.setPixelColor(top_botRight, strip6.Color(255, 0, 0));          //ring bas droite top
      top_botRight++;
  
      strip6.setPixelColor(bot_botRight, strip6.Color(255, 0, 0));         //ring bas droite bot
      if(bot_botRight == 0){
        bot_botRight = 24;
      }
      bot_botRight--;
   }
   if(led6 == 1){
    strip6.setPixelColor(top_botRight, strip6.Color(0, 0, 255));          //ring bas droite top
      top_botRight++;
  
      strip6.setPixelColor(bot_botRight, strip6.Color(0, 0, 255));         //ring bas droite bot
      if(bot_botRight == 0){
        bot_botRight = 24;
      }
      bot_botRight--;
   }
   if(led5 == 0){
    strip5.setPixelColor(top_botLeft, strip5.Color(255, 0, 0));          //ring bas gauche top
    if(top_botLeft == 24){
        top_botLeft = -1;
      }
      top_botLeft++;
  
      strip5.setPixelColor(bot_botLeft, strip5.Color(255, 0, 0));         //ring bas gauche bot
      bot_botLeft--;
   }
   if(led5 == 1){
    strip5.setPixelColor(top_botLeft, strip5.Color(0, 0, 255));          //ring bas gauche top
    if(top_botLeft == 24){
        top_botLeft = -1;
      }
      top_botLeft++;
  
      strip5.setPixelColor(bot_botLeft, strip5.Color(0, 0, 255));         //ring bas gauche bot
      bot_botLeft--;
   }
    strip8.show();                          
    strip10.show();                          
    strip6.show();                          
    strip5.show();      
                       
    delay(wait);                         
  }


delay(wait); 
 
/* 
 *  reverse
 */

  //variable ring droite 2
  int revers_top_right = 18;
  int revers_bot_right = 18;

  //variable ring haut droite 6
  int revers_top_topRight = 14;
  int revers_bot_topRight = 14;

  //variable ring bas gauche
  int revers_top_botLeft = 2;
  int revers_bot_botLeft = 2;

  //variable ring bas droite
  int revers_top_botRight = 23;
  int revers_bot_botRight = 23;

  int bot1 = 0;
  int bot2 = 24;
  
  int left1 = 6;
  int left2 = 6;
  
  int top1 = 12;
  int top2 = 12;
  
  int right1 = 18;
  int right2 = 18;

  int compteur = 0;
  
  for(int i = 0; i<13; i++){
    
    if(led8 == 0){
      strip8.setPixelColor(revers_top_right, strip8.Color(0, 255, 0));         //ring droite top
      revers_top_right--;
      
      strip8.setPixelColor(revers_bot_right, strip8.Color(0, 255, 0));         //ring droite bot
      if(revers_bot_right == 24){
        revers_bot_right = -1;
      }
      revers_bot_right++;
    }
    if(led8 == 1){
      strip8.setPixelColor(revers_top_right, strip8.Color(255, 0, 0));         //ring droite top
      revers_top_right--;
      
      strip8.setPixelColor(revers_bot_right, strip8.Color(255, 0, 0));         //ring droite bot
      if(revers_bot_right == 24){
        revers_bot_right = -1;
      }
      revers_bot_right++;
    }
  if(led10 == 0){
    strip10.setPixelColor(revers_top_topRight, strip10.Color(0, 255, 0));          //ring haut droite top
    if(revers_top_topRight == 24){
      revers_top_topRight = -1;
    }
    revers_top_topRight++;

    strip10.setPixelColor(revers_bot_topRight, strip10.Color(0, 255, 0));         //ring haut droite bot
    revers_bot_topRight--;
  }
  if(led10 == 1){
    strip10.setPixelColor(revers_top_topRight, strip10.Color(255, 0, 0));          //ring haut droite top
    if(revers_top_topRight == 24){
      revers_top_topRight = -1;
    }
    revers_top_topRight++;

    strip10.setPixelColor(revers_bot_topRight, strip10.Color(255, 0, 0));         //ring haut droite bot
    revers_bot_topRight--;
  }  
  if(led6 == 0){
    strip6.setPixelColor(revers_top_botRight, strip6.Color(0, 255, 0));          //ring bas droite top
      revers_top_botRight--;
  
      strip6.setPixelColor(revers_bot_botRight, strip6.Color(0, 255, 0));         //ring bas droite bot
       if( revers_bot_botRight == 24){
         revers_bot_botRight = -1;
      }
      revers_bot_botRight++;
   }
   if(led6 == 1){
    strip6.setPixelColor(revers_top_botRight, strip6.Color(255, 0, 0));          //ring bas droite top
      revers_top_botRight--;
  
      strip6.setPixelColor(revers_bot_botRight, strip6.Color(255, 0, 0));         //ring bas droite bot
       if( revers_bot_botRight == 24){
         revers_bot_botRight = -1;
      }
      revers_bot_botRight++;
   }
   if(led5 == 0){
    strip5.setPixelColor(revers_top_botLeft, strip5.Color(0, 255, 0));          //ring bas gauche top
    if(revers_top_botLeft == 0){
        revers_top_botLeft = 24;
      }
      revers_top_botLeft--;
  
      strip5.setPixelColor(revers_bot_botLeft, strip5.Color(0, 255, 0));         //ring bas gauche bot
      revers_bot_botLeft++;
   }
   if(led5 == 1){
    strip5.setPixelColor(revers_top_botLeft, strip5.Color(255, 0, 0));          //ring bas gauche top
    if(revers_top_botLeft == 0){
        revers_top_botLeft = 24;
      }
      revers_top_botLeft--;
  
      strip5.setPixelColor(revers_bot_botLeft, strip5.Color(255, 0, 0));         //ring bas gauche bot
      revers_bot_botLeft++;
   }
    strip8.show();                          //  Update strip to match
    strip10.show();
    strip6.show();                          //  Update strip 5(haut gauche)
    strip5.show();                          //  Update strip 6(haut droite)
    
   
    compteur++;
    if( compteur >=10){
      strip9.setPixelColor(bot1, strip9.Color(255, 0, 0));         //ring haut gauche bot
      bot1++;
      strip9.setPixelColor(bot2, strip9.Color(255, 0, 0));         //ring haut gauche bot
      bot2--;
      
      strip9.setPixelColor(left1, strip9.Color(255, 0, 0));         //ring haut gauche bot
      left1++;
      strip9.setPixelColor(left2, strip9.Color(255, 0, 0));         //ring haut gauche bot
      left2--;
     
      strip9.setPixelColor(top1, strip9.Color(255, 0, 0));         //ring haut gauche bot
      top1++;
      strip9.setPixelColor(top2, strip9.Color(255, 0, 0));         //ring haut gauche bot
      top2--;
      
      strip9.setPixelColor(right1, strip9.Color(255, 0, 0));         //ring haut gauche bot
      right1++;
      strip9.setPixelColor(right2, strip9.Color(255, 0, 0));         //ring haut gauche bot
      right2--;
  
      strip9.show();                          //  Update strip 6(haut droite)
    
    }
     delay(wait);  
  }
 
 }

/*
 * vague rouge led 10
 */
 void wave10(int wait){

  //variable ring bas gauche
  int top_botLeft = 14;
  int bot_botLeft = 14;

  //variable ring bas droite
  int top_botRight = 10;
  int bot_botRight = 10;

  for(int i = 0; i<13; i++){
    
   if(led8 == 0){
    strip8.setPixelColor(top_botRight, strip8.Color(255, 0, 0));          //ring bas droite top
      top_botRight++;
  
      strip8.setPixelColor(bot_botRight, strip8.Color(255, 0, 0));         //ring bas droite bot
      if(bot_botRight == 0){
        bot_botRight = 24;
      }
      bot_botRight--;
   }
   if(led8 == 1){
    strip8.setPixelColor(top_botRight, strip8.Color(0, 0, 255));          //ring bas droite top
      top_botRight++;
  
      strip8.setPixelColor(bot_botRight, strip8.Color(0, 0, 255));         //ring bas droite bot
      if(bot_botRight == 0){
        bot_botRight = 24;
      }
      bot_botRight--;
   }
   if(led9 == 0){
    strip9.setPixelColor(top_botLeft, strip9.Color(255, 0, 0));          //ring bas gauche top
    if(top_botLeft == 24){
        top_botLeft = -1;
      }
      top_botLeft++;
  
      strip9.setPixelColor(bot_botLeft, strip9.Color(255, 0, 0));         //ring bas gauche bot
      bot_botLeft--;
   }
   if(led9 == 1){
    strip9.setPixelColor(top_botLeft, strip9.Color(0, 0, 255));          //ring bas gauche top
    if(top_botLeft == 24){
        top_botLeft = -1;
      }
      top_botLeft++;
  
      strip9.setPixelColor(bot_botLeft, strip9.Color(0, 0, 255));         //ring bas gauche bot
      bot_botLeft--;
   }
    strip8.show();                          
    strip9.show();      
                       
    delay(wait);                         
  }


delay(wait); 
 
/* 
 *  reverse
 */
  //variable ring bas gauche
  int revers_top_botLeft = 2;
  int revers_bot_botLeft = 2;

  //variable ring bas droite
  int revers_top_botRight = 23;
  int revers_bot_botRight = 23;

  int bot1 = 0;
  int bot2 = 24;
  
  int left1 = 6;
  int left2 = 6;
  
  int top1 = 12;
  int top2 = 12;
  
  int right1 = 18;
  int right2 = 18;

  int compteur = 0;
  
  for(int i = 0; i<13; i++){
    
    if(led8 == 0){
      strip8.setPixelColor(revers_top_botRight, strip8.Color(0, 255, 0));          //ring bas droite top
        revers_top_botRight--;
    
        strip8.setPixelColor(revers_bot_botRight, strip8.Color(0, 255, 0));         //ring bas droite bot
         if( revers_bot_botRight == 24){
           revers_bot_botRight = -1;
        }
        revers_bot_botRight++;
    }
    if(led8 == 1){
      strip8.setPixelColor(revers_top_botRight, strip8.Color(255, 0, 0));          //ring bas droite top
        revers_top_botRight--;
    
        strip8.setPixelColor(revers_bot_botRight, strip8.Color(255, 0, 0));         //ring bas droite bot
         if( revers_bot_botRight == 24){
           revers_bot_botRight = -1;
        }
        revers_bot_botRight++;
    }
    if(led9 == 0){
      strip9.setPixelColor(revers_top_botLeft, strip9.Color(0, 255, 0));          //ring bas gauche top
      if(revers_top_botLeft == 0){
          revers_top_botLeft = 24;
        }
        revers_top_botLeft--;
    
        strip9.setPixelColor(revers_bot_botLeft, strip9.Color(0, 255, 0));         //ring bas gauche bot
        revers_bot_botLeft++;
   }
   if(led9 == 1){
      strip9.setPixelColor(revers_top_botLeft, strip9.Color(255, 0, 0));          //ring bas gauche top
      if(revers_top_botLeft == 0){
          revers_top_botLeft = 24;
        }
        revers_top_botLeft--;
    
        strip9.setPixelColor(revers_bot_botLeft, strip9.Color(255, 0, 0));         //ring bas gauche bot
        revers_bot_botLeft++;
   }
    strip8.show();                          //  Update strip to match
    strip9.show();

    
   
    compteur++;
    if( compteur >=10){
      strip10.setPixelColor(bot1, strip10.Color(255, 0, 0));         //ring haut gauche bot
      bot1++;
      strip10.setPixelColor(bot2, strip10.Color(255, 0, 0));         //ring haut gauche bot
      bot2--;
      
      strip10.setPixelColor(left1, strip10.Color(255, 0, 0));         //ring haut gauche bot
      left1++;
      strip10.setPixelColor(left2, strip10.Color(255, 0, 0));         //ring haut gauche bot
      left2--;
     
      strip10.setPixelColor(top1, strip10.Color(255, 0, 0));         //ring haut gauche bot
      top1++;
      strip10.setPixelColor(top2, strip10.Color(255, 0, 0));         //ring haut gauche bot
      top2--;
      
      strip10.setPixelColor(right1, strip10.Color(255, 0, 0));         //ring haut gauche bot
      right1++;
      strip10.setPixelColor(right2, strip10.Color(255, 0, 0));         //ring haut gauche bot
      right2--;
  
      strip10.show();                          //  Update strip 6(haut droite)
    
    }
     delay(wait);  
  }
 
 } 

  // Theater-marquee-style chasing lights. Pass in a color (32-bit value,
  // a la strip.Color(r,g,b) as mentioned above), and a delay time (in ms)
  // between frames.
  void theaterChase(int led_pin, int wait) {
    Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMPIXELS, led_pin, NEO_GRB + NEO_KHZ800);
    for(int a=0; a<10; a++) {  // Repeat 10 times...
      for(int b=0; b<3; b++) { //  'b' counts from 0 to 2...
        strip.clear();         //   Set all pixels in RAM to 0 (off)
        // 'c' counts up from 'b' to end of strip in steps of 3...
        for(int c=b; c<strip.numPixels(); c += 3) {
          strip.setPixelColor(c, strip1.Color(255, 0, 0)); // Set pixel 'c' to value 'color'
        }
        strip.show(); // Update strip with new contents
        delay(wait);  // Pause for a moment
      }
    }
  }


  // Rainbow-enhanced theater marquee. Pass delay time (in ms) between frames.
  void rainbowRoad(int wait) {
  int firstPixelHue = 0;     // First pixel starts at red (hue 0)
  for(int a=0; a<30; a++) {  // Repeat 30 times...
    for(int b=0; b<3; b++) { //  'b' counts from 0 to 2...
      strip1.clear();         //   Set all pixels in RAM to 0 (off)
      strip2.clear();
      strip3.clear();
      strip4.clear();
      strip5.clear();
      strip6.clear();
      strip7.clear();
      strip8.clear();
      strip9.clear();
      strip10.clear();
      // 'c' counts up from 'b' to end of strip in increments of 3...
      for(int c=b; c<strip1.numPixels(); c += 3) {
        // hue of pixel 'c' is offset by an amount to make one full
        // revolution of the color wheel (range 65536) along the length
        // of the strip (strip.numPixels() steps):
        int      hue   = firstPixelHue + c * 65536L / strip1.numPixels();
        uint32_t color = strip1.gamma32(strip1.ColorHSV(hue)); // hue -> RGB
        strip1.setPixelColor(c, color); // Set pixel 'c' to value 'color'
        strip2.setPixelColor(c, color); // Set pixel 'c' to value 'color'
        strip3.setPixelColor(c, color); // Set pixel 'c' to value 'color'
        strip4.setPixelColor(c, color); // Set pixel 'c' to value 'color'
        strip5.setPixelColor(c, color); // Set pixel 'c' to value 'color'
        strip6.setPixelColor(c, color); // Set pixel 'c' to value 'color'
        strip7.setPixelColor(c, color); // Set pixel 'c' to value 'color'
        strip8.setPixelColor(c, color); // Set pixel 'c' to value 'color'
        strip9.setPixelColor(c, color); // Set pixel 'c' to value 'color'
        strip10.setPixelColor(c, color); // Set pixel 'c' to value 'color'
        
      }
      strip1.show();                // Update strip with new contents
      strip2.show();
      strip3.show();
      strip4.show();
      strip5.show();
      strip6.show();
      strip7.show();
      strip8.show();
      strip9.show();
      strip10.show();
      delay(wait);                 // Pause for a moment
      firstPixelHue += 65536 / 90; // One cycle of color wheel over 90 frames
    }
   }
  }

    // Some functions of our own for creating animated effects -----------------

  // Fill strip pixels one after another with a color. Strip is NOT cleared
  // first; anything there will be covered pixel by pixel. Pass in color
  // (as a single 'packed' 32-bit value, which you can get by calling
  // strip.Color(red, green, blue) as shown in the loop() function above),
  // and a delay time (in milliseconds) between pixels.
  void colorWipe(int led_pin, int wait) {
    Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMPIXELS, led_pin, NEO_GRB + NEO_KHZ800);
  for(int i=0; i<strip.numPixels(); i++) { // For each pixel in strip...
    strip.setPixelColor(i, strip.Color(255, 0, 0));         //  Set pixel's color (in RAM)
    strip.show();                          //  Update strip to match
    delay(wait);                           //  Pause for a moment
  }
  }
  
  // Rainbow cycle along whole strip. Pass delay time (in ms) between frames.
  void rainbow(int led_pin, int wait) {
    Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMPIXELS, led_pin, NEO_GRB + NEO_KHZ800);
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

    strip.rainbow(firstPixelHue);

    // Above line is equivalent to:
    // strip.rainbow(firstPixelHue, 1, 255, 255, true);

    strip.show();// Update strip with new contents



    }
  }
