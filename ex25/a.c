#include <stdio.h>

int sum_array(int *array);

int main()
{

  int array[4] = { 1, 2, 3, -1 };

  int res;

  res = sum_array(array);

  printf("Result: %d\n", res);

  return 0;

}

int sum_array(int *array){
  int acc = 0;
  while (*array != -1) {
    acc = acc + *array;
    array++;
  }
  return acc;
}
