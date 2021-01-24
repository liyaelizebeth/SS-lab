#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

void main()
{
    FILE *f1, *f2, *f3, *f4, *f5;
    f1 = fopen("input.txt", "r");
    f2 = fopen("ntab.txt", "r");
    f3 = fopen("dtab.txt", "r");
    f4 = fopen("arg.txt", "w+");
    f5 = fopen("output.txt", "w");
    char la[20], mne[20], opnd[20], na[20], mne1[20], opnd1[20], arg[20];
    int l, i;

    fscanf(f1, "%s%s%s", la, mne, opnd);
    while (strcmp(mne, "END") != 0)
    {
        if (strcmp(mne, "MACRO") == 0)
        {
            fscanf(f1, "%s%s%s", la, mne, opnd);
            while (strcmp(mne, "MEND") != 0)
            {
                fscanf(f1, "%s%s%s", la, mne, opnd);
            }
        }

        else
        {
            fscanf(f2, "%s", na);
            if (strcmp(mne, na) == 0)
            {
                l = strlen(opnd);
                for (i = 0; i < l; i++)
                {
                    if (opnd[i] != ',')
                    {
                        fprintf(f4, "%c", opnd[i]);
                    }
                    else
                    {
                        fprintf(f4, "\n");
                    }
                }
                fseek(f2, SEEK_SET, 0);
                fseek(f4, SEEK_SET, 0);
                fscanf(f3, "%s%s", mne1, opnd1);
                fprintf(f5, "\t%s\t%s\n", mne1, opnd);
                fscanf(f3, "%s%s", mne1, opnd1);
                while (strcmp(mne1, "MEND") != 0)
                {
                    if (opnd1[0] == '&')
                    {
                        fscanf(f4, "%s", arg);
                        fprintf(f5, "\t%s\t%s\n", mne1, arg);
                    }
                    else
                    {
                        fprintf(f5, "\t%s\t%s\n", mne1, opnd1);
                    }
                    fscanf(f3, "%s%s", mne1, opnd1);
                }
            }
            else
            {
                fprintf(f5, "%s\t%s\t%s\n", la, mne, opnd);
            }
        }

        fscanf(f1, "%s\t%s\t%s", la, mne, opnd);
    }
    fprintf(f5, "%s\t%s\t%s\n", la, mne, opnd);

    fclose(f1);
    fclose(f2);
    fclose(f3);
    fclose(f4);
    fclose(f5);
    printf("pass2 complete");
}