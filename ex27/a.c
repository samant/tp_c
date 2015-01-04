#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void display_array();
void add_to_array(int value);

int *array;
int length = 0;

int main()
{

  int value;
  bool stop = false;

  while (!stop) {
    printf("Enter a value :");
    scanf("%d", &value);
    if ( value != -1 ){
      add_to_array(value);
    }else{
      stop = true;
    }
  }

  display_array();

  free(array);

  return 0;
}

void add_to_array(int value){
  int *new_array, *new_array_ptr, *old_array_ptr;
  new_array = malloc((length + 1)*sizeof(int));
  old_array_ptr = array;
  new_array_ptr = new_array;
  int i = 0;
  while (i < length) {
    *new_array = *array;
    array++;
    new_array++;
    i++;
  }
  free(old_array_ptr);
  *new_array = value;
  array = new_array_ptr;
  length++;
};

void display_array(){
  int i = 0;
  while (i < length) {
    printf("tab[%d]: %d\n",i ,array[i]);
    i++;
  }
}
