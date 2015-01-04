#include <stdio.h>

void display_array(int array[], int array_l);

int main()
{

  int length = 3;
  int array[3] = { 1, 2, 3 };

  display_array(array, length);

  return 0;
}

void display_array(int array[], int array_l){
  int i = 0;
  while(i < array_l) {
    printf("tab[%d]: %d\n",i , array[i]);
    i++;
  };
}
