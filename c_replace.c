#include <stdio.h>
#include <string.h>

int position(char key, char *buff)
{
	for (int i = 0; buff[i] != '\0'; i++) {
		if (buff[i] == key)
			return i;
	}
	return -1;
}

void	tr(char *s1, char *s2, FILE *in, FILE *out)
{
	int c, count;
	while ((c = fgetc(in)) != EOF) {
		printf("%c", c);
		int i = position(c, s1);
		if (i >= 0)
			c = s2[i];
		fputc(c, out);
		count++;
	}
	printf("\n%d", count);
}

int main(int argc, char *argv[])
{
	if (argc < 3) {
		fprintf(stderr, "引数が足りません\n");
		return 1;
	}

	if (strlen(argv[1]) != strlen(argv[2])) {
		fprintf(stderr,"%s と %s の長さが違います\n", argv[1], argv[2]);
		return 1;
	}

	FILE *in = stdin;
	FILE *out = stdout;
	if (argc >= 4) {
		in = fopen(argv[3], "r");
		if (in == NULL) {
			perror(argv[3]);
			return 1;
		}
		if (argc >= 5) {
			out = fopen(argv[4], "w");
			if (out == NULL) {
				perror(argv[4]);
				return 1;
			}
		}
	}
	tr(argv[1], argv[2], in, out);
	fclose(in);
	fclose(out);
	return 0;
}
