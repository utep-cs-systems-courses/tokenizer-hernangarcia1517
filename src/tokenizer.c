#include <stdio.h>
#include <stdlib.h>

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
  int size = 11;
  int countChars = 0;
  for(int i = 0; i < size; i++)
  {
    if(space_char(str[i]) == 1)
    {
      char newStr[size - i];
      countChars = 1;
    }
    if(countChars == 1)
    {
      newStr[size - (size - i)] = str[i];
    }
  }
  printf("new string: %s\n", newStr);
  return newStr;
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
