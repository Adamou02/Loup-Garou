typedef struct Joueur Joueur;
struct Joueur {
    char nom[20];
    char* role;
    int date_de_mort;
    int mort;
    int amour;
    int capitaine;
};

typedef struct Villageois Villageois; //la competence du Villageois s'active si mort == 0
struct Villageois {
    char nom[20];
    int mort;
};

typedef struct Loup Loup;  //la competence du Loup s'active si mort == 0
struct Loup {
    char nom[20];
    int mort;
};

typedef struct Sorciere Sorciere; //la competence de la sorciere s'active si mort == 0 et competence == 1
struct Sorciere {
    char nom[20];
    int mort;
    int soin;
    int poison;
};

typedef struct Chasseur Chasseur; //Chasseur.competence == 0; mais quand il meurt, Chasseur.competence == 1 puis se remets a 0 quand il tire
struct Chasseur {
    char nom[20];
    int mort;
    int competence;
};

typedef struct Voleur Voleur; //Le Voleur est simplement appelé quand la date == 1
struct Voleur {
    char nom[20];
    int mort;
};

typedef struct Petite_Fille Petite_Fille; //La fonction Petite_Fille est appelé chaque nuit a la fin et il y a 1/nb_joueurs chance qu'elle meurt
struct Petite_Fille {
    char nom[20];
    int mort;
};
