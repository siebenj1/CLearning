#include <stdio.h>
#include <stdbool.h>
bool is_leap_year(int year){
  if (year % 4 != 0){
    return false;
  } else if(year % 100 != 0){
    return true;
  }  else if(year % 400 != 0){
    return false;
  } else {
    return true;
  }
}
/* 
another possible solution below
bool is_leap_year(int year) {
    return (year % 4 == 0 && (year % 100 || year % 400 == 0));
}
*/ 
int days_in_month[]={0,31,28,31,30,31,30,31,31,30,31,30,31};

void add_days_to_date(int* mm, int* dd, int* yy, int days_left_to_add){
  int days_left_in_month;
  while (days_left_to_add > 0){
    days_left_in_month = days_in_month[*mm] - *dd;    
    if (*mm == 2 && is_leap_year(*yy) == true){
      days_in_month[2] += 1;
    } 
    if (days_left_to_add > days_left_in_month){
      days_left_to_add -= days_left_in_month + 1;
      *dd = 1;
      if(*mm == 12){
        *mm = 1;
        /*  yy--; causes segment fault when using more than 32 days  */
        *yy = *yy +1;
      } else {
        *mm = *mm +1;
        /*  mm--; causes segment fault when using more than 32 days  */
      }
    } else {
      *dd += days_left_to_add;
      days_left_to_add = 0;
    }
  }
}

int main() {
  int mm;
  int dd;
  int yy;
  int days_left_to_add;
  printf("please enter in the date and the amount of days to add\n (dd mm yy days to add)");
  scanf("%d%d%d%d", &mm, &dd, &yy, &days_left_to_add);
  add_days_to_date(&mm, &dd, &yy, days_left_to_add);
  printf("The date would be.\n %d %d %d\n", mm, dd, yy);
  

  if (is_leap_year(yy) == true){
    printf("Leap Year\n");
  } else{
    printf("Not Leap Year\n");
  }
}
