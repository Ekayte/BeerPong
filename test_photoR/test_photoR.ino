#define R_PIN1        A1
#define R_PIN2        A2
#define R_PIN3        A3
#define R_PIN4        A4
#define R_PIN5        A5
#define R_PIN6        A6
#define R_PIN7        A7
#define R_PIN8        A8
#define R_PIN9        A9
#define R_PIN10       A10


void setup() {
   // initialise la communication avec le PC
   Serial.begin(9600);

   // initialise les broches
   pinMode(R_PIN1, INPUT);
   pinMode(R_PIN2, INPUT);
   pinMode(R_PIN3, INPUT);
   pinMode(R_PIN4, INPUT);
   pinMode(R_PIN5, INPUT);
   pinMode(R_PIN6, INPUT);
   pinMode(R_PIN7, INPUT);
   pinMode(R_PIN8, INPUT);
   pinMode(R_PIN9, INPUT);
   pinMode(R_PIN10, INPUT);
}
 
void loop() {
   // mesure la tension sur la broche A1
 
   
 
   Serial.print("R3 = ");
   Serial.println(analogRead(R_PIN3));
   Serial.println();
   Serial.print("R4 = ");
   Serial.println(analogRead(R_PIN4));
   Serial.println();
   Serial.print("R5 = ");
   Serial.println(analogRead(R_PIN5));
   Serial.println();
   Serial.print("R6 = ");
   Serial.println(analogRead(R_PIN6));
   Serial.println();
   Serial.print("R7 = ");
   Serial.println(analogRead(R_PIN7));
   Serial.println();
   Serial.print("R8 = ");
   Serial.println(analogRead(R_PIN8));
   Serial.println();
   Serial.print("R9 = ");
   Serial.println(analogRead(R_PIN9));
   Serial.println();
   Serial.print("R10 = ");
   Serial.println(analogRead(R_PIN10));
   Serial.println();

   delay(200);
}
