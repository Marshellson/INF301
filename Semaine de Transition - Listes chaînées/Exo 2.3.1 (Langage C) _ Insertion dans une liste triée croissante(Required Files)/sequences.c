/*
 * @Author: ThearchyHelios
 * @Date: 2022-10-07 08:49:25
 * @LastEditTime: 2022-10-07 10:52:15
 * @LastEditors: ThearchyHelios
 * @Description:
 * @FilePath: /INF301/Semaine de Transition - Listes chaînées/Exo 2.3.1 (Langage C) _ Insertion dans une liste triée croissante(Required Files)/sequences.c
 */
#include <stdlib.h>
#include <stdio.h>
#include "sequences.h"

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
        valeurMin = n;
        printf("Donner un entier (un entier moins grand pour finir) :\n");
        scanf("%d", &n);
        while (n >= valeurMin)
        {
            c->suivant = (cellule_t *)malloc(sizeof(cellule_t));
            c = c->suivant;
            c->valeur = n;
            c->suivant = NULL;
            valeurMin = n;
            printf("Donner un entier (un entier moins grand pour finir) :\n");
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

/* insertion dans une sequence triée */
void insertion(liste_t *l, int n)
{
    /* votre code ici */
    cellule_t *c = l->tete;
    cellule_t *new = (cellule_t *)malloc(sizeof(cellule_t));
    new->valeur = n;
    new->suivant = NULL;
    if (c == NULL)
    {
        l->tete = new;
    }
    else
    {
        while (c->suivant != NULL && c->suivant->valeur <= n)
        {
            c = c->suivant;
        }
        new->suivant = c->suivant;
        c->suivant = new;
    }
    return;
}