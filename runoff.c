#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidates have name, vote count, eliminated status
typedef struct
{
    string name;
    int votes;
    bool eliminated;
}
candidate;

// Array of candidates
candidate candidates[MAX_CANDIDATES];

// Numbers of voters and candidates
int voter_count;
int candidate_count;

// Function prototypes
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Keep querying for votes
    for (int i = 0; i < voter_count; i++)
    {

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            // Record vote, unless it's invalid
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }

        printf("\n");
    }

    // Keep holding runoffs until winner exists
    while (true)
    {
        // Calculate votes given remaining candidates
        tabulate();

        // Check if election has been won
        bool won = print_winner();
        if (won)
        {
            break;
        }

        // Eliminate last-place candidates
        int min = find_min();
        bool tie = is_tie(min);

        // If tie, everyone wins
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        // Eliminate anyone with minimum number of votes
        eliminate(min);

        // Reset vote counts back to zero
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}


// Record preference if vote is valisd
bool vote(int voter, int rank, string name)
{
    // iterate through each candidate
    for (int i = 0; i < candidate_count; i++)
    {
        //check if given name is existing
        if (strcmp(candidates[i].name, name) == 0)
        {
            //update preference array - i being the index number of the candidate that we iterate with the for loop.
            // it give us the value for the ith voter at the jth rank
            preferences[voter][rank] = i;
            return true;
        }
    }
    return false;
}


// Tabulate votes for non-eliminated candidates
void tabulate(void)
{
    for (int i = 0; i < voter_count; i++)
    {
        int j = 0;
        //candidate[preference[i][j]] = the candidate that the voter i had for the jth preference
        // if first preference is eliminated go to the next one
        if (candidates[preferences[i][j]].eliminated)
        {
            candidates[preferences[i][j + 1]].votes ++;
        }
        else
        {
            // otherwise take the first preference [0] for the ith voter
            candidates[preferences[i][j]].votes ++;
        }
    }
    return;
}

// Print the winner of the election, if there is one
bool print_winner(void)
{
    int n;
    //voter_count is even
    if (voter_count % 2 == 0)
    {
        n = voter_count / 2 + 1;
    }
    //if voter_count is odd
    else
    {
        n = voter_count / 2 + 0.5;
    }
    // itterating over every candidate
    for (int i = 0; i < candidate_count; i ++)
    {
        // checking if the nbr of vote is >= to the half of the votes - if yes wins!
        if (candidates[i].votes >= n)
        {
            printf("%s\n", candidates[i].name);
            return true;
        }
    }
    return false;
}

// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    // define the first candidate as the smallest value and check all other if smaller they become the smallest value + checking if not eliminated
    int min_v = candidates[0].votes;
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].eliminated == false && candidates[i].votes < min_v)
        {
            min_v = candidates[i].votes;
        }
    }
    return min_v;
}

// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)
{
    for (int i = 0; i < candidate_count; i++)
    {
        // need to make candidate[i].votes != min other wise it will detect some
        if (candidates[i].eliminated == false && candidates[i].votes != min)
        {
            return false;
        }
    }
    return true;
}

// Eliminate the candidate (or candidiates) in last place
void eliminate(int min)
{
    for (int i = 0; i < candidate_count; i++)
    {
        //if not eliminated and has the smallest value then transformed eliminated into true
        if (candidates[i].eliminated == false && candidates[i].votes == min)
        {
            candidates[i].eliminated = true;
        }
    }
    return;
}
