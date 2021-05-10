#define MIN 8
#define MAX 12
#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "role.h"
#include "debutdepartie.c"
#include "role.c"
#include "role_en_vie.c"
#include "jour.c"



void main (int argc, char* argv[]) {
    int date=1,nb_joueurs = -1;
    while (nb_joueurs<MIN || nb_joueurs>MAX) {
        printf("Quel est le nombre de joueurs (minimum 8, maximum 12) : ");
        scanf ("%d", &nb_joueurs);
    }
    system ("clear");
    debutdepartie(nb_joueurs);
    /*while (fin_de_partie != 1) {
        nuit(date);
        jour(date);
        jour++; */
}
