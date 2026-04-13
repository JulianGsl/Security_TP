#include "stdlib.h"
#include "string.h"


// YOU CAN CHANGE THIS VALUE!
#define TARGET 48

void foo(char * buffer){
  char newbuffer[32];
  strcpy(newbuffer, buffer);
}

int main() {
  char * buffer;
  buffer = malloc(sizeof(char)*TARGET);
  memset(buffer, '\x90',TARGET);
  buffer[44] = '\xb9';
  buffer[45] = '\x11';
  buffer[46] = '\x40';
  buffer[47] = '\x00';
  // You can write code here to change the value of "buffer"
  foo(buffer);
  return 0;
}
