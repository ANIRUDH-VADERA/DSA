#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct QUEUE{
    double* arr;
    int rear;  // rear index holds the index of last element entered in the Queue.
    int front; // front index holds the index of last element deleted in the Queue.
    int max;
};


void print(struct QUEUE q){
    printf("\n{");
    for(int i=q.front+1; i<=q.rear ; i++ ){
        printf(" %lf ", q.arr[i]);
    }
    printf("}\n");
}

int isFull(struct QUEUE* q){
    return (q->rear == q->max - 1) ? 1 : 0;
}

int enqueue(struct QUEUE* q, double obj){
    if( !isFull(q) ){
        q->arr[++(q->rear)] = obj;
        return 1;
    }
    return 0;
}

int isEmpty(struct QUEUE* q){
    return (q->rear == q->front) ? 1 : 0;
}

double dequeue(struct QUEUE* q){
    return (!isEmpty(q)) ? (q->arr[++(q->front)]) : INFINITY;
}

int main()
{
    struct QUEUE q;
    q.max = 5;
    q.arr = (double*)malloc(q.max*sizeof(double));
    q.rear  = -1;
    q.front = -1;
    int result;

    result = enqueue(&q, 1.4);
    if(result==0){
        printf("\nQueue is full!\n");
    }
    print(q);

    result = enqueue(&q, 2.4);
    if(result==0){
        printf("\nQueue is full!\n");
    }
    print(q);

    result = enqueue(&q, 3.4);
    if(result==0){
        printf("\nQueue is full!\n");
    }
    print(q);

    result = enqueue(&q, 4.4);
    if(result==0){
        printf("\nQueue is full!\n");
    }
    print(q);

    result = enqueue(&q, 5.4);
    if(result==0){
        printf("\nQueue is full!\n");
    }
    print(q);

    result = enqueue(&q, 6.4);
    if(result==0){
        printf("\nQueue is full!\n");
    }
    print(q);


    double del_ele = 0;

    del_ele = dequeue(&q);
    if(del_ele == INFINITY){
        printf("\n QUEUE is Empty!\n");
    }else{
        printf("\n Deleted Element: %lf\n", del_ele);
    }
    print(q);

    del_ele = dequeue(&q);
    if(del_ele == INFINITY){
        printf("\n QUEUE is Empty!\n");
    }else{
        printf("\n Deleted Element: %lf\n", del_ele);
    }
    print(q);

    del_ele = dequeue(&q);
    if(del_ele == INFINITY){
        printf("\n QUEUE is Empty!\n");
    }else{
        printf("\n Deleted Element: %lf\n", del_ele);
    }
    print(q);

    del_ele = dequeue(&q);
    if(del_ele == INFINITY){
        printf("\n QUEUE is Empty!\n");
    }else{
        printf("\n Deleted Element: %lf\n", del_ele);
    }
    print(q);

    del_ele = dequeue(&q);
    if(del_ele == INFINITY){
        printf("\n QUEUE is Empty!\n");
    }else{
        printf("\n Deleted Element: %lf\n", del_ele);
    }
    print(q);

    del_ele = dequeue(&q);
    if(del_ele == INFINITY){
        printf("\n QUEUE is Empty!\n");
    }else{
        printf("\n Deleted Element: %lf\n", del_ele);
    }
    print(q);

    return 0;
}
