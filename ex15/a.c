#include <stdio.h>

void display_array();

int length = 3;
int array[3] = { 1, 2, 3 };

int main()
{

  display_array();

  return 0;
}

void display_array(){
  int i = 0;
  while(i < length) {
    printf("tab[%d]: %d\n",i , array[i]);
    i++;
  };
}
