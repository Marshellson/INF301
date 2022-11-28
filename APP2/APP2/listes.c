/*
 * @Author: ThearchyHelios
 * @Date: 2022-10-22 13:39:31
 * @LastEditTime: 2022-10-30 14:11:36
 * @LastEditors: ThearchyHelios
 * @Description:
 * @FilePath: /APP2/listes.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#ifdef NCURSES
#include <ncurses.h>
#endif
#include "listes.h"

/*
 *  Auteur(s) :
 *  Date :
 *  Suivi des Modifications :
 *
 */

bool silent_mode = false;

cellule_t *nouvelleCellule(void)
{
    return (cellule_t *)malloc(sizeof(cellule_t));
}

void detruireCellule(cellule_t *cel)
{
    free(cel);
}

/* attention: prend un cellule_t et non un sequence_t */
void detruireSequence(cellule_t *tete)
{
    cellule_t *p_cell = tete;
    while (p_cell != NULL)
    {
        tete = tete->suivant;
        detruireCellule(p_cell);
        p_cell = tete;
    }
}

/* conversion de la chaine de caractere en liste chainee (routine) */
void conversion(char *texte, sequence_t *seq)
{
    /* La sequence donnee en argument est vide car l'execution d'une routine
       libere les cellules au fur et a mesure */
    if (seq->tete != NULL)
    {
        printf("conversion() : la sequence donnee pour charger la routine n'est pas vide.\n");
        return;
    }

    cellule_t *p_cell, *p_prevcell;

    /* Creation tete de la sequence*/
    p_cell = nouvelleCellule();
    p_cell->command = texte[0];
    p_cell->suivant = NULL;
    seq->tete = p_cell;
    p_prevcell = p_cell;

    /* Creation reste de la sequence */
    for (int i = 1; texte[i] != '\0'; i++)
    {
        p_cell = nouvelleCellule();
        p_cell->command = texte[i];
        p_cell->suivant = NULL;
        p_prevcell->suivant = p_cell;
        p_prevcell = p_cell;
    }
}

/* afficher la commande de chaque cellule de la sequence */
void afficher(sequence_t *seq)
{
    assert(seq); /* Le pointeur doit être valide */
    cellule_t *p_cell = seq->tete;

    while (p_cell)
    {
        printf("%c ", p_cell->command);
        p_cell = p_cell->suivant;
    }
    printf("\n");
}

cellule_t *copier_sequence(cellule_t *p_tete)
{
    cellule_t *p_tmp = p_tete;

    // copier la tete de la sequence a la main
    cellule_t *p_tetecpy = nouvelleCellule();
    p_tetecpy->command = p_tete->command;
    p_tetecpy->suivant = NULL;

    cellule_t *p_tmpcpy = p_tetecpy;
    cellule_t *p_tmp2cpy = p_tetecpy;

    p_tmp = p_tmp->suivant;

    while (p_tmp != NULL)
    {
        // creer une nouvelle cellule
        p_tmpcpy = nouvelleCellule();
        p_tmpcpy->suivant = NULL;

        // copier la commande
        p_tmpcpy->command = p_tmp->command;

        p_tmp2cpy->suivant = p_tmpcpy;

        p_tmp2cpy = p_tmp2cpy->suivant;
        p_tmp = p_tmp->suivant;
    }

    return p_tetecpy;
}
