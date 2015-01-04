#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main()
{

  int max_val;
  int nb_elem = 50;

  printf("Enter maximun random value :");
  scanf("%d", &max_val);

  int i = 0;
  int array[nb_elem];

  double acc = 0;
  int min = max_val;
  int max = 0;
  srand(time(NULL));

  while(i < nb_elem) {
    array[i] = rand() % max_val + 1;
    printf("tab[%d]: %d\n",i , array[i]);
    acc = acc + array[i];
    if (array[i] < min) {
      min = array[i];
    };
    if (array[i] > max) {
      max = array[i];
    };
    i++;
  };

  double mean = acc / (double)nb_elem;

  printf("Min: %d\n", min);
  printf("Max: %d\n", max);
  printf("Mean: %lf\n", mean);

  return 0;
}
