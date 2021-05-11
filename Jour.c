#include <stdlib.h>
#include <stdio.h>
#include <varext.h>
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
    -le vote du capitaine doit se faire en debut de partie
*/

//-------------------------------------------------------------FONCTIONS-------------------------------------------------------------//

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
/*
player.name search(player.role)
{
    int i;
    
    for(i=0,i<nombreJoueur,i++)
    {
        if(player[i].role == player.role) 
        return player[i].name
    }
}
*/

void clrVote ()
{
    int i;
    for(i=0;i<nombreJoueur;i++)
    {
        joueur[i].vote = 0;
    }
}

int vote() //fonction vote    + VOIR PROBLEME EVOQUER AVEC VOTECAPITAINE !!!!!!
{
int i,j,k,x,y;   

clrVote();

for (i=0;i<nombreJoueur;i++) //boucle qui définit qui vote
    {
        printf("joueur %s veuillez votez :\n",joueur[i].nom);
        
        for (j=0;j<nombreJoueur;j++) //affiche les votes possible
        {
            if(joueur[j].etat == true)
            {
                printf("%d = %s\n",j,joueur[j].nom);
            }
        }   
        do 
            scanf("\nSelectionner le joueur que vous voulez éliminer: %d",x); //selection du joueur parmis la liste
        while(x > 0 && x < nombreJoueur && joueur[x].etat == true); //s'assure que le joueur voté existe
        system ("clear");

        joueur[x].vote ++;
    }

    int joueurMax = -1;

    for(k=0;k<nombreJoueur;k++)
    {
        if(joueur[k].vote > joueurMax)
        {
            joueurMax = y;
        }
    }
    return y;
}

//-----------------------------------------------------Fonction-principale-----------------------------------------------------//

void chasseur(int* flag) // fonction "chasseur" elle permet si le chasseur est mort de tirer sur un joueur choisit par le defunt chasseur.
{
   int i,x;

    printf("\njoueur %s est mort ..\n Il etait le chasseur, dans un dernier élant de lucidité il tire\n",chasseur.nom);

    for(i=0,i<nombreJoueur;i++)
        {
            if(joueur[j].etat == true)
            {
                printf("%d = %s\n",j,joueur[j].nom);
            }
        }
    do 
        scanf("\n%s selectionner le joueur que vous voulez éliminer: %d",chasseur.nom,x); //selection du joueur parmis la liste
    while(x > 0 && x < nombreJoueur && joueur[x].etat == true);
    system ("clear");

    printf("\n\nLe chasseur a tuer %s qui était un %s",joueur[x].nom,joueur[x].role);
    kill(player[x]); /*il existe donc on l'élimine et on change de competur à 1 pour sortir de la boucle et ne plus
    jamais répéter l'action.*/
    *flag = 1;
}

void amoureux(int* flag) //fonction amoureux sert a vérifier si un des amoureux est mort durant la nuit
{
    int i,j;

    for(i=0,i<nombreJoueur,i++)
    {
        if(joueur[i].dateMort == 1 && joueur[i].amoureux == true) /*
        ces conditions permet de 1) vérifier si le joueur est mort récemment et 2) vérifier si il était amoureux */
        {
            for(j=0,j<nombreJoueur,j++)
            {
                if(joueur[j].amoureux == true && j != i)
                {
                    printf("\n%s est mort il était %s.\n",joueur[i].nom,joueur[i].role);
                    printf("De plus il était amoureux de %s qui était %s\n",joueur[tempLove].nom,joueur[tempLove].role);
                    kill(joueur[j]);
                    *flag = 1;
                }
            }
        }
    } 
}


int capitaineVote(int* flag) // !!!!!!!!!! Problème si un joueur meurt et qu'un joueur[k]> à son numéro n'est pas encore mort (affiche les morts pdt les votes)
{                    // pour résoudre le problème il faut que quand un joueur meurt il laisse sa place à un joueur K> 
    int x;

    printf("Il est l'heure d'élire un Capitaine\n");

    x = vote();

    printf("le joueur élu est le joueur %s !\n Long vie au Capitaine %s !\n",joueur[x].nom,joueur[x].nom);
    joueur[x].capitaine = true;
    *flag = 1;
}

void capitaineMort()
{
    int i,x;

    if(capitaine.etat = false)
    {
        printf("Le Capitaine est Malheureusement mort il était %s\nDans son derniere souffle il chuchote le nom de son héritier\n:",capitaine.nom);

        for(i=0,i<nombreJoueur;i++)
        {
            printf("%d = %s\n",j,joueur[j].nom);
        }
        do 
            scanf("\n%s Selectionner le joueur que vous voulez voir Capitaine: %d\n",capitaine.nom,x); //selection du joueur parmis la liste
        while(joueur[x].etat == true);
        system ("clear");

        printf("le joueur élu est le joueur %s !\n Long vie au Capitaine %s !\n",joueur[x].nom,joueur[x].nom);
        joueur[x].capitaine = true;
        *flag = 1;
    }
}

void votePopulaire()
{
    int pendu;
    printf("\nIl est temps de débatre entre vous\nPuis vous pouvez commencer le vote pour éliminer le joueur le plus suspect..");

    pendu = vote();

    printf("\nLe village à décidé d'éliminer %s qui était un %s",joueur[pendu].nom,joueur[pendu].role);
    kill(joueur[pendu]);

    if(joueur[pendu].role == loupGarou)
    {
        printf("\nLa foule saute de joie !");
    } else {
        printf("\nLes habitant sont accablés de cette malheureuse perte");
    }
}

void compteRendu() //fonction qui annonce les mort de la nuit derniere
{
    
}

//----------------------------------------------------------------MAIN----------------------------------------------------------------//

void main()
{
    if(flagCapitaine == 0)
    {
        capitaineVote(&flagCapitaine);   //Election du capitaine durant la premiere journée
    }

    if (chasseur.present == true && flagChasseur == 0 && chasseur.etat == false)
    {
        chasseur(&flagChasseur);  //Si le chasseur est tuée alors il active le pouvoir de sa carte
    }

    if (cupidon.present == true && flagCupidon == 0)
    {
       amoureux(&flagCupidon);   //Si un des amoureux est mort alors l'autre meurt aussi
    }

    capitaineMort();       //Si le capitaine est mort alors il choisit son héritier

    votePopulaire();       //Le village choisit une personne à éliminer

    printf("\nLe village se rendort\n");  //annonce de fin de la journée

}

/*
    Comment se déroule la journée dans le loup garou:
    -qui est victime de la sorciere ou loup garou
        -si chasseur alors carte activé
        -si joueurs amoureux alors le 2nd meurt
        -si capitaine mort alors désigne son succeseur
    -débat
    -vote (si égalité alors le capitaine départage (il est un vote compte double))
    -annonce de la carte de la personne voté
    -le village se rendort
*/
