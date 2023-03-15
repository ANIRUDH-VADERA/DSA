#include <stdio.h>
#include <math.h>

// Stores the number of Solutions
int count = 0;

// Printing the solution
void print(int n, int **board)
{
    printf("\n\nSolution %d:\n\n", ++count);

    for (int i = 1; i <= n; i++)
    {
        printf("\t%d", i);
    }

    for (int i = 1; i <= n; i++)
    {
        printf("\n\n%d", i);
        for (int j = 1; j <= n; ++j)
        {
            if (board[i] == j)
            {
                printf("\tQ");
            }
            else
            {
                printf("\t-");
            }
        }
    }
}

// function to check for proper positioning of queen
void queen(int *board, int row, int n)
{
    int column;
    for (column = 1; column <= n; ++column)
    {
        if (place(board, row, column))
        {
            board[row] = column; // no conflicts so place queen
            if (row == n)
            {
                print(n, board); // printing the board configuration
            }
            else
            {
                queen(board, row + 1, n); // try queen with next position
            }
        }
    }
}

int main()
{
    int n;
    printf("\n\nEnter number of Queens:");
    scanf("%d", &n);
    // Creating the baord
    int *board = (int *)malloc(n * sizeof(int));
    queen(board, 1, n);
    return 0;
}

/*funtion to check conflicts
If no conflict for desired postion returns 1 otherwise returns 0*/
int place(int *board, int row, int column)
{
    for (int i = 1; i <= row - 1; ++i)
    {
        // checking column and digonal conflicts
        if (board[i] == column)
        {
            return 0;
        }
        else if (abs(board[i] - column) == abs(i - row))
        {
            return 0;
        }
    }
    return 1; // no conflicts
}
