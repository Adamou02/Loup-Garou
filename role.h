typedef struct Joueur Joueur;
struct Joueur {
    char nom[20];
    char* role;
    int date_de_mort;
    int mort;
    int amour;
};

typedef struct Villageois Villageois;
struct Villageois {
    char nom[20];
    int mort;
    int competence;
};

typedef struct Loup Loup;
struct Loup {
    char nom[20];
    int mort;
    int competence;
};

typedef struct Sorciere Sorciere;
struct Sorciere {
    char nom[20];
    int mort;
    int competence;
};

typedef struct Chasseur Chasseur;
struct Chasseur {
    char nom[20];
    int mort;
    int competence;
};

typedef struct Voleur Voleur;
struct Voleur {
    char nom[20];
    int mort;
    int competence;
};

typedef struct Petite_Fille Petite_Fille;
struct Petite_Fille {
    char nom[20];
    int mort;
    int competence;
};
