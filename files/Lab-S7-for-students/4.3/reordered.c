#include "stdio.h"
#include "string.h"

int check_authentification(char *password){
  char password_buffer[16];
  int auth_flag = 0;
  strcpy(password_buffer,password);
  if(strcmp(password_buffer,"good")==0) {auth_flag = 1;}
  else    {printf("bad password!\n");}
  return auth_flag;
}

int main(int argc, char *argv[]){
  if(argc < 2) { printf("missing argument\n"); return 1; }
  if (check_authentification(argv[1]))
  {
    printf("access granted\n");
  }
  return 0;
}



