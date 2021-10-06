#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "history.h"

char *word_start(char *str)
{
  int i = 0;
  for(; space_char(str[i]) == 1; i++)
  {
    if(str[i] == '\0')
    {
      return NULL;
    }
  }

  return &str[i]; // return the pointer to start
}

char *word_end(char *str)
{
  str = word_start(str);
  int i = 0;
  for(; non_space_char(str[i]) == 1; i++)
  {
    if(str[i] == '\0')
    {
      return &str[i - 1];
    }
  }

  return &str[i];
}

char *copy_str(char *inStr, short len)
{
  char *outStr = malloc((len) * sizeof(char));
  int i = 0;
  for(; i < len; i++)
  {
    outStr[i] = inStr[i];
  }
  outStr[i] = '\0';
  
  return outStr;
}

List* init_history()
{
  List *history;
  history = (List*) malloc(sizeof(List));
  history->root = NULL;
  return history;
}

void add_history(List *list, char *str)
{
  char *start = str;
  char *end = str;
  start = word_start(end);
  end = word_end(start);
  Item *newItem = (Item*) malloc(sizeof(Item));
  // add string to linked list
  newItem->str = copy_str(start, end - start);
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
