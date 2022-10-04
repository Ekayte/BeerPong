#include "pir.h"
#include "Arduino.h"

#define PIR_PIN0        22
#define PIR_PIN1        24
#define PIR_PIN2        26
#define PIR_PIN3        28
#define PIR_PIN4        30
#define PIR_PIN5        32
#define PIR_PIN6        34
#define PIR_PIN7        36
#define PIR_PIN8        38
#define PIR_PIN9        40

void init_pir(){
  pinMode(PIR_PIN0, INPUT); //définir la pin 2 comme une entré
  pinMode(PIR_PIN1, INPUT);
  pinMode(PIR_PIN2, INPUT);
  pinMode(PIR_PIN3, INPUT);
  pinMode(PIR_PIN4, INPUT);
  pinMode(PIR_PIN5, INPUT);
  pinMode(PIR_PIN6, INPUT);
  pinMode(PIR_PIN7, INPUT);
  pinMode(PIR_PIN8, INPUT);
  pinMode(PIR_PIN9, INPUT);

}

int mouvement_detecte(){
    if(digitalRead(PIR_PIN0) == HIGH){
        return 0;
    }
    if(digitalRead(PIR_PIN1) == HIGH){
        return 1;
    }
    if(digitalRead(PIR_PIN2) == HIGH){
        return 2;
    }
    if(digitalRead(PIR_PIN3) == HIGH){
        return 3;
    }
    if(digitalRead(PIR_PIN4) == HIGH){
        return 4;
    }
    if(digitalRead(PIR_PIN5) == HIGH){
        return 5;
    }
    if(digitalRead(PIR_PIN6) == HIGH){
        return 6;
    }
    if(digitalRead(PIR_PIN7) == HIGH){
        return 7;
    }
    if(digitalRead(PIR_PIN8) == HIGH){
        return 8;
    }
    if(digitalRead(PIR_PIN9) == HIGH){
        return 9;
    }
    else{
        return 11;
    }
}