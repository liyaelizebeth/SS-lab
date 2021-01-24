#include<stdio.h>
#include<ctype.h>
#include<string.h>


void main()
{
        FILE *f1,*f2,*f3;
        char la[10],ma[10],operand[10];
        f1 = fopen("input.txt","r");     
        f2 = fopen("ntab.txt","w+");
        f3 = fopen("dtab.txt","w+");
        fscanf(f1,"%s%s%s",la,ma,operand);

        while(strcmp(ma,"MEND")!=0)
        {
           if(strcmp(ma,"MACRO")==0)
           {
              fprintf(f2,"%s\n",la);
              fprintf(f3,"%s\t%s\n",la,operand);
           }
           else
              fprintf(f3,"%s\t%s\n",ma,operand);
           fscanf(f1,"%s%s%s",la,ma,operand);
        }
        fprintf(f3,"%s",ma);
        fclose(f1);
        fclose(f2);
        fclose(f3);
        printf("\npass1 completed");





}


