#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
int main(void)
{
    int i;
    string name = get_string();
    printf("%c", toupper(name[0]));
    for (i = 1; i < strlen(name); i++)
    {   string blank = " ";

        if (name[i-1] == blank[0])
        {
            printf ("%c", toupper(name[i]));
        }
        else
        {
            continue;
        }
        }
     printf("\n");
    }