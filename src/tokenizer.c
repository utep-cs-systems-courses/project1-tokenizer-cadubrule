#include <stdio.h>
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
  char *p = str;
  while( *p != '\0'){
    if(*p ==' ' && *(p+1)!='\0')
      return ++p;
    ++p;
  }
p = 0;
  return p;
}; 

/* Returns a pointer terminator char following *word */
char *word_terminator(char *word){
  char *p = word;
  while(*p != '\0'&& *p !=' '){
    ++p;
  }
  --p;
  return p;
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
  return inStr;
};

/* Returns a freshly allocated zero-terminated vector of freshly allocated 
   space-separated tokens from zero-terminated str.

   For example, tokenize("hello world string") would result in:
     tokens[0] = "hello"
     tokens[1] = "world"
     tokens[2] = "string" 
     tokens[3] = 0
*/


/* Prints all tokens. */
void print_tokens(char **tokens){
  return;
};

/* Frees all tokens and the vector containing themx. */
void free_tokens(char **tokens){
  return;
}
