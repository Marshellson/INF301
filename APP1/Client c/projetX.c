/*
 * @Author: ThearchyHelios
 * @Date: 2022-09-15 21:20:05
 * @LastEditTime: 2022-09-23 00:44:01
 * @LastEditors: ThearchyHelios
 * @Description:
 * @FilePath: /APP1/Client c/client-interactif.c
 */
#include "client.h"
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

#define MAXMSG MAXREP

int main()
{

    char *serveur = "im2ag-appolab.u-ga.fr";
    int port = 9999;

    char reponse[MAXREP];
    char message[MAXMSG];

    mode_debug(true);

    puts("Bienvenue dans le client interactif d'AppoLab");
    puts("Connection à AppoLab dans le client interactif d'AppoLab ...");

    // Connexion au serveur AppoLab
    connexion(serveur, port);

    strcpy(message, "login 12100255 JIANG");
    envoyer_recevoir(message, reponse);

    strcpy(message, "load projetX");
    envoyer_recevoir(message, reponse);

    strcpy(message, "help");
    envoyer_recevoir(message, reponse);

    strcpy(message, "depart");
    envoyer_recevoir(message, reponse);

    strcpy(message, "veni vidi vici");
    envoyer_recevoir(message, reponse);

    strcpy(message, "load crypteMove");
    envoyer_recevoir(message, reponse);

    return 0;
}
