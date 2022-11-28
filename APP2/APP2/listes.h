/*
 * @Author: ThearchyHelios
 * @Date: 2022-10-22 13:39:32
 * @LastEditTime: 2022-10-22 13:42:14
 * @LastEditors: ThearchyHelios
 * @Description: 
 * @FilePath: /INF301/APP2/APP2/listes.h
 */
#ifndef LISTES_H
#define LISTES_H

#include <stdbool.h>

/*
 * Pour réaliser des tests de performance, désactiver tous les 
 * affichages.
 * Pour cela, le plus simple est de redefinir les fonctions principales 
 * en decommentant les 3 lignes suivantes et en commentant l'ancienne 
 * definition de 'eprintf' juste dessous.
 */

#ifdef SILENT

#define printf(fmt, ...) (0)
#define eprintf(fmt, ...) (0)
#define putchar(c) (0)

#else

#define eprintf(...) fprintf (stderr, __VA_ARGS__)

#endif

extern bool silent_mode;




struct cellule {
    char   command;
    /* vous pouvez rajouter d'autres champs ici */
    struct cellule *suivant;
};
typedef struct cellule cellule_t;

struct sequence {
    cellule_t *tete;
};
typedef struct sequence sequence_t;

cellule_t* nouvelleCellule (void);

void detruireCellule (cellule_t*);

/* attention: prend un cellule_t et non un sequence_t */
void detruireSequence(cellule_t *tete);

/* conversion de la chaine de caractere en liste chainee */
void conversion(char *texte, sequence_t *seq);

/* afficher la commande de chaque cellule de la sequence */
void afficher(sequence_t* seq);

cellule_t *copier_sequence(cellule_t *p_tete);

#endif
