/*
 * @Author: ThearchyHelios
 * @Date: 2022-10-07 08:49:25
 * @LastEditTime: 2022-10-07 10:49:54
 * @LastEditors: ThearchyHelios
 * @Description: 
 * @FilePath: /INF301/Semaine de Transition - Listes chaînées/Exo 2.3.1 (Langage C) _ Insertion dans une liste triée croissante(Required Files)/principal_liste.c
 */
#include <stdio.h>
#include "sequences.h"

/* A Faire (dans le fichier sequences.c) :
  - implémenter l'insertion d'un entier dans une sequence triée croissante
      sur la structure de données définie dans sequences.h (liste chainée)
  - tester (ajout éventuel de cas de test dans le fichier usr_evaluate.cases),
                                                     */

/*             A priori : ne rien changer ci-dessous
            (ou changer les jeux de test en conséquence)                      */

/* Programme principal (de test) */
int main()
{
    int n;
    liste_t l;
    l.tete = NULL;

    printf("Donner une sequence d'entiers positifs croissante\n\n");
    saisir(&l, 0);
    printf("Donner un entier à inserer \n\n");
    scanf("%d", &n);
    insertion(&l, n);
    printf("Résultat : ");
    afficher(l);
    return 0;
}
