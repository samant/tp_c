#include <stdio.h>

int main(int argc, char **argv)
{

  if (argc >= 2) {

    FILE *f;
    f = fopen(argv[1],"r");

    if (f == NULL){
      printf("File could not be opened\n");
    }
    else {
      int numb, nb_result;
      while (!feof(f)) {
        nb_result = fscanf(f,"%d", &numb);
        if (nb_result > 0) {
          printf("%d\n", (numb * numb));
        }
      }
      fclose(f);
    }
  }

  return 0;
}
