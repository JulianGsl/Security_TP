#include <stdio.h>
#include "string.h"

void func(char *str) {
  char buf[64];
  strcpy(buf,str);
  printf("%s\n",buf);
}

int main(int argc, char **argv) {
  if (argc != 2) { printf("Incorrect arguments\n"); return 1; }
  func(argv[1]);
  return 0;
}
