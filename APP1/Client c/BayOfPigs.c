/*
 * @Author: ThearchyHelios
 * @Date: 2022-09-30 08:13:04
 * @LastEditTime: 2022-09-30 08:20:17
 * @LastEditors: ThearchyHelios
 * @Description:
 * @FilePath: /APP1/Client c/BayOfPigs.c
 */
#include "client.h"
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

#define MAXMSG MAXREP

void inverse(char *TXT, int x)
{
    char k[MAXREP];
    int j = 0;
    int TXTlen = strlen(TXT);
    for (int l = TXTlen - x; l <= TXTlen; l++)
    {
        k[l] = TXT[j];
        j++;
    }
    j = 0;
    for (int a = x; a < TXTlen; a++)
    {
        k[a] = TXT[j];
        j++;
    }
    k[TXTlen] = '\0';
    strcpy(TXT, k);
}

void elem(char *TXT, char *ENC)
{
    char k[MAXREP];
    int ENClen = strlen(ENC);
    k[0] = ENC[ENClen - 1];
    ENC[ENClen - 1] = '\0';
    for (unsigned long j = 0; j <= strlen(TXT); j++)
    {
        k[j + 1] = TXT[j];
    }

    strcpy(TXT, k);
}

int main()
{

    char reponse[MAXREP]; // pour stocker la réponse du serveur
    // char message[MAXMSG]; // pour stocker le message à envoyer au serveur
    //  Affiche les échanges avec le serveur (false pour désactiver)
    mode_debug(true);

    // Connexion au serveur AppoLab
    connexion("im2ag-appolab.u-ga.fr", 9999);
    // utilisez le port 443 en cas de problème sur le 9999
    /* connexion("im2ag-appolab.u-ga.fr", 443); */

    // Remplacez <identifiant> et <tab de passe> ci dessous.

    envoyer_recevoir("login 12100255 JIANG", reponse);
    printf("%s\n", reponse);
    envoyer_recevoir("load BayOfPigs", reponse);
    envoyer_recevoir("help", reponse);
    envoyer_recevoir("start", reponse);
    envoyer_recevoir("Par otuam eriet", reponse);

    char TXT[MAXMSG];
    char ENC[MAXMSG];

    TXT[0] = '\0';
    strcpy(ENC, reponse);
    int ENClen = strlen(ENC);
    int TXTlen = strlen(TXT);
    int d = ENC[ENClen - 1];
    int i = d % 8;

    while (strlen(ENC) != 0)
    {
        TXTlen = strlen(TXT);
        if (i <= TXTlen)
        {
            inverse(TXT, i);
        }
        elem(TXT, ENC);
        ENClen = strlen(ENC);
        d = ENC[ENClen - 1];
        i = i % 8;
    }

    envoyer_recevoir(TXT, reponse);
    return 0;
}
