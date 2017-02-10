#include <cs50.h>
#include <stdio.h>
#include <string.h>
int main (int argc, string argv[])
{
    //iterate over strings in argv
    for (int i = 0; i < argc; i++)
    {
        //iterate over characters in current string
        for (j = 0, n = strlen(argv[1]); j <n ; j++)
        {
            //printf j'th character in i'th string 
            printf("%c\n", argv[i][j]);
        }
    }
}