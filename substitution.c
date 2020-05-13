#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, string argv[])
{
    if (argc == 1)
    {
        printf("Usage: ./substituion.c key\n");
        return 1;
    }

    if (strlen(argv[1]) != 26)
    {
        printf("key must contain 26 characters\n");
        return 1;
    }

    if (argc == 2)
    {
        for (int i = 0 ; i < strlen(argv[1]); i++)
        {

            // if there is a number in the string argv[] - isalnum / return 1 stops the program as well
            // WARNING  isalnum is cheking if it's num or alpha.
            if (isdigit(argv[1][i]))
            {
                printf("Usage: ./substituion.c key\n");
                return 1;
            }
        }

        // 2 loops to see if there is twic the same character
        //first loop count one for each character
        //second loop adds one to the count if it smilar to one seen before
        for (int i = 0 ; i < strlen(argv[1]) ; i++)
        {
            int count = 1;

            for (int j = i + 1; j < strlen(argv[1]) ; j++)
            {
                if (argv[1][i] == argv[1][j])
                {
                    count++;
                }
            }

            if (count >= 2)
            {
                printf("Usage: ./substituion.c key\n");

                return 1;
            }
        }

    }

    string plaintext = get_string("Plaintext : \n");
    printf("ciphertext: ");


    for (int i = 0; i < strlen(plaintext); i++)
    {

        if (ispunct(plaintext[i]))
        {
            printf("%c", plaintext[i]);
        }

        if (isdigit(plaintext[i]))
        {
            printf("%c", plaintext[i]);
        }

        if ((plaintext[i]) == ' ')
        {
            printf(" ");
        }

        if (plaintext[i] == 'a')
        {
            printf("%c", tolower(argv[1][0]));
        }

        if (plaintext[i] == 'b')
        {
            printf("%c", tolower(argv[1][1]));
        }

        if (plaintext[i] == 'c')
        {
            printf("%c", tolower(argv[1][2]));
        }

        if (plaintext[i] == 'd')
        {
            printf("%c", tolower(argv[1][3]));
        }

        if (plaintext[i] == 'e')
        {
            printf("%c", tolower(argv[1][4]));
        }

        if (plaintext[i] == 'f')
        {
            printf("%c", tolower(argv[1][5]));
        }

        if (plaintext[i] == 'g')
        {
            printf("%c", tolower(argv[1][6]));
        }

        if (plaintext[i] == 'h')
        {
            printf("%c", tolower(argv[1][7]));
        }

        if (plaintext[i] == 'i')
        {
            printf("%c", tolower(argv[1][8]));
        }

        if (plaintext[i] == 'j')
        {
            printf("%c", tolower(argv[1][9]));
        }

        if (plaintext[i] == 'k')
        {
            printf("%c", tolower(argv[1][10]));
        }

        if (plaintext[i] == 'l')
        {
            printf("%c", tolower(argv[1][11]));
        }

        if (plaintext[i] == 'm')
        {
            printf("%c", tolower(argv[1][12]));
        }

        if (plaintext[i] == 'n')
        {
            printf("%c", tolower(argv[1][13]));
        }

        if (plaintext[i] == 'o')
        {
            printf("%c", tolower(argv[1][14]));
        }

        if (plaintext[i] == 'p')
        {
            printf("%c", tolower(argv[1][15]));
        }

        if (plaintext[i] == 'q')
        {
            printf("%c", tolower(argv[1][16]));
        }

        if (plaintext[i] == 'r')
        {
            printf("%c", tolower(argv[1][17]));
        }

        if (plaintext[i] == 's')
        {
            printf("%c", tolower(argv[1][18]));
        }

        if (plaintext[i] == 't')
        {
            printf("%c", tolower(argv[1][19]));
        }

        if (plaintext[i] == 'u')
        {
            printf("%c", tolower(argv[1][20]));
        }

        if (plaintext[i] == 'v')
        {
            printf("%c", tolower(argv[1][21]));
        }

        if (plaintext[i] == 'w')
        {
            printf("%c", tolower(argv[1][22]));
        }

        if (plaintext[i] == 'x')
        {
            printf("%c", tolower(argv[1][23]));
        }

        if (plaintext[i] == 'y')
        {
            printf("%c", tolower(argv[1][24]));
        }

        if (plaintext[i] == 'z')
        {
            printf("%c", tolower(argv[1][25]));
        }

        if (plaintext[i] == 'A')
        {
            printf("%c", toupper(argv[1][0]));
        }

        if (plaintext[i] == 'B')
        {
            printf("%c", toupper(argv[1][1]));
        }

        if (plaintext[i] == 'C')
        {
            printf("%c", toupper(argv[1][2]));
        }

        if (plaintext[i] == 'D')
        {
            printf("%c", toupper(argv[1][3]));
        }

        if (plaintext[i] == 'E')
        {
            printf("%c", toupper(argv[1][4]));
        }

        if (plaintext[i] == 'F')
        {
            printf("%c", toupper(argv[1][5]));
        }

        if (plaintext[i] == 'G')
        {
            printf("%c", toupper(argv[1][6]));
        }

        if (plaintext[i] == 'H')
        {
            printf("%c", toupper(argv[1][7]));
        }

        if (plaintext[i] == 'I')
        {
            printf("%c", toupper(argv[1][8]));
        }

        if (plaintext[i] == 'J')
        {
            printf("%c", toupper(argv[1][9]));
        }

        if (plaintext[i] == 'K')
        {
            printf("%c", toupper(argv[1][10]));
        }

        if (plaintext[i] == 'L')
        {
            printf("%c", toupper(argv[1][11]));
        }

        if (plaintext[i] == 'M')
        {
            printf("%c", toupper(argv[1][12]));
        }

        if (plaintext[i] == 'N')
        {
            printf("%c", toupper(argv[1][13]));
        }

        if (plaintext[i] == 'O')
        {
            printf("%c", toupper(argv[1][14]));
        }

        if (plaintext[i] == 'P')
        {
            printf("%c", toupper(argv[1][15]));
        }

        if (plaintext[i] == 'Q')
        {
            printf("%c", toupper(argv[1][16]));
        }

        if (plaintext[i] == 'R')
        {
            printf("%c", toupper(argv[1][17]));
        }

        if (plaintext[i] == 'S')
        {
            printf("%c", toupper(argv[1][18]));
        }

        if (plaintext[i] == 'T')
        {
            printf("%c", toupper(argv[1][19]));
        }

        if (plaintext[i] == 'U')
        {
            printf("%c", toupper(argv[1][20]));
        }

        if (plaintext[i] == 'V')
        {
            printf("%c", toupper(argv[1][21]));
        }

        if (plaintext[i] == 'W')
        {
            printf("%c", toupper(argv[1][22]));
        }

        if (plaintext[i] == 'X')
        {
            printf("%c", toupper(argv[1][23]));
        }

        if (plaintext[i] == 'Y')
        {
            printf("%c", toupper(argv[1][24]));
        }

        if (plaintext[i] == 'Z')
        {
            printf("%c", toupper(argv[1][25]));
        }

    }

    printf("\n");
}


