#include <stdio.h>
#include <stdlib.h>

int main()
{

  int *dptr;
  dptr = malloc(sizeof(int));

  printf("Enter a value :");
  scanf("%d", dptr);

  printf("\nYou entered: %d \n", *dptr);

  free(dptr);

  return 0;
}
