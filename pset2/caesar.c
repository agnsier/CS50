# include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h> //for atoi
int main (int argc, string argv[])
{   
    //checking valdity of argc
    if (argc != 2)
    {
        printf("Usage: ./caesar k");
        return 1;
    }
    // changing string_key to integer
    int key = atoi(argv[1]);
    // in case od key less than 0 return error
    if (key < 0)
    {
        return 1;
    }
    else
    {
        //asking for input
        printf("plaintext:");
        string plaintext = get_string();
        int len_plaintext = strlen(plaintext);
        // creating loop for iterating through each character in string
        printf("ciphertext:");
        for (int j = 0; j < len_plaintext; j++)
        {
            //checking if letter is lowercase or upper
            if islower(plaintext[j])
                printf("%c",(((plaintext[j] + key) - 97) % 26) + 97);
            else if isupper(plaintext[j])
                printf("%c", (((plaintext[j] + key) - 65) % 26) + 65);
            //in case of numbers
            else
                printf("%c", plaintext[j]);
        }
        printf("\n");
        return 0;
    }
}