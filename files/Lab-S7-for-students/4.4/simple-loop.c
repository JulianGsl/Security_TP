#include <stdio.h>

void func(char *str) {
  int i;
  char buf[16];
  for (i=0;i<=16;i++) {
    buf[i] = str[i];
  }
}

int main(int argc, char **argv) {
  func(argv[1]);
}

