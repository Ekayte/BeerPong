#include "rphoto.h"
#include "Arduino.h"


#define RPHOTO_1        A1 
#define RPHOTO_2        A2 
#define RPHOTO_3        A3
#define RPHOTO_4        A4
#define RPHOTO_5        A7 
#define RPHOTO_6        A6
#define RPHOTO_7        A5  
#define RPHOTO_8        A9  
#define RPHOTO_9        A8
#define RPHOTO_10       A10 

#define PAUSE_R         5000
#define VALUE_RESET     30

int table_rphoto[10] = {A1,A2,A3,A4,A5,A6,A7,A8,A9,A10};
bool read_rphoto(int num_strip){
  
    int value_RPHOTO_1 = analogRead(table_rphoto[num_strip]); //on récupère la valeur de la résisantce 
    Serial.println(value_RPHOTO_1);
    delay(PAUSE_R); // attente de x sec 
    int value_RPHOTO_2 = analogRead(table_rphoto[num_strip]); //on récupère la valeur de la résisantce 
    Serial.println(value_RPHOTO_2);
    int value = value_RPHOTO_2 - value_RPHOTO_1;
    Serial.println(value);

    if(value > VALUE_RESET){
        Serial.println("false");
        return false;
    }
    if(value < VALUE_RESET){
      Serial.println("true");
        return true;
    }
}