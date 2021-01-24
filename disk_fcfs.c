#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main()
{
   int disk_queue[100],n,i,h,j,st;
   printf("\nEnter size of disk");
   scanf("%d",&n);
   printf("\nEnter the elements");
   for(i=0;i<n;i++)
   {
      scanf("%d",&disk_queue[i]);
   }
   printf("\nEnter initial head position");
   scanf("%d",&h);
   for(j=0;j<n;j++)
   {
      if(j==0)
      {
          st=abs(h - disk_queue[j]);
          printf("\nMove from %d",h);
          printf("to %d",disk_queue[j]);
          printf("\tSeek time is %d",st);
      }
      else
      {
            st=abs(disk_queue[j-1] - disk_queue[j]);
          printf("\nMove from %d",disk_queue[j-1]);
          printf("to %d",disk_queue[j]);
          printf("\tSeek time is %d",st);
      }
    }

          
}
   




