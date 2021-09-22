#include <stdio.h>
#include <string.h>

#define N 1024

void	search_key(char *key, FILE *fp)
{
	char buff[N];
	while (fgets(buff, N, fp) != NULL) {
		if (strstr(buff, key) != NULL)
			printf("%s", buff);
	}
}

int main(int argc, char *argv[])
{
	if (argc < 2) {
		fprintf(stderr, "引数が足りません\n");
		return 1;
	}
	FILE *in = stdin;
	if (argc >= 3) {
		in = fopen(argv[2],"r");
		if (in == NULL) {
			perror(argv[2]);
			return 1;
		}
	}
	search_key(argv[1], in);
	fclose(in);
	return 0;
}
