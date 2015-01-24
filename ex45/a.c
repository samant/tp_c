#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "list.h"

char filename[20] = "test.bin";

struct node *list;

int main()
{

  load_list(filename, &list);
  display_array(list);

  char name[10];
  int age;
  bool stop = false;
  while (!stop) {
    printf("Enter a name :");
    scanf("%s", name);
    if ( strncmp(name, "quit", 10) != 0 ){
      printf("Enter age :");
      scanf("%d", &age);
      add_to_array(&list, name, age);
    }else{
      stop = true;
    }
  }

  save_list(filename, list);
  display_array(list);

  return 0;
}
