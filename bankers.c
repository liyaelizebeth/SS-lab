#include<stdio.h>
int main()
{
   int n,m,i,j,k;
   int count =0;
   
   int f[10];
   int alloc[100][100],max[100][100],need[100][100];
   int avail[10],seq[10];
   printf("\nENTER NO OF PROCESSES");
   scanf("%d",&n);
   printf("\nENTER NO OF RESOURCES");
   scanf("%d",&m);
   for(i=0;i<n;i++)
   {  
      printf("\nENTER ALLOCATION MATRIX OF P%d",i);
      for(j=0;j<m;j++)
      {
         scanf("%d",&alloc[i][j]);
         f[i]=0;

      }
   }
   for(i=0;i<n;i++)
   {  
      printf("\nENTER MAXIMUM MATRIX OF P %d",i);
      for(j=0;j<m;j++)
      {
         scanf("%d",&max[i][j]);
      }
   }
   
   for(j=0;j<m;j++)
   {
      printf("\nENTER NO OF AVAILABLE INSTANCES OF RESOURCE%d",j);
      scanf("%d",&avail[j]);
   }
   for(i=0;i<n;i++)
   {  
      
      for(j=0;j<m;j++)
      {
         need[i][j] = max[i][j] - alloc[i][j];

      }
   }
   for(i=0;i<n;i++)
   {  
       printf("\n NEED MATRIX OF P%d",i);

      for(j=0;j<m;j++)
      {
         printf("\t %d",need[i][j]);
        
      }
   }
   for (k=0;k<n;k++){
   for(i=0;i<n;i++)
   {  
       
      if ( f[i] == 0)
      {
           for(j=0;j<m;j++)
           {
               if(need[i][j] <= avail[j])
               {
                    continue;
               }
               else
               {
                     break;
               }
            }
            if(j==m)
            {
                 f[i] = 1;
                 for(j=0;j<m;j++)
                 {
                      avail[j] = avail[j]+alloc[i][j];
                  }
                  count++;
                  seq[count - 1]=i;
             }
         }
      }
}
      if (count == n)
      {
         printf("\nSAFE SEQUENCE");
         for(i=0;i<n;i++)
         {
            printf("\tP%d",seq[i]);
         }
       }
       else
          printf("\n NO");


                 

      
   


      
     
   
}
   
          

   


