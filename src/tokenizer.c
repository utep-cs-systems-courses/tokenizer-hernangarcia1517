#include <stdio.h>
#include <stdlib.h>


int string_length(char *word)
{
  char *numberOfCharacters = word;
  while(*word)
  {
    word++;
  }
  return word - numberOfCharacters;
}

int space_char(char c)
{
  if(c == ' ' || c == '\t' || c == '\n')
  {
    return 1;
  }
  return 0;
}

int non_space_char(char c)
{
  int space_char_value = space_char(c);
  if(space_char_value == 1)
  {
    return 0;
  }
  return 1;
}

char *word_start(char *str)
{
  int out = 0;
  int state = out;
  int start = 0;
  int length = string_length(str);

  for(int i = 0;i <= length; i++)
  {
    if(str[i] == '\n')
    {
      start = 1;
      i = length;
    }
    else if(str[i] == ' ' || str[i] == '\t')
    {
      state = out;
    }
    else if(state == out)
    {
      start = i;
      i = length;
    }
  }
  return &str[start];
}

char *word_end(char *str)
{
  int in = 1;
  int out = 0;
  int state = out;
  int end = 0;
  int word_count = 0;
  int length = string_length(str);

  for(int i = 0; i <= length; i++)
  {
    if(space_char(str[i]) == 1)
    {
      if(word_count == 1)
      {
        state = out;
        end = i - 1;
        i = length;
      }
      else
      {
	state = out;
      }
    }
    else if(state == out)
    {
      state = in;
      word_count++;
    }
  }
  return &str[end];
}

int count_words(char *str)
{
  int in = 1;
  int out = 0;
  int state = out;
  int word_count = 0;
  int length = string_length(str);

  for(int i = 0; i <= length; i++)
  {
    if(space_char(str[i]) == 1)
    {
      state = out;
    }
    else if(state == out)
    {
      state = in;
      word_count++;
    }
  }
  return word_count;
}

void free_tokens(char **word)
{
  int i = 0;
  while(word[i] != NULL)
  {
    free(word[i]);
    i++;
  }
  free(word);
}

void print_tokens(char **word)
{
  int i = 0;
  while(word[i] != NULL)
  {
    printf("%s\n", word[i]);
    i++;
  }
}

char **tokenize(char* str)
{
  
}

int main(char args)
{
  char testing[11] = {'t', 'e', 's', 't', ' ', 't', 'e', 's', 't', '2', '\0'};
  int test1 = non_space_char('c');
  int test2 = space_char(' ');
  int test3 = space_char('p');
  int test4 = non_space_char('\t');
  printf("1 test1: %d\n", test1);
  printf("1 test2: %d\n", test2);
  printf("0 test3: %d\n", test3);
  printf("0 test4: %d\n", test4);
  printf("this is a test %s\n", testing);
  word_start(testing);
}
