#include "client.h"
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

#define MAXMSG MAXREP

int main()
{
    char reponse[MAXREP];
    char message[MAXMSG];

    // Affiche les échanges avec le serveur (false pour désactiver)
    mode_debug(true);

    puts("Bienvenue dans cette introduction à AppoLab !\n"
         "AppoLab est un serveur d'exercices algorithmiques que vous allez devoir \n"
         "utiliser pour vos APPs. Je vais vous guider pas à pas pour que vous \n"
         "puissiez vous débrouiller tout·e seul·e.");

    puts("Le client va maintenant tenter de se connecter automatiquement au serveur \n"
         "AppoLab. Il vous faut bien entendu pour cela une connection internet.\n"
         "(En cas de problème, modifiez le fichier client-introduction.c pour \n"
         "utiliser le port 443 au lieu de 9999 sur la ligne 'connexion'.)");

    // Connexion au serveur AppoLab
    connexion("im2ag-appolab.u-ga.fr", 9999);
    /* connexion("im2ag-appolab.u-ga.fr", 443); */

    puts("Si tout va bien, vous devez avoir reçu le message de bienvenue d'AppoLab.\n"
         "Si non, arrêtez ce programme (avec Ctrl-C) et demandez de l'aide à un·e enseignant·e.\n"
         "(Si vous avez des difficultés à lire certains messages, modifiez les couleurs dans client.h et recompilez.)");

    puts("Comme indiqué, commencez par vous loguer avec l'identifiant et le mot de \n"
         "passe qui vous ont été fournis. Pour les étudiants d'INF301, le login est\n"
         "votre numéro d'étudiant·e, et le mot de passe votre nom en majuscule.\n"
         "Entrez les au clavier ainsi :\n"
         "login 12345678 \"MOT DE PASSE\"");

    strcpy(message, "login 12100255 JIANG");
    envoyer_recevoir(message, reponse);

    puts("Bravo, vous venez de vous identifier auprès du serveur !\n"
         "Comme vous pouvez le voir ce programme trace tout ce que vous envoyez au \n"
         "serveur sur les lignes commençant par <<<envoi<<<, et tout ce que répond le \n"
         "serveur sur des lignes commençant par >>>recu >>>.");

    puts("Vous êtes maintenant prêt·e à lancer le premier exercice qui se nomme 'tutoriel'.\n"
         "Lancez le grâce à la commande 'load' ainsi :\n"
         "load tutoriel");

    strcpy(message, "load tutoriel");
    envoyer_recevoir(message, reponse);

    puts("Voilà, vous venez de lancer votre premier exercice...\n"
         "Suivez les consignes de l'exercice maintenant.");

    strcpy(message, "help");
    envoyer_recevoir(message, reponse);

    strcpy(message, "start");
    envoyer_recevoir(message, reponse);

    strcpy(message, "oui");
    envoyer_recevoir(message, reponse);

    strcpy(message, "4");
    envoyer_recevoir(message, reponse);

    strcpy(message, "blanc");
    envoyer_recevoir(message, reponse);

    strcpy(message, "Pincemoi");
    envoyer_recevoir(message, reponse);

    strcpy(message, "tutoriel");
    envoyer_recevoir(message, reponse);

    attendre();

    return 0;
}
