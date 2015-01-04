#include <stdio.h>

int main()
{

  int a, b;

  printf("Enter A :");
  scanf("%d", &a);

  printf("Enter B :");
  scanf("%d", &b);

  if ( ((a >= 0) && (b >= 0)) || ((a < 0) && (b < 0)) ) {
    printf("TRUE\n");
  } else {
    printf("FALSE\n");
  }

  return 0;
}
