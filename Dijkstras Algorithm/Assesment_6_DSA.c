// Data Structures and Algorithms (CSE2011)
// Assessment 06 (LAB)
// 6.Given the following graph G(V, E), find the shortest path from A to every other vertices in the graph

// ANIRUDH VADERA
// 20BCT0144

// Header Files
#include <stdio.h>
#include <math.h>
#include <string.h>

// Defining the number of vertices in the graph
#define MAX 7

// Function to find such a vertex which isnt visited till yet and its distance is minimum
// Greedy step of the algorithm
int minimum(int visited[], double distance[])
{
    // Initializing the minimum distance
    double min_d = INFINITY;
    // The index of the ideal vertex
    int min_idx = -1;
    // Finding the ideal vertex which isnt visited and its distance is minimum
    for (int i = 0; i < MAX; i++)
    {
        if (visited[i] != 1)
        {
            if (distance[i] < min_d)
            {
                min_d = distance[i];
                min_idx = i;
            }
        }
    }
    return min_idx;
}

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

// This function prints the path and the shortest distance of each vertex from the source vertex
void print(double distance[], char path[])
{
    printf("\nShortest path from source vertex to each of the vertex: \t Shortest distance:\n");
    printf("\n");

    // distance array stores the shortest distance from the source vertex

    // Path array stores the parent element of every vertex except the source vertex.

    // Temporary array to store the path
    char temp_array[MAX];
    // indexing for the temporary array
    int temp_array_idx = 0;
    for (int i = 0; i < MAX; i++)
    {
        // At every iteration the indexing of the temporary array becomes 0
        temp_array_idx = 0;

        // Storing the path in the temporary array

        // Adding the vertex to which the path is to be found to the path_array
        temp_array[temp_array_idx++] = convert_index_to_char(i);

        // To revert back to the same array after commiting some changes
        char whole_temp = path[i];

        // Making the path by retracing the parent of the current vertex
        while (path[i] != path[0] && path[i] != '0')
        {
            char temp = path[i];
            int temp_index = convert_char_to_index(temp);
            temp_array[temp_array_idx++] = convert_index_to_char(temp_index);
            path[i] = path[temp_index];
        }

        // Reverting back to undo the changes made
        path[i] = whole_temp;

        // Adding the source vertex to the path_array
        temp_array[temp_array_idx] = path[0];

        // Printing the path and the shortest distance
        printf("\t\t");
        for (int i = temp_array_idx; i > 0; i--)
        {
            printf("%c-->", temp_array[i]);
        }
        printf("%c\t\t\t\t\t\t %lf \t", temp_array[0], distance[i]);
        printf("\n");
    }
    printf("\n");
}

// Dijkstras Algorithm
void Dijkstras(int visited[], double distance[], double A[][MAX], char path[])
{
    for (int i = 0; i < MAX; i++)
    {
        // Greedy step
        // Finding the ideal vertex
        int j = minimum(visited, distance);
        // Visiting that vertex
        visited[j] = 1;
        for (int k = 0; k < MAX; k++)
        {
            if (visited[k] != 1)
            {
                if (distance[k] > (distance[j] + A[j][k]))
                {
                    // Modifying the distance
                    distance[k] = distance[j] + A[j][k];
                    // Modifying the path_array
                    path[k] = convert_index_to_char(j);
                }
            }
        }
    }
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
    A[0][1] = 2;
    A[0][2] = 7;
    A[0][4] = 12;
    A[1][3] = 2;
    A[2][1] = 3;
    A[2][3] = -1;
    A[2][4] = 2;
    A[3][5] = 2;
    A[4][0] = -4;
    A[4][6] = -7;
    A[5][6] = 2;
    A[6][3] = 1;
    // distance array stores the shortest distance from the source vertex
    double distance[MAX];
    // visited array keeps the track if the vertex is visited or not
    int visited[MAX];
    // Path array acts as a parent array and stores the parent of each vertex except the source vertex
    char path[MAX];

    // Initializing the arrays

    for (int i = 0; i < MAX; i++)
    {
        distance[i] = INFINITY;
        visited[i] = 0;
        path[i] = '0';
    }

    // 0 vertex // A vertex is the starting vertex
    distance[0] = 0;
    path[0] = convert_index_to_char(0);

    // Performing the dijkstras algorithm
    Dijkstras(visited, distance, A, path);

    // Printing the shortest distance from source vertex to each vertex  and its path
    print(distance, path);

    return 0;
}
