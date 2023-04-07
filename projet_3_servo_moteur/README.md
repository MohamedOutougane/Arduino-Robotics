# Projet 1 : led clignotante, modifier la fréquence
Ceci est mon troisième projet. Ici on apprend a utiliser un servo-moteur positionnel.


## Contenu du dépôt
Dans ce dépôt, vous trouverez :

- le code en c++ avec l'extension .ino
- des images representant l'installation faite sur Tinkercad

## Composants
- Une carte Arduino UNO R3
- Un servo-moteur positionnel
- un fils rouge
- un fils brun
- un fils vert

## Explication 
Ce code est conçu pour contrôler un servo-moteur connecté à la broche 11 d'une carte Arduino. Le servo-moteur effectue un mouvement oscillant de 0 à 180 degrés, puis revient à sa position initiale de 0 degré. Pour cela, le code utilise la bibliothèque Servo, qui fournit des fonctions pour contrôler facilement les servo-moteurs.

### Voici une explication étape par étape du code :

#### 1 - Déclaration des variables et inclusion de la bibliothèque Servo :

- `#include <Servo.h>` : Inclusion de la bibliothèque Servo pour utiliser ses fonctions.
- `int pos = 0;` : Déclaration de la variable "pos" pour déterminer la position du servo-moteur, initialisée à 0.
- `int moteur = 11;` : Définition de la broche du moteur sur le pin 11.
- `Servo MonServo;` : Création d'un objet Servo nommé "MonServo".

#### 2 - Configuration initiale dans la fonction `setup()` :

- `MonServo.attach(moteur);` : Indique que le servo-moteur est connecté à la broche 11 (moteur) en sortie.

#### 3 - Boucle principale dans la fonction `loop()` :

- Première boucle `for` :
- - `for (pos = 0; pos <= 180; pos += 1)` : La boucle s'exécute tant que la position est inférieure ou égale à 180 degrés. La position est incrémentée de 1 degré à chaque itération.
- - `MonServo.write(pos);` : Envoie la nouvelle position au servo-moteur.
- - `delay(15);` : Attend 15 millisecondes avant la prochaine itération.

- Seconde boucle `for` :
- - `for (pos = 180; pos >= 0; pos -= 1)` : La boucle s'exécute tant que la position est supérieure ou égale à 0 degré. La position est décrémentée de 1 degré à chaque itération.
- - `MonServo.write(pos);` : Envoie la nouvelle position au servo-moteur.
- - `delay(15);` : Attend 15 millisecondes avant la prochaine itération.

La boucle `loop()` s'exécute indéfiniment, ce qui fait osciller le servo-moteur entre 0 et 180 degrés, puis revenir à 0 degré, avec un pas de 1 degré et une pause de 15 millisecondes entre chaque changement de position.

## Poids du programme
```sh
Sketch uses 2128 bytes (6%) of program storage space. Maximum is 32256 bytes.

Global variables use 52 bytes (2%) of dynamic memory, leaving 1996 bytes for local variables. Maximum is 2048 bytes.
```


Merci de votre intérêt pour arduino-robotics! J'espère que vous trouverez ces projets utiles et inspirants pour vos propres aventures dans le monde de la robotique et de la domotique avec Arduino.