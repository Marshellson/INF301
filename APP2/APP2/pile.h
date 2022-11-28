/*
 * @Author: ThearchyHelios
 * @Date: 2022-10-22 13:39:31
 * @LastEditTime: 2022-10-30 15:49:37
 * @LastEditors: ThearchyHelios
 * @Description: 
 * @FilePath: /APP2/pile.h
 */
#ifndef _PILE_H_
#define _PILE_H_

#include "listes.h"

#define MAX_PILE  128

//
// Structures
//

/* ANCIENNE VERSION
typedef struct {
    int n;              // nombre d'elements de la pile
    int tab[MAX_PILE];  // tableau des elements de la pile
} PILE;*/

enum {
    ENTIER = 0,
    BLOC = 1,
};

typedef struct {
    union {
        int entier;
        cellule_t *tete_bloc;
    };
    int contenu; // precise le contenu de l'element
} ELT_PILE;

typedef struct {
    int n;                    // nombre d'elements de la pile
    ELT_PILE tab[MAX_PILE];   // tableau des elements de la pile
} PILE;

//
// Function prototypes
//

/* empile l'element */
void empiler(PILE *pile, ELT_PILE elt);

/* renvoie l'element au sommet de la pile */
ELT_PILE depiler(PILE *pile);

/* additionne deux elements depiles et empile le resultat*/
void additionner(PILE *pile);

/* soustrait deux elements depiles et empile le resultat*/
void soustraire(PILE *pile);

/* multiplie deux elements depiles et empile le resultat*/
void multiplier(PILE *pile);

/* affiche les elements de la pile */
void afficher_pile(PILE *pile);

/* boucle */
void boucle(PILE *pile, char *commande);

#endif
