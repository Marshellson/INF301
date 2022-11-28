/*
 * @Author: ThearchyHelios
 * @Date: 2022-10-22 13:39:31
 * @LastEditTime: 2022-10-30 15:50:24
 * @LastEditors: ThearchyHelios
 * @Description:
 * @FilePath: /APP2/interprete.c
 */
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <stdlib.h>
#ifdef NCURSES
#include <ncurses.h>
#endif
#include "listes.h"
#include "pile.h"
#include "curiosity.h"

/*
 *  Auteur(s) :
 *  Date :
 *  Suivi des Modifications :
 *
 */

void stop(void)
{
    char enter = '\0';
    printf("Appuyer sur entrée pour continuer...\n");
    while (enter != '\r' && enter != '\n')
    {
        enter = getchar();
    }
}

void ajout_en_tete(sequence_t *seq, ELT_PILE elt)
{
    cellule_t *p_tmp;
    if (elt.contenu == ENTIER)
    {
        p_tmp = nouvelleCellule();
        p_tmp->command = elt.entier + '0';
        p_tmp->suivant = seq->tete;
        seq->tete = p_tmp;
    }
    else if ((elt.contenu == BLOC) && (elt.tete_bloc != NULL))
    {
        p_tmp = elt.tete_bloc;
        while (p_tmp->suivant != NULL)
        {
            p_tmp = p_tmp->suivant;
        }
        p_tmp->suivant = seq->tete->suivant;
        detruireCellule(seq->tete);
        seq->tete = elt.tete_bloc;
    }
    else
    {
        p_tmp = seq->tete;
        seq->tete = seq->tete->suivant;
        detruireCellule(p_tmp);
    }
}

void gerer_bloc_cmd(sequence_t *seq, PILE *pile)
{
    cellule_t *p_tmp;
    ELT_PILE elt;
    /* nb_acco == 0 signifie que l'accolade fermante a ete lue.
       Cela permet d'ingorer l'accolade fermante du bloc imbrique. */
    int nb_acco = 1;

    /* Actualisation de la tete de la sequence */
    p_tmp = seq->tete;              // ne pas perdre l'accolade ouvrante
    seq->tete = seq->tete->suivant; // ne pas perdre la suite de la sequence
    detruireCellule(p_tmp);         // liberer l'accolade ouvrante

    /* Debut cas bloc de commandes vide */
    if (seq->tete->command == '}')
    {
        elt.tete_bloc = NULL; // indique a la pile qu'il n'y aura rien a executer
        elt.contenu = BLOC;
        empiler(pile, elt);
        p_tmp = NULL;
        return;
    }
    /* Fin cas bloc de commandes vide */

    /* Empiler l'adresse de la tete du bloc */
    elt.tete_bloc = seq->tete;
    elt.contenu = BLOC;
    empiler(pile, elt);

    /* Isoler le bloc de commandes (supporte aussi les blocs imbriques) */
    p_tmp = seq->tete;
    while (((p_tmp->suivant->command != '}') || (nb_acco != 1)) || (p_tmp->command == '{'))
    {
        if (p_tmp->command == '{')
        {
            nb_acco++;
        }
        if (p_tmp->command == '}')
        {
            nb_acco--;
        }
        p_tmp = p_tmp->suivant;
    }
    seq->tete = p_tmp->suivant;
    p_tmp->suivant = NULL;
    p_tmp = NULL;
}

int interprete(sequence_t *seq, bool debug)
{

    char commande;
    debug = true; /* À enlever par la suite et utiliser "-d" sur la ligne de commandes */

    printf("Programme:");
    afficher(seq);
    printf("\n");
    if (debug)
        stop();

    cellule_t *p_tmp = seq->tete;
    PILE pile = {0, {}};
    ELT_PILE elt; // utilise pour empiler
    ELT_PILE elt2, elt3;
    int arg; // utilise pour les valeurs d'entree
    int ret; // utilise pour les valeurs de retour
    /* utilise pour repousser l'actualisation de la tete de la sequence
       (en cas d'ajout en tete durant la boucle d'execution) */
    int delai = 0;

    while (seq->tete != NULL)
    {
        /*
            On execute toujours la commande de la cellule en tete de la sequence.
            Une fois la commande executee, la cellule suivante devient la nouvelle tete
            et on libere l'ancienne tete.
        */

        commande = seq->tete->command; // commande a executer

        /* Execution de la commande */
        switch (commande)
        {
        case 'A':
            ret = avance();
            if (ret == VICTOIRE)
            {
                detruireCellule(seq->tete); // detruire la queue avant de partir
                seq->tete = NULL;           // ne pas pointer vers une memoire liberee
                return VICTOIRE;
            }
            if (ret == RATE)
            {
                detruireCellule(seq->tete); // meme chose ici
                seq->tete = NULL;
                return RATE;
            }
            break;

        case 'G':
            gauche();
            break;

        case 'D':
            droite();
            break;

        case 'P':
            elt = depiler(&pile);
            arg = elt.entier;
            pose(arg);
            break;

        case 'M':
            elt = depiler(&pile);
            arg = elt.entier;

            elt.entier = mesure(arg);
            elt.contenu = ENTIER;
            empiler(&pile, elt);
            break;

        case 'C':
            elt = depiler(&pile);
            if (elt.contenu == ENTIER)
            {
                empiler(&pile, elt);
                empiler(&pile, elt);
            }
            else
            {
                elt2.tete_bloc = copier_sequence(elt.tete_bloc);
                elt2.contenu = BLOC;
                empiler(&pile, elt);
                empiler(&pile, elt2);
            }
            break;

        case 'I':
            depiler(&pile);
            break;

        case 'X':
            elt = depiler(&pile);
            elt2 = depiler(&pile);
            empiler(&pile, elt);
            empiler(&pile, elt2);
            break;

        case '{':
            gerer_bloc_cmd(seq, &pile);
            break;

        case '!':
            elt = depiler(&pile);
            ajout_en_tete(seq, elt);
            delai = 1;
            break;

        case '?':
            /* Depiler les arguments */
            elt3 = depiler(&pile); // contient une adresse vers un bloc
            elt2 = depiler(&pile); // contient une adresse vers un bloc
            elt = depiler(&pile);  // contient un entier

            printf("Arguments depiles\n");

            /* Ajouter le bloc a executer dans la sequence. Detruire l'autre. */
            if (elt.entier != 0)
            {
                ajout_en_tete(seq, elt2);
                printf("ajout en tete\n");
                detruireSequence(elt3.tete_bloc);
                printf("bloc detruit\n");
            }
            else
            {
                ajout_en_tete(seq, elt3);
                printf("ajout en tete\n");
                detruireSequence(elt2.tete_bloc);
                printf("bloc detruit\n");
            }
            elt2.tete_bloc = NULL;
            elt3.tete_bloc = NULL;
            delai = 1;
            break;

        case '+':
            additionner(&pile);
            break;

        case '-':
            soustraire(&pile);
            break;

        case '*':
            multiplier(&pile);
            break;

        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            elt.entier = commande - '0';
            elt.contenu = ENTIER;
            empiler(&pile, elt);
            break;

        case ' ':
        case '\n':
            break;
        case 'B':
            boucle(&pile, &commande);
            break;

        default:
            eprintf("Caractère inconnu: '%c'\n", commande);
        }

        if (delai == 0)
        {
            /* Actualisation de la tete de la sequence */
            p_tmp = seq->tete;              // ne pas perdre la tete a liberer
            seq->tete = seq->tete->suivant; // nouvelle tete
            detruireCellule(p_tmp);         // liberer l'ancienne tete
            p_tmp = NULL;
        }
        else
        {
            delai = 0;
        }

        /* Affichage pour faciliter le debug */
        for (int i = 0; i < 10; i++)
        {
            printf("\n");
        }
        afficherCarte();
        afficher_pile(&pile);
        printf("\nProgramme:");
        afficher(seq);
        printf("\n");
        if (debug)
            stop();
    }

    return CIBLERATEE;
}
