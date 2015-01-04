#include <stdio.h>
#include <math.h>

int main()
{

  int i = 0;
  double array[32];

  while(i < 32) {
    array[i] = pow((double)2, (double)i);
    printf("tab[%d]: %lf\n",i , array[i]);
    i++;
  };

  return 0;
}
