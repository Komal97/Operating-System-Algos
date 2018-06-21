#include<stdio.h>
#include<conio.h>
void print(int processes[10],int arrival[10],int exe[10],int turn[10],int wait[10],int n)
{ float totalturn=0,totalwaiting=0;
  int i;

  printf("\n Process   Arrival Time     Burst Time     Waiting Time    Turn-Around Time");
  for(i=0;i<n;i++)
   { totalturn+=turn[i];
     totalwaiting+=wait[i];
     printf("\n P%d\t\t%d\t\t%d\t\t%d\t\t%d",processes[i],arrival[i],exe[i],wait[i],turn[i]);
   }
   printf("\n\n Average turnaround time is : %.2f",(float)(totalturn/n));
   printf("\n Average waiting time is : %.2f",(float)(totalwaiting/n));
}
void main()
{ int sum,n,i,j,temp,temp1,temp2,processes[10],wait[10],arrival[10],exe[10],turn[10];
  clrscr();

  printf("\n Shortest Job");
  printf("\n ------------");
  printf("\n Enter the number of processes : ");
  scanf("%d",&n);

  printf("\n Enter the process,arrival time and execution time \n");
  for(i=0;i<n;i++)
  {  scanf("%d %d %d",&processes[i],&arrival[i],&exe[i]);
  }

  for(i=0;i<n;i++)
   { for(j=0;j<n-i-1;j++)
     { if(exe[j]>exe[j+1])
	{  temp=exe[j];
	   exe[j]=exe[j+1];
	   exe[j+1]=temp;

	   temp1=arrival[j];
	   arrival[j]=arrival[j+1];
	   arrival[j+1]=temp1;

	   temp2=processes[j];
	   processes[j]=processes[j+1];
	   processes[j+1]=temp2;
	}
     }
   }


   for(i=0;i<n;i++)
   { sum=0;
     for(j=0;j<=i;j++)
      { sum = sum + exe[j];
      }
     turn[i] = sum - arrival[i];
     wait[i] = turn[i] - exe[i];
   }

   print(processes,arrival,exe,turn,wait,n);
   getch();
}