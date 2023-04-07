// C++ code
// Ne pas prendre en compte les erreurs sur un ide qui n'est pas celui de l'arduino

// Ici je déclare mes variable et mes librairie
int led = 2; // Définition de la broche de la LED sur le pin 2
int potentiometre = A5; // Définition de la broche potentiometre sur le pin A5
int duree; // Déclaration de la varibale "durée"

// Ici, ce code ne s'execute qu'une seule fois
void setup() {
  Serial.begin(9600); // Initialisation de la communication série à 9600 baud
  
  pinMode(led, OUTPUT); // Configuration de la broche de la LED en sortie
  pinMode(potentiometre, INPUT); // Configuration de la pin A5 en entrée
}

// Ici, la boucle s'effectue indéfiniement
void loop() {
  duree = analogRead(potentiometre); // Je lis la valeur sur le potentiometre et je la donne a duree ( valeur entre 0 et 1023)
  duree = map(duree, 0, 1023, 100, 1000); //Avec la fonction MAP, je convertit mes extreme 0 et 1023 en 100 et 1000 (entre 1/10 de seoncde et 1 seconde)
  
  //Envoyer un message indiquant la durée donné par le potentiometre
  Serial.print("La duree est de ");
  Serial.println(duree);
  
  digitalWrite(led, HIGH); // Allumer la LED
  Serial.println("La led est allumee"); // Envoyer un message indiquant que la LED est allumée
  delay(duree); // Attendre la durée donné par le potentiometre

  digitalWrite(led, LOW); // Éteindre la LED
  Serial.println("La led est eteinte"); // Envoyer un message indiquant que la LED est éteinte
  delay(duree); // Attendre la durée donné par le potentiometre
}