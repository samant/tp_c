#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct node {
  char data[10];
  struct node *nextptr;
};

void add_to_array(char word[10]);
void display_array(struct node *lptr);

struct node *list;

int main()
{

  char word[10];
  bool stop = false;

  while (!stop) {
    printf("Enter a word :");
    scanf("%s", word);
    if ( strncmp(word, "quit", 10) != 0 ){
      add_to_array(word);
    }else{
      stop = true;
    }
  }

  display_array(list);

  return 0;
}

void add_to_array(char word[10]){
  struct node *nptr, *pptr, *newptr;
  if (list == NULL){
    nptr = malloc(sizeof(struct node));
    strcpy((*nptr).data, word);
    (*nptr).nextptr = NULL;
    list = nptr;
  }else{
    pptr = NULL;
    nptr = list;
    while( (nptr != NULL) && ( strncmp( (*nptr).data, word, 10 ) < 0) ){
      pptr = nptr;
      nptr = (*nptr).nextptr;
    }
    if( (nptr == NULL) || ( strncmp(word, (*nptr).data, 10) != 0 ) ){
      newptr = malloc(sizeof(struct node));
      strcpy((*newptr).data, word);
      if (pptr == NULL){
        list = newptr;
      }else{
        (*pptr).nextptr = newptr;
      }
      (*newptr).nextptr = nptr;
    }else{
      if (pptr == NULL){
        list = (*nptr).nextptr;
      }else{
        (*pptr).nextptr = (*nptr).nextptr;
      }
      free(nptr);
    }
  }
};

void display_array(struct node *lptr) {
  int i = 0;
  while (lptr!=NULL) {
    printf("list[%d]: %s\n", i, (*lptr).data);
    lptr = (*lptr).nextptr;
    i++;
  }
}
