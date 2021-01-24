#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

enum
{
    THINKING,
    EATING,
    HUNGRY
} state[5];
int i, k, flag[5], n;

int initialize(void)
{
    for (i = 0; i < 5; i++)
    {
        state[i] = THINKING;
        flag[i] = 0;
    }
}

int test(int x)
{
    if (state[(x + 4) % 5] == THINKING && state[(x + 1) % 5] == THINKING && state[x] == HUNGRY)
    {
        state[x] = EATING;
        flag[x] = 1;
    }
}

int pickup(int x)
{
    state[x] = HUNGRY;
    test(x);
    if (flag[x] == 0)
        printf("Philosopher %d cannot eat now", x + 1);
    else
    {
        printf("\n philosopher %d is eating\n", x + 1);
    }
}

int putdown(int x)
{
    state[x] = THINKING;
    test((x + 4) % 5);
    test((x + 1) % 5);
    printf("\n philosopher %d is thinking", x + 1);
}

void main()
{
    initialize();
    while (1)
    {
        printf("\n1.start eat \n2.end eat \n3.exit");
        printf("\nenter choice");
        scanf("%d", &k);
        if (k == 3)
            exit(0);
        printf("\n which philosopher");
        scanf("%d", &n);
        if (k == 1)
            pickup(n - 1);
        else if (k == 2)
            putdown(n - 1);
    }
}
