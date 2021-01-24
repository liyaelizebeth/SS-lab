#include <stdio.h>
#include <stdlib.h>
int n, b[10], wt[10], trn[10], Pid[10];
int quantum;
float avgwait, avgturn;

int waiting()
{
    int b_rem[10], i, flag = 0;
    for (i = 0; i < n; i++)
    {
        b_rem[i] = b[i];
    }

    int time = 0;

    while (1)
    {
        for (i = 0; i < n; i++)
        {
            if (b_rem[i] > 0)
            {
                flag = 1;
                if (b_rem[i] > quantum)
                {
                    time += quantum;
                    b_rem[i] -= quantum;
                }
                else
                {
                    time += b_rem[i];
                    wt[i] = time - b[i];
                    b_rem[i] = 0;
                }
            }
        }
        if (flag == 0)
            exit(0);
    }
}

int turnaround()
{
    int i, sumturn = 0;
    for (i = 0; i < n; i++)
    {
        trn[i] = wt[i] + b[i];
    }
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
    printf("\nenter time quantum");
    scanf("%d", &quantum);
    for (i = 0; i < n; i++)
    {
        printf("\nenter burst time of P%d", i + 1);
        scanf("%d", &b[i]);
        Pid[i] = i + 1;
    }

    calc();
    display();
}