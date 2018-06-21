#include<stdio.h>
#include<conio.h>
void print(int arrival[10],int exe[10],int turn[10],int wait[10],int n)
{ float totalturn=0,totalwaiting=0;
  int i;

  printf("\n Process   Arrival Time     Burst Time     Waiting Time    Turn-Around Time");
  for(i=0;i<n;i++)
   { totalturn+=turn[i];
     totalwaiting+=wait[i];
     printf("\n P%d\t\t%d\t\t%d\t\t%d\t\t%d",i+1,arrival[i],exe[i],wait[i],turn[i]);
   }
   printf("\n\n Average turnaround time is : %.2f",(float)(totalturn/n));
   printf("\n Average waiting time is : %.2f",(float)(totalwaiting/n));
}

void main()
{ int n,i,j,wait[10],arrival[10],exe[10],turn[10];
  float sum;
  clrscr();

  printf("\n First Come First Serve");
  printf("\n ----------------------");
  printf("\n Enter the number of processes : ");
  scanf("%d",&n);

  printf("\n Enter the arrival time and execution time  \n");
  for(i=0;i<n;i++)
   { printf(" P%d : ",i+1);
     scanf(" %d %d",&arrival[i],&exe[i]);
   }

  for(i=0;i<n;i++)
   { sum=0;
     for(j=0;j<=i;j++)
      { sum=sum+exe[j];
      }
      turn[i] = sum - arrival[i];
      wait[i] = turn[i] - exe[i];
   }
   print(arrival,exe,turn,wait,n);

   getch();
}