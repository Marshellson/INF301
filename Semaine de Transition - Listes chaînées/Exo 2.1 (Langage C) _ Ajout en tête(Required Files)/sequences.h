/*
 * @Author: ThearchyHelios
 * @Date: 2022-10-07 08:49:25
 * @LastEditTime: 2022-10-07 09:10:36
 * @LastEditors: ThearchyHelios
 * @Description: 
 * @FilePath: /INF301/Semaine de Transition - Listes chaînées/Exo 2.1 (Langage C) _ Ajout en tête(Required Files)/sequences.h
 */
/************************************************************/
/*     Bibliothèque pour les séquences d'entiers            */
/*        implémentées par une liste chaînée                */
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
  Format d'entrée : un espace entre deux entiers, -1 pour finir  */
void saisir(liste_t *l, int valeurMin);

/* Affichage d'une sequence d'entiers.
  Format de sortie : un espace entre deux entiers */
void afficher(liste_t *l);

/* Ajout en tete d'une sequence */
void ajout_en_tete(liste_t *l, int n);
