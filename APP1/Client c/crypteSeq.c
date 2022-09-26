/*
 * @Author: ThearchyHelios
 * @Date: 2022-09-26 09:08:43
 * @LastEditTime: 2022-09-26 09:08:43
 * @LastEditors: ThearchyHelios
 * @Description:
 * @FilePath: /APP1/Client c/crypteSeq.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include "struct.h"
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

void dechiffreBayOfPigs(char CHI[], char DEC[])
{
    char newChar, tabl_X[100000];
    int X;
    int lenCHI = strlen(CHI);
    int lenDEC = 0;

    while (lenCHI > 0)
    {
        newChar = CHI[lenCHI - 1];
        X = newChar % 8;
        if (X > 0 && lenDEC > X)
        {
            // Stocke les valeurs de fin à replacé en début
            for (int i = 0; i < X; i++)
            {
                tabl_X[i] = DEC[lenDEC + i - X];
            }
            // Déplace les valeurs
            for (int i = lenDEC - X - 1; i >= 0; i--)
            {
                DEC[i + X + 1] = DEC[i];
            }
            // Copie des caractères stockés dans tabl_X vers DEC
            for (int i = 1; i <= X; i++)
            {
                DEC[i] = tabl_X[i - 1];
            }
        }
        // Décalage pour accepter la nouvelle lettre
        else
        {
            for (int i = lenDEC; i >= 0; i--)
            {
                DEC[i + 1] = DEC[i];
            }
        }
        // Caractère issu de CHI
        DEC[0] = newChar;

        lenDEC++;
        lenCHI--;
    }
}

void chiffreSeq(char TXT[], char ENC[])
{
    char C, D, seqCar[256] = "";

    int lenTXT = strlen(TXT);
    int lenSeqCar, progressENC = 0, flag;
    // Parcour TXT
    for (int i = 0; i < lenTXT; i++)
    {
        C = TXT[i];
        lenSeqCar = strlen(seqCar);
        flag = 0;
        // Parcour la seq de caractère pour voir si C est présent
        for (int j = 0; j < lenSeqCar; j++)
        {
            if (seqCar[j] == C)
            {
                if (j == 0)
                {
                    D = seqCar[lenSeqCar - 1];
                }
                else
                {
                    D = seqCar[j - 1];
                }
                flag = 1;
                // Délpace les cactères pour placer C à la fin de Seq Car
                for (int z = j; z < lenSeqCar - 1; z++)
                {
                    seqCar[z] = seqCar[z + 1];
                }
                seqCar[lenSeqCar - 1] = C;
                break;
            }
        }
        // Si C n’a pas été rencontré dans la séquence de caractères
        if (flag == 0)
        {
            ENC[progressENC] = C;
            seqCar[lenSeqCar] = C;
        }
        else
        {
            ENC[progressENC] = D;
        }

        progressENC++;
    }
}

void debMessage(char TXT[], char message[])
{
    int i = 0, z;
    while (i < 1000000)
    {
        if (TXT[i] == 'A' && TXT[i + 1] == 'l' && TXT[i + 2] == 'i' && TXT[i + 3] == 'c' && TXT[i + 4] == 'e' && TXT[i + 5] == ',')
            break;
        i++;
    }

    z = 0;
    while (TXT[i] != '\0')
    {
        message[z] = TXT[i];
        z++;
        i++;
    }
}

char check_seq(seq *seq, char newC)
{
    int i, j, position_lettrePivot;
    for (i = seq->start; i <= seq->end; i++)
    {

        if (seq->chaine[i] == newC)
        {
            position_lettrePivot = i + 1;

            // Cas fin de chaine :
            if (i > 0 && i == seq->end)
            {
                seq->end += 1;
                seq->chaine[seq->end] = seq->chaine[seq->start];
                seq->start += 1;

                // Renvoie de la dernière valeurs
                return seq->chaine[seq->end];
            }

            // ############################################################ //
            //                 Déplace le début de la chaine
            // ############################################################ //
            // Si la chaine à déplacer est plus courte avant la lettre pivot
            if ((position_lettrePivot - seq->start) < (seq->end - (position_lettrePivot)))
            {
                // Si la position final atteindra les 10 000 à la fin de la fonction replace la chaine au départ du tableau
                if (seq->end == (TAILLE_SEQ - 1))
                {
                    int z = 0;
                    // Replace les lettres d’avant pivot au depart
                    for (j = seq->start; j < position_lettrePivot; j++)
                    {
                        seq->chaine[z] = seq->chaine[j];
                        z++;
                    }
                    // Renitialisation de la position de départ de la chaine
                    seq->start = 0;
                    // Replace les lettres d’apres pivot au depart
                    for (j = position_lettrePivot + 1; j <= seq->end; j++)
                    {
                        seq->chaine[z] = seq->chaine[j];
                        z++;
                    }
                    // Mise à niveau du nombre marquant la fin de la chaine
                    seq->end = z;
                    // Place lettre pivot à la fin de la chaine
                    seq->chaine[z] = seq->chaine[position_lettrePivot];

                    // Renvoie la lettre pivot
                    return seq->chaine[z];
                }

                // Ajoute 1 à la position de la dernière lettre de la seq
                seq->end += 1;
                // Place à la dernière case de seq le caractère d’échange
                seq->chaine[seq->end] = seq->chaine[position_lettrePivot];
                // Décale les lettres avant et incluant la lettre newC
                for (j = position_lettrePivot; j > seq->start; j--)
                {
                    seq->chaine[j] = seq->chaine[j - 1];
                }
                // Ajoute 1 à la position de départ
                seq->start += 1;

                // Renvoie la valeur de la lettre pivot
                return seq->chaine[seq->end];
            }

            // ############################################################ //
            //                  Déplace la fin de la chaine
            // ############################################################ //
            // Si la chaine à déplacer est plus courte apres la lettre pivot
            char lettre_pivot = seq->chaine[position_lettrePivot];
            // Deplacement des elements apres lettre pivot
            for (j = position_lettrePivot; j < seq->end; j++)
            {
                // printf("Affecte %c à la place de %c\n", seq->chaine[j + 1], seq->chaine[j]);
                seq->chaine[j] = seq->chaine[j + 1];
            }
            // affectation de la valeur pivot en fin de chaine
            seq->chaine[seq->end] = lettre_pivot;
            // retourne la lettre pivot pour completer le texte decode
            return lettre_pivot;
        }

        // printf("%c != %c\n", seq->chaine[i], newC);
    }
    // Si le caractère n’est pas présent dans seq ajout de ce caractère à la fin de seq et retourne ce même pour le texte décodé
    seq->end += 1;
    seq->chaine[seq->end] = newC;
    return newC;
}

void dechiffreSeq(char TXT[], char DEC[])
{
    seq s;
    init_seq(&s);
    int lenDEC = strlen(DEC);
    int i = 0;
    while (TXT[i] != '\0')
    {
        DEC[i] = check_seq(&s, TXT[i]);
        lenDEC++;
        i++;
    }
}

int main()
{
    char reponse[MAXREP];
    char message[MAXMSG];

    // Affiche les échanges avec le serveur (false pour désactiver)
    mode_debug(true);

    connexion("im2ag-appolab.u-ga.fr", 9999);
    envoyer_recevoir("login 12012095 PIGNON", reponse);

    envoyer_recevoir("load crypteSeq", reponse);
    dechiffreBayOfPigs(reponse, message);
    envoyer_recevoir(message, reponse);
    envoyer_recevoir("start", reponse);
    dechiffreBayOfPigs(reponse, message);
    printf("crypteSeq : %s\n", message);
    chiffreSeq(message, reponse);
    envoyer_recevoir(reponse, message);
    debMessage(message, reponse);
    dechiffreSeq(reponse, message);
    printf("Message : %s\n", message);
    envoyer_recevoir("quit", reponse);

    deconnexion();

    return 0;
}