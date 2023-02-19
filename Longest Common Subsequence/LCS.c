#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int l1, l2;
    printf("Enter the length of string 1 : ");
    scanf("%d", &l1);
    printf("Enter the length of string 2 : ");
    scanf("%d", &l2);
    char *str1 = (char *)malloc(l1 * sizeof(char));
    char *str2 = (char *)malloc(l2 * sizeof(char));
    printf("Enter the string 1 : ");
    scanf("%s", str1);
    printf("Enter the string 2 : ");
    scanf("%s", str2);
    // Creating a dp memotization array
    int **dp = (int **)malloc((l1 + 1) * sizeof(int *));
    for (int i = 0; i < l1 + 1; i++)
    {
        dp[i] = (int *)malloc((l2 + 1) * sizeof(int));
    }
    // Initializing dp array
    for (int i = 0; i < l1 + 1; i++)
    {
        dp[i][0] = 0;
    }
    for (int i = 0; i < l2 + 1; i++)
    {
        dp[0][i] = 0;
    }

    // Performing our logic
    for (int i = 1; i < l1 + 1; i++)
    {
        for (int j = 1; j < l2 + 1; j++)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = fmax(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }
    printf("The memo array is : \n");
    printf("[ \n");
    for (int i = 0; i < l1 + 1; i++)
    {
        printf("[ ");
        for (int j = 0; j < l2 + 1; j++)
        {
            printf("%d ", dp[i][j]);
        }
        printf("]\n");
    }
    printf("]\n");
    printf("The length of the longest common subsequence is : %d\n", dp[l1][l2]);
    if (dp[l1][l2] != 0)
    {
        int l = dp[l1][l2];
        char *lcs = (char *)malloc(l * sizeof(char));
        int idx = 0;
        int curr = 0;
        for (int i = 0; i < l2 + 1; i++)
        {
            if (dp[l1][i] != curr)
            {
                lcs[idx++] = str2[i - 1];
                curr++;
            }
        }
        printf("The longest common subsequence is : %s", lcs);
    }
    else
    {
        printf("There is no common subsequence");
    }

    return 0;
}