#include <stdio.h>
#include <stdlib.h>

void decode(FILE *in, FILE *out)
{
  int c;
  while ((c = fgetc(in)) != EOF) {
    int n = fgetc(in);
	printf("%c:", c);
	printf("%c\n", n);
    if (n == EOF) {
      fprintf(stderr, "圧縮ファイルが壊れています\n");
      exit(1);
    }
	n = n - 48;
    while (n-- > 0) fputc(c, out);
  }
}

int main(int argc, char *argv[])
{
  if (argc < 3) {
    fprintf(stderr, "引数が足りません\n");
    return 1;
  }
  FILE *in = fopen(argv[1], "r");
  if (in == NULL) {
    perror(argv[1]);
    return 1;
  }
  FILE *out = fopen(argv[2], "w");
  if (out == NULL) {
    perror(argv[2]);
    return 1;
  }
  decode(in, out);
  fclose(in);
  fclose(out);
  return 0;
}
