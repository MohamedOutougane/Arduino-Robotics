// C++ code
// Ne pas prendre en compte les erreurs sur un ide qui n'est pas celui de l'arduino

// Ici je déclare mes variable et mes librairie
long duree;					// Déclaration de la variable duree en entier long
long distance;				// Déclaration de la variable distance en entier long

int trigger = 2;			// Définition de la broche trigger du capteur de distance par ultrason sur le pin 2
int echo = 4;				// Définition de la broche echo du capteur de distance par ultrason sur le pin 4

// Ici, ce code ne s'execute qu'une seule fois
void setup() {
  pinMode(trigger, OUTPUT);	// Initialisation de la broche trigger en sortie
  pinMode(echo, INPUT);		// Initialisation de la broche echo en entree
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

  // Attendre 1 seconde avant de répéter la mesure
  delay(1000);
}