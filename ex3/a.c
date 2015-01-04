#include <stdio.h>

int main()
{

  int i, ten, hundred;

  printf( "Enter a value :");
  scanf("%d", &i);

  ten = (i % 100) / 10;
  hundred = (i % 1000) / 100;

  printf( "\nTens digit: %d \n", ten);
  printf( "Hundreds digit: %d \n", hundred);

  return 0;
}
