#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
  int number;
  struct node *nextptr;
};

struct node *new_list();
struct node *create_list(int array[3]);
struct node *list_fusion(struct node *lptr1, struct node *lptr2);
void add_to_array(struct node *lptr, int nb);
void display_array(struct node *lptr);

struct node *list1;
struct node *list2;
struct node *final_list;

int main()
{
  int array1[3] = {1,4,7};
  int array2[3] = {3,12,21};

  list1 = create_list(array1);
  printf("List 1\n");
  display_array(list1);

  list2 = create_list(array2);
  printf("List 2\n");
  display_array(list2);

  final_list = list_fusion(list1, list2);
  printf("Final List\n");
  display_array(final_list);

  return 0;
}

struct node *create_list(int array[3]){
  struct node *lptr;
  lptr = new_list();
  int i = 0;
  while( i< 3){
    add_to_array(lptr, array[i]);
    i++;
  }
  return lptr;
}

struct node *new_list() {
  struct node *lptr;
  lptr = malloc(sizeof(struct node));
  (*lptr).number = -1;
  (*lptr).nextptr = NULL;
  return lptr;
}

void add_to_array(struct node *lptr, int nb){
  struct node *nptr, *pptr;
  pptr = NULL;
  nptr = lptr;
  while( nptr != NULL ){
    pptr = nptr;
    nptr = (*nptr).nextptr;
  }
  nptr = malloc(sizeof(struct node));
  (*nptr).number = nb;
  (*nptr).nextptr = NULL;
  (*pptr).nextptr = nptr;
};

struct node *list_fusion(struct node *lptr1, struct node *lptr2){
  struct node *nptr1, *nptr2, *current, *res;
  nptr1 = (*lptr1).nextptr;
  nptr2 = (*lptr2).nextptr;
  current = new_list();
  res = current;
  while( (nptr1 != NULL) || (nptr2 != NULL) ){
    if ( (nptr2 == NULL) || ( (nptr1 != NULL) && ((*nptr1).number <= (*nptr2).number) ) ){
      (*current).nextptr = nptr1;
      nptr1 = (*nptr1).nextptr;
    } else {
      (*current).nextptr = nptr2;
      nptr2 = (*nptr2).nextptr;
    }
    current = (*current).nextptr;
  }
  return res;
};

void display_array(struct node *lptr) {
  int i = 0;
  lptr = (*lptr).nextptr;
  while (lptr!=NULL) {
    printf("list[%d]: %d\n", i, (*lptr).number);
    lptr = (*lptr).nextptr;
    i++;
  }
}
