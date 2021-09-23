#include "bst.h"  
  
int main(int argc, char **argv)	/* prints arguments in order */
{
  printf("hello but this is from sortargs\n");
  for (char **p = &argv[1]; *p; p++)
    bstInsert(&bstRoot, *p);
  bstPrint(bstRoot);
  bstClear(&bstRoot);
}
