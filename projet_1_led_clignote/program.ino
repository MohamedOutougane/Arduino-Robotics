// C++ code
// Ne pas prendre en compte les erreurs sur un ide qui n'est pas celui de l'arduino

int led = 2; // Définition de la broche de la LED sur le pin 2

void setup() {
  Serial.begin(9600); // Initialisation de la communication série à 9600 baud
  pinMode(led, OUTPUT); // Configuration de la broche de la LED en sortie
}

void loop() {
  digitalWrite(led, HIGH); // Allumer la LED
  Serial.println("La led est allumee"); // Envoyer un message indiquant que la LED est allumée
  delay(1000); // Attendre 1000 millisecondes (1 seconde)

  digitalWrite(led, LOW); // Éteindre la LED
  Serial.println("La led est eteinte"); // Envoyer un message indiquant que la LED est éteinte
  delay(1000); // Attendre 1000 millisecondes (1 seconde)
}