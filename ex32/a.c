#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
  int data;
  struct node *nextptr;
};

void add_to_array(int value);
void display_array(struct node *lptr);
struct node *invert_order(struct node *list);

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

  printf("Normal order\n");
  display_array(list);
  struct node *inverted_list = invert_order(list);
  printf("Inverted order\n");
  display_array(inverted_list);

  return 0;
}

struct node *invert_order(struct node *list){
  if ( list == NULL) {
    return NULL;
  }
  if ( (*list).nextptr == NULL ){
    return list;
  } else {
    struct node *rest = (*list).nextptr;
    (*list).nextptr = NULL;
    struct node *inverted_rest = invert_order(rest);
    (*rest).nextptr = list;
    return inverted_rest;
  }
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
