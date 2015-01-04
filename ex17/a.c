#include <stdio.h>

int fact_rec(int x);

int main()
{

  int x, res;

  printf("Enter x :");
  scanf("%d", &x);
  res = fact_rec(x);
  printf("Result : %d\n", res);

  return 0;
}

int fact_rec(int x){
  if (x == 0) {
    return 1;
  }else{
    return (x * fact_rec(x-1));
  }
}
