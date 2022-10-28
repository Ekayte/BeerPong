#include <Adafruit_NeoPixel.h>

#include "strip.h"
#include "pir.h"
#include "rphoto.h"

#define NB_STRIPS       10 // nombre de bandeau de leds

#ifdef __AVR__
#include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif


enum {
  INIT,
  GAME,
  STOP
} state;

int num_pir = 11; // variable pour récupérer le numéro du capteur, 11 est valeur qui signifie qu'aucun mouvement n'a été détecté
int r_photo = 0;
bool strips_count[NB_STRIPS] = {false,false,false,false,false,false,false,false,false,false}; // tableau de vérification et de comptage des strips
bool read_r = true; 

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
    case INIT:  // initialisation des annimation 
    Serial.println("intit");
    clear_all_strip(); // clear buffer des strips
    rainbowRoad(5); // rainbow du lancement du beerpong
    set_all_strips_green(); // set des 10 strip en vert
        
    state = GAME;    
      break;

    case GAME: // case du jeu 
    
    num_pir = mouvement_detecte(); // récupération du numéro du capteur qui detecte la chute de la balle 
    if(num_pir !=11 && num_pir !=0 && num_pir !=4 && num_pir !=9 && strips_count[num_pir] == false ){ // si un mouvement est detecté et que le numéro du strip est false

      strips_count[num_pir] = true; // numéro du strip liée au numéro du catpeur pir = true

      clear_all_strip(); 
      set_strip_red(num_pir); // strip en rouge
      read_r = read_rphoto(num_pir); // vérification si le verre à bien été retiré avec la photo résistance 
      if( read_r == true){ // si read_r true --> cela signifie que le verre n'a pas été retiré 
        set_strip_green(num_pir); // on remet le strip en vert
        strips_count[num_pir] = false; // on remet à false le numéro du strip dans le tableau compteur 
      }
    }
    if(num_pir !=0){
      set_strip_yello(num_pir); // strip en jaune      
      
    }

    //TODO
    
    //rainbow(1);

      break;

    case STOP:
    //TODO
      break;

    default:
      break;
    
  }

}


