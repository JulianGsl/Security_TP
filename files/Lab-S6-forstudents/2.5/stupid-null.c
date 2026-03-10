#include "stdio.h"
#include "stdlib.h"
#include "string.h"

void legitimate() {
  printf("I am the legitimate function\n");
}

void bad() {
  printf("I am the bad function\n");
}

void main(){
  void (*func)() = legitimate;
  func();
  void (*bad)() = NULL;
  bad();
}
