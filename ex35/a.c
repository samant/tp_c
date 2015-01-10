#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct node {
  char data[10];
  struct node *nextptr;
};

struct node *new_list();
void add_to_array(char word[10]);
void display_array(struct node *lptr);

struct node *list;

int main()
{
  list = new_list();
  
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

struct node *new_list() {
  struct node *lptr;
  lptr = malloc(sizeof(struct node));
  strcpy((*lptr).data, "");
  (*lptr).nextptr = NULL;
  return lptr;
}

void add_to_array(char word[10]){
  struct node *nptr, *pptr, *newptr;
  pptr = NULL;
  nptr = list;
  while( (nptr != NULL) && ( strncmp( (*nptr).data, word, 10 ) < 0) ){
    pptr = nptr;
    nptr = (*nptr).nextptr;
  }
  newptr = malloc(sizeof(struct node));
  strcpy((*newptr).data, word);
  if (pptr == NULL){
    list = newptr;
  }else{
    (*pptr).nextptr = newptr;
  }
  (*newptr).nextptr = nptr;
};

void display_array(struct node *lptr) {
  int i = 0;
  lptr = (*lptr).nextptr;
  while (lptr!=NULL) {
    printf("list[%d]: %s\n", i, (*lptr).data);
    lptr = (*lptr).nextptr;
    i++;
  }
}
