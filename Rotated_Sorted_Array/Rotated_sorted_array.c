#include <stdio.h>
#include <math.h>

int binarySearch(int arr[], int l_idx, int r_idx, int key)
{
    if (l_idx <= r_idx)
    {
        int m_idx = (l_idx + r_idx) / 2;
        if (arr[m_idx] == key)
        {
            return m_idx;
        }
        else if (arr[m_idx] > key)
        {
            return binarySearch(arr, l_idx, m_idx - 1, key);
        }
        else if (arr[m_idx] < key)
        {
            return binarySearch(arr, m_idx + 1, r_idx, key);
        }
    }
    return -1;
}

int findPivot(int A[], int l_idx, int r_idx)
{
    int m_idx = l_idx + (r_idx - l_idx) / 2;
    if (r_idx - l_idx == 1)
    {
        return l_idx + 1;
    }
    else if (A[m_idx] > A[l_idx]) //LEFT SUBARRAY IS SORTED
    {
        return findPivot(A, m_idx, r_idx);
    }
    else if (A[m_idx] < A[r_idx]) //RIGHT SUBARRAY IS SORTED
    {
        return findPivot(A, l_idx, m_idx);
    }
    return 0;
}

int Mbinarysearch(int arr[], int n, int key)
{

    int p_idx = findPivot(arr, 0, n - 1);
    int idx;
    if (p_idx == 0)
    {
        idx = binarySearch(arr, 0, n - 1, key);
    }
    else
    {
        idx = binarySearch(arr, p_idx, n - 1, key);
        if (idx == -1)
        {
            idx = binarySearch(arr, 0, p_idx - 1, key);
        }
    }
    return idx;
}

int main()
{

    int arr[9] = {55, 66, 77, 88, 99, 11, 22, 33, 44};
    int n = 9;
    int key = 11;
    int idx = Mbinarysearch(arr, n, key);
    if (idx == -1)
    {
        printf("not in array");
    }
    else
    {
        printf("key is at %d position", idx);
    }

    return 0;
}