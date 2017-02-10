#include <cs50.h>
#include <stdio.h>

// declaring my variables
int main(void){
  int space;
  int hash;
  int i;
  int height;

  do
  {
    printf("Height:");
    height=GetInt();
  }
  while(height <= 0 || height >23);
  printf("\n");

  for (i = 0 ; i < height; i++)
     {
       for (space = (height-i); space > 0 ; space --){
         printf(" ");
     }
       for (hash = 1 ;hash <= (i+1); hash++){
         printf("#");
       }
       printf("  ");
       for ( hash = 1; hash <= (i+1); hash++) {
         printf("#");
       }
       for (space = (height-i); space > 0 ; space --){
         printf(" ");
       }
       printf("\n");
       }
  return 0;
  }
 