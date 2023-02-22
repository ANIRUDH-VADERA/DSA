#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Performing our logic
int knapSack(int W, int weight[], int profit[], int n)
{
    int i, w;
    // Creating a dp memotization array
    int **dp = (int **)malloc((n + 1) * sizeof(int *));
    for (int i = 0; i < n + 1; i++)
    {
        dp[i] = (int *)malloc((W + 1) * sizeof(int));
    }
    for (i = 0; i <= n; i++)
    {
        for (w = 0; w <= W; w++)
        {
            if (i == 0 || w == 0)
            {
                dp[i][w] = 0;
            }
            else if (weight[i - 1] <= w)
            {
                dp[i][w] = fmax(profit[i - 1] + dp[i - 1][w - weight[i - 1]], dp[i - 1][w]);
            }
            else
            {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    printf("The memo array is : \n");
    printf("[ \n");
    for (int i = 0; i < n + 1; i++)
    {
        printf("[ ");
        for (int j = 0; j < W + 1; j++)
        {
            printf("%d ", dp[i][j]);
        }
        printf("]\n");
    }
    printf("]\n");
    return dp[n][W];
}
// Driver code
int main()
{
    int profit[] = {6, 10, 8};
    int weight[] = {2, 5, 6};
    int W = 10;
    int n = sizeof(profit) / sizeof(profit[0]);
    printf("The Maximum Profit that can be carried out is : %d", knapSack(W, weight, profit, n));
    return 0;
}