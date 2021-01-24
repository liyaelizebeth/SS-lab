#include <stdio.h>

int b[10], wt[10], trn[10];
float avgwait, avgtrn;

int avgwaiting(int n)
{
    int sumwt = 0;
    int i;
    for (i = 1; i < n; i++)
    {
        wt[i] = wt[i - 1] + b[i - 1];
        sumwt += wt[i];
    }

    avgwait = (float)sumwt / n;
}

int avgturn(int n)
{
    int sumtrn = 0;
    int i;
    for (i = 0; i < n; i++)
    {
        trn[i] = wt[i] + b[i];
        sumtrn += trn[i];
    }
    avgtrn = (float)sumtrn / n;
}

int calc(int n)
{
    avgwaiting(n);
    avgturn(n);
}

void display(int n)
{
    int i;
    printf("\nProcess\tWaiting time\tTurnaround time");
    for (i = 0; i < n; i++)
    {
        printf("\nP%d\t%d\t%d", i, wt[i], trn[i]);
    }
    printf("\n%f", avgwait);
    printf("\n%f", avgtrn);
}

void main()
{
    int n, i;
    printf("\neneter no of processes");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("\nenter burst time of process P%d", i);
        scanf("%d", &b[i]);
    }
    calc(n);
    display(n);
}