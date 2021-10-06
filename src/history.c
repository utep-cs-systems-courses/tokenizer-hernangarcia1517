#include <stdio.h>
#include <stdlib.h>
#include "history.h"

List* init_history()
{
  List *history;
  history = (List*) malloc(sizeof(List));
  history->root = NULL;
  return history;
}

void add_history(List *list, char *str)
{
  Item *newItem = (Item*) malloc(sizeof(Item));
  // add string to linked list
  newItem->str = str;
  newItem->next = NULL;

  if(list->root == NULL)
  {
    newItem->id = 1;
    list->root = newItem;
  }
  else
  {
    Item *currentItem = list->root;
    while(currentItem->next != NULL)
    {
      currentItem = currentItem->next;
    }
    newItem->id = currentItem->id+1;
    currentItem->next = newItem;
  }
}

char *get_history(List *list, int id)
{
  if(list->root == NULL)
  {
    return "List is empty";
  }
  else
  {
    Item* temp = list->root;
    while(temp != NULL)
    {
      if(temp->id == id)
      {
	return temp->str;
      }
      temp = temp->next;
    }
  }
}

void print_history(List *list)
{
  Item *temp = (list->root);
  while(temp != NULL)
  {
    printf("history working: %s\n", temp->str);
    temp = temp->next;
  }
}

void free_history(List *list)
{
  Item *temp;
  Item *temp2;
  temp2 = list->root;
  while(temp2 != NULL)
  {
    temp = temp2;
    temp2 = temp2->next;
    free(temp);
  }
  free(list);
}
