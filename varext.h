#include <stdlib.h>
#include <stdio.h>
#define true 1
#define false 0

int flagChasseur = 0,flagCupidon = 0,flagCapitaine = 0;

int i;

void main()
{
    for(i=0,i<nombreJoueur,i++)
    {
        if(joueur[i].role == chasseur)
        {
            chasseur.present = true;
        } else {
            chasseur.present = false;
        }
        if(joueur[i].role == cupidon)
        {
            cupidon.present = true;
        } else {
            cupidon.present = false;
        }
    }
}
