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
      char ch;
      printf("The contents of %s file are :\n", argv[1]);
      while( ( ch = fgetc(f) ) != EOF ) {
        printf("%c",ch);
      }
      fclose(f);
    }
  }

  return 0;
}
