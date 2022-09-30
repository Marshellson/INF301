/*
 * @Author: ThearchyHelios
 * @Date: 2022-09-30 08:25:17
 * @LastEditTime: 2022-09-30 08:59:29
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

void crypteSeq(char *message, char *messageDecrypte)
{
  char sequence[10000];
  int x, y;
  int l;
  int indiceCase, longueurMessage, longueurSequence, longueurTableau, indicesMessage;

  indicesMessage = 0;
  l = message[indicesMessage];
  longueurSequence = 0;
  longueurTableau = 0;
  sequence[longueurSequence] = l;
  longueurSequence++;
  messageDecrypte[longueurTableau] = l;
  longueurTableau++;
  longueurMessage = strlen(message);
  int booleanTemp;

  for (y = 0; y < longueurMessage; y++)
  {
    indicesMessage++;
    l = message[indicesMessage];
    booleanTemp = 1;

    for (x = 0; x < longueurSequence; x++)
    {
      if (l == sequence[x])
      {
        booleanTemp = 0;
        indiceCase = x;
      }
    }
    if (booleanTemp)
    {
      sequence[longueurSequence] = l;
      longueurSequence++;
      messageDecrypte[longueurTableau] = l;
      longueurTableau++;
    }
    else
    {
      if (indiceCase != 0)
      {
        messageDecrypte[longueurTableau] = sequence[indiceCase - 1];
        longueurTableau++;
      }

      else
      {
        messageDecrypte[longueurTableau] = sequence[longueurSequence - 1];
        longueurTableau++;
      }

      if (indiceCase != longueurSequence - 1)
      {
        for (x = indiceCase; x < longueurSequence - 1; x++)
        {
          sequence[x] = sequence[x + 1];
        }
        sequence[longueurSequence - 1] = l;
      }
    }
  }
}

void decrypteSequence(char *rep, char *messageDecrypte)
{

  int x, y;
  char carac;
  int indiceCase, booleanTemp, longueurMessage, longueurSequence, longueurTableau, indiceMessage;
  char sequence[10000];

  indiceMessage = 0;
  carac = rep[indiceMessage];
  longueurSequence = 0;
  longueurTableau = 0;
  sequence[longueurSequence] = carac;
  longueurSequence++;
  messageDecrypte[longueurTableau] = carac;
  longueurTableau++;
  longueurMessage = strlen(rep);

  for (y = 0; y < longueurMessage; y++)
  {
    indiceMessage++;
    carac = rep[indiceMessage];
    booleanTemp = 1;
    for (x = 0; x < longueurSequence; x++)
    {
      if (carac == sequence[x])
      {
        booleanTemp = 0;
        indiceCase = x;
      }
    }
    if (booleanTemp)
    {
      sequence[longueurSequence] = carac;
      longueurSequence++;
      messageDecrypte[longueurTableau] = carac;
      longueurTableau++;
    }
    else
    {
      if (indiceCase != longueurSequence - 1)
      {
        messageDecrypte[longueurTableau] = sequence[indiceCase + 1];
        longueurTableau++;
      }
      else
      {
        messageDecrypte[longueurTableau] = sequence[0];
        longueurTableau++;
      }
      if (indiceCase != longueurSequence - 1)
      {
        if (indiceCase + 1 != longueurSequence - 1)
        {
          indiceCase++;
          carac = sequence[indiceCase];
          for (x = indiceCase; x < longueurSequence - 1; x++)
          {
            sequence[x] = sequence[x + 1];
          }
          sequence[longueurSequence - 1] = carac;
        }
      }
      else
      {
        carac = sequence[0];
        for (x = 0; x < longueurSequence - 1; x++)
        {
          sequence[x] = sequence[x + 1];
        }
        sequence[longueurSequence - 1] = carac;
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
  char messageDecrypte[MAXREP];
  char messageDecrypte2[MAXREP];
  char mot_de_pass2[200] = "There will be no Nineteen Eighty-Four";
  char tableau[MAXREP];

  mode_debug(true);

  connexion("im2ag-appolab.u-ga.fr", 9999);
  envoyer_recevoir("login 12100255 JIANG", rep);
  envoyer_recevoir("load Northwoods", rep);
  envoyer_recevoir("ok", rep);
  envoyer_recevoir("start", rep);
  envoyer_recevoir("hasta la victoria siempre", rep);
  decrypteSequence(rep, messageDecrypte);

  longueur = strlen(messageDecrypte);
  for (x = longueur - 29; x < longueur - 9; x++)
  {
    mot_de_pass[x - longueur + 29] = messageDecrypte[x];
  }

  envoyer_recevoir(mot_de_pass, rep);
  crypteSeq(mot_de_pass2, messageDecrypte2);
  envoyer_recevoir(messageDecrypte2, rep);
  longueur = strlen(rep);
  for (x = 24; x < longueur; x++)
  {
    tableau[x - 24] = rep[x];
  }

  decrypteSequence(tableau, messageDecrypte);
  envoyer_recevoir(messageDecrypte, rep);

  return 0;
}