#include <stdlib.h>
#include <stdio.h>
#define true 1
#define false 0

int flagChasseur = 0,flagCupidon = 0,flagCapitaine = 0;

int chercherRole(char* role)
{
    int i;

    for(i=0,i<nombreJoueur,i++)
    {
        if(joueur[i].role == role)
        {
            return i;
        }
    }
}

int chercherCapitaine()
{
    int i;

    for(i=0,i<nombreJoueur,i++)
    {
        if(joueur[i].Capitaine == true)
        {
            return i;
        }
    }
}

int capt = -1;
int cha = -1;
int cup = -1;
int nb_mort = 0;
