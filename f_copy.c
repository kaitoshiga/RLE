#include <stdio.h>

#define N 1024

// ファイルのコピー
void copy(FILE *in, FILE *out)
{
  int c;
  while ((c = fgetc(in)) != EOF) fputc(c, out);
}

void copy1(FILE *in, FILE *out)
{
  char *buff[N];
  int size;
  do {
    size = fread(buff, sizeof(char), N, in);
    fwrite(buff, sizeof(char), N, out);
  } while (size == N);
}

int main(int argc, char *argv[])
{
  FILE *in = stdin;
  FILE *out = stdout;
  if (argc >= 2) {
    in = fopen(argv[1], "r");
    if (in == NULL) {
      perror(argv[1]);
      return 1;
    }
    if (argc >= 3) {
      out = fopen(argv[2], "w");
      if (out == NULL) {
        perror(argv[2]);
        fclose(in);
        return 1;
      }
    }
  }
  copy1(in, out);
  fclose(in);
  fclose(out);
  return 0;
}
