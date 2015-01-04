#include <stdio.h>

int fibona_not_rec(int x);

int main()
{

  int x, res;

  printf("Enter x :");
  scanf("%d", &x);
  res = fibona_not_rec(x);
  printf("Result : %d\n", res);

  return 0;
}

int fibona_not_rec(int x){
  int i = 0;
  int acc, prec, tmp = 0;
  while (i <= x) {
    if ((i==0) || (i==1)) {
      acc = 1;
      prec = 1;
    }else{
      tmp = acc;
      acc = acc + prec;
      prec = tmp;
    }
    i++;
  }
  return acc;
}
