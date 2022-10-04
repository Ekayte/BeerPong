#include <Adafruit_NeoPixel.h>
#include "strip.h"
#include "pir.h"
#include "rphoto.h"

#ifdef __AVR__
#include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif


enum {
  INIT,
  GAME,
  STOP
} state;

int num_pir = 11; // valeur qui signifie qu'aucun mouvement n'a été détecté
int r_photo = 0;

void setup() {
  Serial.begin(9600); 
    // These lines are specifically to support the Adafruit Trinket 5V 16 MHz.
    // Any other board, you can remove this part (but no harm leaving it):
  #if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
    clock_prescale_set(clock_div_1);
  #endif
    // END of Trinket-specific code.


  init_strips();
  clear_all_strip(); 
  init_pir();

  

}

void loop() {
  switch (state){
    case INIT:
    
    clear_all_strip();
    rainbowRoad(50);
    set_all_strips_green();
    
      break;

    case GAME:
    num_pir = mouvement_detecte();
    if(num_pir != 11 ){
      set_strip_red(num_pir);
      if( read_rphoto(num_pir) ){
        set_strip_green(num_pir);
      }

    }
  

    //TODO
      break;

    case STOP:
    //TODO
      break;

    default:
      break;
    
  }

}


