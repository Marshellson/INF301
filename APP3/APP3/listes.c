/*
 * @Author: ThearchyHelios
 * @Date: 2022-11-28 08:47:47
 * @LastEditTime: 2022-11-28 08:53:20
 * @LastEditors: ThearchyHelios
 * @Description:
 * @FilePath: /INF301/APP3/APP3/listes.c
 */
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "listes.h"

/* fichier à compléter au besoin */

void init_liste_vide(liste_t *L)
{
    /* a completer */
    L->tete = NULL;
}

void liberer_liste(liste_t *L)
{
    /* a completer */
    cellule_t *p_cell = L->tete;
    while (p_cell != NULL)
    {
        L->tete = L->tete->suivant;
        free(p_cell);
        p_cell = L->tete;
    }
}

int ajouter_tete(liste_t *L, string c)
{ /* retourne 0 si OK, 1 sinon  */
    /* a completer */
    cellule_t *cel = (cellule_t *)malloc(sizeof(cellule_t));
    if (!cel)
    {
        return 1;
    }
    cel->val = c;
    cel->suivant = L->tete;
    L->tete = cel;
    return 0;
}
