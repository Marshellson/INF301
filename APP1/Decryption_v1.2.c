/*
 * @Author: ThearchyHelios
 * @Date: 2022-09-18 22:21:00
 * @LastEditTime: 2022-09-18 23:24:47
 * @LastEditors: ThearchyHelios
 * @Description:
 * @FilePath: /INF301/APP1/Decryption_v1.2.c
 */

#include <stdio.h>

// Donner ici un programme qui décrypte n'importe quel message de Alice à Bob et vice versa, même si le décalage n'est pas fixe d'un message à l'autre.
// Vous pouvez supposer que nos correspondant sont très polis et commencent toujours leurs messages de la même manière.

#define BUFSIZE 512

int main(int argc, char *argv[])
{
	char lettre_premier = 'C';
	int nombre_de_decalage = argv[1][0] - lettre_premier;

	char buffer[BUFSIZE];

	while (fgets(buffer, BUFSIZE - 1, stdin))
	{

		for (int i = 0; i < BUFSIZE; i++)
		{
			if (buffer[i] >= 'a' && buffer[i] <= 'z')
			{
				buffer[i] = buffer[i] + nombre_de_decalage;
				if (buffer[i] > 'z')
				{
					buffer[i] = buffer[i] - 'z' + 'a' - 1;
				}
				else if (buffer[i] < 'a')
				{
					buffer[i] = buffer[i] + 'z' - 'a' + 1;
				}
			}
			else if (buffer[i] >= 'A' && buffer[i] <= 'Z')
			{
				buffer[i] = buffer[i] + nombre_de_decalage;
				if (buffer[i] > 'Z')
				{
					buffer[i] = buffer[i] - 'Z' + 'A' - 1;
				}
				else if (buffer[i] < 'A')
				{
					buffer[i] = buffer[i] + 'Z' - 'A' + 1;
				}
			}
			else
			{
				buffer[i] = buffer[i];
			}
		}

		printf("%s", buffer);
	}
	return 0;
}
