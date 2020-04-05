#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>


float index(float L, float s);

int main(void)
{
    //prompting for text
    //don't need text to be an array because it's a string. therefore i can work on it after like if it was an array.
    string text = get_string("Text: ");

    //counting nbr of letters in the array
    // variable that will store the number of characters
    int nbr_letters = 0 ;

    // strlen(text) take into consideration all characters (including space, ., ! etc. but it allows to go over every character)
    // the loop goes oever every character and look if its a A or a and if yes adds 1 to nbr_letters
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] >= 'a' && text[i] <= 'z')
        {
            nbr_letters = nbr_letters + 1;
        }

        else if (text[i] >= 'A' && text[i] <= 'Z')
        {
            nbr_letters = nbr_letters + 1;
        }

    }

    // counting number of words with the number of space +1 (start nbr_words = 1) because the last word won't be counted otherwise!
    int nbr_words = 1;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == ' ')
        {
            nbr_words = nbr_words + 1;
        }

    }

    // couting number of sentences
    int nbr_sentences = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text [i] == '.')
        {
            nbr_sentences = nbr_sentences + 1;
        }

        if (text [i] == '!')
        {
            nbr_sentences = nbr_sentences + 1;
        }

        if (text [i] == '?')
        {
            nbr_sentences = nbr_sentences + 1;
        }
    }


    // I needed to transforme the values inside the division into float in order to get a float result
    float L = ((100 * (float)nbr_letters) / (float) nbr_words);
    float s = ((100 * (float) nbr_sentences) / (float) nbr_words);

    // function call - Colman Liau's Index
    float result = index(L, s);


    if (result < 1)
    {
        printf("Before Grade 1\n");
    }

    if (result >= 16)
    {
        printf("Grade 16+\n");
    }

    //%.0f so i get 0 value after 8 and not 8.00
    if (result >= 1 && result <= 15)
    {
        printf("Grade %.0f\n", result);
    }

}


//Function definition for index
// rounding the result because it's a float --> roundf and not just round
float index(float L, float s)
{
    float index =  0.0588 * L - 0.296 * s - 15.8;
    return roundf(index);
}



