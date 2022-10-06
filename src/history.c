#include <stdio.h>
#include <stdlib.h>
#include "history.h"
//#include _HISTORY_

/* Initialize the linked list to keep the history. */
List* init_history(){
   Item *temp = (Item*)malloc(sizeof(Item));
   List *root = (List*)malloc(sizeof(List));
   //  struct s_Item *temp;
   //  struct s_List *root;
 temp->id = 0;
 temp->str = NULL;
 temp->next = NULL;
 root->root = temp;
 List* thislist = root;
 return thislist;
								   
};

/* Add a history item to the end of the list.
   List* list - the linked list
   char* str - the string to store
*/
void add_history(List *list, char **str){
  if(list->root->str == NULL){
    list->root->str = str;
    list->root->id = 0;
    return;
  }
  Item *newItem = (Item*)malloc(sizeof(Item));
  Item *p = list->root;
  int newID = 1;
  while(p->next != NULL){
      p = p->next;
      newID++;
    }
  p->next = newItem;
  p = p->next;
  p->str = str;
  p->id = newID;
  return;
  };

/* Retrieve the string stored in the node where Item->id == id.
   List* list - the linked list
   int id - the id of the Item to find */
char **get_history(List *list, int id){
  Item *p = list->root;
  int i = 0;
  while(p->id != id){
    if(p->id == id)
      return p->str;
    if(!(p->next))
      break;
    p = p->next;
  }
  printf("item not found in list");
  return p->str;
};

/*Print the entire contents of the list. */
void print_history(List *list){
  Item *p = list->root;
  while(p->next){
    printf("this items id: %d, this items *str : ",p->id);
    for(int x=0;*(*(p->str+x))!='\0';x++){
    for(int y=0;*(*(p->str+x)+y) !='\0';y++)
      printf("%c",*(*(p->str+x)+y));
    printf(" ");
  }
    p=p->next;
  }
    //this will take us to the last node
    //now we check if the list is just empty
    //and print the last item if its there
    printf("this items id: %d, this items *str : ",p->id);
    for(int i=0;*(*(p->str+i))!='\0';i++){
    for(int j=0;*(*(p->str+i)+j) !='\0';j++)
      printf("%c",*(*(p->str+i)+j));
    printf(" ");
  } 
    printf("\n");
    printf("this is all the items in the list\n");
  return;
};

/*Free the history list and the strings it references. */
void free_history(List *list){
  free_item(list->root);
  free(list);
  return;
};

void free_item(Item *item){
  if(item->next != NULL)
    free_item(item->next);
  free(item);
};
