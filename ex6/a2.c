#include <stdio.h>

int main()
{

  int x;

  printf("Enter x :");
  scanf("%d", &x);

  int i = 1;
  double res;

  while(i <= x) {
    res = ( 1 / (double)i);
    printf("%lf\n", res);
    i++;
  };

  return 0;
}
