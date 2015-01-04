#include <stdio.h>
#include <math.h>

int main()
{

  double n1, n2, t, q;

  printf("Enter n1 :");
  scanf("%lf", &n1);

  printf("Enter n2 :");
  scanf("%lf", &n2);

  q = modf((n1 / n2), &t);

  printf("Div : %f\n", t);
  printf("Fractionary part : %f\n", q);

  double l, w;

  printf("Enter l :");
  scanf("%lf", &l);

  w = trunc( fmod((l * q), 256.0) );

  printf("Char: %c\n", (char)w);

  return 0;
}
