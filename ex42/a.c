#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void readfile();
void add_to_file(char name[20], int age);

char filename[20] = "clients.txt";

int main()
{

  readfile();

  char name[20];
  int age;
  bool stop = false;

  while (!stop) {
    printf("Enter a name :");
    scanf("%s", name);
    if ( strncmp(name, "quit", 10) != 0 ){
      printf("Enter age :");
      scanf("%d", &age);
      add_to_file(name, age);
    }else{
      stop = true;
    }
  }

  return 0;
}

void readfile(){
  FILE *f;
  f = fopen(filename,"r");
  if (f != NULL){
    int age, nb_result;
    char name[20];
    while (!feof(f)) {
      nb_result = fscanf(f,"%20s %5d\n", name, &age);
      if (nb_result > 0) {
        printf("%20s %5d\n", name, age);
      }
    }
    fclose(f);
  }
}

void add_to_file(char name[20], int age){
  FILE *f;
  f = fopen(filename,"a");
  if (f == NULL){
    printf("File could not be opened\n");
  }
  else {
    fprintf(f, "%20s %5d\n", name, age);
    fclose(f);
  }
}
