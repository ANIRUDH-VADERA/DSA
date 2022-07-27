// Data Structures and Algorithms (CSE2011)
// Assessment 01 (LAB)
// 1. Finding the distance between the pair of points which are closest (in the sense of euclidean distance).

// ANIRUDH VADERA
// 20BCT0144

// Header Files
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <conio.h>

//Function for taking the input for making the array from the user.
void input(int array[], unsigned int n)
{
    int i;
    printf("Enter the elements of the array:\n");
    for (i = 0; i < n; i++)
    {
        printf("Element %d:\n", i + 1);
        scanf("%d", &array[i]);
    }
}

//Part-1
//Function for finding the key in the array using the linear search
//The given array is unsorted hence n comparisions is needed(worst-case) for finding the key
//Therefore the upper bound is
//Time complexity=O(n)
//Function returns -1 if the key is not found
unsigned int LinearSearch(int array[], unsigned int n, int key, unsigned int *count)
{
    int i; //Looping variable
    for (i = 0; i < n; i++)
    {
        //For finding the number of comparisions in the Linear Search
        *count = *count + 1;
        if (array[i] == key) //checking if the i(th) element is the key or not.
        {
            return i;
        }
    }
    return -1; //Condition if the key is not in the array
}

//Part-2
//Function for finding the key in the array using the Binary search
//The given array is sorted using the information given we use Binary search to improve the upper Bound
//In each recursive call the size of the given array is reduced to half
//Time complexity=O(log(n))
//Function returns -1 if the key is not found
unsigned int BinarySearch(int array[], int str_idx, int end_idx, int key, unsigned int *count)
{
    //For finding the number of comparisions in the Binary Search for first if() statement
    *count = *count + 1;
    if (str_idx <= end_idx) //Condition if the key is not in the array
    {
        int mid_idx;
        mid_idx = (str_idx + end_idx) / 2;
        if (key == array[mid_idx]) //Checking if the element in the middle index is the key or not
        {
            //for first if() statement
            *count = *count + 1;
            return mid_idx;
        }
        else if (key > array[mid_idx]) //This means the key is in the Left sub array
        {
            //for else-if() statement the first condition is false and this condition is also checked hence we are adding +2.
            *count = *count + 2;
            return BinarySearch(array, mid_idx + 1, end_idx, key, count);
        }
        else if (key < array[mid_idx]) //This means the key is in the Right sub array
        {
            //Similarly for the previous 2 if() statements are executed and fails then we add +3
            *count = *count + 3;
            return BinarySearch(array, str_idx, mid_idx - 1, key, count);
        }
    }
    return -1;
}

//Part-3
//Function for finding the key in the array
//This is Rotated sorted array problem, the array is initially sorted but is rotated from a pivot element using the information given we imrpove the upper bound using the combined function.
//In each recursive call the size of the given array is reduced to half
//Time complexity=O(log(n))
//Function returns -1 if the key is not found
int Rotated_array_Search(int arr[], int l_idx, int r_idx, int key, unsigned int *count)
{
    //For finding the number of comparisions in the rotated sorted  Search for first if() statement
    *count = *count + 1;
    if (l_idx <= r_idx) //Condition if the key is not in the array
    {
        int m_idx = (l_idx + r_idx) / 2;
        if (arr[m_idx] == key) //Checking if the element in the middle index is the key or not
        {
            //for first if() statement
            *count = *count + 1;
            return m_idx;
        }
        else if (arr[m_idx] > arr[l_idx]) //If this passes it means Left sub array is sorted
        {
            //for else-if() statement the first condition is false and this condition is also checked hence we are adding +2.
            *count = *count + 2;
            if (key < arr[m_idx] && key >= arr[l_idx]) //This means the key is in the left sub array
            {
                //now as we going into the if condition with 2 statements connected by and so we increase it by 2
                *count = *count + 2;
                return Rotated_array_Search(arr, l_idx, m_idx - 1, key, count);
            }
            else //This means the key is in the right sub array
            {
                //now as we going into the else condition of the (if condition with 2 statements connected by and) so we increase it by 2
                *count = *count + 2;
                return Rotated_array_Search(arr, m_idx + 1, r_idx, key, count);
            }
        }
        else if (arr[m_idx] < arr[r_idx]) //If this passes it means Right sub array is sorted
        {
            //Similarly for the previous 2 if() statements are executed and fails then we add +3
            *count = *count + 3;
            if (key >= arr[m_idx] && key <= arr[r_idx]) //This means the key is in the Right sub array
            {
                //Similar logic line 103
                *count = *count + 2;
                return Rotated_array_Search(arr, m_idx + 1, r_idx, key, count);
            }
            else //This means the key is in the left sub array
            {
                //Similar logic line 109
                *count = *count + 2;
                return Rotated_array_Search(arr, l_idx, m_idx - 1, key, count);
            }
        }
    }
    return -1;
}

//Function for printing the array
void print(int array[], unsigned int n)
{
    int i;
    printf("The given array is:\n");
    printf("{ ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }
    printf("}\n");
}

//_main_
int main()
{
    //n is the number of elements
    unsigned int n = 0;
    printf("Enter the number of elements:");
    scanf("%d", &n);

    //this is the integer array
    int array[n];

    //Boundary Condition
    if (n > 2)
    {
        int key = 0;            //Initializing the key
        int key_position;       //This is the key position
        unsigned int count = 0; //This is the count variable for finding the total number of comparisions in Linear search, Binary search and the Rotated_array search.
        unsigned int *LS_count; //Pointer to the Count
        LS_count = &count;

        // For taking the input from user
        input(array, n);

        // Taking the flag from the user to know wether they want to use Linear search, binary search or rotated_array search
        int flag;
        printf("Enter your choice:\n");
        printf("Press: '0' for Linear search \n");   //Part-1, For the unsorted array
        printf("Press: '1' for Binary search \n");   //Part-2, For the sorted array
        printf("Press: '2' for Modified search \n"); //Part-3, For the sorted array but its rotated about a pivot element
        printf("Your choice:");
        scanf("%d", &flag);

        //Checking the value of the flag and accordingly giving the commands
        if (flag == 0 || flag == 1 || flag == 2)
        {
            //Printing the array
            print(array, n);
            printf("\nEnter the key you want to find in the given array:");

            //Getting the key as an input from the user
            scanf("%d", &key);

            //Giving commands according to flag variable discussed above
            if (flag == 0)
            {
                key_position = LinearSearch(array, n, key, LS_count);
            }
            else if (flag == 1)
            {
                key_position = BinarySearch(array, 0, n - 1, key, LS_count);
            }
            else if (flag == 2)
            {
                key_position = Rotated_array_Search(array, 0, n - 1, key, LS_count);
            }

            //Printing the value of the key_position i.e the position index of the key
            if (key_position >= 0)
            {
                //Assuming the fisrt element has position 1
                printf("\nThe given key is present in the given array at %d position.\n", key_position + 1);
            }
            else
            {
                printf("\nThe given key is not present in the given array\n");
            }
            printf("\nTotal number of times the comparisions is needed to find the key:%d\n", *LS_count);
        }
        else
        {
            //Boundary condition
            printf("Your choice was invalid");
        }
    }
    else
    {
        //Invalid input
        printf("\nInvalid Input");
    }
    return 0;
}