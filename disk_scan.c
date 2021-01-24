#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int sort(int arr[100],int n)
{
    int i,temp;
    for(i=0;i<n-i-1;i++)
    {
       if(arr[i] > arr[i+1])
       {
           temp = arr[i];
           arr[i]=arr[i+1];
           arr[i+1]=temp;
       }
     }
}


void scan(int Ar[100], int n, int start) {
    int i, pos, diff, seekTime=0, current;
    
    for(i=0;i<n;i++) {                                      
        if(Ar[i]==start) {
            pos=i;
            break;
        }
    }
    
    printf("\nMovement of Cylinders\n");
    for(i=pos;i<n-1;i++) {
        diff = abs(Ar[i+1] - Ar[i]);
        seekTime += diff;
        printf("Move from %d to %d with seek time %d\n", Ar[i], Ar[i+1], diff);
    }
    current=i;                                              
    
    for(i=pos-1;i>=0;i--) {
        diff = abs(Ar[current] - Ar[i]);
        seekTime += diff;
        printf("Move from %d to %d with seek time %d\n", Ar[current], Ar[i], diff);
        current=i;
    }
    printf("\nTotal Seek Time: %d", seekTime);
    
    printf("\nAverage Seek Time = %f",(float) seekTime/(n-1));
    printf("\n");
}

    




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
   sort(disk_queue,n);
   scan(disk_queue,n,h);

   

          
}
   
