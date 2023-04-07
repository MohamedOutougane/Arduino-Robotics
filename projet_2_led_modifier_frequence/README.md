# Projet 1 : led clignotante, modifier la fréquence
Ceci est mon second projet. Ici on améliore le premier projet en ajoutant un potentiometre.


## Contenu du dépôt
Dans ce dépôt, vous trouverez :

- le code en c++ avec l'extension .ino
- des images representant l'installation faite sur Tinkercad

## Composants
- Une carte Arduino UNO R3
- Une LED
- Une résistance 1 kΩ
- Une breadbord
- 3 fils rouge
- 4 fils brun
- 1 fils bleu
- 1 fils vert

## Explication 
Ce code est conçu pour faire clignoter une LED connectée à la broche 2 de la carte Arduino. La durée d'allumage et d'extinction de la LED est contrôlée par un potentiomètre connecté à la broche analogique A5. Le code utilise la communication série pour afficher des messages sur l'état de la LED et la durée déterminée par le potentiomètre.

### Voici une explication étape par étape du code:

#### 1 - Déclaration des variables et des broches:

- `int led = 2;` : La broche de la LED est définie sur le pin 2.
- `int potentiometre = A5;` : La broche du potentiomètre est définie sur le pin analogique A5.
- `int duree;` : Déclaration de la variable "duree" qui stockera la durée d'allumage et d'extinction de la LED.

#### 2 - Configuration initiale dans la fonction `setup()`:

- `Serial.begin(9600);` : Initialisation de la communication série à 9600 baud.
- `pinMode(led, OUTPUT);` : Configuration de la broche de la LED en sortie.
- `pinMode(potentiometre, INPUT);` : Configuration de la broche du potentiomètre en entrée.

#### 3 - Boucle principale dans la fonction `loop()`:

- `duree = analogRead(potentiometre);` : Lecture de la valeur analogique du potentiomètre (entre 0 et 1023) et stockage dans la variable "duree".
- `duree = map(duree, 0, 1023, 100, 1000);` : Conversion de la valeur de "duree" (0 à 1023) en une nouvelle plage de valeurs (100 à 1000), qui correspond à la durée en millisecondes.
- Affichage de la durée donnée par le potentiomètre dans la communication série.
- Allumage de la LED, affichage de l'état dans la communication série, puis attente de la durée déterminée par le potentiomètre.
- Extinction de la LED, affichage de l'état dans la communication série, puis attente de la durée déterminée par le potentiomètre.

La boucle `loop()` s'exécute indéfiniment, ce qui fait clignoter la LED avec la durée d'allumage et d'extinction contrôlée par le potentiomètre.

## Poids du programme
```sh
Sketch uses 2578 bytes (7%) of program storage space. Maximum is 32256 bytes.

Global variables use 244 bytes (11%) of dynamic memory, leaving 1804 bytes for local variables. Maximum is 2048 bytes.
```


Merci de votre intérêt pour arduino-robotics! J'espère que vous trouverez ces projets utiles et inspirants pour vos propres aventures dans le monde de la robotique et de la domotique avec Arduino.