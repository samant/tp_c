#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
  int data;
  struct node *nextptr;
};

void add_to_array(int value);
void display_array(struct node *lptr);

struct node *list;

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

  display_array(list);

  return 0;
}

void add_to_array(int value){
  struct node *nptr, *pptr;
  if (list == NULL){
    nptr = malloc(sizeof(struct node));
    (*nptr).data = value;
    (*nptr).nextptr = NULL;
    list = nptr;
  }else{
    pptr = NULL;
    nptr = list;
    while( nptr != NULL ){
      pptr = nptr;
      nptr = (*nptr).nextptr;
    }
    nptr = malloc(sizeof(struct node));
    (*nptr).data = value;
    (*nptr).nextptr = NULL;
    (*pptr).nextptr = nptr;
  }
};

void display_array(struct node *lptr) {
  int i = 0;
  while (lptr!=NULL) {
    printf("list[%d]: %d\n", i, (*lptr).data);
    lptr = (*lptr).nextptr;
    i++;
  }
}
