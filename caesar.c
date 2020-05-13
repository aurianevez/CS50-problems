#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if (argc < 2 || argc > 2)
    {
        printf("Usage: ./caesar.c key\n");
        return 1;
    }

    if (argc == 2)
    {
        for (int i = 0; i < strlen(argv[1]); i++)
        {
            // if there is a letter in the string argv[1] - isalpha / return 1 stops the program as well
            if (isalpha(argv[1][i]))
            {
                printf("Usage: ./caesar.c key\n");
                return 1;
            }

        }

        // if no letter then print argv[1] as an integer - the function atoi transform a string into int
        //printf("Sucsess\n");
        //printf("%i\n", atoi(argv[1]));
    }

    //prompting for the plaintext
    string plaintext = get_string("plaintext : ");

    //the function atoi transform a string into int
    int j = atoi(argv[1]);

    printf("ciphertext: ");

    // if we print %c the computer will show us the the character - however char are actually number - that why
    // we can write this : >= 'a'
    // ((((plaintext[i] - 97) + j) % 26) + 97) : i first transforme the char in an index from o to 25 with -97 then had the key then use %26 to make sure we
    // go back to 0 after z and finally convert back to ASCII with + 97
    // This loop goes over every character of the plaintext that the user as prompt.
    // not that char are quote in sigle ' ' // print in " "

    for (int i = 0; i < strlen(plaintext); i++)
    {
        if (plaintext[i] >= 'a' && plaintext[i] <= 'z')
        {
            printf("%c", ((((plaintext[i] - 97) + j) % 26) + 97));
        }

        if (plaintext[i] >= 'A' && plaintext[i] <= 'Z')
        {
            printf("%c", ((((plaintext[i] - 65) + j) % 26) + 65));
        }

        if (plaintext[i] == ' ')
        {
            printf(" ");
        }

        if (plaintext[i] == '.' || plaintext[i] == '!' || plaintext[i] == '?' || plaintext[i] == ',')
        {
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");

}