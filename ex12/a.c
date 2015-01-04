#include <stdio.h>

int main()
{

  int max_val;

  printf("Enter maximun value :");
  scanf("%d", &max_val);

  int i = 0;
  int array[max_val];

  while(i < max_val) {
    array[i] = i+1;
    i++;
  };

  int v;
  i = 1;
  while(i < max_val) {
    if(array[i] != 0) {
      v = (i+1);
      while(v < max_val) {
        if( (array[v] % (i+1)) == 0) {
          array[v] = 0;
        };
        v++;
      };
    };
    i++;
  };

  i = 0;
  while(i < max_val) {
    printf("Tab[%d]: %d \n",i , array[i]);
    i++;
  };

  return 0;
}
