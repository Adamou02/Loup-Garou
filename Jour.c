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

int nb_mort = 0;

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

void chasseurFct(int* flag) // fonction "chasseur" elle permet si le chasseur est mort de tirer sur un joueur choisit par le defunt chasseur.
{
   int i,x;

    printf("\ndans la nuit, le joueur %s est mort ..\n Il etait le chasseur, dans un dernier élant de lucidité il tire\n",joueur[cha].nom);

    for(i=0,i<nombreJoueur;i++)
        {
            if(joueur[j].etat == true)
            {
                printf("%d = %s\n",j,joueur[j].nom);
            }
        }
    do 
        scanf("\n%s selectionner le joueur que vous voulez éliminer: %d",joueur[cha].nom,x); //selection du joueur parmis la liste
    while(x > 0 && x < nombreJoueur && joueur[x].etat == true);
    system ("clear");

    printf("\n\nLe chasseur a tuer %s qui était un %s",joueur[x].nom,joueur[x].role);
    kill(player[x]); /*il existe donc on l'élimine et on change de competur à 1 pour sortir de la boucle et ne plus
    jamais répéter l'action.*/
    nb_mort++;
    *flag = 1;
}

void amoureux(int* flag) //fonction amoureux sert a vérifier si un des amoureux est mort durant la nuit
{
    int i,j;

    for(i=0,i<nombreJoueur,i++)
    {
        if(joueur[i].amoureux == true && joueur[i].etat == false) /*
        ces conditions permet de 1) vérifier si le joueur est mort récemment et 2) vérifier si il était amoureux */
        {
            for(j=0,j<nombreJoueur,j++)
            {
                if(joueur[j].amoureux == true && j != i)
                {
                    printf("\n%s est mort il était %s.\n",joueur[i].nom,joueur[i].role);
                    printf("De plus il était amoureux de %s qui était %s\n",joueur[tempLove].nom,joueur[tempLove].role);
                    kill(joueur[j]);
                    nb_mort = nb_mort + 2;
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

    capt = chercherCapitaine();

    if(joueur[capt].etat = false)
    {
        nb_mort++;
        printf("Le Capitaine est Malheureusement mort il était %s\nDans son derniere souffle il chuchote le nom de son héritier\n:",joueur[capt].nom);

        for(i=0,i<nombreJoueur;i++)
        {
            printf("%d = %s\n",i,joueur[i].nom);
        }
        do 
            scanf("\n%s selectionnez le joueur que vous voulez voir Capitaine: %d\n",joueur[capt].nom,x); //selection du joueur parmis la liste
        while(joueur[x].etat == true);
        system ("clear");

        printf("Le joueur élu est le joueur %s !\n Long vie au Capitaine %s !\n",joueur[x].nom,joueur[x].nom);
        joueur[x].capitaine = true;
    }
}

void votePopulaire()
{
    int pendu;
    printf("\nIl est temps de débatre entre vous\nPuis vous pouvez commencer le vote pour éliminer le joueur le plus suspect..");

    pendu = vote();

    printf("\nLe village à décidé d'éliminer %s qui était un %s",joueur[pendu].nom,joueur[pendu].role);
    kill(joueur[pendu]);
    nb_mort++;

    if(joueur[pendu].role == loupGarou)
    {
        printf("\nLa foule saute de joie !");
    } else {
        printf("\nLes habitant sont accablés de cette malheureuse perte");
    }
}

int compteRendu(nb_mort) //fonction qui annonce les mort de la nuit derniere
{
    int i;

    for(i=0,i<nombreJoueur,i++)
    {
        if(date - joueur[i].dateMort == 0 && joueur[i].etat == false)
        {
            if(joueur[i].amoureux != false || joueur[i].role != chasseur || joueur.capitaine != true)
            {
                if(nb_mort == 0)
                {
                    printf("\nDans la nuit, le joueur %s est mort. Il était %s.\n",joueur[i].nom,joueur[i].role);
                    nb_mort++;
                } else if(nb_mort == 1) {
                    printf("\nDe plus le joueur %s est mort. Il était %s.\n",joueur[i].nom,joueur[i].role);
                    nb_mort++;
                }
            }
        }
    }
}

//----------------------------------------------------------------MAIN----------------------------------------------------------------//

void main()
{
    cha = chercherRole(chasseur);
    cup = chercherRole(cupidon);
    nb_mort = 0;

    if(flagCapitaine == 0)
    {
        capitaineVote(&flagCapitaine);   //Election du capitaine durant la premiere journée
    }

    if (joueur[cha].present == true && flagChasseur == 0 && joueur[cha].etat == false)
    {
        chasseur(&flagChasseur);  //Si le chasseur est tuée alors il active le pouvoir de sa carte
    }

    if (joueur[cup].present == true && flagCupidon == 0)
    {
       amoureux(&flagCupidon);   //Si un des amoureux est mort alors l'autre meurt aussi
    }

    compteRendu();

    capitaineMort();       //Si le capitaine est mort alors il choisit son héritier

    votePopulaire();       //Le village choisit une personne à éliminer

    if (joueur[cha].present == true && flagChasseur == 0 && joueur[cha].etat == false)
    {
        chasseur(&flagChasseur);  //Si le chasseur est tuée alors il active le pouvoir de sa carte
    }

    if (joueur[cup].present == true && flagCupidon == 0)
    {
       amoureux(&flagCupidon);   //Si un des amoureux est mort alors l'autre meurt aussi
    }

    capitaineMort(); 

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
    (si chasseur, amoureux ou capitaine mort réefectuer leur fonctions)
    -annonce de la carte de la personne voté
    -le village se rendort
*/
