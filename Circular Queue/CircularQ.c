#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct QUEUE
{
    double *arr;
    int rear;  // holds the index of last element inserted
    int front; // holds the index of element tobe deleted
    int max;
};

void print(struct QUEUE q)
{
    if (q.front == -1 && q.rear == -1)
    {
        printf("{}");
        return;
    }
    printf("\n{");
    int i = q.front;
    while (i != q.rear)
    {
        printf(" %lf ", q.arr[i]);
        i = (i + 1) % (q.max);
    }
    printf(" %lf ", q.arr[q.rear]);

    printf("}\n");
}

int enqueue(struct QUEUE *q, double obj)
{
    int idx = (q->rear + 1) % (q->max);
    if (q->front == idx)
    {
        return 0;
    }
    else if (q->front == -1 && q->rear == -1)
    {
        q->front = 0;
        q->arr[++(q->rear)] = obj;
        return 1;
    }
    else
    {
        q->rear = idx;
        q->arr[q->rear] = obj;
        return 1;
    }
}

double dequeue(struct QUEUE *q)
{
    double del_value = 0;
    if (q->rear == -1 && q->front == -1)
    {                         // No element in the queue
        del_value = INFINITY; // Indicator value
    }
    else if (q->rear == q->front)
    { // Exactly one element in the queue
        del_value = q->arr[q->front];
        q->front = -1;
        q->rear = -1;
    }
    else
    {
        del_value = q->arr[q->front];
        q->front = (q->front + 1) % (q->max);
    }
    return del_value;
}

int main()
{
    struct QUEUE q;
    q.max = 5;
    q.arr = (double *)malloc(sizeof(double) * q.max);
    q.rear = -1;
    q.front = -1;
    int result;

    result = enqueue(&q, 1.4);
    if (result == 0)
    {
        printf("\nQueue is Full!\n");
    }
    print(q);

    result = enqueue(&q, 2.4);
    if (result == 0)
    {
        printf("\nQueue is Full!\n");
    }
    print(q);

    result = enqueue(&q, 3.4);
    if (result == 0)
    {
        printf("\nQueue is Full!\n");
    }
    print(q);

    result = enqueue(&q, 4.4);
    if (result == 0)
    {
        printf("\nQueue is Full!\n");
    }
    print(q);

    result = enqueue(&q, 5.4);
    if (result == 0)
    {
        printf("\nQueue is Full!\n");
    }
    print(q);

    result = enqueue(&q, 6.4);
    if (result == 0)
    {
        printf("\nQueue is Full!\n");
    }
    print(q);

    // dequeue Operations
    //

    double deleted_element = 0;
    deleted_element = dequeue(&q);
    if (deleted_element == INFINITY)
    {
        printf("\nQueue is Empty!\n");
    }
    else
    {
        printf("\nDeleted element: = %lf \n", deleted_element);
    }
    print(q);

    deleted_element = dequeue(&q);
    if (deleted_element == INFINITY)
    {
        printf("\nQueue is Empty!\n");
    }
    else
    {
        printf("\nDeleted element: = %lf \n", deleted_element);
    }
    print(q);

    result = enqueue(&q, 6.4);
    if (result == 0)
    {
        printf("\nQueue is Full!\n");
    }
    print(q);

    result = enqueue(&q, 7.4);
    if (result == 0)
    {
        printf("\nQueue is Full!\n");
    }
    print(q);

    result = enqueue(&q, 8.4);
    if (result == 0)
    {
        printf("\nQueue is Full!\n");
    }
    print(q);

    deleted_element = dequeue(&q);
    if (deleted_element == INFINITY)
    {
        printf("\nQueue is Empty!\n");
    }
    else
    {
        printf("\nDeleted element: = %lf \n", deleted_element);
    }
    print(q);

    return 0;
}
