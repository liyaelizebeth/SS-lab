#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int x = 0, y = 1, s = 1;
int empty = 4, full = 0;
int buffer[4], op;

int wait(int s)
{
    while (s <= 0)
        ;
    return (--s);
}

int signal(int s)
{
    return (++s);
}

int produce()
{
    empty = wait(empty);
    s = wait(s);
    x = (x + 1) % 5;
    printf("\nproduce item %d", x);
    s = signal(s);
    full = signal(full);
}

int consume()
{
    full = wait(full);
    s = wait(s);
    printf("\nconsume item %d", y);
    y = (y + 1) % 5;
    s = signal(s);
    empty = signal(empty);
}

void main()
{
    while (1)
    {
        printf("\n1.Produce \n2.Consume \n3.Exit");
        printf("\nenter choice");
        scanf("%d", &op);
        if (op == 1)
        {
            if ((s == 1) && (empty != 0))
                produce();
            else
            {
                printf("\nBuffer is full");
            }
        }
        else if (op == 2)
        {
            if ((s == 1) && (full != 0))
                consume();
            else
            {
                printf("\nbuffer is empty");
            }
        }
        else if (op == 3)
            exit(0);
    }
}