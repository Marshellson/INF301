/*
 * @Author: ThearchyHelios
 * @Date: 2022-10-07 08:49:25
 * @LastEditTime: 2022-10-07 10:50:03
 * @LastEditors: ThearchyHelios
 * @Description:
 * @FilePath: /INF301/Semaine de Transition - Listes chaînées/Exo 2.3.1 (Langage C) _ Insertion dans une liste triée croissante(Required Files)/sequences.h
 */
/************************************************************/
/*  bibliothèque pour les sequences d'entier sous formes    */
/*     le listes chaînées                                   */
/************************************************************/

/*        a priori : ne rien changer ici                    */

struct cellule
{
    int valeur;
    struct cellule *suivant;
};
typedef struct cellule cellule_t;

struct liste
{
    cellule_t *tete;
};
typedef struct liste liste_t;

/* lecture d'une sequence d'entiers.
  Format d'entrée : un espace entre deux entiers, une valeur décroissante pour finir  */
void saisir(liste_t *l, int valeurMin);

/* Affichage d'une sequence d'entiers.
  Format de sortie : un espace entre deux entiers */
void afficher(liste_t l);

/* insertion dans une sequence triée */
void insertion(liste_t *l, int n);
