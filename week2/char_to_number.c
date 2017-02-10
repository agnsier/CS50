#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{   
    //ask user for input
    string s = get_string();
    // check corectness
    if ( s != NULL)
    {
        //iterate over a characters in s one at a time
        for ( int i = 0, n = strlen(s) ; i < n ; i++)
        {
            printf("%c\n", s[i]);
        }
    }

}