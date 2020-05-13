#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
}
pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;
int voter_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
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
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            // our initial graph will have no edges in it --> set to false
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
// the function parameters don't have to have the same name that the argument when we call the function
// the name of the parameters doesn't have to be conencted to anytings it's juste a name - what matters is the type of the variable
// so it's ok if we use rank as parameters and j as an argument in the function call
// in the function call we can see that ranks[candidate_count] and that there is a for loop with j that is connected to candidate_count
// because the function is in the for loop going over every candidate we don't need to put it again in the function!
bool vote(int rank, string name, int ranks[])
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i], name) == 0)
        {
            ranks[rank] = i;
            return true;
        }
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    for (int j = 0; j < candidate_count; j++)
    {
        for (int k = j + 1; k < candidate_count; k++)
        {
            preferences[ranks[j]][ranks[k]]++;
        }
    }
    return;
}

// Record pairs of candidates where one is preferred over the other
// paris[] can't be with pairs[i] because it would never save all pairs as it goes from o to candidate_count-1 !
void add_pairs(void)
{
    for (int i = 0; i < candidate_count; i ++)
    {
        for (int j = i + 1 ; j <= candidate_count; j++)
        {
            if (preferences[i][j] > preferences[j][i])
            {
                pairs[pair_count].winner = i;
                pairs[pair_count].loser = j;
                pair_count++;
            }

            if (preferences[i][j] < preferences[j][i])
            {
                pairs[pair_count].winner = j;
                pairs[pair_count].loser = i;
                pair_count++;
            }
        }
    }
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    pair swap;
    for (int i = 0; i < pair_count - 1; i++)
    {
        for (int j = 0; j < pair_count - i - 1; j++)
        {
            int left_winner = pairs[j].winner;
            int right_winner = pairs[j + 1].winner;
            int left_loser = pairs[j].loser;
            int right_loser = pairs[j + 1].loser;

            if (preferences[left_winner][left_loser] < preferences[right_winner][right_loser])
            {
                swap = pairs [j + 1];
                pairs [j + 1] = pairs [j];
                pairs [j] = swap;
            }
        }
    }
    return;
}

bool search_cycle(int l, int w);

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    for (int i = 0; i < pair_count; i++)
    {
        if (!search_cycle(pairs[i].loser, pairs[i].winner))
        {
            locked[pairs[i].winner][pairs[i].loser] = true;
        }
    }
    return;
}

// where l is the original loser and w the original winner
// the check-cycle first make sure that an arrow doesnt exist already from l to w
// if yes = cycle return true
// if not we need to check if there isnt : l --> another candidate --> w
// in other words we need to check if the looser wins over the winner trough another candidate.
bool search_cycle(int l, int w)
{
    // base case
    if (locked[l][w] == true)
    {
        return true; // it creates a cycle
    }

    else
    {
        int i;
        for (i = 0; i < candidate_count; i++)
        {
            if (locked[l][i] == true)
            {
                // check cycle again to see if for l --> i reached to w.
                return search_cycle(i, w); // important to put return before calling the function again otherwise it won't don't all over again
            }
        }
        return false; // doesn't creat a cycle
    }
}





// Print the winner of the election
// we need to look for the candiate (i) who has no edge pointing to him. for nay j --> locked [j][i] == false
// nmbr of false = nmbr of candidate
// if we use the count++ it allows for tied
void print_winner(void)
{
    for (int i = 0; i < candidate_count; i++)
    {
        // Int count needs to be within the i loop so it's set to 0 if we change i
        int count = 0;
        for (int j = 0; j < candidate_count; j++)
        {
            if (locked[j][i] == false)
            {
                count++;
            }

            else if (locked[j][i] == true)
            {
                break;
            }
        }

        if (count == candidate_count)
        {
            printf("%s\n", candidates[i]);
            return;
        }
    }
}

