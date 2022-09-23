/*
 * @Author: ThearchyHelios
 * @Date: 2022-09-15 20:40:27
 * @LastEditTime: 2022-09-19 16:12:03
 * @LastEditors: ThearchyHelios
 * @Description:
 * @FilePath: /APP1/count_5_char_after.c
 */

#include <stdio.h>

// Count 5 char after the input file

int main(int argc, char *argv[])
{
	// read the input file
	FILE *input = fopen(argv[1], "r");
	if (input == NULL)
	{
		printf("Could not open %s.\n", argv[1]);
		return 1;
	}
	char c;
	while ((c = fgetc(input)) != EOF)
	{
		if (c >= 'a' && c <= 'z')
		{
			c = c - 5;
			if (c > 'z')
			{
				c = c - 'z' + 'a' - 1;
			}
			else if (c < 'a')
			{
				c = c + 'z' - 'a' + 1;
			}
		}
		else if (c >= 'A' && c <= 'Z')
		{
			c = c - 5;
			if (c > 'Z')
			{
				c = c - 'Z' + 'A' - 1;
			}
			else if (c < 'A')
			{
				c = c + 'Z' - 'A' + 1;
			}
		}
		else{
			c = c;
		}
		printf("%c", c);
	}
}
