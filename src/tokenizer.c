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

int main(char args)
{
  printf("testpassed4\n");
  int x = space_char(' ');
  printf("bool: %d\n", x);
}
