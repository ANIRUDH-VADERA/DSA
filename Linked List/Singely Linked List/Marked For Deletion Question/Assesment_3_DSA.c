// Data Structures and Algorithms (CSE2011)
// Assessment 03 (LAB)

// ANIRUDH VADERA
// 20BCT0144

// Header Files

//Implementation using SLL

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Strcuture Definition for a single Node
struct NODE
{
    //The element data
    double data;
    //The next element
    struct NODE *next;

    //flag=1(if the element is not marked for deleted)
    //flag=0(if the element is marked for deleted)
    //The flag element to check for deleted status or not

    int flag;

    //If the element is marked for deleted then this struct element is used
    //It stores the position at which this element was deleted
    //Suppose there are 5 unmarked elements and a particular element is deleted at the last
    //therefore position_deleted=5 for that particular element

    int position_deleted;
};

//Strcuture Definition for the Singely_Linked_LIST
struct LIST
{
    struct NODE *head; //The starting of the SLL
    struct NODE *tail; //The end of the SLL
};

//Strcuture Definition for a creating a new single Node
struct NODE *Create_Node(double item)
{
    struct NODE *new_node = (struct NODE *)malloc(sizeof(struct NODE));
    new_node->data = item;
    new_node->next = NULL;
    //Initializing with 1 therefore initially the element is not marked for deleted
    new_node->flag = 1;
    //Initially the element is not marked for deleted therefore its -1
    new_node->position_deleted = -1;
    return new_node;
}

//Function to add the element at the starting of the SLL
void addFirst(struct LIST *SLL, double item)
{
    struct NODE *new_node = Create_Node(item);
    if (SLL->head == NULL)
    {
        SLL->head = new_node;
        SLL->tail = new_node;
        return;
    }
    else
    {
        // To link the new node with the current SLL
        new_node->next = SLL->head;
        SLL->head = new_node;
        return;
    }
}

//Function to add the element at the end of the SLL
void addLast(struct LIST *SLL, double item)
{
    struct NODE *new_node = Create_Node(item);
    if (SLL->head == NULL) //Empty SLL
    {
        SLL->head = new_node;
        SLL->tail = new_node;
        return;
    }
    else
    {
        SLL->tail->next = new_node;
        SLL->tail = new_node;
        return;
    }
}

//Function to display the current status of the SLL
void display(struct LIST *SLL)
{
    printf("\nThe SLL at the moment is :");
    printf("\n{");
    struct NODE *temp = NULL;
    temp = SLL->head;
    while (temp != NULL)
    {
        //Only showing the elements having the flag as 1(i.e not marked for deleted elements)
        if (temp->flag == 1)
        {
            printf(" %lf ", temp->data);
        }
        temp = temp->next;
    }
    printf("}\n");
    printf("\n");
}

//Function which actually deletes the nodes which are marked for deleted
//This function is only called when special condition is called
//condtion
//Number of marked for deleted nodes in the list exceeds the number of non marked for deleted nodes
void del_marked_nodes(struct LIST *SLL, int count1, int count2, int *del_count)
{

    printf("\nThe elements are now Permanantly deleted:\n");

    //This node is a temporary node for traversing through SLL
    struct NODE *temp = NULL;
    //This node keeps the track of the previous of temp
    //i.e this node traverse through SLL one prior to temp
    struct NODE *previous = NULL;
    //Create a new node with INFINITY data and store that in previous
    //Make previous->next equal to SLL->head
    //Change the SLL->head to the current previous
    //Now traverse through the SLL
    //whenever a node with flag 0 is encountered
    //The memory of that particular node is deallocated
    //The previous->next is made to temporary->next
    previous = Create_Node(INFINITY);
    previous->next = SLL->head;
    SLL->head = previous;
    temp = SLL->head->next;
    while (temp != NULL)
    {
        if (temp->flag == 0)
        {
            previous->next = temp->next;
            //Deallocating the memory
            free(temp);
        }
        else
        {
            previous = temp;
            SLL->tail = temp;
        }
        temp = previous->next;
    }
    //Deleting the fake head we previously created
    //Defining the correct head
    previous = SLL->head;
    SLL->head = SLL->head->next;
    //Deallocating the memory
    free(previous);

    //As all the elements marked for deleted are now actually deleted
    //So del_count is made to 0
    *del_count = 0;
    return;
}

//This function checks the condition
//Condition
//Number of marked for deleted nodes in the list exceeds the number of non marked for deleted nodes
//If the condition passes it calls the del_marked_nodes function
int count_check_deleted(struct LIST *SLL, int *del_count)
{
    //Creating a temporary node for iterating through SLL
    struct NODE *tempo = NULL;
    tempo = SLL->head;
    //count1 is the count for marked for deleted nodes
    int count1 = 0;
    //count2 is the count for not marked for deleted nodes
    int count2 = 0;
    while (tempo != NULL)
    {
        if (tempo->flag == 0)
        {
            count1 = count1 + 1;
        }
        else
        {
            count2 = count2 + 1;
        }
        tempo = tempo->next;
    }
    //Checking the condition and calling the function
    if (count1 > count2)
    {
        del_marked_nodes(SLL, count1, count2, del_count);
    }
    return 0;
}

//Function for making the first element of SLL marked for deleted
double delFirst(struct LIST *SLL, int *del_count)
{
    double del_data = INFINITY;
    if (SLL->head == NULL)
    {
        //The SLL is empty so delete operation cant be performed.
        return del_data;
    }
    else if (SLL->head == SLL->tail)
    {
        //This case for exactly one element in the SLL
        //As there is only one element we directly deallocate its memory
        del_data = SLL->head->data;
        free(SLL->head);
        SLL->head = NULL;
        SLL->tail = NULL;
        return del_data;
    }

    //Creating a temporary node for iterating through SLL
    struct NODE *temp = NULL;
    temp = SLL->head;
    //This loops find the first occurence of the node which has a flag of 1
    while (temp->flag != 1)
    {
        temp = temp->next;
    }
    //temp now stores the first node with flag as 1
    del_data = temp->data;

    //Incrementing the del_count = number of elements currently marked for deleted
    *del_count = *del_count + 1;

    //Defining the position_deleted as the current deleted count
    temp->position_deleted = *del_count;

    //Marking the node for deletion
    temp->flag = 0;

    printf("First element is now marked for deletion or is actually deleted according to the condition specified\n");
    //Checking the condition
    count_check_deleted(SLL, del_count);
    return del_data;
}

//Function for making the last element of SLL marked for deleted
double delLast(struct LIST *SLL, int *del_count)
{
    double del_data = INFINITY;
    if (SLL->head == NULL)
    {
        //The SLL is empty so delete operation cant be performed.
        return del_data;
    }
    else if (SLL->head == SLL->tail)
    {
        //This case for exactly one element in the SLL
        //As there is only one element we directly deallocate its memory
        del_data = SLL->head->data;
        free(SLL->head);
        SLL->head = NULL;
        SLL->tail = NULL;
        return del_data;
    }

    //Creating a temporary node for iterating through SLL
    struct NODE *temp1 = NULL;
    temp1 = SLL->head;
    //This node will store the last element with flag is 1
    struct NODE *last_element_with_flag1 = NULL;
    while (temp1 != NULL)
    {
        if (temp1->flag == 1)
        {
            last_element_with_flag1 = temp1;
        }
        temp1 = temp1->next;
    }
    //temp1 now stores the first node with flag as 1
    del_data = last_element_with_flag1->data;

    //Incrementing the del_count = number of elements currently marked for deleted
    *del_count = *del_count + 1;

    //Defining the position_deleted as the current deleted count
    last_element_with_flag1->position_deleted = *del_count;

    //Marking the node for deletion
    last_element_with_flag1->flag = 0;

    printf("Last element is now marked for deletion or is actually deleted according to the condition specified\n");
    //Checking the condition
    count_check_deleted(SLL, del_count);

    return del_data;
}

//This function marks for delete the ith node in the SLL
double del_i_node(struct LIST *SLL, int index, int *del_count)
{
    double del_data = INFINITY;
    if (SLL->head == NULL)
    {
        //The SLL is empty so delete operation cant be performed.
        return del_data;
    }
    else if (SLL->head == SLL->tail)
    {
        //This case for exactly one element in the SLL
        //As there is only one element we directly deallocate its memory
        del_data = SLL->head->data;
        free(SLL->head);
        SLL->head = NULL;
        SLL->tail = NULL;
        return del_data;
    }
    else
    {
        //Creating a temporary variable to traverse through SLL
        struct NODE *temp = NULL;
        temp = SLL->head;
        //This count stores the number of nodes with flag 1
        int count = 0;
        while (temp != NULL)
        {
            if (temp->flag == 1)
            {
                count = count + 1;
            }
            if (count == index) //For checking the right index is found or not
            {
                del_data = temp->data;
                //To mark the element deleted
                temp->flag = 0;
                //Incrementing the del_count = number of elements currently marked for deleted
                *del_count = *del_count + 1;
                temp->position_deleted = *del_count;
                break;
            }
            temp = temp->next;
        }

        //Condition check
        count_check_deleted(SLL, del_count);
        return del_data;
    }
}

//Function for finding the size of the SLL
int size(struct LIST *SLL)
{
    //Count for keeping track of size
    int count = 0;
    struct NODE *temp = NULL;
    //Looping variable
    temp = SLL->head;
    while (temp != NULL)
    {
        if (temp->flag == 1)
        {
            count = count + 1;
        }
        temp = temp->next;
    }
    return count;
}

//Function for recalling the last deleted node
void recall_last_deleted(struct LIST *SLL, int *del_count)
{
    //Creating a temporary looping variable
    struct NODE *temp = NULL;
    temp = SLL->head;
    //flag variable for checking if there are marked for deleted nodes or not
    int f = 0;
    while (temp != NULL)
    {
        if (temp->position_deleted == *del_count && temp->flag == 0)
        {
            //Redifing the count operations
            temp->flag = 1;
            temp->position_deleted = -1;
            *del_count = *del_count - 1;
            f = 1;
            break;
        }
        temp = temp->next;
    }
    if (f == 0)
    {
        printf("ERROR!!!!!!!\n");
        printf("As there are no elements present in the SLL that are marked for deleted.\n");
        printf("Hence the last deleted node can't be recalled.");
    }
    else
    {
        printf("Element recalled and added back");
        display(SLL);
    }
}

//_Main_
int main()
{
    struct LIST SLL;
    SLL.head = NULL;
    SLL.tail = NULL;

    //Printing Menu
    printf("\nREAD THE BELOW MENU FOR VARIOUS OPERATIONS:\n");
    printf("Press 1: ADD_FIRST:     Adding the element at the starting of the singely linked list\n");
    printf("Press 2: ADD_LAST:      Adding the element at the end of the singely linked list\n");
    printf("Press 3: DEL_FIRST:     Marking the element for deletion at starting of the singely linked list\n");
    printf("Press 4: DEL_LAST:      Marking the element for deletion at end of the singely linked list\n");
    printf("Press 5: DEL_Ith_NODE:  Marking the element for deletion at the given index of the singely linked list\n");
    printf("Press 6: DISPLAY:       Displaying the current status of singely linked list\n");
    printf("Press 7: SIZE:          Printing the size of the current singely linked list\n");
    printf("Press 8: RECALL:        Recalling the last deleted node of the singely linked list\n");
    printf("Press 9: EXIT:          Exiting the menu operations\n");

    //User choice
    char choice;
    //Element
    double element;
    //Index at which the element is to be inserted
    int index;

    double element_deleted;

    //keeping the track for count of marked for deleted elements
    int count_of_deleted;
    int *del_count;
    del_count = &count_of_deleted;

    //Menu
    //making swicth cases for different cases
    printf("\nEnter your Choice after '>>'\n");
    while (1)
    {

        printf(">");
        scanf("%c", &choice);
        switch (choice)
        {
        case '1':
            printf("\nEnter value for the element: ");
            scanf("%lf", &element);
            addFirst(&SLL, element);
            printf("Element is now added");
            display(&SLL);
            break;
        case '2':
            printf("\nEnter value for the element: ");
            scanf("%lf", &element);
            addLast(&SLL, element);
            printf("Element is now added");
            display(&SLL);
            break;

        case '3':
            element_deleted = delFirst(&SLL, del_count);
            display(&SLL);
            if (element_deleted == INFINITY)
            {
                printf("The SLL is empty so delete operation cant be performed");
            }
            else
            {
                printf("The deleted element is: %lf\n", element_deleted);
            }
            break;

        case '4':
            element_deleted = delLast(&SLL, del_count);
            display(&SLL);
            if (element_deleted == INFINITY)
            {
                printf("The SLL is empty so delete operation cant be performed");
            }
            else
            {
                printf("The deleted element is: %lf\n", element_deleted);
            }
            break;

        case '5':
            printf("\nEnter position at which you want to perform the delete operation: ");
            scanf("%d", &index);
            element_deleted = del_i_node(&SLL, index, del_count);
            display(&SLL);
            if (element_deleted == INFINITY)
            {
                printf("The SLL is empty so delete operation cant be performed");
            }
            else
            {
                printf("%d element is now marked for deletion", index);
                printf("The deleted element is: %lf\n", element_deleted);
            }
            break;

        case '6':
            display(&SLL);
            break;

        case '7':
            printf("\nThe size of the SLL at the moment is: %d \n", size(&SLL));
            break;

        case '8':
            recall_last_deleted(&SLL, del_count);
            display(&SLL);
            break;

        case '9':
            printf("Exiting....");
            return 0;
        }
    }
    return 0;
}