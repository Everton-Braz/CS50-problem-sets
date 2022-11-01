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

// Record preference if vote is valid
bool vote(int voter, int rank, string name)
{
    // O nome do candidato digitado precisa corresponder ao nome de algum candidato.
    // Se sim, retornar true.
    // usar candidate_count no loop
    // usar strcmp para comparar os nomes, comparar com "0";
    // Lembre-se de que as preferences [i] [j] armazenam o índice do candidato que é a j ésima preferência
    // classificada para o i ésimo eleitor.

    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i].name, name) == 0)
        {
            preferences[voter][rank] = i;
            printf("Pref.: %i\n", preferences[voter][rank]);
            return true;
        }
    }

    return false;
}

// Tabulate votes for non-eliminated candidates
void tabulate(void)
{
        //     tabulate
        // A função deve atualizar o número de votes que cada candidato possui nesta fase do segundo turno.
        // Lembre-se de que em cada estágio do segundo turno, cada eleitor vota efetivamente em seu candidato preferido
        // que ainda não foi eliminado.
        // Lembre-se de que voter_count armazena o número de eleitores na eleição.
        // Lembre-se de que, para um eleitor i, seu candidato de primeira escolha é representado por preferences [i][0],
        // seu candidato de segunda escolha por preferences [i][1] , etc.
        // Lembre-se de que a estrutura do candidato possui um campo denominado eliminado , o que será true caso o candidato
        // tenha sido eliminado da eleição.
        // Lembre-se de que a struct do candidate tem um campo chamado votes , que você provavelmente desejará atualizar para
        // o candidato preferido de cada eleitor.
    for (int i = 0; i < voter_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            if(candidates[preferences[i][j]].eliminated == false){
                candidates[preferences[i][j]].votes++;
                break;
            }
        }
    }
    return;
}

// Print the winner of the election, if there is one
bool print_winner(void)
{
         for (int i = 0; i < voter_count; i++){
            if(candidates[i].votes > voter_count/2){
            printf("Winner: %s\n", candidates[i].name);
            return true;
            }
         }
   return false;
}

// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
         int min = voter_count;
         for (int i = 0; i < candidate_count; i++)
            if(candidates[i].votes < min && candidates[i].eliminated == false)
            {
                min = candidates[i].votes;
            }
         return min;
}


// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)
{
        // Conta quantos candidatos ainda estão na disputa (Não eliminados)
        int notEliminated = 0;
        // Conta os candidatos remanescentes que tem o mínimo de votos.
        int candidatesWithMin = 0;
        // Busca entre todos os candidatos, os não eliminados.
        for (int i = 0; i < candidate_count; i++)
        {
            if(!candidates[i].eliminated)
            {
                // O contador soma cada valor encontrado, um a um.
                notEliminated++;
            }
                // Se o candidato[0], o canditado[1]... for igual ao min, o contador vai somando de 1 a 1.
                if (candidates[i].votes == min)
                    {
                        candidatesWithMin++;
                    }
        }
        // Posso retornar true dentro do if
        if (notEliminated == candidatesWithMin)
        {
            return true;
        }
    return false;
}

// Eliminate the candidate (or candidates) in last place
void eliminate(int min)
{
         for (int i = 0; i < candidate_count; i++)
            if(candidates[i].votes == min && candidates[i].eliminated == false)
            {
                candidates[i].eliminated = true;
            }
    return;
}
