#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

int wc(FILE *fp)
{
	bool inword = false;
	int c, n = 0;
	while ((c = fgetc(fp)) != EOF)
	{
		if (isspace(c))
			inword = false;
		else
		{
			if (!inword)
			{
				inword = true;
				n++;
			}
		}
	}
	return n;
}

int main(int argc, char *argv[])
{
	FILE *fp = stdin;
	if (argc >= 2)
	{
		fp = fopen(argv[1], "r");
		if(fp == NULL)
		{
			perror(argv[1]);
			return 1;
		}
	}
	printf("%d\n", wc(fp));
	return 0;
}
