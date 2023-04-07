# Projet 1 : led clignotante
Ceci est mon premier projet, une initiation. Je fait un simplement clignoter une led toute les seconde.


## Contenu du dépôt
Dans ce dépôt, vous trouverez :

- le code en c++ avec l'extension .ino
- des images representant l'installation faite sur Tinkercad

## Composants
- Une carte Arduino UNO R3
- Une LED
- Une résistance 1 kΩ
- Une breadbord
- 2 fils rouge
- 3 fils brun
- 1 fils bleu

## Explication 
Dans ce code, j'ai ajouté des commentaires en français pour expliquer chaque étape du code. Le code allume et éteint une LED connectée à la broche 2 de la carte Arduino, en alternance toutes les secondes, et envoie des messages via la communication série pour indiquer l'état de la LED.

### Voici une explication étape par étape du code :

#### 1 - Déclaration des variables et inclusion de la bibliothèque Servo :

- `led` : entier définissant le numéro de la broche de l'Arduino utilisée pour la LED (pin 2).

#### 2 - Configuration initiale dans la fonction `setup()` :

- Initialise la communication série avec une vitesse de transmission de 9600 baud.
- Configure la broche de la LED (pin 2) en mode sortie.

#### 3 - Boucle principale dans la fonction `loop()` :

- Utilise `digitalWrite()` pour allumer la LED en envoyant un signal HIGH (niveau logique haut) à la broche 2.
- Envoie un message ("La led est allumee") sur le moniteur série pour indiquer que la LED est allumée.
- Attends 1 seconde (1000 millisecondes) avec la fonction `delay()`.
- Utilise `digitalWrite()` pour éteindre la LED en envoyant un signal LOW (niveau logique bas) à la broche 2.
- Envoie un message ("La led est eteinte") sur le moniteur série pour indiquer que la LED est éteinte.
- Attends 1 seconde (1000 millisecondes) avec la fonction `delay()`.

La boucle `loop()` continue de s'exécuter indéfiniment, faisant ainsi clignoter la LED toutes les secondes.

## Poids du programme
```sh
Sketch uses 2028 bytes (6%) of program storage space. Maximum is 32256 bytes.

Global variables use 226 bytes (11%) of dynamic memory, leaving 1822 bytes for local variables. Maximum is 2048 bytes.
```


Merci de votre intérêt pour arduino-robotics! J'espère que vous trouverez ces projets utiles et inspirants pour vos propres aventures dans le monde de la robotique et de la domotique avec Arduino.