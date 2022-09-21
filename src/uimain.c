#include <stdio.h>
#include "tokenizer.h"

int main(){
  /*here we are using this UImain file to test our functions to begin with
    we created a character array to jhold the user input and tested the space_char and
    non_space_char methods. after this, we tested word_start and word_terminator on the given input
    we even passed the pointer recieved by word_start to word_terminator to see if it gets the
    correct word.Then i tested the count_words method using the buffer variable from user input
 I organized the Makefile to be similar to Lab0 though i have not added the 
    connection to the history.h file.
   */
  char buffer[100];//100 as a general maxsize
  puts("Please enter a string\n");
  printf("-->");
  fgets(buffer,100,stdin);
  printf("You entered: ");
  printf("%s\n",buffer);
  printf("test space_char:  %d\n", space_char(buffer[0]));
  printf("test non_space_char:  %d\n", non_space_char(buffer[0]));

  char *p1 = word_start(buffer);
  printf("%c\n",*p1);
  printf("%d\n",p1);

  char *p2 = word_terminator(p1);
  printf("%c\n",*p2);
  printf("%d\n",p2);

  printf("number of words: %d\n",count_words(buffer));
  
  
  return 0;
}
