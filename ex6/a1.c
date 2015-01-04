#include <stdio.h>

int main()
{

  int x;

  printf("Enter x :");
  scanf("%d", &x);

  int i = 1;
  double res;

  while(i <= x) {
    res = 2 * i;
    printf("%d\n", (int)res);
    i++;
  };

  return 0;
}
