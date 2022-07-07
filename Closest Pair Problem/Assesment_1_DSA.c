
// Data Structures and Algorithms (CSE2011)
// Assessment 01 (LAB)
// 1. Finding the distance between the pair of points which are closest (in the sense of euclidean distance).

// ANIRUDH VADERA
// 20BCT0144

// Header Files
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Structure Definition
struct Point
{
    // 2-Dimmensional Space
    float x_coordinate; //x-coordinate of the given point
    float y_coordinate; //y-coordinate of the given point
};

//Input Function for setting the values in the structure.
unsigned int input(struct Point array[], unsigned int n, unsigned int f)
{
    int i;
    float temp; // Temporary Variable
    for (i = 0; i < n; i++)
    {
        printf("\nPoint %d\n", i + 1);
        printf("x-coordinate=");
        scanf("%f", &(array[i].x_coordinate));
        printf("y-coordinate=");
        scanf("%f", &(array[i].y_coordinate));
        //Condition For checking if the y-coordinate of all the points is same or not
        if (i == 0)
        {
            temp = array[i].y_coordinate;
        }
        else
        {
            // f is a flag variable which becomes 0(initially 1) if any one of the y-coordinate is different.
            if (array[i].y_coordinate != temp)
            {
                f = 0;
            }
        }
    }
    return f;
}

// print Function to print the points given
void print(struct Point array[], unsigned int n)
{
    int i;
    printf("\nThe given points are:\n");
    printf("[\n");
    for (i = 0; i < n; i++)
    {
        printf("\t(");
        printf("%f,", array[i].x_coordinate);
        printf("%f", array[i].y_coordinate);
        printf(")\n");
    }
    printf("]\n");
}

//Part-A
//Function to Calculate Euclidean Distance between the two given points
// i and j are the indexes for the points in the structure array
float edistance(struct Point array[], int i, int j)
{
    return sqrt(pow((array[i].x_coordinate - array[j].x_coordinate), 2) + pow((array[i].y_coordinate - array[j].y_coordinate), 2));
}

//Part-C
//Merging function to be used in Merge sort
// Merges the left and the right sub array into the given array
void Merge(struct Point array[], unsigned int str_index, int mid, unsigned int end_idx)
{
    int l = mid - str_index + 1; //length of the left sub array
    int r = end_idx - mid;       //length of the right sub array

    struct Point LeftSubArray[l];  //Left sub array
    struct Point RightSubArray[r]; //Right sub array

    int m; //iterating variable

    for (m = 0; m < l; m++)
    {
        // Creating the left sub array
        LeftSubArray[m].x_coordinate = array[str_index + m].x_coordinate;
        LeftSubArray[m].y_coordinate = array[str_index + m].y_coordinate;
    }
    for (m = 0; m < r; m++)
    {
        // Creating the right sub array
        RightSubArray[m].x_coordinate = array[mid + 1 + m].x_coordinate;
        RightSubArray[m].y_coordinate = array[mid + 1 + m].y_coordinate;
    }

    int i = 0;         //pointer to left sub array
    int j = 0;         //pointer to right sub array
    int k = str_index; //pointer of the array to be modified i.e the main array

    while (i < l && j < r)
    {
        if (LeftSubArray[i].x_coordinate <= RightSubArray[j].x_coordinate)
        {
            array[k].x_coordinate = LeftSubArray[i].x_coordinate;
            i++;
            k++;
        }
        else if (LeftSubArray[i].x_coordinate > RightSubArray[j].x_coordinate)
        {
            array[k].x_coordinate = RightSubArray[j].x_coordinate;
            k++;
            j++;
        }
    }

    // if there are remaining points(x-coordinates)
    while (i < l)
    {
        array[k].x_coordinate = LeftSubArray[i].x_coordinate;
        k++;
        i++;
    }

    while (j < r)
    {
        array[k].x_coordinate = RightSubArray[j].x_coordinate;
        k++;
        j++;
    }
}

//Part-C
//Merge Sort to sort the points in increasing order of x-coordinates of the points
//if and only if the given y-coordinates of all the points is fixed.
void MergeSort(struct Point array[], unsigned int str_index, unsigned int end_idx)
{
    if (str_index < end_idx)
    {
        int mid;
        mid = (str_index + end_idx) / 2;
        MergeSort(array, str_index, mid);   //left sub array
        MergeSort(array, mid + 1, end_idx); //right sub array
        Merge(array, str_index, mid, end_idx);
    }
}

//Part-C
//This function is called only if the y-coordinates of all the given points is fixed
float modified_minimum_distance(struct Point array[], unsigned int n, unsigned int *p)
{
    {
        float mindistance;
        MergeSort(array, 0, n - 1);
        // Above function sorts the structure array in
        // increasing order of x-coordinates
        // now making comparisions for adjacent x-coordinates
        // to find the min_absolute_distance
        int i;
        float min_absolute_difference, absolute_difference;
        min_absolute_difference = INFINITY;
        for (i = 0; i < n - 1; i++)
        {
            // In this special case the euclidean distance between the two points will
            // be equal to the absolute difference only so incrementing the count
            *p = *p + 1;
            absolute_difference = fabs(array[i].x_coordinate - array[i + 1].x_coordinate);
            if (absolute_difference < min_absolute_difference)
            {
                min_absolute_difference = absolute_difference; // euclidean distnace=absolute difference
            }
        }
        return min_absolute_difference; // euclidean distnace=absolute difference
    }
}

//This function is called only if the y-coordinates of all the given points is not fixed
float minimum_distance(struct Point array[], unsigned int n, unsigned int *p)
{
    {
        int i, j;
        float mindistance, distance;
        mindistance = INFINITY;
        for (i = 0; i < n - 1; i++)
        {
            for (j = i + 1; j < n; j++)
            {
                //Incrementing the count whenever the euclidean distance function is called
                *p = *p + 1;
                distance = edistance(array, i, j);
                if (distance < mindistance)
                {
                    mindistance = distance;
                }
            }
        }
        return mindistance;
    }
}

// Printing the pair of points which are closest
void print_pair(struct Point array[], unsigned int n, float mindistance)
{
    int i, j, c = 0;
    float distance;
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {

            distance = edistance(array, i, j);
            if (distance == mindistance)
            {
                c = c + 1;
                printf("Pair %d:\n", c);
                printf("{(%f,%f)  ,  ", array[i].x_coordinate, array[i].y_coordinate);
                printf("(%f,%f)}\n", array[j].x_coordinate, array[j].y_coordinate);
            }
        }
    }
}

// _Main_
int main()
{
    unsigned int n = 0;
    unsigned int f = 1, flag; //flag to check wether if the y-coordinates of all the points is same or not
    float min_distance;
    float modified_min_distance;
    unsigned int count = 0; //count variable
    unsigned int *p;        //pointer to the count
    p = &count;
    // Input for number of Points
    printf("\nEnter the number of points:");
    scanf("%u", &n);
    if (n > 2) // Boundary Condition
    {

        struct Point point_array[n]; // structure array

        flag = input(point_array, n, f); // flag variable to check if the y-coordinates is fixed or not

        print(point_array, n);

        if (flag == 0)
        {
            // Part-A
            // Normal Case
            min_distance = minimum_distance(point_array, n, p);
            printf("\nThe distance between the closest pair of points is : %f\n", min_distance);
            printf("\nPair of points with the same minimum distance are:\n");
            print_pair(point_array, n, min_distance);
        }
        else
        {
            // Part-C
            // Special case when the y-coordinates of all points is fixed
            modified_min_distance = modified_minimum_distance(point_array, n, p);
            printf("\nThe distance between the closest pair of points is : %f\n", modified_min_distance);
            printf("Pair of points with the same minimum distance are:\n");
            print_pair(point_array, n, modified_min_distance);
        }

        //Part B
        //Prints the number of times the Euclidean distance is calculated
        //Count
        printf("\nNumber of times Euclidean Distance is calculated: %d", *p);
    }
    else
    {
        // If n<=2
        printf("Invalid input");
    }
    return 0;
}