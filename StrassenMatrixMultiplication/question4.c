#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

// To Simple Print a matrix
void print(int **arr, int r, int c)
{
    printf("[");
    for (int i = 0; i < r; i++)
    {
        printf("\n  [ ");
        for (int j = 0; j < c; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("]");
    }
    printf("\n]\n");
}

// Adding two matrix and storing in third
void add_matrix(int **a, int **b, int **c, int row, int column)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            c[i][j] += a[i][j] + b[i][j];
        }
    }
}

// Subtracting two matrix and storing in third
void sub_matrix(int **a, int **b, int **c, int row, int column)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            c[i][j] += a[i][j] - b[i][j];
        }
    }
}

// Simple Divide and Conquer Approach
int **dac(int **a, int **b, int r1, int c1, int r2, int c2)
{

    int **res = (int *)malloc(r1 * sizeof(int *));
    for (int i = 0; i < r1; i++)
    {
        res[i] = (int *)malloc(c2 * sizeof(int));
    }

    if (r1 == 1 && r2 == 1 && c1 == 1 && c2 == 1)
    {
        res[0][0] = a[0][0] * b[0][0];
    }
    else
    {
        // Allocating and Initializing the Arrays
        // 4 arrays for A and 4 for B
        int **a00 = malloc((r1 / 2) * sizeof(int *));
        int **a01 = malloc((r1 / 2) * sizeof(int *));
        int **a10 = malloc((r1 / 2) * sizeof(int *));
        int **a11 = malloc((r1 / 2) * sizeof(int *));

        int **b00 = malloc((r2 / 2) * sizeof(int *));
        int **b01 = malloc((r2 / 2) * sizeof(int *));
        int **b10 = malloc((r2 / 2) * sizeof(int *));
        int **b11 = malloc((r2 / 2) * sizeof(int *));

        for (int i = 0; i < (r1 / 2); i++)
        {
            a00[i] = (int *)malloc((c1 / 2) * sizeof(int));
            a01[i] = (int *)malloc((c1 / 2) * sizeof(int));
            a10[i] = (int *)malloc((c1 / 2) * sizeof(int));
            a11[i] = (int *)malloc((c1 / 2) * sizeof(int));
        }

        for (int i = 0; i < (r2 / 2); i++)
        {
            b00[i] = (int *)malloc((c2 / 2) * sizeof(int));
            b01[i] = (int *)malloc((c2 / 2) * sizeof(int));
            b10[i] = (int *)malloc((c2 / 2) * sizeof(int));
            b11[i] = (int *)malloc((c2 / 2) * sizeof(int));
        }

        for (int i = 0; i < (r1 / 2); i++)
        {
            for (int j = 0; j < (c1 / 2); j++)
            {
                a00[i][j] = a[i][j];
                a01[i][j] = a[i][j + (c1 / 2)];
                a10[i][j] = a[i + (r1 / 2)][j];
                a11[i][j] = a[i + (r1 / 2)][j + (c1 / 2)];
            }
        }

        for (int i = 0; i < (r2 / 2); i++)
        {
            for (int j = 0; j < (c2 / 2); j++)
            {
                b00[i][j] = b[i][j];
                b01[i][j] = b[i][j + (c2 / 2)];
                b10[i][j] = b[i + (r2 / 2)][j];
                b11[i][j] = b[i + (r2 / 2)][j + (c2 / 2)];
            }
        }

        // Allocating the result array
        int **res00 = malloc((r1 / 2) * sizeof(int *));
        int **res01 = malloc((r1 / 2) * sizeof(int *));
        int **res10 = malloc((r1 / 2) * sizeof(int *));
        int **res11 = malloc((r1 / 2) * sizeof(int *));

        for (int i = 0; i < (r1 / 2); i++)
        {
            res00[i] = (int *)malloc((c2 / 2) * sizeof(int));
            res01[i] = (int *)malloc((c2 / 2) * sizeof(int));
            res10[i] = (int *)malloc((c2 / 2) * sizeof(int));
            res11[i] = (int *)malloc((c2 / 2) * sizeof(int));
            for (int j = 0; j < (c2 / 2); j++)
            {
                res00[i][j] = 0;
                res01[i][j] = 0;
                res10[i][j] = 0;
                res11[i][j] = 0;
            }
        }

        // Performing addition on 2subparts of the problem
        // Total 8 divisions as the funciton is called 8 times
        // Total 4 additions as add function is called 4 times
        add_matrix(dac(a00, b00, (r1 / 2), (c1 / 2), (r2 / 2), (c2 / 2)), dac(a01, b10, (r1 / 2), (c1 / 2), (r2 / 2), (c2 / 2)), res00, (r1 / 2), (c2 / 2));
        add_matrix(dac(a00, b01, (r1 / 2), (c1 / 2), (r2 / 2), (c2 / 2)), dac(a01, b11, (r1 / 2), (c1 / 2), (r2 / 2), (c2 / 2)), res01, (r1 / 2), (c2 / 2));
        add_matrix(dac(a10, b00, (r1 / 2), (c1 / 2), (r2 / 2), (c2 / 2)), dac(a11, b10, (r1 / 2), (c1 / 2), (r2 / 2), (c2 / 2)), res10, (r1 / 2), (c2 / 2));
        add_matrix(dac(a10, b01, (r1 / 2), (c1 / 2), (r2 / 2), (c2 / 2)), dac(a11, b11, (r1 / 2), (c1 / 2), (r2 / 2), (c2 / 2)), res11, (r1 / 2), (c2 / 2));

        // Storing the result in final matrix
        for (int i = 0; i < (r1 / 2); i++)
        {
            for (int j = 0; j < (c2 / 2); j++)
            {
                res[i][j] = res00[i][j];
                res[i][j + (c2 / 2)] = res01[i][j];
                res[(r1 / 2) + i][j] = res10[i][j];
                res[i + (r1 / 2)][j + (c2 / 2)] = res11[i][j];
            }
        }

        // Deallocating the unrequired space
        for (int i = 0; i < (r1 / 2); i++)
        {
            free(a00[i]);
            free(a01[i]);
            free(a10[i]);
            free(a11[i]);
        }
        free(a00);
        free(a01);
        free(a10);
        free(a11);
        for (int i = 0; i < (r2 / 2); i++)
        {
            free(b00[i]);
            free(b01[i]);
            free(b10[i]);
            free(b11[i]);
        }
        free(b00);
        free(b01);
        free(b10);
        free(b11);
        for (int i = 0; i < (r1 / 2); i++)
        {
            free(res00[i]);
            free(res01[i]);
            free(res10[i]);
            free(res11[i]);
        }
        free(res00);
        free(res01);
        free(res10);
        free(res11);
    }
    return res;
}

int **strassen(int **a, int **b, int r1, int c1, int r2, int c2)
{

    int **res = (int *)malloc(r1 * sizeof(int *));
    for (int i = 0; i < r1; i++)
    {
        res[i] = (int *)malloc(c2 * sizeof(int));
    }

    if (r1 == 1 && r2 == 1 && c1 == 1 && c2 == 1)
    {
        res[0][0] = a[0][0] * b[0][0];
    }
    else
    {
        // Allocating and Initializing the Arrays
        // 4 arrays for A and 4 for B
        int **a00 = malloc((r1 / 2) * sizeof(int *));
        int **a01 = malloc((r1 / 2) * sizeof(int *));
        int **a10 = malloc((r1 / 2) * sizeof(int *));
        int **a11 = malloc((r1 / 2) * sizeof(int *));

        int **b00 = malloc((r2 / 2) * sizeof(int *));
        int **b01 = malloc((r2 / 2) * sizeof(int *));
        int **b10 = malloc((r2 / 2) * sizeof(int *));
        int **b11 = malloc((r2 / 2) * sizeof(int *));

        for (int i = 0; i < (r1 / 2); i++)
        {
            a00[i] = (int *)malloc((c1 / 2) * sizeof(int));
            a01[i] = (int *)malloc((c1 / 2) * sizeof(int));
            a10[i] = (int *)malloc((c1 / 2) * sizeof(int));
            a11[i] = (int *)malloc((c1 / 2) * sizeof(int));
        }

        for (int i = 0; i < (r2 / 2); i++)
        {
            b00[i] = (int *)malloc((c2 / 2) * sizeof(int));
            b01[i] = (int *)malloc((c2 / 2) * sizeof(int));
            b10[i] = (int *)malloc((c2 / 2) * sizeof(int));
            b11[i] = (int *)malloc((c2 / 2) * sizeof(int));
        }

        for (int i = 0; i < (r1 / 2); i++)
        {
            for (int j = 0; j < (c1 / 2); j++)
            {
                a00[i][j] = a[i][j];
                a01[i][j] = a[i][j + (c1 / 2)];
                a10[i][j] = a[i + (r1 / 2)][j];
                a11[i][j] = a[i + (r1 / 2)][j + (c1 / 2)];
            }
        }

        for (int i = 0; i < (r2 / 2); i++)
        {
            for (int j = 0; j < (c2 / 2); j++)
            {
                b00[i][j] = b[i][j];
                b01[i][j] = b[i][j + (c2 / 2)];
                b10[i][j] = b[i + (r2 / 2)][j];
                b11[i][j] = b[i + (r2 / 2)][j + (c2 / 2)];
            }
        }

        // Allocating the result array
        int **res00 = malloc((r1 / 2) * sizeof(int *));
        int **res01 = malloc((r1 / 2) * sizeof(int *));
        int **res10 = malloc((r1 / 2) * sizeof(int *));
        int **res11 = malloc((r1 / 2) * sizeof(int *));

        for (int i = 0; i < (r1 / 2); i++)
        {
            res00[i] = (int *)malloc((c2 / 2) * sizeof(int));
            res01[i] = (int *)malloc((c2 / 2) * sizeof(int));
            res10[i] = (int *)malloc((c2 / 2) * sizeof(int));
            res11[i] = (int *)malloc((c2 / 2) * sizeof(int));
            for (int j = 0; j < (c2 / 2); j++)
            {
                res00[i][j] = 0;
                res01[i][j] = 0;
                res10[i][j] = 0;
                res11[i][j] = 0;
            }
        }

        // Allocating the 10 sum arrays which will store the computation of arrays
        int **s1 = (int **)malloc((r2 / 2) * sizeof(int *));
        int **s2 = (int **)malloc((r1 / 2) * sizeof(int *));
        int **s3 = (int **)malloc((r1 / 2) * sizeof(int *));
        int **s4 = (int **)malloc((r2 / 2) * sizeof(int *));
        int **s5 = (int **)malloc((r1 / 2) * sizeof(int *));
        int **s6 = (int **)malloc((r2 / 2) * sizeof(int *));
        int **s7 = (int **)malloc((r1 / 2) * sizeof(int *));
        int **s8 = (int **)malloc((r2 / 2) * sizeof(int *));
        int **s9 = (int **)malloc((r1 / 2) * sizeof(int *));
        int **s10 = (int **)malloc((r2 / 2) * sizeof(int *));

        for (int i = 0; i < (r1 / 2); i++)
        {
            s2[i] = (int *)malloc((c2 / 2) * sizeof(int));
            s3[i] = (int *)malloc((c2 / 2) * sizeof(int));
            s5[i] = (int *)malloc((c2 / 2) * sizeof(int));
            s7[i] = (int *)malloc((c2 / 2) * sizeof(int));
            s9[i] = (int *)malloc((c2 / 2) * sizeof(int));
            for (int j = 0; j < (c1 / 2); j++)
            {
                s2[i][j] = 0;
                s3[i][j] = 0;
                s5[i][j] = 0;
                s7[i][j] = 0;
                s9[i][j] = 0;
            }
        }
        for (int i = 0; i < (r2 / 2); i++)
        {
            s1[i] = (int *)malloc((c2 / 2) * sizeof(int));
            s4[i] = (int *)malloc((c2 / 2) * sizeof(int));
            s6[i] = (int *)malloc((c2 / 2) * sizeof(int));
            s8[i] = (int *)malloc((c2 / 2) * sizeof(int));
            s10[i] = (int *)malloc((c2 / 2) * sizeof(int));
            for (int j = 0; j < (c2 / 2); j++)
            {
                s1[i][j] = 0;
                s4[i][j] = 0;
                s6[i][j] = 0;
                s8[i][j] = 0;
                s10[i][j] = 0;
            }
        }

        // Performing 5 addition and 5 subtraction operations
        sub_matrix(b01, b11, s1, (r2 / 2), (c2 / 2));
        add_matrix(a00, a01, s2, (r1 / 2), (c1 / 2));
        add_matrix(a10, a11, s3, (r1 / 2), (c1 / 2));
        sub_matrix(b10, b00, s4, (r2 / 2), (c2 / 2));
        add_matrix(a00, a11, s5, (r1 / 2), (c1 / 2));
        add_matrix(b00, b11, s6, (r2 / 2), (c2 / 2));
        sub_matrix(a01, a11, s7, (r1 / 2), (c1 / 2));
        add_matrix(b10, b11, s8, (r2 / 2), (c2 / 2));
        sub_matrix(a00, a10, s9, (r1 / 2), (c1 / 2));
        add_matrix(b00, b01, s10, (r2 / 2), (c2 / 2));

        // Performing a total of 7 divisons
        int **p1 = strassen(a00, s1, (r1 / 2), (c1 / 2), (r2 / 2), (c2 / 2));
        int **p2 = strassen(s2, b11, (r1 / 2), (c1 / 2), (r2 / 2), (c2 / 2));
        int **p3 = strassen(s3, b00, (r1 / 2), (c1 / 2), (r2 / 2), (c2 / 2));
        int **p4 = strassen(a11, s4, (r1 / 2), (c1 / 2), (r2 / 2), (c2 / 2));
        int **p5 = strassen(s5, s6, (r1 / 2), (c1 / 2), (r2 / 2), (c2 / 2));
        int **p6 = strassen(s7, s8, (r1 / 2), (c1 / 2), (r2 / 2), (c2 / 2));
        int **p7 = strassen(s9, s10, (r1 / 2), (c1 / 2), (r2 / 2), (c2 / 2));

        // Finally performing 3 addition and 3 subtraction operations to store the result
        add_matrix(p5, p4, res00, (r1 / 2), (c2 / 2));
        sub_matrix(p6, p2, res00, (r1 / 2), (c2 / 2));

        add_matrix(p1, p2, res01, (r1 / 2), (c2 / 2));

        add_matrix(p3, p4, res10, (r1 / 2), (c2 / 2));

        sub_matrix(p5, p3, res11, (r1 / 2), (c2 / 2));
        sub_matrix(p1, p7, res11, (r1 / 2), (c2 / 2));

        for (int i = 0; i < (r1 / 2); i++)
        {
            for (int j = 0; j < (c2 / 2); j++)
            {
                res[i][j] = res00[i][j];
                res[i][j + (c2 / 2)] = res01[i][j];
                res[(r1 / 2) + i][j] = res10[i][j];
                res[i + (r1 / 2)][j + (c2 / 2)] = res11[i][j];
            }
        }

        // Deallocating the unrequired memory
        for (int i = 0; i < (r1 / 2); i++)
        {
            free(a00[i]);
            free(a01[i]);
            free(a10[i]);
            free(a11[i]);
        }
        free(a00);
        free(a01);
        free(a10);
        free(a11);
        for (int i = 0; i < (r2 / 2); i++)
        {
            free(b00[i]);
            free(b01[i]);
            free(b10[i]);
            free(b11[i]);
        }
        free(b00);
        free(b01);
        free(b10);
        free(b11);
        for (int i = 0; i < (r1 / 2); i++)
        {
            free(res00[i]);
            free(res01[i]);
            free(res10[i]);
            free(res11[i]);
        }
        free(res00);
        free(res01);
        free(res10);
        free(res11);
        for (int i = 0; i < (r1 / 2); i++)
        {
            free(s2[i]);
            free(s3[i]);
            free(s5[i]);
            free(s7[i]);
            free(s9[i]);
        }
        for (int i = 0; i < (r2 / 2); i++)
        {
            free(s1[i]);
            free(s4[i]);
            free(s6[i]);
            free(s8[i]);
            free(s10[i]);
        }
        free(s1);
        free(s2);
        free(s3);
        free(s4);
        free(s5);
        free(s6);
        free(s7);
        free(s8);
        free(s9);
        free(s10);
    }
    return res;
}

int main()
{
    // Menu Driven Program
    int flag = 1;

    while (flag == 1)
    {
        int r1, r2, c1, c2;
        printf("Enter the Number of rows of matrix A : ");
        scanf("%d", &r1);
        printf("Enter the Number of columns of matrix A : ");
        scanf("%d", &c1);
        printf("Enter the Number of rows of matrix B : ");
        scanf("%d", &r2);
        printf("Enter the Number of columns of matrix B : ");
        scanf("%d", &c2);
        if (c1 != r2)
        {
            printf("The Number of Columns of Matrix A must match with Number of rows of matrix B\n");
            printf("Enter the Dimmensions again : \n");
            printf("Enter the Number of rows of matrix A : ");
            scanf("%d", &r1);
            printf("Enter the Number of columns of matrix A : ");
            scanf("%d", &c1);
            printf("Enter the Number of rows of matrix B : ");
            scanf("%d", &r2);
            printf("Enter the Number of columns of matrix B : ");
            scanf("%d", &c2);
        }
        if ((ceil(log2(r1)) != floor(log2(r1))) || (ceil(log2(r2)) != floor(log2(r2))) || (ceil(log2(c1)) != floor(log2(c1))) || (ceil(log2(c2)) != floor(log2(c2))))
        {
            printf("The Dimmensions must be a power of 2\n");
            printf("Enter the Dimmensions again : \n");
            printf("Enter the Number of rows of matrix A : ");
            scanf("%d", &r1);
            printf("Enter the Number of columns of matrix A : ");
            scanf("%d", &c1);
            printf("Enter the Number of rows of matrix B : ");
            scanf("%d", &r2);
            printf("Enter the Number of columns of matrix B : ");
            scanf("%d", &c2);
        }
        // Allocating the main arrays
        int **A = (int **)malloc(r1 * sizeof(int *));
        int **B = (int **)malloc(r2 * sizeof(int *));
        printf("\nEnter the Elements of matrix A rowwise : \n");
        for (int i = 0; i < r1; i++)
        {
            A[i] = (int *)malloc(c1 * sizeof(int));
            for (int j = 0; j < c1; j++)
            {
                printf("El: i = %d,j = %d : ", i, j);
                scanf("%d", &A[i][j]);
            }
        }
        printf("\nEnter the Elements of matrix B rowwise : \n");
        for (int i = 0; i < r2; i++)
        {
            B[i] = (int *)malloc(c2 * sizeof(int));
            for (int j = 0; j < c2; j++)
            {
                printf("El: i = %d,j = %d : ", i, j);
                scanf("%d", &B[i][j]);
            }
        }
        // Checking the choice
        printf("\n1 : Matrix Multiplication using Simple Divide and Conquer : \n");
        printf("2 : Matrix Multiplication using Strassen's matrix multiplication : \n");
        int choice;
        printf("Choice : ");
        scanf("%d", &choice);
        if (choice != 1 && choice != 2)
        {
            printf("Enter Correct Choice : \n");
            printf("Choice : ");
            scanf("%d", choice);
        }
        int **C;
        if (choice == 1)
        {
            C = dac(A, B, r1, c1, r2, c2);
        }
        else
        {
            C = strassen(A, B, r1, c1, r2, c2);
        }
        printf("The Matrix A is : \n");
        print(A, r1, c1);
        printf("The Matrix B is : \n");
        print(B, r2, c2);
        printf("The Result Matrix C is : \n");
        print(C, r1, c2);
        printf("Do You want to continue : 1: Yes , 0: No : ");
        scanf("%d", &flag);
    }

    return 0;
}