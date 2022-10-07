/************************************************************/
/*  bibliothèque pour les sequences d'entier sous formes    */
/*     le listes chaînées                                   */
/************************************************************/

/*        a priori : ne rien changer ici                    */

struct cellule {
    int valeur;
    struct cellule *suivant;};
typedef struct cellule cellule_t;

struct liste {
    cellule_t *tete;};
typedef struct liste liste_t;

/* lecture d'une sequence d'entiers.
  Format d'entrée : un espace entre deux entiers, une valeur décroissante pour finir  */
void saisir(liste_t *l, int valeurMin) ;

/* Affichage d'une sequence d'entiers.
  Format de sortie : un espace entre deux entiers */
void afficher(liste_t l);

/* insertion dans une sequence triée */
void insertion(liste_t *l, int n);
