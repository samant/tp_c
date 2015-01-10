#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct node {
  char name[10];
  int age;
  struct node *prevptr;
  struct node *nextptr;
};

void add_to_array(char name[10], int age);
void display_array(struct node *lptr);
void display_mean_age(struct node *lptr);

struct node *list;

int main()
{

  char name[10];
  int age;
  bool stop = false;

  while (!stop) {
    printf("Enter a name :");
    scanf("%s", name);
    if ( strncmp(name, "quit", 10) != 0 ){
      printf("Enter age :");
      scanf("%d", &age);
      add_to_array(name, age);
    }else{
      stop = true;
    }
  }

  display_array(list);

  display_mean_age(list);

  return 0;
}

void add_to_array(char name[10], int age){
  struct node *nptr, *pptr;
  if (list == NULL){
    nptr = malloc(sizeof(struct node));
    strcpy((*nptr).name, name);
    (*nptr).age = age;
    (*nptr).nextptr = NULL;
    (*nptr).prevptr = NULL;
    list = nptr;
  }else{
    pptr = NULL;
    nptr = list;
    while( nptr != NULL ){
      pptr = nptr;
      nptr = (*nptr).nextptr;
    }
    nptr = malloc(sizeof(struct node));
    strcpy((*nptr).name, name);
    (*nptr).age = age;
    (*nptr).nextptr = NULL;
    (*nptr).prevptr = pptr;
    (*pptr).nextptr = nptr;
  }
};

void display_array(struct node *lptr) {
  while (lptr!=NULL) {
    printf("%s: %d\n", (*lptr).name, (*lptr).age);
    lptr = (*lptr).nextptr;
  }
}

void display_mean_age(struct node *lptr) {
  double acc = 0;
  int i = 0;
  while (lptr!=NULL) {
    acc = acc + (*lptr).age;
    lptr = (*lptr).nextptr;
    i++;
  }
  printf("Mean age: %lf\n", (acc/(double)i));
}
