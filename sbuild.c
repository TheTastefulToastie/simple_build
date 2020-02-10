// @Compile gcc -std=c99 sbuild.c -o sbuild
// @Compile gcc -std=c99 sbuild.c -o sbuild && sudo cp sbuild /usr/bin

#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static inline
char * read_first_line(char *path) {
  FILE *fp = fopen(path, "r");
  if (fp == NULL) {
    fprintf(stderr, "Failed to open file \"%s\".", path);
    return NULL;
  }
  const int max_len = 1024;
  char *line = calloc(1, max_len);
  fgets(line, max_len, fp);
  fclose(fp);
  // TODO: Handle windows line endings
  size_t len = strlen(line);
  line[len - 1] = 0; // Remove newline
  if (line[len - 2] == '\r') line[len - 2] = 0;
  return line;
}

int main(int argc, char **argv) {
  if (argc != 2) {
    printf("Usage: %s entry_file.c\n", argv[0]);
    return 1;
  }
  char *first_line = read_first_line(argv[1]);
  if (first_line == NULL) return 1;
  const char *tag = "@Compile ";
  char *tag_end = strstr(first_line, tag) + strlen(tag);
  int return_value = 0;
  if (tag) {
    printf("> %s\n", tag_end);
    fflush(stdout);
    return_value = system(tag_end);
  }
  free(first_line);
  return return_value;
}
