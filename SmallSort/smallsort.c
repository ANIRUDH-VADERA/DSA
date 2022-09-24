#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle
{
    int a;
    int b;
    int c;
};

typedef struct triangle triangle;
void sort_by_area(triangle *tr, int n)
{
    /**
	* Sort an array a of the length n
	*/
    float p;
    float area;
    triangle *tr1 = malloc(n * sizeof(triangle));
    float arr[100][2];
    for (int i = 0; i < n; i++)
    {
        p = (tr[i].a + tr[i].b + tr[i].c) / 2.0;
        area = (float)sqrt(p * (p - tr[i].a) * (p - tr[i].b) * (p - tr[i].c));
        arr[i][0] = i;
        arr[i][1] = area;
    }
    int min_idx = 0;
    float temp1, temp2;
    for (int i = 0; i < (n - 1); i++)
    {
        min_idx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[min_idx][1] > arr[j][1])
            {
                min_idx = j;
            }
        }
        if (min_idx != i)
        {
            temp1 = arr[min_idx][0];
            temp2 = arr[min_idx][1];
            arr[min_idx][0] = arr[i][0];
            arr[min_idx][1] = arr[i][1];
            arr[i][0] = temp1;
            arr[i][1] = temp2;
        }
    }
    printf("arr=[ ");
    for (int i = 0; i < n; i++)
    {
        printf("%.1f ", arr[i][1]);
    }
    printf("]\n");
    printf("aidx=[ ");
    for (int i = 0; i < n; i++)
    {
        printf("%.1f ", arr[i][0]);
    }
    printf("]\n");
    for (int i = 0; i < n; i++)
    {
        tr1[i].a = tr[(int)arr[i][0]].a;
        tr1[i].b = tr[(int)arr[i][0]].b;
        tr1[i].c = tr[(int)arr[i][0]].c;
    }
    for (int i = 0; i < n; i++)
    {
        tr[i].a = tr1[i].a;
        tr[i].b = tr1[i].b;
        tr[i].c = tr1[i].c;
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    triangle *tr = malloc(n * sizeof(triangle));
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
    }
    sort_by_area(tr, n);
    printf("hi\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
    }
    return 0;
}