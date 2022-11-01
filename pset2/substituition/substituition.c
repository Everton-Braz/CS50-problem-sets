#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(int argc, string argv[])
{
    if(argc != 2)
    {
        printf("Usage only 1 argument");
        return 1;
    }
    if (strlen(argv[1]) < 26)
    {
        printf("The argument should contain the 26 caracteres of alphabet");
        return 1;
    }
    for (int c = 0; c < strlen(argv[1]); c++)
        if (!isupper(argv[1][c]) && !islower(argv[1][c]))
        {
        printf("The argument only should is an of the 26 caracteres of alphabet");
        return 1;
        }
    string key = argv[1];
    for (int i = 0; i < strlen(key); i++)
    {
        for (int j = i + 1; j < strlen(key); j++)
            if (toupper(key[i]) == toupper(key[j]))
            {
             printf("The argument only should is an UNIQUE of the 26 caracteres of alphabet");
             return 1;
            }
    }
    printf("%s\n", key);
    string plaintext = get_string("Type the text to encipher: ");
    for (int i = 0; i < strlen(plaintext); i++)
        if (isupper(plaintext[i]))
        {
            int letter = plaintext[i] - 65;
            printf("%c", key[letter]);
        }
        else if (islower(plaintext[i]))
        {
            int letter = plaintext[i] - 97;
            printf("%c", key[letter] + 32);
        }
        else
        {
            printf("%c", plaintext[i]);
        }
    printf("\n");
}