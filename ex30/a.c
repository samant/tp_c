#include <stdio.h>
#include <string.h>

struct user {
  char firstname[10];
  char lastname[10];
  int age;
};

void display_users_by(struct user *array[]);
void add_user(int i, struct user current_user);
void add_user_by_age(struct user *current_user);
void add_user_by_name(struct user *current_user);

int nb_elem = 3;

struct user users[3];
struct user *ages[3];
struct user *names[3];

int main()
{

  struct user current_user;

  int i = 0;
  while(i < nb_elem){
    printf("User %d\n", i);
    printf("Firstname:");
    scanf("%s", current_user.firstname);
    printf("Lastname:");
    scanf("%s", current_user.lastname);
    printf("Age:");
    scanf("%d", &current_user.age);
    add_user(i, current_user);
    i++;
  }

  printf("Display by name\n");
  display_users_by(names);
  printf("Display by age\n");
  display_users_by(ages);

  return 0;

}

void display_users_by(struct user *array[]){
  int i = 0;
  while(i < nb_elem){
    printf("%s %s - age: %d\n", (*array[i]).firstname, (*array[i]).lastname, (*array[i]).age);
    i++;
  }
}

void add_user(int i, struct user current_user){
  users[i] = current_user;
  add_user_by_age(&users[i]);
  add_user_by_name(&users[i]);
}

void add_user_by_age(struct user *current_user){
  int x = 0;
  while( (ages[x] != NULL) && ( (*ages[x]).age < (*current_user).age ) ){
    x++;
  }
  int place = x;
  int i = nb_elem;
  while ( i > place ) {
    ages[i] = ages[i-1];
    i--;
  }
  ages[i] = current_user;
}

void add_user_by_name(struct user *current_user){
  int x = 0;
  while( (names[x] != NULL) && (strlen((*names[x]).firstname) > 0) && ( strncmp( (*names[x]).firstname, (*current_user).firstname, 10 ) < 0) ){
    x++;
  }
  int place = x;
  int i = nb_elem;
  while ( i > place ) {
    names[i] = names[i-1];
    i--;
  }
  names[i] = current_user;
}
