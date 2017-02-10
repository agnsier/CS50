#include <stdio.h>
#include <cs50.h>
int main(void)
{
    printf("Minutes:");
    int m = get_int();
    int y = 12;
    int i = m*y;
    printf("Bottles:%i\n", i);
}