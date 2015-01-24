#ifndef _LIST_H_
#define _LIST_H_

struct node {
  char name[10];
  int age;
  struct node *nextptr;
};

void add_to_array(struct node **lptr, char name[10], int age);
void display_array(struct node *lptr);
void load_list(char filename[20], struct node **lptr);
void save_list(char filename[20], struct node *lptr);

#endif
