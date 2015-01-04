#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

int main()
{

  int max_val;
  int nb_elem = 50;

  printf("Enter maximun random value :");
  scanf("%d", &max_val);

  int i = 0;
  int array[nb_elem];

  srand(time(NULL));

  while(i < nb_elem) {
    array[i] = rand() % max_val + 1;
    printf("tab[%d]: %d\n",i , array[i]);
    i++;
  };

  int start, end, length, prec = 0;
  i = 0;
  while(i < nb_elem){
    if(prec > array[i]){
      end = i - 1;
      if( start != end ){
        printf("Start: %d\n", start);
        printf("End: %d\n", end);
        if( (end-start+1) > length){
          length = (end-start+1);
        };
      };
      start = i;
      end = i;
    };
    prec = array[i];
    i++;
  };

  printf("Longest: %d\n",length);

  return 0;

}
