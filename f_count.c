#include <stdio.h>

int main(int argc, char *argv[])
{
	FILE *fp = stdin;
	if (argc >= 2) {
		fp =  fopen(argv[1], "r");
		if (fp == NULL) {
			perror(argv[1]);
			return 1;
		}
	}

	int c, line = 0, size = 0;
	while ((c = fgetc(fp)) != EOF) {
		if (c == '\n')
			line++;
		size++;
	}
	printf("size = %d, line = %d\n", size, line);
  	fclose(fp);
  	return 0;
}
