/*
 * @Author: ThearchyHelios
 * @Date: 2022-10-22 13:39:32
 * @LastEditTime: 2022-10-30 15:51:26
 * @LastEditors: ThearchyHelios
 * @Description:
 * @FilePath: /APP2/pile.c
 */
#include <stdio.h>
#include "pile.h"

//-------------------------------------------------------------------------------

/* empile l'element */
void empiler(PILE *pile, ELT_PILE elt)
{
    pile->tab[pile->n] = elt;
    pile->n++;
}

//-------------------------------------------------------------------------------

/* renvoie l'element au sommet de la pile */
ELT_PILE depiler(PILE *pile)
{
    ELT_PILE elt = pile->tab[pile->n - 1];
    pile->n--;
    return elt;
}

//-------------------------------------------------------------------------------

/* additionne deux elements depiles et empile le resultat*/
void additionner(PILE *pile)
{
    ELT_PILE n2 = depiler(pile);
    ELT_PILE n1 = depiler(pile);
    ELT_PILE elt;
    elt.entier = n1.entier + n2.entier;
    elt.contenu = ENTIER;
    empiler(pile, elt);
}

//-------------------------------------------------------------------------------

/* soustrait deux elements depiles et empile le resultat*/
void soustraire(PILE *pile)
{
    ELT_PILE n2 = depiler(pile);
    ELT_PILE n1 = depiler(pile);
    ELT_PILE elt;
    elt.entier = n1.entier - n2.entier;
    elt.contenu = ENTIER;
    empiler(pile, elt);
}

//-------------------------------------------------------------------------------

/* multiplie deux elements depiles et empile le resultat*/
void multiplier(PILE *pile)
{
    ELT_PILE n2 = depiler(pile);
    ELT_PILE n1 = depiler(pile);
    ELT_PILE elt;
    elt.entier = n1.entier * n2.entier;
    elt.contenu = ENTIER;
    empiler(pile, elt);
}

//-------------------------------------------------------------------------------

/* affiche les elements de la pile */
void afficher_pile(PILE *pile)
{
    ELT_PILE elt;
    cellule_t *p_cell;
    printf("Pile :");

    for (int i = 0; i < pile->n; i++)
    {
        elt = pile->tab[i];

        if (elt.contenu == ENTIER)
        {
            printf("%d ", elt.entier);
        }

        else if (elt.contenu == BLOC)
        {
            p_cell = elt.tete_bloc;
            printf("{");
            while (p_cell != NULL)
            {
                printf("%c", p_cell->command);
                p_cell = p_cell->suivant;
            }
            printf("} ");
        }
    }

    printf("\n");
}

ELT_PILE sommet(PILE *pile)
{
    return pile->tab[pile->n - 1];
}

/*Commande [cmd n B] : exécute cmd, décrémente
n sans enlever B de la routine si n != 0. Sinon
enlève cmd et n de la pile, et B de la routine.*/
void boucle(PILE *pile, char *commande){
    ELT_PILE elt = depiler(pile);
    cellule_t *p_cell = elt.tete_bloc;
    sequence_t seq;
    seq.tete = p_cell;
    ELT_PILE elt2 = depiler(pile);
    elt2.entier--;
    if(elt2.entier == 0){
        empiler(pile, elt2);
        depiler(pile);
    }
    else{
        empiler(pile, elt2);
        empiler(pile, elt);
    }
}