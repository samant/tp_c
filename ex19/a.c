#include <stdio.h>

int fact_not_rec(int x);

int main()
{

  int x, res;

  printf("Enter x :");
  scanf("%d", &x);
  res = fact_not_rec(x);
  printf("Result : %d\n", res);

  return 0;
}

int fact_not_rec(int x){
  int acc;
  int i = 0;
  while( i <= x ){
    if ( i == 0) {
      acc = 1;
    } else {
      acc = acc * i;
    }
    i++;
  }
  return acc;
}
