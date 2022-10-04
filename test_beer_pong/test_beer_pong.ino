
#include <Adafruit_NeoPixel.h>
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
#define NUMPIXELS       24 // Popular NeoPixel ring size
#define DELAYVAL        10 // Time (in milliseconds) to pause between pixels
#define PAUSE_R         10000
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


enum {
  INIT,
  WAIT_BALL,
  ANNIMATION,
  WAIT_RESISTANCE,
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

#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
clock_prescale_set(clock_div_1);
#endif

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

pinMode(RPHOTO_1, INPUT);// Set photoresistance input

}

void loop() {

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

       for (int i = 0; i < NUMPIXELS; i++) { 
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
        delay(DELAYVAL); 
      }

      
    state = WAIT_BALL;
    break;

    case WAIT_BALL:

     if (digitalRead(PIR_PIN1) == HIGH && led1 == 0) { //le capteur détecte un mouvement
        Serial.println("mouvement detecte 1 ");
        strip1.clear();
        led1 = 1;
        state = ANNIMATION;
      }

      break;
    
    case ANNIMATION:

      if(led1){
        wave1(30);
      state = WAIT_RESISTANCE;
      }
      break;
    
    case WAIT_RESISTANCE:

      if(led1){
        
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
        }
      }
      state = WAIT_BALL;
      break;
    case STOP:
      Serial.println("STOP");


      break;

    default:
      // statements
      break;
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
