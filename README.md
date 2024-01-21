# Objectif
L'objectif du TP est de réaliser un compteur numérique et d'en afficher la valeur sur les digits de la DE10

# Intro
On veut pouvoir écrire un code source qui va générer un compteur incrémenté chaque seconde grâce à l'interruption générée par un timer.
Cette valeur va alors être envoyée à 3 décodeurs BCD qui vont convertir la valeur sur 4 bits en entrée pour allumer les digits correspondant au nombre reçu.

# Création d'une structure NIOSII standard et ajout d'un timer et 3 PIOs
## Schéma du système
![Alt text](systeme_complet-1.png)

## Platform designer
![Alt text](modele_qsys-1.png)