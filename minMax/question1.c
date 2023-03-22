#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("Enter the Number of Students Participating in Online Quiz : \n");
    scanf("%d", &n);
    // Allocating a array for student scores
    int *arr = (int *)malloc(n * sizeof(int));
    printf("Enter the Students Scores : \n");
    for (int i = 0; i < n; i++)
    {
        printf("Score for Student %d : \n", i + 1);
        scanf("%d", &arr[i]);
    }
    // Initializing max and min by first element of array
    int max = arr[0];
    int min = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }
    printf("The Top Score of the Students in Online Quiz is : %d\n", max);
    printf("The Least Score of the Students in Online Quiz is : %d\n", min);
    return 0;
}