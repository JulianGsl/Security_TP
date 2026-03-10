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
  long *malloc2 = malloc(0);
  long *malloc3 = malloc(0);
  *malloc2 = (long)bad;
  malloc1->vulnfunc();
}

