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


cellule_t* nouvelleCellule (void)
{
    /* À compléter (utiliser malloc) */
    printf("\n>>>>>>>>>>> A Faire : liste.c/nouvelleCellule() <<<<<<<<<<<<<<<<\n");
    return NULL;
}


void detruireCellule (cellule_t* cel)
{
    /* À compléter (utiliser free) */
    printf("\n>>>>>>>>>>> A Faire : liste.c/detruireCellule() <<<<<<<<<<<<<<<<\n");
}


void conversion (char *texte, sequence_t *seq)
{
  /* À compléter */
    printf("\n>>>>>>>>>>> A Faire : liste.c/conversion() <<<<<<<<<<<<<<<<\n");
}






void afficher (sequence_t* seq)
{
    assert (seq); /* Le pointeur doit être valide */
    /* À compléter */
    printf("\n>>>>>>>>>>> A Faire : liste.c/afficher() <<<<<<<<<<<<<<<<\n");
}

