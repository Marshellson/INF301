/*
 * @Author: ThearchyHelios
 * @Date: 2022-10-07 08:49:25
 * @LastEditTime: 2022-10-07 09:12:22
 * @LastEditors: ThearchyHelios
 * @Description: 
 * @FilePath: /INF301/Semaine de Transition - Listes chaînées/Exo 2.2 (Langage C) _ Ajout en queue(Required Files)/sequences.c
 */
#include <stdlib.h>
#include <stdio.h>
#include "sequences.h"

/* Ajout en queue d'une séquence  : à implementer */

/* lecture d'une sequence d'entiers.
  En entrée : des entiers (-1 pour finir)*/
void saisir(liste_t *l, int valeurMin)
{
    int n = -1;
    cellule_t *c;
    printf("Donner un entier (un entier négatif pour finir) :\n");
    scanf("%d", &n);
    if (n >= valeurMin)
    {
        c = (cellule_t *)malloc(sizeof(cellule_t));
        c->valeur = n;
        c->suivant = NULL;
        l->tete = c;
        printf("Donner un entier (un entier négatif pour finir) :\n");
        scanf("%d", &n);
        while (n >= valeurMin)
        {
            c->suivant = (cellule_t *)malloc(sizeof(cellule_t));
            c = c->suivant;
            c->valeur = n;
            c->suivant = NULL;
            printf("Donner un entier (un entier négatif pour finir) :\n");
            scanf("%d", &n);
        }
    }
    else
    {
        l->tete = NULL;
    }
    return;
}

/* Affichage d'une sequence d'entiers.
  En  sortie : un espace entre deux entiers */
void afficher(liste_t l)
{
    cellule_t *c;
    if (l.tete == NULL)
    {
        printf("\n");
    }
    else
    {
        c = l.tete;
        while (c != NULL)
        {
            printf(" %d", c->valeur);
            c = c->suivant;
        }
        printf("\n");
    }
    return;
}

/* Ajout en queue d'une sequence d'entiers implémentée par une liste chaînée */
void ajout_en_queue(liste_t *l, int n)
{
    /* votre code ici */
    cellule_t *c;
    c = (cellule_t *)malloc(sizeof(cellule_t));
    c->valeur = n;
    c->suivant = NULL;
    if (l->tete == NULL)
    {
        l->tete = c;
    }
    else
    {
        cellule_t *d;
        d = l->tete;
        while (d->suivant != NULL)
        {
            d = d->suivant;
        }
        d->suivant = c;
    }
    return;
}
