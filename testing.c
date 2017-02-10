#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    int i,key;
    char plain[100],cipher[100];
    printf("Enter key:");
    scanf("%d",&key);
    key=key%26; // adjusting key
    fflush(stdin);
    printf("Enter text:");
    gets(plain);
    for(i=0;i<strlen(plain);i++)
    {
        if(isalpha(plain[i]))
        {
            if(islower(plain[i]))
                cipher[i]=(plain[i]+key-'a')%26+'a';
            else
                cipher[i]=(plain[i]+key-'A')%26+'A';
        }
        else
            cipher[i]=plain[i];
    }
    cipher[i]='\0';
    printf("After ciphering: %s",cipher);
    getch();
    return 0;
}