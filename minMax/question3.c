#include <stdio.h>
#include <stdlib.h>

void dc(int *arr, int st, int end, int *max, int *min)
{
    if (st <= end)
    {
        int mid = st + (end - st) / 2;
        if (arr[mid] < *min)
        {
            *min = arr[mid];
        }
        if (arr[mid] > *max)
        {
            *max = arr[mid];
        }
        dc(arr, mid + 1, end, max, min);
        dc(arr, st, mid - 1, max, min);
    }
}

int main()
{
    int n;
    printf("Enter the Number of Elements in Array : \n");
    scanf("%d", &n);
    // Allocating a array
    int *arr = (int *)malloc(n * sizeof(int));
    printf("Enter the elements of array : \n");
    for (int i = 0; i < n; i++)
    {
        printf("Element %d : \n", i + 1);
        scanf("%d", &arr[i]);
    }
    // Initializing max and min by first element of array
    int max = arr[0];
    int min = arr[0];
    dc(arr, 0, n - 1, &max, &min);
    printf("The Maximum Element of the Array is  : %d\n", max);
    printf("The Minimum Element of the Array is : %d\n", min);
    return 0;
}