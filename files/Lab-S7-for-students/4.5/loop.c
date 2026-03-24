#include "stdlib.h"
#include "string.h"


// YOU CAN CHANGE THIS VALUE!
#define TARGET 32

void foo(char * buffer){
  char newbuffer[32];
  strcpy(newbuffer, buffer);
}

int main() {
  char * buffer;
  buffer = malloc(sizeof(char)*TARGET);
  memset(buffer, '\x90',TARGET);
  // You can write code here to change the value of "buffer"
  foo(buffer);
  return 0;
}
