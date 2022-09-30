/*
 * @Author: ThearchyHelios
 * @Date: 2022-09-19 09:16:04
 * @LastEditTime: 2022-09-26 09:31:44
 * @LastEditors: ThearchyHelios
 * @Description:
 * @FilePath: /APP1/Client c/crypemove_essayer.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include "client.h"

#define MAXMSG MAXREP

int algoCrypteMove(char TXT[], char ENC[])
{
    int lenTXT = strlen(TXT);
    // Contient la position du caractère à ajouter dans le tableau encodé
    int avancementENC = 0;
    // Contient la position de la première lettre dans le tableau TXT
    int position_start = 0;
    // Contient la position de la dernière lettre dans le tableau TXT
    int position_finish = lenTXT - 1;

    char X;

    // Tant qu’il reste des lettres dans le texte à chiffrer
    while (position_finish >= position_start)
    {
        // Concatène la lettre première lettre de TXT à ENC
        ENC[avancementENC] = TXT[position_start];
        // Pour ne plus prendre en compte le caractère ajouté à ENC
        position_start++;
        // Calcul de X, à partir de la lettre concaténée à ENC
        X = ENC[avancementENC] % 8;
        // Ajoute 1 à la taille du texte Encodé pour pouvoir concaténer au bonne endroit les futurs lettres
        avancementENC++;

        if (X > 0 && ((position_finish - position_start) >= X))
        {
            // nb cases disponible avant = position_start
            // Si assez de place pour stocker la fin de la chaine au début du tableau
            if (position_start >= (position_finish - (position_start + X - 1)))
            {
                // Initialisation compteur j, pour déplacer les élément de fin de chaine de caractère au début
                int j = position_start + X;
                // Calcul nouvelle position start de la chaine de caractère
                position_start -= position_finish - (position_start + X - 1);
                // Calcul la nouvelle position final de la chaine de caractère
                position_finish = j - 1;
                // Boucle pour placer les X caractères finaux au début de la chaine
                for (int i = position_start; i < (position_finish - X + 1); i++)
                {
                    TXT[i] = TXT[j];
                    j++;
                }
            }
            // Si assez de place pour stocker à la fin du tableau
            else if (MAXMSG >= position_finish + X)
            {
                int j = position_start;
                position_start += X;
                position_finish += X;
                for (int i = position_finish - X + 1; i <= position_finish; i++)
                {
                    TXT[i] = TXT[j];
                    j++;
                }
            }
            // Si de la place null part renvoie 1
            else
            {
                return 1;
            }
        }
    }
    return 0;
}

void crypteMove(char TXT[], char ENC[])
{
    if (algoCrypteMove(TXT, ENC) == 1)
        printf("Le texte est de trop grande taille ... Il n a pas pu etre dechiffre\n");
}

int main()
{
    // crypeMove essayer

    char TXT[MAXMSG];
    char ENC[MAXMSG];
    printf("Saisissez le message a chiffrer: ");
    fgets(TXT, MAXMSG, stdin);
    crypteMove(TXT, ENC);
    printf("Message chiffrer: %s\n", ENC);
    return 0;
}