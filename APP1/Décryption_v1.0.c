/*
 * @Author: ThearchyHelios
 * @Date: 2022-09-15 21:21:47
 * @LastEditTime: 2022-09-18 22:19:09
 * @LastEditors: ThearchyHelios
 * @Description:
 * @FilePath: /INF301/APP1/Décryption_v1.0.c
 */

// Au programme : décrypter de manière automatique un texte crypté selon la méthode de cryptage initialement utilisée par Alice et Bob, qui utilise un décalage constant (à vous de deviner lequel).

#include <stdio.h>

#define BUFSIZE 512

int main(int argc, char *argv[])
{
	char buffer[BUFSIZE];

	while (fgets(buffer, BUFSIZE - 1, stdin))
	{

		// completer ici le code pour décrypter le message.

		for (int i = 0; i < BUFSIZE; i++)
		{
			if (buffer[i] >= 'a' && buffer[i] <= 'z')
			{
				buffer[i] = buffer[i] - 5;
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
				buffer[i] = buffer[i] - 5;
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
}