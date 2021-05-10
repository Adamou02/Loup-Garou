#include "stdio.h"
#include "stdlib.h"

void chasseur (int nb_joueurs, Joueur joueur[nb_joueurs]) {
    unsigned int i;
    if (Chasseur.mort == 1) {
        Chasseur.competence == 1;
    }
    if (Chasseur.competence == 1) {
        printf ("Quelle joueur voulez vous tuer : \n");
        for (i=0; i<nb_joueurs; i++) {
            printf ("%s", joueur[i].nom);
        }
    }
}