#include <stdio.h>
#include <stdlib.h>
#include "history.h"

List* init_history()
{
  List history;
  history = (List) malloc(sizeof(List));
  history->root = NULL;
  return history;
}

void add_history(List *list, char *str)
{
  Node new = (Node) malloc(sizeof(Node));

  if(list->root == NULL)
  {
    new->id = 1;
    list->root = new;
  }
  else
  {
    Node currentNode = list->root;
    while(currentNode->next != NULL)
    {
      currentNode = currentNode->next;
    }
    new->id = currentNode->id+1;
    currentNode->next = new;
  }
  // add string to linked list
  new->str = str;
  new->next = NULL;
}

char *get_history(List *list, int id)
{
  if(list->root == NULL)
  {
    return "List is empty";
  }
  else
  {
    Node* temp = list->root;
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
  Node* temp = (list->root);
  while(temp != NULL)
  {
    printf("history working: %s\n", temp->str);
    temp = temp->next;
  }
}

void free_history(List *list)
{
}
