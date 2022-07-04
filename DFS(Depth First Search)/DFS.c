#include <stdio.h>
#include <math.h>
#include <string.h>

#define MAX 7

// Function to give the vertex of the corresponding index
char convert_index_to_char(int a)
{
    if (a == 0)
    {
        return 'A';
    }
    else if (a == 1)
    {
        return 'B';
    }
    else if (a == 2)
    {
        return 'C';
    }
    else if (a == 3)
    {
        return 'D';
    }
    else if (a == 4)
    {
        return 'E';
    }
    else if (a == 5)
    {
        return 'F';
    }
    else if (a == 6)
    {
        return 'G';
    }
}

// Function to give the index of the corresponding vertex
int convert_char_to_index(char a)
{
    if (a == 'A')
    {
        return 0;
    }
    else if (a == 'B')
    {
        return 1;
    }
    else if (a == 'C')
    {
        return 2;
    }
    else if (a == 'D')
    {
        return 3;
    }
    else if (a == 'E')
    {
        return 4;
    }
    else if (a == 'F')
    {
        return 5;
    }
    else if (a == 'G')
    {
        return 6;
    }
}

void DFS(int i, int visited[MAX], int parent[MAX], double A[MAX][MAX])
{
    visited[i] = 1;
    printf("%c\t", convert_index_to_char(i));
    for (int j = 0; j < MAX; j++)
    {
        if (A[i][j] != INFINITY && visited[j] == 0)
        {
            parent[j] = i;
            DFS(j, visited, parent, A);
        }
    }
    return;
}

int main()
{
    // Adjacency Matrix representation of the Graph
    double A[MAX][MAX];
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            // Initializing with infinity
            A[i][j] = INFINITY;
        }
    }

    // Modifying the distances of the edges
    A[0][1] = 1;
    A[1][5] = 1;
    A[1][2] = 1;
    A[2][3] = 1;
    A[2][4] = 1;
    A[3][4] = 1;
    A[3][6] = 1;
    A[5][0] = 1;
    A[5][6] = 1;
    A[6][0] = 1;
    // distance array stores the shortest distance from the source vertex
    // visited array keeps the track if the vertex is visited or not
    int visited[MAX];
    // Path array acts as a parent array and stores the parent of each vertex except the source vertex
    int parent[MAX];

    // Initializing the arrays
    for (int i = 0; i < MAX; i++)
    {
        visited[i] = 0;
        parent[i] = -1;
    }
    DFS(0, visited, parent, A);
    return 0;
}
