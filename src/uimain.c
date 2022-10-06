#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

int main(){
  int exit = 0;
  List *hist1 = init_history();
  printf("Hello welcome to the tokenizer\n");
  while(exit == 0){
  char buffer[100];//100 as a general maxsize
  puts("please:\n1.Enter a string to tokenize\n2.Enter ! to print history\n3.Enter @ to exit.\n");
  printf("-->");
  fgets(buffer,100,stdin);
  printf("You entered: ");
  printf("%s\n",buffer);
  char **p;
  switch(buffer[0]){
  case '!':
    print_history(hist1);
    break;
  case '@':
    exit++;
    break;
  default:
    p = tokenize(buffer);
    add_history(hist1,p);
    printf("added new  history item\n");
    break;
  }
  }
  free_history(hist1);
  printf("thank you for using tokenizer");
  return 0;
}
