#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#define MAX 7

struct QUEUE
{
    int *arr;
    int rear;  // holds the index of last element inserted
    int front; // holds the index of element tobe deleted
    int max;
};

int enqueue(struct QUEUE *q, int obj)
{
    int idx = (q->rear + 1) % (q->max);
    if (q->front == idx)
    {
        return 0;
    }
    else if (q->front == -1 && q->rear == -1)
    {
        q->front = 0;
        q->arr[++(q->rear)] = obj;
        return 1;
    }
    else
    {
        q->rear = idx;
        q->arr[q->rear] = obj;
        return 1;
    }
}

int dequeue(struct QUEUE *q)
{
    int del_value = 0;
    if (q->rear == -1 && q->front == -1)
    {                    // No element in the queue
        del_value = -10; // Indicator value
    }
    else if (q->rear == q->front)
    { // Exactly one element in the queue
        del_value = q->arr[q->front];
        q->front = -1;
        q->rear = -1;
    }
    else
    {
        del_value = q->arr[q->front];
        q->front = (q->front + 1) % (q->max);
    }
    return del_value;
}

void print(struct QUEUE q)
{
    if (q.front == -1 && q.rear == -1)
    {
        printf("{}");
        return;
    }
    printf("\n{");
    int i = q.front;
    while (i != q.rear)
    {
        printf(" %d ", q.arr[i]);
        i = (i + 1) % (q.max);
    }
    printf(" %d ", q.arr[q.rear]);

    printf("}\n");
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

int isEmpty(struct QUEUE *q)
{
    if (q->front == -1)
    {
        return 1;
    }
    return 0;
}

int main()
{
    // Adjacency Matrix representation of the Graph
    int A[MAX][MAX];
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            // Initializing with infinity
            A[i][j] = 0;
        }
    }

    // Modifying the distances of the edges
    A[0][1] = 1;
    A[0][6] = 1;
    A[0][5] = 1;
    A[1][5] = 1;
    A[1][2] = 1;
    A[2][4] = 1;
    A[2][3] = 1;
    A[3][4] = 1;
    A[3][5] = 1;
    A[5][6] = 1;
    A[5][0] = 1;
    // distance array stores the shortest distance from the source vertex
    int level[MAX];
    // visited array keeps the track if the vertex is visited or not
    int visited[MAX];
    // Path array acts as a parent array and stores the parent of each vertex except the source vertex
    int parent[MAX];

    // Initializing the arrays

    for (int i = 0; i < MAX; i++)
    {
        level[i] = -1;
        visited[i] = 0;
        parent[i] = -1;
    }

    // 0 vertex // A vertex is the starting vertex
    struct QUEUE q;
    q.rear = -1;
    q.front = -1;
    q.max = MAX;
    q.arr = (int *)malloc(sizeof(int) * q.max);
    visited[0] = 1;
    enqueue(&q, 0);
    level[0] = 0;
    printf("%c\t", convert_index_to_char(0));
    while (isEmpty(&q) != 1)
    {
        int j = dequeue(&q);
        for (int k = 0; k < MAX; k++)
        {
            if (visited[k] == 0 && A[j][k] != 0)
            {
                enqueue(&q, k);
                visited[k] = 1;
                parent[k] = j;
                level[k] = level[j] + 1;
                printf("%c\t", convert_index_to_char(k));
            }
        }
    }
}
