// C++ code
// Ne pas prendre en compte les erreurs sur un ide qui n'est pas celui de l'arduino

// Ici je déclare mes variable et mes librairie
#include <Servo.h>		//inclure la librairie du servo dans ce programme pour utiliser ses fonctions

int pos = 0; 			// Définition de la variable pos pour determiner la position a 0
int moteur = 11;		// Définition de la broche du moteur sur le pin 11
Servo MonServo;			// On initialise Servo

// Ici, ce code ne s'execute qu'une seule fois
void setup() {
  MonServo.attach(moteur); 	// J'indique que le servo est attaché au pin 11 (moteur) en sortie
}

// Ici, la boucle s'effectue indéfiniement
void loop() {
  
  // je boucle, tant que la position est inférieur a 180 degres, j'ajoute 1 degres toute les 15 miliseconde. 
  for (pos = 0; pos <= 180; pos += 1) {
    MonServo.write(pos);
    delay(15);
  }
  
  // je boucle, tant que la position est supérieur a 0 degres, j'enleve 1 degres toute les 15 miliseconde.
  for (pos = 180; pos >= 0; pos -= 1) {
    MonServo.write(pos);
    delay(15);
  }
}