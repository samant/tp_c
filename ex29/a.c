#include <stdio.h>
#include <string.h>

struct user {
  char firstname[10];
  char lastname[10];
  int age;
};

void display_users();
void add_user(struct user current_user);

int nb_elem = 3;

struct user users[3];

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
    add_user(current_user);
    i++;
  }

  display_users();

  return 0;

}

void display_users(){
  int i = 0;
  while(i < nb_elem){
    printf("%s %s - age: %d\n", users[i].firstname, users[i].lastname, users[i].age);
    i++;
  }
}

void add_user(struct user current_user){
  int x = 0;
  while( (strlen(users[x].firstname) > 0) && ( strncmp( users[x].firstname, current_user.firstname, 10 ) < 0) ){
    x++;
  }
  int place = x;
  int i = nb_elem;
  while ( i > place ) {
    users[i] = users[i-1];
    i--;
  }
  users[i] = current_user;
}
