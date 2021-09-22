#include <stdio.h>
#include <string.h>

#define N 1024

void replace(char *key, char *s, FILE *in, FILE *out)
{
  char buff[N];
  int len = strlen(key);
  while (fgets(buff, N, in) != NULL) {
    char *p;
    char *q = buff;
    while ((p = strstr(q, key)) != NULL) {
      *p = '\0';
      fprintf(out, "%s%s", q, s);
      q = p + len;
    }
    fprintf(out, "%s", q);
  }
}

int main(int argc, char *argv[])
{
  FILE *in = stdin;
  FILE *out = stdout;
  if (argc < 3) {
    fprintf(stderr, "引数が足りません\n");
    return 1;
  }
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
  replace(argv[1], argv[2], in, out);
  fclose(in);
  fclose(out);
  return 0;
}
