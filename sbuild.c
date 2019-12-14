// @Compile gcc -std=c99 sbuild.c -o sbuild
// @Compile gcc -std=c99 sbuild.c -o sbuild && sudo cp sbuild /usr/bin

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * read_first_line(char *path) {
  const int max_len = 1024;
  char *line = malloc(max_len);
  FILE *fp = fopen(path, "r");
  fgets(line, max_len, fp);
  fclose(fp);
  line[strlen(line) - 1] = 0; // Remove newline
  return line;
}

int main(int argc, char **argv) {
  if (argc != 2) {
    printf("Usage: %s entry_file.c\n", argv[0]);
    return 1;
  }
  char *first_line = read_first_line(argv[1]);
  const char *tag = "@Compile";
  const int tag_len = strlen(tag);
  char *tag_start = strstr(first_line, tag);
  if (tag_start)
    system(tag_start + tag_len);
  free(first_line);
  return 0;
}
