#include <stdio.h>
#include <cs50.h>
int main(void)
{  
    for ( int i = 65; i < 90; i++)
    {
        printf("%c is %i\n", (char) i, i);
        // or printf("%c is %i\n", i, i); 
    }
}