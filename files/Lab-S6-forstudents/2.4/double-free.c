#include "stdio.h"
#include "stdlib.h"
#include "string.h"

void main(){
  char *a = malloc(10);
  char *b = malloc(10);
  char *c = malloc(10);
  free(a);
  free(b);
  free(a);
  char *d = malloc(10);
  char *e = malloc(10);
  char *f = malloc(10);
  strcpy(d,"Hello!\n");
  printf("%s",d);
  printf("%s",f);
  strcpy(f,"Broken!\n");
  printf("%s",d);
}

