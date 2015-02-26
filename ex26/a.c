#include <stdio.h>
#include <stdlib.h>

int main()
{

  int *dptr = malloc(sizeof(int));

  printf("Enter a value :");
  scanf("%d", dptr);

  printf("\nYou entered: %d \n", *dptr);

  free(dptr);

  *dptr = 2;
  printf("%p", dptr);
  printf("%d", *dptr);

  return 0;
}
