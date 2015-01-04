#include <stdio.h>

int main()
{
  int nb_elem = 3;

  struct user {
    char firstname[10];
    char lastname[10];
    int age;
  };

  struct user users[nb_elem];

  int i = 0;
  while(i < nb_elem){
    printf("User %d\n", i);
    printf("Firstname:");
    scanf("%s", users[i].firstname);
    printf("Lastname:");
    scanf("%s", users[i].lastname);
    printf("Age:");
    scanf("%d", &users[i].age);
    printf("%s %s - age: %d\n", users[i].firstname, users[i].lastname, users[i].age);
    i++;
  }

  return 0;

}
