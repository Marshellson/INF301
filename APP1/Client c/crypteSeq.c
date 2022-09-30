/*
 * @Author: ThearchyHelios
 * @Date: 2022-09-26 09:08:43
 * @LastEditTime: 2022-09-30 09:00:53
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

void crypteSequence(char *message, char *messageDecrypte)
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
        booleanTemp = 1; // si n'existe pas

        for (x = 0; x < longueurSequence; x++)
        {
            if (l == sequence[x]) // si existe
            {
                booleanTemp = 0;
                indiceCase = x; // on stocke num de sa case
            }
        }
        if (booleanTemp)
        { // if la premiere fois que cette lettre (a) apparait, on va l'ajtxt_decryer à la fin nde sequence et de messageDecrypte
            sequence[longueurSequence] = l;
            longueurSequence++;
            messageDecrypte[longueurTableau] = l;
            longueurTableau++;
        }
        else
        { // si la lettre existe (a) deja en sequence, on prend lettre qui la precede et l'ajtxt_decrye à fin messageDecrypte, puis on la rend au debut de sequence
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
            { // si a n'existe pas à la fin de sequence
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

    int a, b;
    int longueurMessage, longueurSequence, longueurTableau;
    char sequence[10000];

    int indicesMessage = 83;
    char caractre = rep[indicesMessage];

    longueurSequence = 0;
    longueurTableau = 0;
    sequence[longueurSequence] = caractre;
    longueurSequence++;
    messageDecrypte[longueurTableau] = caractre;
    longueurTableau++;
    longueurMessage = strlen(rep);
    int indiceCase;
    int booleanTemp;
    for (b = 83; b < longueurMessage; b++)
    {
        indicesMessage++;
        caractre = rep[indicesMessage];
        booleanTemp = 1;
        for (a = 0; a < longueurSequence; a++)
        {
            if (caractre == sequence[a])
            {
                booleanTemp = 0;
                indiceCase = a;
            }
        }
        if (booleanTemp)
        {
            sequence[longueurSequence] = caractre;
            longueurSequence++;
            messageDecrypte[longueurTableau] = caractre;
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
                    caractre = sequence[indiceCase];
                    for (a = indiceCase; a < longueurSequence - 1; a++)
                    {
                        sequence[a] = sequence[a + 1];
                    }
                    sequence[longueurSequence - 1] = caractre;
                }
            }
            else
            {
                caractre = sequence[0];
                for (a = 0; a < longueurSequence - 1; a++)
                {
                    sequence[a] = sequence[a + 1];
                }
                sequence[longueurSequence - 1] = caractre;
            }
        }
    }
}

void decrypteMove(char *rep, char *msg)
{
    int x, y;
    int len, a;
    char tableau[MAXMSG];
    int mod, indicesMessage;
    char txt[MAXREP];

    len = strlen(rep);
    for (x = 0; x < len; x++)
    {
        txt[x] = rep[x];
    }

    a = len;
    indicesMessage = len - 1;

    for (y = 0; y < a; y++)
    {
        mod = txt[indicesMessage] % 8; // mod de dernier caractere de text à decrypter
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
        tableau[len] = txt[indicesMessage];
        len = strlen(tableau);
        indicesMessage--;
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
    char messageDecrypte[MAXREP];
    char messageDecrypte2[MAXREP];

    mode_debug(true);

    connexion("im2ag-appolab.u-ga.fr", 9999);
    envoyer_recevoir("login 12100255 JIANG", rep);
    envoyer_recevoir("load crypteSeq", rep);
    envoyer_recevoir("Alice, nous avons besoin de toi. Decode mon msg au plus vite. Bob", rep);
    envoyer_recevoir("start", rep);

    decrypteMove(rep, msg);         // decryptage par methode crypteMove
    crypteSequence(msg, messageDecrypte); // encrypter par methode cryptesequence
    envoyer_recevoir(messageDecrypte, rep);
    decrypteSequence(rep, messageDecrypte2); // decryptage par methode de cryptesequence
    envoyer_recevoir(messageDecrypte2, rep);

    printf("Fin de la connection au serveur\n");
    return 0;
}