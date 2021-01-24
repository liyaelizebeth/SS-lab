#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct
{
    char dname[10], fname[10][10];
    int fcnt;

} dir;

int main()
{
    char f[10];
    int op, i;
    dir.fcnt = 0;
    printf("\nEnter name of directory");
    scanf("%s", dir.dname);
    while (1)
    {
        printf("\n1.ADD FILE \n2.DELETE FILE \n3.SEARCH FILE \n4.DISPLAY FILE \n5.EXIT");
        printf("\nEnter choice");
        scanf("%d", &op);
        if (op == 1)
        {
            printf("\nenter filename");
            scanf("%s", dir.fname[dir.fcnt]);
            dir.fcnt += 1;
        }
        else if (op == 2)
        {
            printf("\nenter file to be deleted");
            scanf("%s", f);
            for (i = 0; i < dir.fcnt; i++)
            {
                if (strcmp(f, dir.fname[i]) == 0)
                {
                    strcpy(dir.fname[i], dir.fname[dir.fcnt - 1]);
                    break;
                }
            }
            if (i == dir.fcnt)
                printf("\nfile not found");
            else
                dir.fcnt -= 1;
        }
        else if (op == 3)
        {
            printf("\nenter file to be searched");
            scanf("%s", f);
            for (i = 0; i < dir.fcnt; i++)
            {
                if (strcmp(f, dir.fname[i]) == 0)
                {
                    printf("\nFile %s found", f);
                    break;
                }
            }
            if (i == dir.fcnt)
                printf("\nFile not found");
        }
        else if (op == 4)
        {
            for (i = 0; i < dir.fcnt; i++)
            {
                printf("\t%s", dir.fname[i]);
            }
        }
        else if (op == 5)
        {
            exit(0);
        }
    }
}