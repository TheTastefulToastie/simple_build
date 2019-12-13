// @Compile gcc -std=c99 test.c -o test && ./test Dave
#include <stdio.h>

void open_pod_bay_doors(char *name) {
  printf("I'm sorry %s, I'm afraid I can't do that.\n", name);
}

int main(int argc, char **argv) {
  open_pod_bay_doors(argv[1]);
  return 0;
}
