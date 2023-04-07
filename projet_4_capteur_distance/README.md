# Projet 1 : led clignotante, modifier la fréquence
Ceci est mon quatrème projet. Ici j'utilise un capteur de distance graçe a un emmeteur a ultra-sons.


## Contenu du dépôt
Dans ce dépôt, vous trouverez :

- le code en c++ avec l'extension .ino
- des images representant l'installation faite sur Tinkercad

## Composants
- Une carte Arduino UNO R3
- Un capteur de distance par ultrasons
- un fils rouge
- un fils brun
- un fils vert
- un fils bleu

## Explication 
Ce code est conçu pour être utilisé avec un capteur de distance à ultrasons. Il mesure la distance entre le capteur et un objet en face de lui, puis affiche la distance en centimètres sur le moniteur série toute les une seconde.

### Voici une explication étape par étape du code :

#### 1 - Déclaration des variables :

- `duree` : variable longue pour stocker la durée de l'impulsion émise par le capteur (en microsecondes).
- `distance` : variable longue pour stocker la distance calculée (en centimètres).
- `trigger` : entier définissant le numéro de la broche de l'Arduino utilisée pour le signal de déclenchement du capteur (pin 2).
- `echo` : entier définissant le numéro de la broche de l'Arduino utilisée pour recevoir le signal d'écho du capteur (pin 4).

#### 2 - Configuration initiale dans la fonction `setup()`:

- Initialise les broches trigger et echo en mode sortie et entrée, respectivement.
- Configure le moniteur série avec une vitesse de transmission de 9600 baud.

#### 3 - Boucle principale dans la fonction `loop()`:

- Envoie un signal carré sur la broche trigger pour déclencher une mesure.
- Attends 2 µs, active la broche trigger pendant 2 µs, puis désactive la broche trigger.
- Utilise la fonction `pulseIn()` pour mesurer la durée de l'impulsion reçue sur la broche echo.
- Calcule la distance en centimètres en utilisant la formule `(vitesse du son * durée) / 2`. La vitesse du son dans l'air est de 340 m/s, et la durée est convertie en secondes et la distance en centimètres. On divise par 2 car le temps de vol est aller-retour.
- Affiche la distance calculée sur le moniteur série.
- Attends 1 seconde avant de répéter la mesure.

La boucle `loop()` s'exécute indéfiniment, ce qui fait logger la distance entre le capteur et l'objet.

## Poids du programme
```sh
Sketch uses 2652 bytes (8%) of program storage space. Maximum is 32256 bytes.

Global variables use 206 bytes (10%) of dynamic memory, leaving 1842 bytes for local variables. Maximum is 2048 bytes.
```


Merci de votre intérêt pour arduino-robotics! J'espère que vous trouverez ces projets utiles et inspirants pour vos propres aventures dans le monde de la robotique et de la domotique avec Arduino.