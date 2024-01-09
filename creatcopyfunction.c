#include<stdio.h>
#include<string.h>
 
void copy(char* dst, char* src){
  while (*src != '\0'){ //tells while loop to continue as long as it does not meet the terminating character of the string
    *dst = *src;
    //intial made a mistake with *src = *dst
    src++;
    dst++;
  }
  *dst = '\0';
}
 
int main(){
  char srcString[] = "We promptly judged antique ivory buckles for the next prize!";
    char i = strlen(srcString) + 1;
    char dstString[i];
    copy(dstString, srcString);
    printf("%s", dstString);
 
}
