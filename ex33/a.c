#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct node {
  char data[10];
  struct node *nextptr;
};

struct node *readList();
void printList(struct node *lptr);

int main()
{
  struct node *list;
  list = readList();
  printList(list);
  return 0;
}

struct node *readList() {
  struct node *nptr,*aptr,*lptr, *precptr;
  char word[10];
  printf("Enter a word :");
  scanf("%s",word);
  if ( strncmp(word, "quit", 10) == 0 ){
    return NULL;
  }
  else {
    lptr = malloc(sizeof(struct node));
    strcpy((*lptr).data, word);
    (*lptr).nextptr = NULL;
    scanf("%s",word);
    while(strncmp(word, "quit", 10) != 0) {

      nptr = malloc(sizeof(struct node));
      strcpy((*nptr).data, word);

      aptr = lptr;
      precptr = NULL;
      while( (aptr != NULL) && ( strncmp( (*aptr).data, word, 10 ) < 0) ){
        precptr = aptr;
        aptr = (*aptr).nextptr;
      }

      if (precptr == NULL){
        lptr = nptr;
      }else{
        (*precptr).nextptr = nptr;
      }

      (*nptr).nextptr = aptr;

      printList(lptr);

      scanf("%s",word);
    }
    return lptr;
  }
}

  void printList(struct node *lptr) {
    int i = 0;
    while (lptr!=NULL) {
      printf("list[%d]: %s\n", i, (*lptr).data);
      lptr = (*lptr).nextptr;
      i++;
    }
  }
