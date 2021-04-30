#include <stdlib.h>
#include <stdio.h>
#define true 1
#define false 0

/*
    MEMO:
    -penser a réduire la variable nombreJoueur dans la fonction kill
    -ne pas oublier de variable dans la structure d'un joueurs c-a-d:
        -player.role
        -player.state
        -player.name
        -player.dateMort
        -player.amoureux
    -ne pas oublier le struct qui previent qu'une carte est présent dans le jeu exemple : chasseur.presence = true
    -la variable capitaine va être chiante car potentielement répétitif à attribué -> y reflechir en groupe
    -la fonction askRole doit etre dans la partie Initialisation de Adam car utilse pour savoir si un role est present dans la partie
    pour ne pas faire de boucle inutile (par contre prend plus de place) 
    -DEMANDER A ADAM COMMENT AVOIR LA FONCTION "CLEAR" 
    -essayer d'initialiser les flag à 0 dans le fichier initialisation pour ne pas les réinitialiser à 0 chaque jour 
*/

// FONCTIONS //

/*

FONCTION POUR L'INITIALISATION (Adam)

int present(askRole)
{
    for(i=0,i<nombreJoueur,i++)
    {
        if (player[i].role == askRole)
        askRole.presence = true;
    }
}
*/

player.name search(player.role)
{
    int i;
    
    for(i=0,i<nombreJoueur,i++)
    {
        if(player[i].role == player.role) 
        return player[i].name
    }
}

void chasseur(int* flag) // fonction "chasseur" elle permet si le chasseur est mort de tirer sur un joueur choisit par le defunt chasseur.
{
    char cible[10];
    int i;

    search(player.chasseur)->chasseur;

    if(chasseur.presence == true && chasseur.etat == false && flag = 0) /* verification de si un chasseur est present dans la partie 
    si il est mort et une variable flag qui permet de ne pas répété l'opération plusieurs fois (le chasseur ne meurt qu'une fois).*/
    {
        printf("\njoueur %s est mort ..\n Il etait le chasseur, dans un dernier élant de lucidité il tire sur : ",chasseur.name);
        scanf("%s",&cible[10]); //il choisit sa cible
        
        while(i=0,i>nombreJoueurs,i++) //on verifie qu'il existe un joueur avec le nom donner par le chasseur.
        {
            if(player[i].nom = cible)
            {
                printf("\n\nle chasseur a tuer %s qui était un %s",player[i].name,player[i].role);
                kill(player[i].state); /*il existe donc on l'élimine et on change de competur à 1 pour sortir de la boucle et ne plus
                jamais répéter l'action.*/
                *flag = 1;
            }
        }    
    }
}

void amoureux(int* flag) //fonction amoureux sert a vérifier si un des amoureux est mort durant la nuit
{
    int i,j;

    for(i=0,i<nombreJoueur,i++)
    {
        if(player[i].state = false && player[i].dateMort >= 1 && player[i].amoureux == true) /*
        ces conditions permet de 1) trouver le mort de 2) vérifier si le meurtre est recent et 3) vérifier si il était amoureux */
        {
            for(j=0,j<nombreJoueur,j++)
            {
                if(player[j].amoureux == true && j != i)
                {
                int tempLove = j;
                }
            }
            printf("\n%s est mort il était %s.\n",player[i].name,player[i].role);
            printf("De plus il était amoureux de %s qui était %s",player[tempLove].name,player[tempLove].role);
            kill(player[i].state);
            kill(player[j].state);
            *flag = 1;
        }
    }
}

void capitaineElec();

void capitaineMort();

void vote(); // vote puis annonce de la personne élu (morte+role)

// MAIN //

void main()
{
    int flag1 = 0,flag2 = 0,flag3 = 0; // peut être les initialiser à 0 dans le fichier initialisation

    present(chasseur) = cha;
    if (cha == true && flag1 == 0)
    {
        chasseur(&flag1);
    }

    present(cupidon) = cup;
    if (cup == true && flag2 == 0)
    {
       amoureux(&flag2); 
    }

    printf("\nil est temps de débatre entre vous\n");

    vote();

    printf("\n le village se rendort\n");

}

/*
    Comment se déroule la journée dans le loup garou:
    -qui est victime de la sorciere ou loup garou
        -si chasseur alors carte activé
        -si joueurs amoureux alors le 2nd meurt
        -si capitaine alors désigne son succeseur
    -débat
    -vote (si égalité alors le capitaine départage (il est un vote compte double))
    -annonce de la carte de la personne voté
    -le village se rendort
*/