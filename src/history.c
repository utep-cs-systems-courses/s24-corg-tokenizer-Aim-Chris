#include <stdio.h>
#include <stdlib.h>
#include "history.h"
List *init_history(){
  List *list = malloc(sizeof(List));
  list->root = NULL;
  return list;
}
void add_history(List *list, char *str){
  int id = 1;
  Item *new_i = malloc(sizeof(Item));
  new_i->id = id++;
  new_i->str = str;
  new_i->next = NULL;
  if(list->root == NULL){
    list->root = new_i;
    return;
  }
  Item *tmp = list->root;
  while(tmp->next != NULL){
    tmp = tmp->next;
  }
  tmp->next = new_i;
}
char *get_history(List *list, int id){
  Item *tmp = list->root;
  while(tmp != NULL){
    if(tmp->id == id){
      return tmp->str;
    }
    tmp = tmp->next;
  }
  return NULL;
}
void print_history(List *list){
  Item *tmp = list->root;
  while(tmp != NULL){
    printf("%d: %s\n", tmp->id, tmp->str);
    tmp = tmp->next;
  }
}
void free_history(List *list){
  Item *tmp;
  while(list->root != NULL){
    tmp = list->root;
    list->root = list->root->next;
    free(tmp->str);//free memory for word
    free(tmp); //free memory for item
  }
  free(list); //free memory for str
}
