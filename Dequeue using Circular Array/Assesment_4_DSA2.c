// Data Structures and Algorithms (CSE2011)
// Assessment 04 (LAB)
//Matrix Problem

// ANIRUDH VADERA
// 20BCT0144

// Header Files

//Implementation of Deque using circular array.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct Deque
{
    double *arr;
    int rear;  // rear is the last element of the deque
    int front; // front is the first element of the deque
    int max;
};

//Function definitions:
int add_Front(struct Deque *dq, double key);
int add_Last(struct Deque *dq, double key);
double del_Front(struct Deque *dq);
double del_Last(struct Deque *dq);
int is_Full(struct Deque *dq);
int is_Empty(struct Deque *dq);
void Print(struct Deque dq);

//To add the element at the front end of deque
int add_Front(struct Deque *dq, double key)
{
    if (!is_Full(dq))
    {
        if (dq->front == -1) // prints {} in case queue is empty
        {
            dq->front = 0;
            dq->rear = 0;
        }
        else if (dq->front == 0)
        {
            dq->front = (dq->max) - 1;
        }
        else
        {
            dq->front = (dq->front) - 1;
        }
        dq->arr[dq->front] = key;
        return 1;
    }
    return 0;
}

//To add the element at the rear end of deque
int add_Last(struct Deque *dq, double key)
{
    if (!is_Full(dq))
    {
        if (dq->front == -1) // prints {} in case queue is empty
        {
            dq->front = 0;
            dq->rear = 0;
        }
        else if (dq->rear == (dq->max) - 1)
        {
            dq->rear = 0;
        }
        else
        {
            dq->rear = (dq->rear) + 1;
        }
        dq->arr[dq->rear] = key;
        ;
        return 1;
    }
    return 0;
}

//To delete the element at the front end of deque
double del_Front(struct Deque *dq)
{
    double del_element = INFINITY;
    if (!is_Empty(dq))
    {
        del_element = dq->arr[dq->front];
        if (dq->rear == dq->front)
        {
            dq->rear = 0;
            dq->front = -1;
        }
        else if (dq->front == (dq->max) - 1)
        {
            dq->front = 0;
        }
        // increment rear by 1
        else
        {
            dq->front = (dq->front) + 1;
        }
    }
    return del_element;
}

//To delete the element at the rear end of deque
double del_Last(struct Deque *dq)
{
    double del_element = INFINITY;
    if (!is_Empty(dq))
    {
        del_element = dq->arr[dq->rear];
        // if the number of elements in the queue is 1 again initialize rear and front
        if (dq->rear == dq->front)
        {
            dq->rear = 0;
            dq->front = -1;
        }
        //if rear is the first position in the array, rear = q.max - 1
        else if (dq->rear == 0)
        {
            dq->rear = (dq->max) - 1;
        }
        // decrement rear by 1 to maintain deque operations ;
        else
        {
            dq->rear = (dq->rear) - 1;
        }
    }
    return del_element;
}

//Checks wether the deque has reached its max length or not
int is_Full(struct Deque *dq)
{
    if ((dq->front == 0 && dq->rear == (dq->max) - 1) || dq->front == (dq->rear) + 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

//Checks wether the deque is empty or not
int is_Empty(struct Deque *dq)
{
    if (dq->front == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

//To print the deque
void Print(struct Deque dq)
{
    printf("\n{");
    if (dq.front == -1) // prints {} in case queue is empty
    {
        printf("}");
        return;
    }
    if (dq.front > dq.rear) // i.e. the last element in the queue is before the first element
    {
        for (int i = dq.front; i <= (dq.max) - 1; i++)
        {
            printf(" %lf ", dq.arr[i]);
        }
        for (int i = 0; i <= (dq.rear); i++)
        {
            printf(" %lf ", dq.arr[i]);
        }
        printf("}\n");
        return;
    }
    for (int i = dq.front; i <= dq.rear; i++)
    {
        printf(" %lf ", dq.arr[i]);
    }
    printf("}\n");
    return;
}

//__main__
int main()
{
    //struct definition
    struct Deque dq;

    //max_size of the deque
    printf("Enter maximum deque length:\n");
    scanf("%d", &dq.max);

    //Allocating memory dynamically
    dq.arr = (double *)malloc(dq.max * sizeof(double));
    //Initializing rear and front end of the array
    dq.rear = 0;
    dq.front = -1;

    int choice, output;
    double element, del_output;

    //Printing Menu
    printf("\nREAD THE BELOW MENU FOR VARIOUS OPERATIONS:\n");
    printf("Press 1: ADD_FRONT:     Adding the element at the front end of the deque\n");
    printf("Press 2: ADD_LAST:      Adding the element at the end of the deque\n");
    printf("Press 3: DEL_FRONT:     Deleting  the element at front end starting of the deque\n");
    printf("Press 4: DEL_LAST:      Deleting the element  at rear  end of the deque\n");
    printf("Press 5: PRINT:         Displaying the current status of deque\n");
    printf("Press 6: EXIT:          Exiting the menu operations\n");

    while (1)
    {
        //Enter your choice
        printf("\nEnter Your Choice: ");
        scanf("%d", &choice);
        //switch case for the menu
        switch (choice)
        {
        case 1:
            printf("\nEnter value to add in the front index of deque: ");
            scanf("%lf", &element);
            output = add_Front(&dq, element);
            if (output == 0)
            {
                //error condition
                printf("\nThe Deque is full");
            }
            else
            {
                Print(dq);
                printf("\nElement is now added");
            }
            break;
        case 2:
            printf("\nEnter value to add in the rear index of deque: ");
            scanf("%lf", &element);
            output = add_Last(&dq, element);
            if (output == 0)
            {
                //error condition
                printf("\nThe Deque is full");
            }
            else
            {
                Print(dq);
                printf("\nElement is now added");
            }
            break;
        case 3:
            del_output = del_Front(&dq);
            if (del_output == INFINITY)
            {
                //error condition
                printf("\nThe Dequeue is empty");
            }
            else
            {
                Print(dq);
                printf("\nElement is now deleted is %lf", del_output);
            }
            break;
        case 4:
            del_output = del_Last(&dq);
            if (del_output == INFINITY)
            {
                //error condition
                printf("\nThe Dequeue is empty");
            }
            else
            {
                Print(dq);
                printf("\nElement deleted is %lf", del_output);
            }
            break;
        case 5:
            Print(dq);
            break;
        case 6:
            printf("\nExiting...");
            //Exiting the while operation
            return 0;
        default:
            return 0;
        }
    }
    return 0;
}