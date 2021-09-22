#include <stdio.h>
#include <string.h>

void encode(FILE *in, FILE *out)
{
	int c = fgetc(in);
	if (c == EOF) return;
	do {
		int n = 1;
		int x = c;
		while(n < 255 && (c = fgetc(in)) == x) {
			n++;
		}
		fputc(x, out);
		if(n + '0' > 1)
			fputc(n + '0', out);
	} while(c != EOF);
}

int	main(int argc, char *argv[])
{
	FILE *in = stdin;
	FILE *out = stdout;
	if(argc >= 2) {
		in = fopen(argv[1], "r");
		if (in == NULL) {
			perror(argv[1]);
			return 1;
		}
		if(argc >= 3) {
			out = fopen(argv[2], "w");
			if(out == NULL) {
				perror(argv[2]);
				return 1;
			}
		}
	}
	encode(in, out);
	fclose(in);
	fclose(out);
	return 0;
}
