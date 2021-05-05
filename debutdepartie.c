#include "stdio.h"
#include "stdlib.h"
#include "time.h"


void role_joueur(int nb_joueurs, int taille_deck, Joueur joueur[nb_joueurs], char* role[taille_deck]) { //doit rajouter l'aleatoire et la case Voleur
    srand(time(NULL));    //permet d'avoir de l'aléatoire différent à chaque exécution.
    int i, j, poubelle;
    for (i=0; i<nb_joueurs; i++) {
        printf("Bonjour joueur %d, quel est ton pseudo (20 caractères max): ", i+1);
        scanf("%s", joueur[i].nom);
        j = rand () % taille_deck;        //on tire un role aleatoirement dans le deck
        while (role[j] == "NULL") {             //si role[j] a déjà été donné a un joueur, on redonne une valeur aleatoire à j pour avoir un nouveau role[j]
            j = rand () % taille_deck;
        }
        joueur[i].role = role[j];
        role[j] = "NULL";
        system ("clear");
        printf("%s, ton rôle est : %s \nTape 1 pour effacer ton rôle de l'écran.", joueur[i].nom, joueur[i].role);   //car le printf joueur->role ne marche pas a la fin
        scanf("%d", &poubelle);
        system ("clear");
        joueur[i].amour = 0;
        joueur[i].mort = 0;
    }
    for (i=0; i<nb_joueurs; i++) {
        printf("%s\n", joueur[i].role);
    }
}



void creation_deck(int nb_joueurs, Joueur joueur[nb_joueurs]) {
    int i, taille_deck = nb_joueurs+2; //on met nb_joueurs+2 cartes dans le deck à cause du role Voleur qui necessite un pile de 2 cartes inconnues.
    //On prend le nombre maximal de joueurs (12) et on adapte les parties qui ont moins de joueurs en "supprimant" les derniers cartes.
    char* role[]= {"Villageois", "Villageois", "Loup-garou", "Loup-garou", "Voyante", "Sorcière", "Cupidon", "Voleur", "Chasseur", "Petite fille", "Villageois", "Villageois", "Villageois", "Loup-garou"};
    //On supprime les cartes du rang taille_deck jusqu'au rang maximal atteint dans un partie de 12 joueurs, donc de 14 cartes.
    for (i=taille_deck; i<MAX+2; i++) {
        role[i] = "NULL";
    }
    role_joueur(nb_joueurs, taille_deck, joueur, role);
}


void debutdepartie (int nb_joueurs) {
    int i;
    Joueur joueur[nb_joueurs];   
                                
    creation_deck(nb_joueurs, joueur);
}