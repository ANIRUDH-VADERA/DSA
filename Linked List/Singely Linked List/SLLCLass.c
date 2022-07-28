#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct NODE{
    double data;
    struct NODE* next;
};

struct LIST{
    struct NODE* head;
    struct NODE* tail;
};

struct NODE* createNode(double item){
    struct NODE* newnode = (struct NODE*)malloc(sizeof(struct NODE));
    newnode->data = item;
    newnode->next = NULL;
    return newnode;
}

void addLast(struct LIST* lst, double item){
    struct NODE* nn = createNode(item);
    if(lst->head == NULL){ // SLL is empty
        lst->head = nn;
        lst->tail = nn;
        return;
    }
    lst->tail->next = nn;
    lst->tail = nn;
}


void addFirst(struct LIST* lst, double item){
    struct NODE* nn=createNode(item);
    if(lst->head == NULL){
        lst->head=nn;
        lst->tail=nn;
        return;
    }
    nn->next = lst->head; // Linking the new node with the current list
    lst->head = nn;
}

double delLast(struct LIST* lst){
    double todel = INFINITY;
    if(lst->head==NULL){
        return todel;
    }else if(lst->head == lst->tail){
        todel = lst->head->data;
        free(lst->head);
        lst->head = NULL;
        lst->tail = NULL;
        return todel;
    }
    struct NODE* temp = NULL;
    for( temp=lst->head; temp->next != lst->tail ; temp=temp->next );
    temp->next = NULL;
    todel = lst->tail->data;
    free(lst->tail);
    lst->tail=temp;
    return todel;
}

int size(struct LIST* lst){
    int count = 0;
    for(struct NODE* temp = lst->head; temp ; temp=temp->next){
        count++;
    }
    return count;
}

void display(struct LIST* lst){
    printf("\n{");
    struct NODE* temp = NULL;
    for( temp = lst->head; temp!=NULL ; temp=temp->next ){
        printf(" %lf ", temp->data);
    }
    printf("}\n");
}

double delFirst(struct LIST* lst){
    double todel = INFINITY;
    if(lst->head == NULL){
        return todel;
    }else if(lst->head == lst->tail){
        todel = lst->head->data;
        free(lst->head);
        lst->head= NULL;
        lst->tail = NULL;
        return todel;
    }
    todel = lst->head->data;
    struct NODE* delNode = lst->head;
    lst->head = lst->head->next;
    free(delNode);
    
    return todel;
}

int main(){
    struct LIST lst;
    lst.head = NULL;
    lst.tail = NULL;

    addLast( &lst, 1.4 );
    display( &lst );
    addLast( &lst, 2.4 );
    display( &lst );
    addLast( &lst, 3.4 );
    display( &lst );
    addLast( &lst, 4.4 );
    display( &lst );
    addLast( &lst, 5.4 );
    display( &lst );

    addFirst( &lst, 100 );
    display(&lst);
    addFirst( &lst, 200 );
    display(&lst);
    addFirst( &lst, 300 );
    display(&lst);
    addFirst( &lst, 400 );
    display(&lst);
    
    printf("Deleted element = %lf\n", delLast(&lst));
    display(&lst);
    printf("Deleted element = %lf\n", delLast(&lst));
    display(&lst);
    printf("Deleted element = %lf\n", delLast(&lst));
    display(&lst);
    printf("Deleted element = %lf\n", delLast(&lst));
    display(&lst);
    printf("Deleted element = %lf\n", delLast(&lst));
    display(&lst);

    printf("Deleted element = %lf\n", delFirst(&lst));
    display(&lst);
    printf("Deleted element = %lf\n", delFirst(&lst));
    display(&lst);
    printf("Deleted element = %lf\n", delFirst(&lst));
    display(&lst);
    printf("Deleted element = %lf\n", delFirst(&lst));
    display(&lst);
    printf("Deleted element = %lf\n", delFirst(&lst));
    display(&lst);

    printf("\nSize of the List: %d ", size(&lst));
    return 0;
}
