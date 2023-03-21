#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void fractionalKnapsack(int *weight, int *profit, int W, int n)
{
    // Sorting according to ratio
    int *ratio = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        ratio[i] = profit[i] / weight[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (ratio[i] < ratio[j])
            {
                int temp = ratio[j];
                ratio[j] = ratio[i];
                ratio[i] = temp;

                temp = weight[j];
                weight[j] = weight[i];
                weight[i] = temp;

                temp = profit[j];
                profit[j] = profit[i];
                profit[i] = temp;
            }
        }
    }
    float *used = (float *)malloc(n * sizeof(float));
    float totalProfit = 0;
    for (int i = 0; i < n; i++)
    {
        used[i] = 0.0;
    }
    for (int i = 0; i < n; i++)
    {
        if (weight[i] <= W)
        {
            W -= weight[i];
            used[i] = 1.0;
            totalProfit += used[i] * profit[i];
            printf("Added object (%d, %d) completely in the bag. Space left: %d.\n", profit[i], weight[i], W);
        }
        else
        {
            used[i] = (float)W / weight[i];
            totalProfit += used[i] * profit[i];
            W = 0;
            printf("Added %f%% (%d, %d) of object in the bag.\n", used[i], profit[i], weight[i]);
            break;
        }
    }
    printf("The Profit array is: \n");
    printf("[ ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", profit[i]);
    }
    printf("]\n");
    printf("The Weight array is: \n");
    printf("[ ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", weight[i]);
    }
    printf("]\n");
    printf("The usage of objects is as follows: \n");
    printf("[ ");
    for (int i = 0; i < n; i++)
    {
        printf("%f ", used[i]);
    }
    printf("]\n");
    printf("Filled the bag with objects worth %f\n", totalProfit);
    free(ratio);
    free(weight);
    free(profit);
}

void Knapsack01(int *weight, int *profit, int W, int n)
{
    // Sorting according to ratio
    int *ratio = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        ratio[i] = profit[i] / weight[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (ratio[i] < ratio[j])
            {
                int temp = ratio[j];
                ratio[j] = ratio[i];
                ratio[i] = temp;

                temp = weight[j];
                weight[j] = weight[i];
                weight[i] = temp;

                temp = profit[j];
                profit[j] = profit[i];
                profit[i] = temp;
            }
        }
    }
    float *used = (float *)malloc(n * sizeof(float));
    float totalProfit = 0;
    for (int i = 0; i < n; i++)
    {
        used[i] = 0.0;
    }
    for (int i = 0; i < n; i++)
    {
        if (weight[i] <= W)
        {
            W -= weight[i];
            used[i] = 1.0;
            totalProfit += used[i] * profit[i];
            printf("Added object (%d, %d) completely in the bag. Space left: %d.\n", profit[i], weight[i], W);
        }
    }
    printf("The Profit array is: \n");
    printf("[ ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", profit[i]);
    }
    printf("]\n");
    printf("The Weight array is: \n");
    printf("[ ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", weight[i]);
    }
    printf("]\n");
    printf("The usage of objects is as follows: \n");
    printf("[ ");
    for (int i = 0; i < n; i++)
    {
        printf("%f ", used[i]);
    }
    printf("]\n");
    printf("Filled the bag with objects worth %f\n", totalProfit);
}

int main()
{
    // Menu Driven Program
    int flag = 1;

    while (flag == 1)
    {
        int n;
        printf("Enter the number of elements : ");
        scanf("%d", &n);
        int *profit = (int *)malloc(n * sizeof(int));
        int *weight = (int *)malloc(n * sizeof(int));
        printf("Enter the weights of elements : \n");
        for (int i = 0; i < n; i++)
        {
            printf("Weight of %d element : ", i + 1);
            scanf("%d", &weight[i]);
        }
        printf("Enter the profit of elements : \n");
        for (int i = 0; i < n; i++)
        {
            printf("Profit of %d element : ", i + 1);
            scanf("%d", &profit[i]);
        }
        // The maximum weight u can take
        int W;
        printf("Enter the capacity of Knapsack : ");
        scanf("%d", &W);
        // Checking the choice
        printf("\n1 : Fractional Knapsack Problem : \n");
        printf("2 : 0/1 Knapsack Problem : \n");
        int choice;
        printf("Choice : ");
        scanf("%d", &choice);
        if (choice != 1 && choice != 2)
        {
            printf("Enter Correct Choice : \n");
            printf("Choice : ");
            scanf("%d", choice);
        }
        if (choice == 1)
        {
            fractionalKnapsack(weight, profit, W, n);
        }
        else
        {
            Knapsack01(weight, profit, W, n);
        }
        free(weight);
        free(profit);
        printf("Do You want to continue : 1: Yes , 0: No : ");
        scanf("%d", &flag);
    }

    return 0;
}