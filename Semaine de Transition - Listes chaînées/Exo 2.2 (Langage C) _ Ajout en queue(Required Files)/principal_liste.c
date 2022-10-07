#include <stdio.h>
#include "sequences.h"

/* A Faire (dans le fichier sequences.c) : 
  - implémenter l'ajout en queue d'une séquence
      sur la structure de données définie dans sequences.h (liste chainée)
  - tester (ajout éventuel de cas de test dans le fichier usr_evaluate.cases), 
                                                     */


/*             A priori : ne rien changer ci-dessous 
            (ou changer les jeux de test en conséquence)                      */


/* Programme principal (de test) */
int main() {
int n;
liste_t l;
l.tete = NULL;


printf("Donner une sequence d'entiers positifs (un entier négatif pour finir)\n\n");
saisir(&l,0);
printf("Donner un entier à ajouter \n\n");
scanf("%d",&n);
ajout_en_queue(&l,n);
printf("Résultat : ");
afficher(l);
return 0;}
