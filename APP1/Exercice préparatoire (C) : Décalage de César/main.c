/*
 * @Author: ThearchyHelios
 * @Date: 2022-09-15 20:11:03
 * @LastEditTime: 2022-09-18 20:40:12
 * @LastEditors: ThearchyHelios
 * @Description:
 * @FilePath: /INF301/APP1/Exercice préparatoire (C) : Décalage de César/main.c
 */

#include <stdio.h>

int main(void)
{
	char lettreLue;
	char lettreSuivante3;

	printf("Donner une lettre \n");
	scanf("%c", &lettreLue);

	// completer ici le calcul de la lettre suivante (3 rang plus loin)

	lettreSuivante3 = lettreLue + 3;
	if (lettreSuivante3 > 'z')
	{
		lettreSuivante3 = lettreSuivante3 - 'z' + 'a' - 1;
	}

	printf("\n%c\n", lettreSuivante3);

	return 0;
}