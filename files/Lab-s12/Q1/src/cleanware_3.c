#include<stdio.h>

int malicious_behaviour(){
  printf("I am evil!!!\n");
}

int nice_behaviour(){
  printf("I am nice.\n");
}

int main(int argc, char **argv){
  nice_behaviour();
}
