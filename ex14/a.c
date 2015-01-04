#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

int main()
{

  int year;

  printf("Enter a year :");
  scanf("%d", &year);

  enum Months
  {
    january,
    february,
    march,
    april,
    mai,
    june,
    july,
    august,
    september,
    october,
    november,
    december
  };

  int month_days[12];

  month_days[january] = 31;
  if( ((year % 4) == 0) && !(((year % 400) != 0) && ((year % 100) == 0)) ) {
    month_days[february] = 29;
  } else {
    month_days[february] = 28;
  }
  month_days[march] = 31;
  month_days[april] = 30;
  month_days[mai] = 31;
  month_days[june] = 30;
  month_days[july] = 31;
  month_days[august] = 31;
  month_days[september] = 30;
  month_days[october] = 31;
  month_days[november] = 30;
  month_days[december] = 31;

  enum Months i = january;
  while(i <= december){
    printf("Number of days for %d : %d \n",(i + 1) , month_days[i]);
    i++;
  }

  return 0;

}
