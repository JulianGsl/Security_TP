#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef struct{
  char *name;
  char *name2;
  void (*func)();
} exploitable;

void legitimate() {
  printf("I am the legitimate function\n");
}

void bad() {
  printf("I am the bad function\n");
}

void print_exploitable(exploitable *e) {
  if (e == NULL) { printf("Bad argument\n"); return; }
  printf("Name: %s\n",e->name);
  e->func();
}

void free_exploitable(exploitable *e) {
  if (e == NULL) { return; } 
  e->func = NULL;
  free(e);
}

int main(){
  exploitable *fun1 = NULL;
  exploitable *bad1 = NULL;
  fun1 = malloc(sizeof(exploitable));
  fun1->name = "good1";
  fun1->func = legitimate;
  print_exploitable(fun1);
  free(fun1);
  bad1 = malloc(sizeof(exploitable));
  bad1->name = "I caught your function!";
  print_exploitable(bad1);
  free(bad1);

  // Try again
  fun1 = NULL;
  bad1 = NULL;
  printf("\nTrying again, with free_exploitable function.\n\n");
  fun1 = malloc(sizeof(exploitable));
  fun1->name = "good1";
  fun1->func = legitimate;
  print_exploitable(fun1);
  free_exploitable(fun1);
  bad1 = malloc(sizeof(exploitable));
  bad1->name = "I caught your function!";
  print_exploitable(bad1);
  free_exploitable(bad1);
  return 0;
}
