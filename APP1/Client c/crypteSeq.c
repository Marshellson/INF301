/*
 * @Author: ThearchyHelios
 * @Date: 2022-09-26 09:08:43
 * @LastEditTime: 2022-09-30 08:19:32
 * @LastEditors: ThearchyHelios
 * @Description:
 * @FilePath: /APP1/Client c/crypteSeq.c
 */
#include "client.h"
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

#define MAXMSG MAXREP

void cryptesequence(char *message, char *txt_decry)
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
        trueOrFalse = 1; // si n'existe pas

        for (x = 0; x < seque_longueur; x++)
        {
            if (l == sequence[x]) // si existe
            {
                trueOrFalse = 0;
                indice_C = x; // on stocke num de sa case
            }
        }
        if (trueOrFalse)
        { // if la premiere fois que cette lettre (a) apparait, on va l'ajtxt_decryer à la fin nde sequence et de txt_decry
            sequence[seque_longueur] = l;
            seque_longueur++;
            txt_decry[longueur_tableau] = l;
            longueur_tableau++;
        }
        else
        { // si la lettre existe (a) deja en sequence, on prend lettre qui la precede et l'ajtxt_decrye à fin txt_decry, puis on la rend au debut de sequence
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
            { // si a n'existe pas à la fin de sequence
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

    int a, b;
    int txt_longeur, seque_longueur, longueur_tableau;
    char sequence2[10000];

    int indices_text = 83;
    char carac = rep[indices_text];

    seque_longueur = 0;
    longueur_tableau = 0;
    sequence2[seque_longueur] = carac;
    seque_longueur++;
    txt_decry2[longueur_tableau] = carac;
    longueur_tableau++;
    txt_longeur = strlen(rep);
    int indice_C;
    int trueOrFalse;
    for (b = 83; b < txt_longeur; b++)
    {
        indices_text++;
        carac = rep[indices_text];
        trueOrFalse = 1;
        for (a = 0; a < seque_longueur; a++)
        {
            if (carac == sequence2[a])
            {
                trueOrFalse = 0;
                indice_C = a;
            }
        }
        if (trueOrFalse)
        {
            sequence2[seque_longueur] = carac;
            seque_longueur++;
            txt_decry2[longueur_tableau] = carac;
            longueur_tableau++;
        }
        else
        {
            if (indice_C != seque_longueur - 1)
            {
                txt_decry2[longueur_tableau] = sequence2[indice_C + 1];
                longueur_tableau++;
            }
            else
            {
                txt_decry2[longueur_tableau] = sequence2[0];
                longueur_tableau++;
            }

            if (indice_C != seque_longueur - 1)
            {
                if (indice_C + 1 != seque_longueur - 1)
                {

                    indice_C++;
                    carac = sequence2[indice_C];
                    for (a = indice_C; a < seque_longueur - 1; a++)
                    {
                        sequence2[a] = sequence2[a + 1];
                    }
                    sequence2[seque_longueur - 1] = carac;
                }
            }
            else
            {
                carac = sequence2[0];
                for (a = 0; a < seque_longueur - 1; a++)
                {
                    sequence2[a] = sequence2[a + 1];
                }
                sequence2[seque_longueur - 1] = carac;
            }
        }
    }
}

void decrypteMove(char *rep, char *msg)
{
    int x, y;
    int len, a;
    char tableau[MAXMSG];
    int mod, indices_text;
    char txt[MAXREP];

    len = strlen(rep);
    for (x = 0; x < len; x++)
    {
        txt[x] = rep[x];
    }

    a = len;
    indices_text = len - 1;

    for (y = 0; y < a; y++)
    {
        mod = txt[indices_text] % 8; // mod de dernier caractere de text à decrypter
        len = strlen(tableau);

        if (mod != 0 && mod < len)
        {
            for (x = 0; x < mod; x++)
            {

                tableau[len] = tableau[x]; // pour x=mod, prendre les x premiers elements et les deplacer à la fin
                len = strlen(tableau);
            }

            for (x = 0; x < len; x++)
            {
                if (x < len - mod)
                {
                    tableau[x] = tableau[x + mod];
                }
                else
                {
                    tableau[x] = '\0';
                }
            }
        }
        len = strlen(tableau);
        tableau[len] = txt[indices_text];
        len = strlen(tableau);
        indices_text--;
    }
    for (x = 0; x < len; x++)
    {
        msg[x] = tableau[len - 1 - x];
    }
}

int main()
{
    char rep[MAXREP]; // pour stocker la rÃ©ponse du serveur
    char msg[MAXMSG]; // pour stocker le msg Ã  envoyer au serveur
    char txt_decry[MAXREP];
    char txt_decry2[MAXREP];

    mode_debug(true);

    connexion("im2ag-appolab.u-ga.fr", 9999);
    envoyer_recevoir("login 12100255 JIANG", rep);
    envoyer_recevoir("load crypteSeq", rep);
    envoyer_recevoir("Alice, nous avons besoin de toi. Decode mon msg au plus vite. Bob", rep);
    envoyer_recevoir("start", rep);

    decrypteMove(rep, msg);         // decryptage par methode crypteMove
    cryptesequence(msg, txt_decry); // encrypter par methode cryptesequence
    envoyer_recevoir(txt_decry, rep);
    decrypteSeq(rep, txt_decry2); // decryptage par methode de cryptesequence
    envoyer_recevoir(txt_decry2, rep);

    printf("Fin de la connection au serveur\n");
    return 0;
}