#include <stdio.h>

int main(){


for (int superdeduper = 1; superdeduper < 100; superdeduper++) {
  if (superdeduper % 15 == 0){
    printf("Fizz Buzz\n");;
    continue;
  } else if (superdeduper % 5 == 0){
    printf("Buzz\n");
    continue;
  } else if (superdeduper % 3 ==0){
    printf("Fizz\n");
    continue;
  }
  printf("%d\n",superdeduper);
  }

}
