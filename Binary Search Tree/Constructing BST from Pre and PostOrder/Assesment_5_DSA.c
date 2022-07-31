// Data Structures and Algorithms (CSE2011)
// Assessment 01 (LAB)
// 5. Given the pre-order traversal or post-order traversal of the Binary Search tree,construct the BST.

// ANIRUDH VADERA
// 20BCT0144

// Header Files
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Structure Definition of BSTree
struct BSTNode
{
    double data;
    struct BSTNode *left;
    struct BSTNode *right;
};

// Creating a new node
struct BSTNode *createNewNode(double v)
{
    struct BSTNode *newnode = (struct BSTNode *)malloc(sizeof(struct BSTNode));
    newnode->data = v;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

// Function to convert the given pre-order traversal into a BSTree
struct BSTNode *preorder_to_BST(double *ptr, int start, int end)
{
    // Boundary condition
    // If the start and end is same i.e only a single element
    // Return that node
    if (start == end)
    {
        struct BSTNode *node = createNewNode(*(ptr + start));
        return node;
    }
    else
    {
        // root here means the root node for the underlying subtree
        // At every recursive call our root node changes
        // As we know in a preorder traversal the root node for the particular subtree is the starting node only
        // Therefore the root node is initialized with Array[start]
        struct BSTNode *root = createNewNode(*(ptr + start));
        int i = 0;

        // First we find the first element in the range given to us by the function
        // Then we traverse through the sequence from start to end
        // And find the first occurence of a node with value property larger than the first element
        for (i = start + 1; i <= end; i++)
        {
            if (*(ptr + i) > *(ptr + start))
            {
                break;
            }
        }

        // Checking the condition if the modified start is less than the modified end for the subarray(left to i) to be passed
        if ((start + 1) <= (i - 1))
        {
            // we make the left child of the current root as the root of the subarray we are going to pass
            root->left = preorder_to_BST(ptr, start + 1, i - 1);
        }

        // Checking the condition if the modified start is less than the modified end for the subarray(right to i including i) to be passed
        if (i <= end)
        {
            // we make the right child of the current root as the root of the subarray we are going to pass
            root->right = preorder_to_BST(ptr, i, end);
        }

        // At the last reccursive call this node to be returned becomes the root of the whole BSTree
        return root;
    }
}

// Function to convert the given post-order traversal into a BSTree
struct BSTNode *postorder_to_BST(double *ptr, int start, int end)
{
    // Boundary condition
    // If the start and end is same i.e only a single element
    // Return that node
    if (start == end)
    {
        struct BSTNode *node = createNewNode(*(ptr + start));
        return node;
    }
    else
    {
        // root here means the root node for the underlying subtree
        // At every recursive call our root node changes
        // As we know in a postorder traversal the root node for the particular subtree is the last node only
        // Therefore the root node is initialized with Array[end]
        struct BSTNode *root = createNewNode(*(ptr + end));
        int i = 0;

        // First we find the last element in the range given to us by the function
        // Then we traverse through the sequence from start to end
        // And find the first occurence of a node with value property larger than the last element
        for (i = start; i <= end - 1; i++)
        {
            if (*(ptr + i) > *(ptr + end))
            {
                break;
            }
        }

        // Checking the condition if the modified start is less than the modified end for the subarray(left to i) to be passed
        if (start <= (i - 1))
        {
            // we make the left child of the current root as the root of the subarray we are going to pass
            root->left = postorder_to_BST(ptr, start, i - 1);
        }

        // Checking the condition if the modified start is less than the modified end for the subarray(right to i including i) to be passed
        if (i <= end - 1)
        {
            // we make the right child of the current root as the root of the subarray we are going to pass
            root->right = postorder_to_BST(ptr, i, end - 1);
        }

        // At the last reccursive call this node to be returned becomes the root of the whole BSTree
        return root;
    }
}

// Function for traversing through tree using inorder traversal
void inorder(struct BSTNode *root)
{
    if (root != NULL)
    {
        inorder(root->left);           // Traverse into Left subtree
        printf(" %5.2lf", root->data); // visiting(printing the value) the node
        inorder(root->right);          // Traverse into Right subtree
    }
}

int main()
{
    // Choice is for the user to enter to perform pre-order traversal to BSTree or post-order traversal to BSTree
    int choice;
    printf("Press 0 to convert preorder sequence into a BSTree\n");
    printf("Press 1 to convert postorder sequence into a BSTree\n");
    printf("Your Choice : ");
    scanf("%d", &choice);

    // n is the number of elements to be in the BSTree
    int n;
    printf("\nEnter the number of nodes in the binary search tree/No of elements to be entered : ");
    scanf("%d", &n);

    double sequence[n];

    if (n != 0)
    {
        // Getting the preorder sequence or the postorder sequence from the user

        printf("\nEnter the elements for the preorder or postorder sequence\n");
        for (int i = 0; i < n; i++)
        {
            printf("Element %d : ", i + 1);
            scanf("%lf", &(sequence[i]));
        }

        if (choice == 0) //For the preorder traversal to BSTree
        {
            printf("\n\nConverted the given preorder sequence into a BSTree\n");
            printf("\nThe inorder traversal of the BSTree is : ");
            printf("\n{");
            struct BSTNode *BST_root = preorder_to_BST(sequence, 0, n - 1);
            inorder(BST_root);
            printf(" }\n");
        }
        else if (choice == 1) //For the postorder traversal to BSTree
        {
            printf("\nConverted the given postorder sequence into a BSTree\n");
            printf("\nThe inorder traversal of the BSTree is:\n");
            printf("\n{");
            struct BSTNode *BST_root = postorder_to_BST(sequence, 0, n - 1);
            inorder(BST_root);
            printf(" }\n");
        }
        else
        {
            printf("Enter a valid choice\n");
        }
    }
    else
    {
        printf("The BSTree is empty\n");
    }

    return 0;
}
