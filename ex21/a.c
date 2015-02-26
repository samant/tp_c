#include <stdio.h>

int main()
{

  int x, *xptr;
  x = 3;
  xptr = &x;

  printf("x: %d\n", x);
  printf("*xptr: %d\n", *xptr);
  printf("Increment\n");
  *xptr = (*xptr) + 5;
  printf("x: %d\n", x);
  printf("*xptr: %d\n", *xptr);

  return 0;
}
