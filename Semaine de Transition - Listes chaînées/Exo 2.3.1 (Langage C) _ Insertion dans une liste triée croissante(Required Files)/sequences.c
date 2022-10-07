#include <stdlib.h>
#include <stdio.h>
#include "sequences.h"

/* lecture d'une sequence d'entiers.
  En entrée : des entiers (-1 pour finir)*/
void saisir(liste_t *l, int valeurMin) {
  int n=-1;
  cellule_t *c;
  printf("Donner un entier (un entier négatif pour finir) :\n");
  scanf("%d",&n);
  if (n>=valeurMin) {
    c = (cellule_t *) malloc(sizeof(cellule_t));  
    c->valeur = n;
    c->suivant = NULL;  
    l->tete = c;
    valeurMin = n;
    printf("Donner un entier (un entier moins grand pour finir) :\n");
    scanf("%d",&n);
    while (n>=valeurMin) {
      c->suivant = (cellule_t *) malloc(sizeof(cellule_t));
      c = c->suivant;
      c->valeur = n;
      c->suivant = NULL;  
      valeurMin = n;
      printf("Donner un entier (un entier moins grand pour finir) :\n");
      scanf("%d",&n);}}
  else {
    l->tete = NULL;}
return;}

/* Affichage d'une sequence d'entiers.
  En  sortie : un espace entre deux entiers */
void afficher(liste_t l) {
  cellule_t *c;
  if (l.tete==NULL) {
    printf("\n");}
  else {
    c = l.tete;
    while (c!=NULL) {
      printf(" %d",c->valeur);
      c = c->suivant;}
    printf("\n");}
return;}

/* insertion dans une sequence triée */
void insertion(liste_t *l, int n) {
  /* votre code ici */
return;}
