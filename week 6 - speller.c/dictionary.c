// Implements a dictionary's functionality

#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include "dictionary.h"

#define HASHTABLE_SIZE 20000

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;



// Hash table size
node *table[HASHTABLE_SIZE];

//boal for the word_count in dictionnary

bool loaded = false;

//word count
int word_count = 0;

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    int length = strlen(word);
    //array to copy the word in order to not modify text
    char word_copy[length + 1];

    //copy the word
    strcpy(word_copy, word);

    //tolower word
    for (int i = 0; i < length; i++)
    {
        word_copy[i] = tolower(word_copy[i]);
    }

    //hasing the word
    int h = hash(word_copy);

    //cursor to traver the linked-list
    node *cursor = table[h];

    //traversing the linked list
    while (cursor != NULL)
    {
        //comparing if the word that the cursor points is = to the word
        if (strncmp(cursor->word, word_copy, 2) != 0)
        {
            cursor = cursor->next;
        }

        else
        {
            return true;
        }

    }

    return false;
}




// Hashes word to a number
// *Hash function retrieved from https://www.reddit.com/r/cs50/comments/1x6vc8/pset6_trie_vs_hashtable/cf9nlkn/
// * addapted to my code
unsigned int hash(const char *word)
{
    int n = strlen(word);
    unsigned int hash = 0;
    for (int i = 0; i <= n; i++)
    {
        hash = (hash << 2) ^ tolower(word[i]);
    }
    return hash % HASHTABLE_SIZE;
    return 0;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    //open dictionary file
    FILE *dico = fopen(dictionary, "r");
    if (dico == NULL)
    {
        printf("Could not open file\n");
        return false;
    }

    //array to store the word that's being read
    char word_copy[LENGTH + 1];

    //read dic. word by word
    while ((fscanf(dico, "%s", word_copy)) != EOF)
    {
        node *new_node = malloc(sizeof(node));
        if (new_node == NULL)
        {
            printf("Couldn't allocate memory");
            return false;
        }

        //word count for size dico
        word_count++;
        //copy word into node
        strcpy(new_node->word, word_copy);

        //index returned after the word being hashed
        int h = hash(word_copy);


        //store in n next the adress of the first node in the list
        new_node->next = table[h];

        //link the n node to the hash array
        table[h] = new_node;
    }
    loaded = true;
    fclose(dico);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    if (loaded)
    {
        return word_count;
    }


    return 0;

}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    for (int i = 0; i <= HASHTABLE_SIZE; i++)
    {
        node *tmp = 0;
        node *cursor = table[i];
        while (cursor != NULL)
        {
            tmp = cursor;
            cursor = cursor->next;
            free(tmp);
        }
    }
    return true;
}
