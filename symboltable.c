#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct Symbol
{
    int add;
    char label[20];

} s[11];

#define MAX 11
int a[MAX];
int count = 0;

int find(int x)
{
    int k = x % MAX;
    return k;
}

void create(int add, char label[20], int key)
{
    int i;
    int flag = 0;

    if (count != MAX)
    {
        for (i = key; i < MAX; i++)
        {
            if (a[i] == 0)
            {
                flag = 1;
                a[i] = add;
                s[i].add = add;
                strcpy(s[i].label, label);
                count++;
                break;
            }
        }
        if (flag == 0)
        {
            for (i = 0; i < key; i++)
            {
                if (a[i] == 0)
                {
                    flag = 1;
                    a[i] = add;
                    s[i].add = add;
                    strcpy(s[i].label, label);
                    count++;
                    break;
                }
            }
        }
    }
    else
    {
        printf("\nTable is full");
    }
}

void modify(int add, char label[20])
{
    int i, flag = 0;
    for (i = 0; i < MAX; i++)
    {
        if (s[i].add == add)
        {
            printf("\nvalue found %d\t%s", s[i].add, s[i].label);
            strcpy(s[i].label, label);
            printf("\n new value found %d\t%s", s[i].add, s[i].label);
            flag = 1;
        }
    }
    if (flag == 0)
    {
        printf("\naddress not found");
    }
}

void search(char label[20])
{
    int i, flag = 0;
    for (i = 0; i < MAX; i++)
    {
        if (strcmp(s[i].label, label) == 0)
        {
            flag = 1;
            printf("\nfound");
        }
        else
        {
            printf("\nnot found");
        }
    }
}

void display()
{
    int i;
    printf("\nindex\taddress\tlabel");
    for (i = 0; i < MAX; i++)
    {
        printf("\n%d\t%d\t%s", i, s[i].add, s[i].label);
    }
}

int main()
{

    int add, op;
    char j[20], i;
    for (i = 0; i < MAX; i++)
    {
        a[i] = 0;
        s[i].add = 0;
        strcpy(s[i].label, "");
    }
    while (1)
    {
        printf("\n1.CREATE \n2.MODIFY \n3.SEARCH \n4.DISPLAY \n5.EXIT");
        printf("\nenter option");
        scanf("%d", &op);
        if (op == 1)
        {
            printf("\nenter address");
            scanf("%d", &add);
            printf("\nenter label");
            scanf("%s", j);
            int key = find(add);
            create(add, j, key);
        }
        else if (op == 2)
        {
            printf("\nenter address");
            scanf("%d", &add);
            printf("\nenter new label");
            scanf("%s", j);
            modify(add, j);
        }
        else if (op == 3)
        {
            printf("\nenter label");
            scanf("%s", j);
            search(j);
        }
        else if (op == 4)
        {
            display();
        }
        else if (op == 5)
        {
            exit(0);
        }
    }
}