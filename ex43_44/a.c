#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void add_to_file(int number);
void read_file();

char filename[20] = "test.bin";

int main()
{

  int number;
  bool stop = false;

  while (!stop) {
    printf("Enter a number :");
    scanf("%d", &number);
    if ( number != -1 ){
      add_to_file(number);
    }else{
      stop = true;
    }
  }

  read_file();

  return 0;
}

void add_to_file(int number){
  FILE *f;
  f = fopen(filename,"ab");
  if (f == NULL){
    printf("File could not be opened\n");
  }
  else {
    fwrite(&number, sizeof(int), 1, f);
    fclose(f);
  }
}

void read_file(){
  int number, nb_result;
  FILE *f;
  f = fopen(filename,"rb");
  if (f == NULL){
    printf("File could not be opened\n");
  }
  else {
    while(!(feof(f))){
      nb_result = fread(&number, sizeof(int), 1, f);
      if (nb_result > 0){
        printf("%d\n", (number * number));
      }
    }
    fclose(f);
  }
}
