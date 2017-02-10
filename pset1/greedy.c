#include <cs50.h>
#include <stdio.h>
#include<math.h>

// declaring my variables
int main(void){
int count = 0;
float user_input;
float cents;

// askig user for input
  do
  {
    printf("O hai! How much change is owed?");
    user_input = get_float();
    cents = user_input * 100;
    // converting decimal number to nearest int
    cents = roundf(cents);
  }
  //checking user input
  while( user_input < 0);
  //looping through number of cents
  while (cents >= 25)
  {
    count += 1;
    cents -= 25;
  }
  while (cents >= 10)
  {
    count += 1;
    cents -= 10;
  }
  while (cents >= 5)
  {
    count += 1;
    cents -= 5;
  }
  while (cents >= 1)
  {
    count += 1;
    cents -= 1;
  }
  // printing number of coins 
  printf ( "%i\n", count);
}