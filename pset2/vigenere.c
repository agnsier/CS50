# include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main (int argc, string argv[])
{   
    // input key ;
    string key = argv[1];
    int shift;

   
    //checking valdity of argc, we want 2 arguments;
    if (argc != 2)
    {
        printf("Usage: ./caesar k");
        return 1;
    }
    // loop throug all characters and check if they are alphabetical if not return 1;
    for ( int i = 0, j = strlen(key); i < j; i++)
    {
        if (!isalpha(key[i]))
        {
            printf("Usage: ./caesar k");
            return 1;
        }
    }
    
    //asking for input
    printf("plaintext:");
    string plaintext = get_string();
    int len_plaintext = strlen(plaintext);
        // creating loop for iterating through each character in string
    printf("ciphertext:");
    for (int i = 0, j = 0; i < len_plaintext; i ++, j++)
        {    
            //ABC.. Z --> ABC.. Z round alphabeth 
            if (j >= strlen(key))
            {
                j = 0;
            }
            int key_value = key[j];
            // if character isn't letter j won't icrease
            if (!isalpha(plaintext[i]))
            {
                j = (j - 1);
            }  
            // Aa = 0 && Zz = 25 for uppercase letters 'a' = 97 'A'= 65
            if ((key_value >= 'A') && (key_value <= 'Z'))
            {
                key_value = (key_value - 'A');
            }
            // Aa = 0 && Zz = 25 for lowercase letters
            if ((key_value >= 'a') && (key_value <= 'z'))
            {
                key_value = (key_value - 'a');
            }
            
            shift = (plaintext[i] + key_value);
            
            if (isupper(plaintext[i]) && (shift > 'Z'))
            {
                shift = (shift - 26);
            }
            if (islower(plaintext[i]) && (shift > 'z'))
            {
                shift = (shift - 26);
            }
            // if character is alphabetical print
            if (isalpha(plaintext[i]))
            {
                printf("%c", shift);
            }
 
            // if non-alphabetical character, print as is   
            else
            {
                printf("%c", plaintext[i]);
            } 
        }  
    printf("\n");
    return 0;
}