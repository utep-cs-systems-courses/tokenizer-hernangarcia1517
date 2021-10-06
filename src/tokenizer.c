#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

int space_char(char c)
{
  if(c == ' ' || c == '\t')
  {
    return 1;
  }
  return 0;
}

int non_space_char(char c)
{
  if(c != ' ' && c != '\t')
  {
    return 1;
  }
  return 0;
}

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

int count_words(char *str)
{
  int n = 0;
  int i = 0;
  for(; str[i] != '\0'; i++)
  {
    if(str[i] == ' ')
    {
      n++;
    }
  }
  n++; // because of the last word
  
  return n;
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

void free_tokens(char **tokens)
{
  free(tokens);
}

void print_tokens(char **tokens)
{
  int i = 0;
  for(; tokens[i] != NULL; i++)
  {
    printf("%s\n", tokens[i]);
  }
}

char **tokenize(char* str)
{
  int i = 0;
  int token_count = count_words(str);
  char **tokens = malloc(token_count * sizeof(char*));
  char *start = str; // start pointer
  char *end = str; // end pointer

  for(; i < token_count; i++)
  {
    start = word_start(end); // pointer to the beginning of the word
    end = word_end(start); //pointer to the end of the discovered word

    tokens[i] = copy_str(start, end - start);
  }
  tokens[i] = NULL;
  
  return tokens;
}

List *init_history()
{
  List *history;
}

void print_history(List *list)
{
  printf("print history");
}

void free_history(List *list)
{
  printf("free history");
}

void addhistory(List *list, char *str)
{
  printf("add history");
}

char *get_history(List *list, int id)
{
  printf("get history");
}

int main(char args)
{
  char userInput[64];
  printf("Enter strings to tokenize: (40 characters max)\n");
  fgets(userInput, 64, stdin); // stdin is standard input, fgets comes from stdio
  printf("\n");

  printf("Output: \n");

  char **tokens = tokenize(userInput);
  print_tokens(tokens);

  free_tokens(tokens);
}
