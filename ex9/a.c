#include <stdio.h>
#include <stdbool.h>

int main()
{

  int i = 1;
  bool cont = true;
  double u = 0;
  double v = 0;

  while(cont) {
    u = 1 / (double)(i*i);
    v = v + u;
    printf("n: %d\n", i);
    printf("U(n): %lf\n", u);
    printf("V(n): %lf\n", v);
    cont = (u > 0.001);
    i++;
  };

  return 0;
}
