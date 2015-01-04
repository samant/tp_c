#include <stdio.h>
#include <math.h>

int main()
{

  int x;

  printf("Enter x :");
  scanf("%d", &x);

  int i = 0;
  double res = 0;

  while(i <= x) {
    res = res + (1 / pow((double) 2, (double)i));
    i++;
  };

  printf("%lf\n", res);

  return 0;
}
