#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    // iterate over each candidate to compare if the value candidates[i].name = to the value name entered by the voters - if yes adds 1 to the candidates[i].votes
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i].name, name) == 0)
        {
            candidates[i].votes++;
            return true;
        }
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    int largest = 0;
    // iterate over the list of candidates and check the number of votes - finding the bigest value in the array
    for (int i = 0; i < candidate_count; i++)
    {
        // for each iteration is the value ins largest is smaller than the value in candidates[i].vote largest takes its value
        if (largest <= candidates[i].votes)
        {
            largest = candidates[i].votes;
        }
    }

    // iterate over the candidate list to see which one has the value = largest
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == largest)
        {
            printf("%s\n", candidates[i].name);
        }
    }
    return;
}




