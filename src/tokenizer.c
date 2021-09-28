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
  printf("this is another test %s\n", *str);
}

int main(char args)
{
  char testing[5] = {'t', 'e', 's', 't', '\0'};
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
