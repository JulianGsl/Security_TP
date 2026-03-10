#include "stdio.h"
#include "stdlib.h"

typedef struct{
  void (*vulnfunc)();
} exploitable;

void legitimate() {
  printf("I am the legitimate function\n");
}

void bad() {
  printf("I am the bad function\n");
}

void main(){
  exploitable *malloc1 = malloc(sizeof(exploitable));
  malloc1->vulnfunc = legitimate;
  malloc1->vulnfunc();
  free(malloc1);
  malloc1->vulnfunc();
}

