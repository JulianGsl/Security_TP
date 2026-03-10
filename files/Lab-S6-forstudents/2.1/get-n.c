#include "stdio.h"
#include "string.h"
#include "stdlib.h"

int main(int argc, char * argv[]) {
  if (argc < 3) { return 1; }
  int len = atoi(argv[2]);
  printf("%c\n",argv[1][len]);
  return 0;
}
