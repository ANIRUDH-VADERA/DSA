#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct BSTNode
{
    double data;
    struct BSTNode *left;
    struct BSTNode *right;
    struct BSTNode *parent; // Parent of root node is NULL
};

// root Node
struct BSTNode *bstree = NULL;

// Create a new Node
struct BSTNode *createNewNode(double v)
{
    struct BSTNode *newnode = (struct BSTNode *)malloc(sizeof(struct BSTNode));
    newnode->data = v;
    newnode->left = NULL;
    newnode->right = NULL;
    newnode->parent = NULL;
    return newnode;
}

// Add a node to the BST
void addNode(struct BSTNode *root, double v)
{
    if (root == NULL)
    {
        bstree = createNewNode(v);
        return;
    }
    if (root->data == v)
    {
        return;
    }

    if (root->data > v)
    {
        if (root->left == NULL)
        {
            struct BSTNode *newnode = createNewNode(v);
            newnode->parent = root;
            root->left = newnode;
        }
        else
        {
            addNode(root->left, v);
        }
    }
    else
    {
        if (root->right == NULL)
        {
            struct BSTNode *newnode = createNewNode(v);
            newnode->parent = root;
            root->right = newnode;
        }
        else
        {
            addNode(root->right, v);
        }
    }
}

// printing  LVR
void inorder(struct BSTNode *root)
{
    if (root != NULL)
    {
        inorder(root->left);           // L
        printf(" %5.2lf", root->data); // V
        inorder(root->right);          // R
    }
}

// printing VLR
void preorder(struct BSTNode *root)
{
    if (root != NULL)
    {
        printf(" %5.2lf", root->data); // V
        preorder(root->left);          // L
        preorder(root->right);         // R
    }
}
// printing LRV
void postorder(struct BSTNode *root)
{
    if (root != NULL)
    {
        postorder(root->left);         // L
        postorder(root->right);        // R
        printf(" %5.2lf", root->data); // V
    }
}

// 0 : key is not present in the BST
// 1 : key is present in the BST

int Search(struct BSTNode *root, double key)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root->data == key)
    {
        return 1;
    }
    else if (root->data > key)
    {
        return Search(root->left, key);
    }
    else
    {
        return Search(root->right, key);
    }
}

// Finding the minimum element in BST
double Minimum(struct BSTNode *root)
{
    if (root == NULL)
    {
        return INFINITY;
    }
    if (root->left == NULL)
    {
        return (root->data);
    }
    return Minimum(root->left);
}

// Finding the maximum element in BST
double Maximum(struct BSTNode *root)
{
    if (root == NULL)
    {
        return (-1) * INFINITY;
    }
    if (root->right == NULL)
    {
        return (root->data);
    }
    return Maximum(root->right);
}

// Finding the kth maximum element in BST
void kthMaximum(struct BSTNode *root, int k, int *count)
{
    if (root != NULL)
    {
        kthMaximum(root->right, k, count);
        (*count)++;
        if (k == *count)
        {
            printf("\n %d th Maximum = %lf\n", k, root->data);
        }
        kthMaximum(root->left, k, count);
    }
}

// returns the value property of the successor of the given node
double successor(struct BSTNode *node)
{
    double succ_value = INFINITY;
    if (node->right != NULL)
        return Minimum(node->right);

    struct BSTNode *temp = node->parent;
    while (temp != NULL && temp->right == node)
    {
        node = temp;
        temp = temp->parent;
    }
    if (temp != NULL)
    {
        return temp->data;
    }
    return succ_value;
}
// returns the value property of the predecessor of the given node
double predecessor(struct BSTNode *node)
{
    double pred_value = INFINITY;
    if (node->left != NULL)
        return Maximum(node->left);

    struct BSTNode *temp = node->parent;
    while (temp != NULL && temp->left == node)
    {
        node = temp;
        temp = temp->parent;
    }
    if (temp != NULL)
    {
        return temp->data;
    }
    return pred_value;
}

void deleteNode(struct BSTNode *node, double v)
{
    // 1. node == NULL
    if (node == NULL)
    {
        return;
    }

    // searching
    if (node->data > v)
    {
        if (node->left != NULL)
        {
            deleteNode(node->left, v);
            return;
        }
    }
    else if (node->data < v)
    {
        if (node->right != NULL)
        {
            deleteNode(node->right, v);
            return;
        }
    }

    // node->data == v
    // Case 1:  if the node to deleted is the leaf node

    if (node->left == NULL && node->right == NULL)
    {
        if (node->parent != NULL)
        {
            if (node->parent->left == node)
            {
                free(node->parent->left);
                node->parent->left = NULL;
            }
            else
            {
                free(node->parent->right);
                node->parent->right = NULL;
            }
        }
        else
        {
            free(node);
            bstree = NULL;
            node = NULL;
        }
        return;
    }

    // case 2 :  if the node to deleted has only left child
    if (node->left != NULL && node->right == NULL)
    {
        if (node->parent != NULL)
        {
            node->left->parent = node->parent;
            if (node->parent->left == node)
            {
                node->parent->left = node->left;
                free(node);
            }
            else
            {
                node->parent->right = node->left;
                free(node);
            }
        }
        else
        {
            node->left->parent = NULL;
            bstree = node->left;
            free(node);
        }
        return;
    }

    // case 3 :  if the node to deleted has only right child
    if (node->left == NULL && node->right != NULL)
    {
        if (node->parent != NULL)
        {
            node->right->parent = node->parent;
            if (node->parent->left == node)
            {
                node->parent->left = node->right;
                free(node);
            }
            else
            {
                node->parent->right = node->right;
                free(node);
            }
        }
        else
        {
            node->right->parent = NULL;
            bstree = node->right;
            free(node);
        }
        return;
    }

    // case 4 :  if the node to be deleted has both left and right subtree
    if (node->left != NULL && node->right != NULL)
    {
        double pdata = predecessor(node);
        node->data = pdata;
        deleteNode(node->left, pdata);
        return;
    }
}

int main()
{
    addNode(bstree, 50);
    addNode(bstree, 30);
    addNode(bstree, 10);
    addNode(bstree, 100);
    addNode(bstree, 55);
    addNode(bstree, 50);
    addNode(bstree, 70);

    printf("\nInorder:");
    inorder(bstree);
    printf("\nPreorder:");
    preorder(bstree);
    printf("\nPostOrder:");
    postorder(bstree);
    printf("\n");

    printf("50? : %d\n", Search(bstree, 50));
    printf("10? : %d\n", Search(bstree, 10));
    printf("100? : %d\n", Search(bstree, 100));
    printf("-220? : %d\n", Search(bstree, -220));
    printf("7740? : %d\n", Search(bstree, 7740));

    printf("\n Maximum :  %lf \n", Maximum(bstree));
    printf("\n Minimum :  %lf \n", Minimum(bstree));

    int count = 0;
    kthMaximum(bstree, 4, &count);
    count = 0;
    kthMaximum(bstree, 1, &count);
    count = 0;
    kthMaximum(bstree, 100, &count);

    printf(" \n Predecessor : %lf ", predecessor(bstree));
    printf(" \n Successor : %lf ", successor(bstree));

    printf("\n Inorder : ");
    inorder(bstree);
    deleteNode(bstree, 100);
    printf("\n Inorder (after deletion of 100) : ");
    inorder(bstree);

    deleteNode(bstree, 50);
    printf("\n Inorder (after deletion of 50) : ");
    inorder(bstree);

    return 0;
}
