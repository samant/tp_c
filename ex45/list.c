#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "list.h"

void add_to_array(struct node **lptr, char name[10], int age){
  struct node *nptr, *pptr;
  if (*lptr == NULL){
    nptr = malloc(sizeof(struct node));
    strcpy((*nptr).name, name);
    (*nptr).age = age;
    (*nptr).nextptr = NULL;
    *lptr = nptr;
  }else{
    pptr = NULL;
    nptr = *lptr;
    while( nptr != NULL ){
      pptr = nptr;
      nptr = (*nptr).nextptr;
    }
    nptr = malloc(sizeof(struct node));
    strcpy((*nptr).name, name);
    (*nptr).age = age;
    (*nptr).nextptr = NULL;
    (*pptr).nextptr = nptr;
  }
};

void display_array(struct node *lptr) {
  while (lptr!=NULL) {
    printf("%s: %d\n", (*lptr).name, (*lptr).age);
    lptr = (*lptr).nextptr;
  }
}

void save_list(char filename[20], struct node *lptr){
  FILE *f;
  f = fopen(filename,"wb");
  if (f == NULL){
    printf("File could not be opened\n");
  }
  else {
    while (lptr!=NULL) {
      fwrite(lptr, sizeof(struct node), 1, f);
      lptr = (*lptr).nextptr;
    }
    fclose(f);
  }
}

void load_list(char filename[20], struct node **lptr){
  int nb_result;
  struct node nptr;
  FILE *f;
  f = fopen(filename,"rb");
  if (f == NULL){
    printf("File could not be opened\n");
  }
  else {
    while(!(feof(f))){
      nb_result = fread(&nptr, sizeof(struct node), 1, f);
      if (nb_result > 0){
        add_to_array(&*lptr, nptr.name, nptr.age);
      }
    }
    fclose(f);
  }
}
