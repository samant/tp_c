#include <stdio.h>

int fibona_rec(int x);

int main()
{

  int x, res;

  printf("Enter x :");
  scanf("%d", &x);
  res = fibona_rec(x);
  printf("Result : %d\n", res);

  return 0;
}

int fibona_rec(int x){
  if ( (x == 0) || (x == 1) ) {
    return 1;
  } else {
    return (fibona_rec(x-1) + fibona_rec(x-2));
  }
}
