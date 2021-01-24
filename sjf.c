#include <stdio.h>
int n, b[10], wt[10], trn[10], Pid[10];
float avgwait, avgturn;

int swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int sort()
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - 1 - i; j++)
        {
            if (b[j] > b[j + 1])
            {
                swap(&b[j], &b[j + 1]);
                swap(&Pid[j], &Pid[j + 1]);
            }
        }
    }
}

int waiting()
{
    int i;
    int sumwt = 0;
    for (i = 1; i < n; i++)
    {
        wt[i] = wt[i - 1] + b[i - 1];
        sumwt += wt[i];
    }
    avgwait = (float)sumwt / n;
}

int turnaround()
{
    int i, sumturn = 0;
    for (i = 0; i < n; i++)
    {
        trn[i] = wt[i] + b[i];
        sumturn += trn[i];
    }
    avgturn = (float)sumturn / n;
}

int display()
{
    int i;
    printf("\nProcess\tburst\twait\tturn");
    for (i = 0; i < n; i++)
    {
        printf("\n%d\t%d\t%d\t%d", Pid[i], b[i], wt[i], trn[i]);
    }
}

int calc()
{
    waiting();
    turnaround();
}

void main()
{
    int i;
    printf("\nenter the no of prosesses");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("\nenter burst time of P%d", i + 1);
        scanf("%d", &b[i]);
        Pid[i] = i + 1;
    }
    sort();
    calc();
    display();
}