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

int main() {
	/*	!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		!!! Éviter le plus possible de modifier ce fichier !!!
		!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

		Modifications autorisées :
			* login et mdp

		modifiez les variables ci-dessous: mettez vos identifiant et mot de passe
	 */
	char *login = "12100255";
	char *mdp = "JIANG";
	char *serveur = "im2ag-appolab.u-ga.fr";
	int port = 9999;
	// En cas de problème de connexion, essayer sur le port 443 au lieu de 9999
	/* int port = 443; */

	/*	######################################
		#  NE PLUS RIEN MODIFIER CI-DESSOUS  #
		######################################
	 */

	char reponse[MAXREP];
	char message[MAXMSG];

	mode_debug(true);

	puts("Bienvenue dans le client interactif d'AppoLab");
	puts("Connection à AppoLab dans le client interactif d'AppoLab ...");

	// Connexion au serveur AppoLab
	connexion(serveur, port);

	// LOGIN
	if (strcmp(login, "<login>") || strcmp(mdp, "<mot de passe>")) {
	    printf("Identification de %s ...\n", login);
	    char user_logs[256];
	    snprintf(user_logs, sizeof user_logs, "%s %s %s", "login", login, mdp);
	    envoyer_recevoir(user_logs, reponse);
	    prefix_print(stderr, COL_RECU, reponse);
	} else {
	    puts("Identifiez vous maintenant (login <login> <mot de passe>)");
	}

	// Interaction
	bool quit = false;
	while (!quit) {
	    int ret;
	    printf ("> ");
	    fflush (stdout);

	    if (!fgets (message, MAXMSG, stdin)) {
	        break;
	    }
	    if (!strcmp(message, "quit")) {
	        quit = true;
	        puts("bye bye...");
	    } else {
	        ret = envoyer_recevoir(message, reponse);
	        prefix_print(stderr, COL_RECU, reponse);
	        if (ret < 0) {break;}
	    }
	}

	// strcpy(message, "login 12100255 JIANG");
	// envoyer_recevoir(message, reponse);

	// strcpy(message, "load projetX");
	// envoyer_recevoir(message, reponse);

	// strcpy(message, "help");
	// envoyer_recevoir(message, reponse);

	// strcpy(message, "depart");
	// envoyer_recevoir(message, reponse);

	// strcpy(message, "veni vidi vici");
	// envoyer_recevoir(message, reponse);

	// strcpy(message, "load crypteMove");
	// envoyer_recevoir(message, reponse);

	// attendre();

	return 0;
}
