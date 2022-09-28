#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

/* Return true (non-zero) if c is a whitespace characer
   ('\t' or ' ').  
   Zero terminators are not printable (therefore false) */
int space_char(char c){
  if(c == ' ' || c=='\t')
    return 1;
  return 0;
}

/* Return true (non-zero) if c is a non-whitespace 
   character (not tab or space).  
   Zero terminators are not printable (therefore false) */ 
int non_space_char(char c){
  if(c == ' ' || c=='\t')
    return 0;
  return 1;
}

/* Returns a pointer to the first character of the next 
   space-separated word in zero-terminated str.  Return a zero pointer if 
   str does not contain any words. */
char *word_start(char *str){
  while( *str != '\0'){
    if(space_char(*str) && *(str+1)!='\0')
      return ++str;
    ++str;
  }
str = 0;
  return str;
}; 

/* Returns a pointer terminator char following *word */
char *word_terminator(char *word){
  
  while(*word != '\0'&& non_space_char(*word)){
    ++word;
  }
  --word;
  return word;
};

/* Counts the number of words in the string argument. */
int count_words(char *str){
  int count = 0;
  int newSpace = 1;
  while(*str != '\0'){
    if(*str != ' '&& newSpace == 1){
      count++;
      newSpace = 0;
    }
    if(*str == ' ')
      newSpace = 1;

    str++;
  }
  return count;
}

/* Returns a fresly allocated new zero-terminated string 
   containing <len> chars from <inStr> */
char *copy_str(char *inStr, short len){
  char *p =(char*)malloc((len+1)*sizeof(char));
  for(int i=0;i<len;i++)
    p[i] = inStr[i];
  p[len] = '\0';
  return p;
};

/* Returns a freshly allocated zero-terminated vector of freshly allocated 
   space-separated tokens from zero-terminated str.

   For example, tokenize("hello world string") would result in:
     tokens[0] = "hello"
     tokens[1] = "world"
     tokens[2] = "string" 
     tokens[3] = 0
*/
char **tokenize(char* str){
  int  count = count_words(str);
  char **vect =(char**)malloc((count+1)*sizeof(char*));
  char *endch = (char*)malloc(1*sizeof(char));
  *endch = '\0';
  while(space_char(*str)){
    str++;
	}
    char  *start = str;
    for(int i = 0;i< count;i++){
      vect[i] = copy_str(start,(word_terminator(start)-start)+1);
     start = word_start(start);
    }
    vect[count]=endch;
    return vect;
}

/* Prints all tokens. */
void print_tokens(char **tokens){
  
  for(int x=0;*(*(tokens+x))!='\0';x++){
    for(int y=0;*(*(tokens+x)+y) !='\0';y++)
      printf("%c",*(*(tokens+x)+y));
    printf("\n");
  }
  return;
};

/* Frees all tokens and the vector containing themx. */
void free_tokens(char **tokens){

  return;
}
