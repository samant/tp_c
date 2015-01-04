#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

int main()
{

  int x, guess;

  srand(time(NULL));
  x = rand() % 100 + 1;
  printf("%d\n", x);

  bool res = false;

  while(!res) {

    printf("Enter a number :");
    scanf("%d", &guess);
    res = (guess == x);

  };

  printf("You win!\n");

  return 0;
}
