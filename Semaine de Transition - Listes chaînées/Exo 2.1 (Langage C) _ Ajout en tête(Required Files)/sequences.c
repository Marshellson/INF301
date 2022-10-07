/*
 * @Author: ThearchyHelios
 * @Date: 2022-10-07 08:49:25
 * @LastEditTime: 2022-10-07 08:50:32
 * @LastEditors: ThearchyHelios
 * @Description: 
 * @FilePath: /INF301/Semaine de Transition - Listes chaînées/Exo 2.1 (Langage C) _ Ajout en tête(Required Files)/sequences.c
 */
#include <stdlib.h>
#include <stdio.h>
#include "sequences.h"

/* Ajout en tete d'une sequence  : à implementer */


/* lecture d'une sequence d'entiers.
   En entrée : des entiers (-1 pour finir) */
void saisir(liste_t *l, int valeurMin) {
    int n=-1;
    cellule_t *c;
    printf("Donner un entier (un entier négatif pour finir) :\n");
    scanf("%d",&n);
    if (n>=valeurMin) {
        c = (cellule_t *) malloc(sizeof(cellule_t));  
        c->valeur = n;
        c->suivant = NULL;  
        l->tete = c;
        printf("Donner un entier (un entier négatif pour finir) :\n");
        scanf("%d",&n);
        while (n>=valeurMin) {
            c->suivant = (cellule_t *) malloc(sizeof(cellule_t));
            c = c->suivant;
            c->valeur = n;
            c->suivant = NULL;  
            printf("Donner un entier (un entier négatif pour finir) :\n");
            scanf("%d",&n);
        }
    }
    else {
        l->tete = NULL;
    }
}

/* Affichage d'une sequence d'entiers.
  En  sortie : un espace entre deux entiers */
void afficher(liste_t *l) {
    cellule_t *c;
    c = l->tete;
    while (c!=NULL) {
        printf(" %d",c->valeur);
        c = c->suivant;
    }
    printf("\n");
}

/* Ajout en tete d'une sequences d'entiers implémentée par une liste chaînée */
void ajout_en_tete(liste_t *l, int n) {
    /* votre code ici */
    cellule_t *c;
    c = (cellule_t *) malloc(sizeof(cellule_t));
    c->valeur = n;
    c->suivant = l->tete;
    l->tete = c;
    return;
}
