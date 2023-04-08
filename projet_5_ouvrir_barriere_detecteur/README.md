# Projet 1 : led clignotante, modifier la fréquence
Ceci est mon cinquèeme projet. Ici on combine les projets 3 et 4 afin de créer une barrière qui s'ouvre et se faire lorsque l'on basse devant.


## Contenu du dépôt
Dans ce dépôt, vous trouverez :

- le code en c++ avec l'extension .ino
- des images representant l'installation faite sur Tinkercad

## Composants
- Une carte Arduino UNO R3
- Un capteur de distance par ultrasons
- un servo moteur
- une breadbord
- 5 fils rouge
- 5 fils brun
- 4 fils vert
- 2 fils bleu

## Explication 
Ce code est conçu pour contrôler une barrière en utilisant un capteur à ultrasons et un moteur servo. Le fonctionnement de base est le suivant : si la distance détectée par le capteur est inférieure ou égale à un seuil déterminé (100 cm), la barrière s'ouvre, sinon, elle se ferme.

### Voici une explication détaillée du code :

#### 1 - Les bibliothèques et variables sont déclarées :

- La bibliothèque Servo est incluse pour contrôler le moteur servo.
- Les variables `duree`, `distance`, `trigger`, `echo`, `moteur` et `seuil` sont déclarées pour stocker les données du capteur à ultrasons et les broches utilisées.
- La variable `barriere` est déclarée pour stocker la position de la barrière (ouverte ou fermée).

#### 2 - Configuration initiale dans la fonction `setup()`:

- Initialise les broches trigger et echo en mode sortie et entrée, respectivement.
- Le moteur servo est attaché à la broche `moteur`.
- Configure le moniteur série avec une vitesse de transmission de 9600 baud.

#### 3 - Boucle principale dans la fonction `loop()`:

- Envoie un signal carré sur la broche trigger pour déclencher une mesure.
- Attends 2 µs, active la broche trigger pendant 2 µs, puis désactive la broche trigger.
- Utilise la fonction `pulseIn()` pour mesurer la durée de l'impulsion reçue sur la broche echo.
- Calcule la distance en centimètres en utilisant la formule `(vitesse du son * durée) / 2`. La vitesse du son dans l'air est de 340 m/s, et la durée est convertie en secondes et la distance en centimètres. On divise par 2 car le temps de vol est aller-retour.
- Affiche la distance calculée sur le moniteur série.
- Si la distance est inférieure ou égale au seuil (100 cm), la barrière est ouverte (position 90°). Sinon, après un délai de 2 secondes, la barrière est fermée (position 0°).
- La position de la barrière est envoyée au moteur servo.

La boucle `loop()` s'exécute indéfiniment, ce qui fait logger la distance entre le capteur et l'objet.

## Poids du programme
```sh
Sketch uses 3678 bytes (11%) of program storage space. Maximum is 32256 bytes.

Global variables use 249 bytes (12%) of dynamic memory, leaving 1799 bytes for local variables. Maximum is 2048 bytes.
```


Merci de votre intérêt pour arduino-robotics! J'espère que vous trouverez ces projets utiles et inspirants pour vos propres aventures dans le monde de la robotique et de la domotique avec Arduino.