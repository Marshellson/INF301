/*
 * @Author: ThearchyHelios
 * @Date: 2022-09-30 08:25:17
 * @LastEditTime: 2022-09-30 08:25:18
 * @LastEditors: ThearchyHelios
 * @Description:
 * @FilePath: /APP1/Client c/northwoods.c
 */
#include "client.h"
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

#define MAXMSG MAXREP

void crypteSeq(char *message, char *txt_decry)
{
  char sequence[10000];
  int x, y;
  int l;
  int indice_C, txt_longeur, seque_longueur, longueur_tableau, indices_text;

  indices_text = 0;
  l = message[indices_text];
  seque_longueur = 0;
  longueur_tableau = 0;
  sequence[seque_longueur] = l;
  seque_longueur++;
  txt_decry[longueur_tableau] = l;
  longueur_tableau++;
  txt_longeur = strlen(message);
  int trueOrFalse;

  for (y = 0; y < txt_longeur; y++)
  {
    indices_text++;
    l = message[indices_text];
    trueOrFalse = 1;

    for (x = 0; x < seque_longueur; x++)
    {
      if (l == sequence[x])
      {
        trueOrFalse = 0;
        indice_C = x;
      }
    }
    if (trueOrFalse)
    {
      sequence[seque_longueur] = l;
      seque_longueur++;
      txt_decry[longueur_tableau] = l;
      longueur_tableau++;
    }
    else
    {
      if (indice_C != 0)
      {
        txt_decry[longueur_tableau] = sequence[indice_C - 1];
        longueur_tableau++;
      }

      else
      {
        txt_decry[longueur_tableau] = sequence[seque_longueur - 1];
        longueur_tableau++;
      }

      if (indice_C != seque_longueur - 1)
      {
        for (x = indice_C; x < seque_longueur - 1; x++)
        {
          sequence[x] = sequence[x + 1];
        }
        sequence[seque_longueur - 1] = l;
      }
    }
  }
}

void decrypteSeq(char *rep, char *txt_decry2)
{

  int x, y;
  char carac;
  int indice_C, trueOrFalse, txt_longueur, seq_longueur, tableau_longueur, indice_txt;
  char sequence2[10000];

  indice_txt = 0;
  carac = rep[indice_txt];
  seq_longueur = 0;
  tableau_longueur = 0;
  sequence2[seq_longueur] = carac;
  seq_longueur++;
  txt_decry2[tableau_longueur] = carac;
  tableau_longueur++;
  txt_longueur = strlen(rep);

  for (y = 0; y < txt_longueur; y++)
  {
    indice_txt++;
    carac = rep[indice_txt];
    trueOrFalse = 1;
    for (x = 0; x < seq_longueur; x++)
    {
      if (carac == sequence2[x])
      {
        trueOrFalse = 0;
        indice_C = x;
      }
    }
    if (trueOrFalse)
    {
      sequence2[seq_longueur] = carac;
      seq_longueur++;
      txt_decry2[tableau_longueur] = carac;
      tableau_longueur++;
    }
    else
    {
      if (indice_C != seq_longueur - 1)
      {
        txt_decry2[tableau_longueur] = sequence2[indice_C + 1];
        tableau_longueur++;
      }
      else
      {
        txt_decry2[tableau_longueur] = sequence2[0];
        tableau_longueur++;
      }
      if (indice_C != seq_longueur - 1)
      {
        if (indice_C + 1 != seq_longueur - 1)
        {
          indice_C++;
          carac = sequence2[indice_C];
          for (x = indice_C; x < seq_longueur - 1; x++)
          {
            sequence2[x] = sequence2[x + 1];
          }
          sequence2[seq_longueur - 1] = carac;
        }
      }
      else
      {
        carac = sequence2[0];
        for (x = 0; x < seq_longueur - 1; x++)
        {
          sequence2[x] = sequence2[x + 1];
        }
        sequence2[seq_longueur - 1] = carac;
      }
    }
  }
}

int main()
{
  char rep[MAXREP];
  int longueur;
  int x;
  char mot_de_pass[100];
  char txt_decry[MAXREP];
  char txt_decry2[MAXREP];
  char mot_de_pass2[200] = "There will be no Nineteen Eighty-Four";
  char tableau[MAXREP];

  mode_debug(true);

  connexion("im2ag-appolab.u-ga.fr", 9999);
  envoyer_recevoir("login 12100255 JIANG", rep);
  envoyer_recevoir("load Northwoods", rep);
  envoyer_recevoir("ok", rep);
  envoyer_recevoir("start", rep);
  envoyer_recevoir("hasta la victoria siempre", rep);
  decrypteSeq(rep, txt_decry);

  longueur = strlen(txt_decry);
  for (x = longueur - 29; x < longueur - 9; x++)
  {
    mot_de_pass[x - longueur + 29] = txt_decry[x];
  }

  envoyer_recevoir(mot_de_pass, rep);
  crypteSeq(mot_de_pass2, txt_decry2);
  envoyer_recevoir(txt_decry2, rep);
  longueur = strlen(rep);
  for (x = 24; x < longueur; x++)
  {
    tableau[x - 24] = rep[x];
  }

  decrypteSeq(tableau, txt_decry);
  envoyer_recevoir(txt_decry, rep);

  return 0;
}