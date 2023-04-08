// C++ code
// Ne pas prendre en compte les erreurs sur un ide qui n'est pas celui de l'arduino

// Ici je déclare mes variable et mes librairie
#include <Servo.h>			//inclure la librairie du servo dans ce programme pour utiliser ses fonctions

int barriere = 0;			// Déclaration de la variable barriere (position) en integer a 0
long duree;					// Déclaration de la variable duree en entier long
long distance;				// Déclaration de la variable distance en entier long
const int seuil = 100;		// Déclaration de la constante seuil qui sera a 100cm

int trigger = 13;			// Définition de la broche trigger du capteur de distance par ultrason sur le pin 13
int echo = 12;				// Définition de la broche echo du capteur de distance par ultrason sur le pin 12
int moteur = 3;				// Définition de la broche du moteur sur le pin 11

Servo MonServo;				// Initialisation de Servo

// Ici, ce code ne s'execute qu'une seule fois
void setup() {
  pinMode(trigger, OUTPUT);	// Initialisation de la broche trigger en sortie
  pinMode(echo, INPUT);		// Initialisation de la broche echo en entree
  MonServo.attach(moteur);	// J'indique que le servo est attaché au pin 11 (moteur) en sortie
  Serial.begin(9600);		// Initialise le moniteur serie pour afficher des message ( avec vitesse de transmission de 9600 baud)
}

// Ici, la boucle s'effectue indéfiniement
void loop() {
 
  // Envoie d'un signal carré sur le trigger afin de déclencher une mesure
  digitalWrite(trigger, LOW);	// fermer le courant sur le trigger
  delayMicroseconds(2);			// attendre 2 micro seconde
  digitalWrite(trigger, HIGH);	// ouvrir le courant sur le trigger
  delayMicroseconds(2);			// attendre 2 micro seconde
  digitalWrite(trigger, LOW);	// fermer le courant sur le trigger
  
  // Une fois que la broche echo reçcoit un signal, la broche echo va envoyer un courant a la carte arduino
  // et la fonction pulseIn va calculer le temps entre le passage de LOW a HIGH pour la broche echo 
  //(en microseconde)
  duree = pulseIn(echo, HIGH);
  
  // Calcul de la distance en centimètres à partir de la durée (temps de vol de l'onde ultrasonique aller-retour)
  // On utilise la formule : distance = (vitesse du son * durée) / 2
  // Ici, on prend la vitesse du son dans l'air : 340 m/s
  // On convertit la durée en secondes (duree/1000000) et la distance en centimètres (en multipliant par 100)
  // On divise par 2 car le temps de vol est aller-retour, donc la distance est parcourue deux fois
  distance = duree * 340 / (2 * 10000);

  // Affichage de la distance calculée sur le moniteur série
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  //si la distance est inferieur au seuil, alors on ouvre la barrière, sinon on ferme la barriere
  if(distance <= seuil) {
    barriere = 90;
  }else {
    delay(2000);
     barriere = 0;
  }
  
  // on envoie l'info au moteur
  MonServo.write(barriere);
  // Attendre 3 seconde avant de répéter la mesure
  delay(1000);
}