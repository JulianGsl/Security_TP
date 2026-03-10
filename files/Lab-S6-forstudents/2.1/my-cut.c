#include "stdio.h"
#include "string.h"
#include "stdlib.h"

int main(int argc, char * argv[]) {
  if (argc < 4) { return 1; }
  int start = atoi(argv[2]);
  int end = atoi(argv[3]);
  while(start < end) {
    printf("%c",argv[1][start]);
    start++;
  }
  printf("\n");
  return 0;
}
