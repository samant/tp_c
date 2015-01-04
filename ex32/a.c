#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
  int data;
  struct node *nextptr;
};

struct node *readList();
void printList(struct node *lptr);
struct node * invert_order(struct node *list);

int main()
{
  struct node *list;
  list = readList();
  printf("Normal order\n");
  printList(list);
  list = invert_order(list);
  printf("Inverted order\n");
  printList(list);
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

struct node *readList() {
  struct node *nptr,*aptr,*lptr;
  int num;
  printf("Enter a value :");
  scanf("%d",&num);
  if (num == -1)
    return NULL;
  else {
    lptr = malloc(sizeof(struct node));
    (*lptr).data = num;
    aptr = lptr;
    scanf("%d",&num);
    while (num != -1) {
      nptr = malloc(sizeof(struct node));
      (*nptr).data = num;
      (*aptr).nextptr = nptr;
      aptr = nptr;
      scanf("%d",&num);
    }
    (*aptr).nextptr = NULL;
    return lptr;
  }
}

void printList(struct node *lptr) {
  int i = 0;
  while (lptr!=NULL) {
    printf("list[%d]: %d\n", i, (*lptr).data);
    lptr = (*lptr).nextptr;
    i++;
  }
}
