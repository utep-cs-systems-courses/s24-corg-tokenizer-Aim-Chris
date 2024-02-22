#include <stdio.h>
#include "tokenizer.h"
#include <stdlib.h>

int space_char(char c){
  if(c == ' ' || c == '\t'){
    return 1;
  }else{
    return 0;
  }
}
int non_space_char(char c){
  return !space_char(c);
}
char *token_start(char *word){
  while(*word != '\0' && space_char(*word)){
    word++;
  }
  if(*word == '\0'){
    return NULL;
  } else {
    return word;
  }
}
char *token_terminator(char *word){
  while(*word != '\0' && non_space_char(*word)){
    word++;
  }
  return word;
}
int count_tokens(char *word){
  int count = 0;
  char *token = token_start(word);
  while(token != NULL){
    if(non_space_char(*token)){
      count++;
	}
    token = token_terminator(token); //move to next token
    token = token_start(token); // start of next token
  }
  return count;
}
char *copy_str(char *inStr, short len){
  char *copyStr = malloc((len +1)* sizeof(char));
  int i;
  for(i =0; i<len; i++){
    copyStr[i] = inStr[i];
  }
  copyStr[i] = '\0';
  return copyStr;
}
char **tokenize(char *word){
  int num_t = count_tokens(word);
  char **tokens = malloc((num_t +1) * sizeof(char *)); //find space
  char *ptr = word;
  int i = 0;
  while(i < num_t){
    ptr = token_start(ptr);
    char *eptr = token_terminator(ptr);
    int token_len = eptr - ptr;
    tokens[i] = copy_str(ptr, token_len); //copy
    ptr = eptr;
    i++;
  }
  tokens[num_t] = NULL;
  return tokens;
}
