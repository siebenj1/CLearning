#include<stdio.h>
#include<string.h>
int main() {

  int counter1[] = {0,0,0,0};
  int counter2[] = {0,0,0,0};
  char s1[] = {"dbb cccccaacb cdbababdcdcdab dcdad"};
  char s2[] = {"bbbcc bdddccccad cdbbaaacaccdabdd"};
  int flag = 0;

  for(int i = 0; i < strlen(s1); i++){
    if(s1[i] == 'a'){
      counter1[0]++;
      continue;
    } else if(s1[i] == 'b'){
      counter1[1]++;
      continue;
    } else if(s1[i] == 'c'){
      counter1[2]++;
      continue;
    } else if(s1[i] == 'd'){
      counter1[3]++;
      continue;
    } else{}
  }
  for(int x = 0; x < strlen(s2); x++){
    if(s2[x] == 'a'){
      counter2[0]++;
      continue;
    } else if(s2[x] == 'b'){
      counter2[1]++;
      continue;
    } else if(s2[x] == 'c'){
      counter2[2]++;
      continue;
    } else if(s2[x] == 'd'){
      counter2[3]++;
      continue;
    } else{}
  }
  for(int z = 0; z < 4; z++){
    if(counter1[z] == counter2[z]){
      flag=0;
    } else if(counter1[z] != counter2[z]){
      flag=1;
    }
    
  }
  if(flag == 0){
    printf("Anagram!");
  } else if(flag == 1){
    printf("Not Anagram!");
  }
  
}
