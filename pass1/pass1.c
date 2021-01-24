#include <stdio.h>
#include <ctype.h>
#include <string.h>

void main()
{

     char label[20], opcode[20], opnd[20], code[20], mne[20];
     int locctr, start, length;

     FILE *f1, *f2, *f3, *f4;

     f1 = fopen("input.txt", "r");
     f2 = fopen("optab.txt", "r");
     f3 = fopen("symtab.txt", "w");
     f4 = fopen("output.txt", "w");

     fscanf(f1, "%s\t%s\t%s", label, opcode, opnd);
     if (strcmp(opcode, "START") == 0)
     {
          start = atoi(opnd);
          locctr = start;
          fprintf(f4, "\t%s\t%s\t%s", label, opcode, opnd);
          fscanf(f1, "%s\t%s\t%s", label, opcode, opnd);
     }
     else
          locctr = 0;

     while (strcmp(opcode, "END") != 0)
     {
          fprintf(f4, "%d\t", locctr);
          if (strcmp(label, "**") != 0)
          {
               fprintf(f3, "%s\t%d", label, locctr);
          }
          fscanf(f2, "%s\t%s", code, mne);
          while (strcmp(code, "END") != 0)
          {
               if (strcmp(opcode, code) == 0)
               {
                    locctr += 3;
                    break;
               }

               fscanf(f2, "%s\t%s", code, mne);
          }

          if (strcmp(opcode, "WORD") == 0)
               locctr += 3;
          else if (strcmp(opcode, "RESW") == 0)
               locctr += 3 * (atoi(opnd));
          else if (strcmp(opcode, "BYTE") == 0)
               locctr += 1;

          fprintf(f4, "%s\t%s\t%s", label, opcode, opnd);
          fscanf(f1, "%s\t%s\t%s", label, opcode, opnd);
     }

     fprintf(f4, "%d\t%s\t%s\t%s", locctr, label, opcode, opnd);
     length = locctr - start;
     printf("%d", length);
     fclose(f1);
     fclose(f2);
     fclose(f3);
     fclose(f4);
}
