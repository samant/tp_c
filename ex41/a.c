#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void add_to_file(char word[20]);

char filename[20] = "test.txt";

int main()
{

  char word[20];
  bool stop = false;

  while (!stop) {
    printf("Enter a word :");
    scanf("%s", word);
    if ( strncmp(word, "quit", 10) != 0 ){
      add_to_file(word);
    }else{
      stop = true;
    }
  }

  return 0;
}

void add_to_file(char word[20]){
  FILE *f;
  f = fopen(filename,"a");
  if (f == NULL){
    printf("File could not be opened\n");
  }
  else {
    fprintf(f, "%s\n", word);
    fclose(f);
  }
}
