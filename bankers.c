#include <stdio.h>

void main()
{
    int m, n, i, j;
    int alloc[10][10], maxi[10][10], need[10][10];
    int avail[10], seq[10];

    printf("\nenter no of processes");
    scanf("%d", &m);
    printf("enter no of resources");
    scanf("%d", &n);
    for (i = 0; i < m; i++)
    {
        printf("\nenter allocation matrix of P%d", i);
        for (j = 0; j < n; j++)
        {
            scanf("%d", &alloc[i][j]);
        }
    }

    for (i = 0; i < m; i++)
    {
        printf("\nenter maximum matrix of P%d", i);
        for (j = 0; j < n; j++)
        {
            scanf("%d", &maxi[i][j]);
        }
    }

    for (i = 0; i < m; i++)
    {

        for (j = 0; j < n; j++)
        {
            need[i][j] = maxi[i][j] - alloc[i][j];
        }
    }

    for (i = 0; i < m; i++)
    {
        printf("\nNeed matrix of P%d", i);

        for (j = 0; j < m; j++)
        {
            printf("\t%d", need[i][j]);
        }
    }
}