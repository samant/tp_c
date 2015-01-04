#include <stdio.h>

void change_sign_by_value(int i);

void change_sign_by_address(int *i);

int main()
{

  int i = 3;

  printf("Call by value\n");
  printf("Before: %d\n", i);
  change_sign_by_value(i);
  printf("After: %d\n", i);

  printf("Call by address\n");
  printf("Before: %d\n", i);
  change_sign_by_address(&i);
  printf("After: %d\n", i);

  return 0;
}

void change_sign_by_value(int i){
  i = -i;
}

void change_sign_by_address(int *i){
  *i = -*i;
}
