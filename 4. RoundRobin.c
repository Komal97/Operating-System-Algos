#include<stdio.h>
int main()
{ int a[15],b[15],w[15],count,n,q,r,order[15],index,i,j,rt[15],time,avgtr[15]N;
  float sum=0,sum1=0;
  printf("\n Round Robin");
  printf("\n ------------");
  printf("\n Enter the number of processes & the quantum : ");
  scanf("%d%d",&n,&q);
  printf("\n Enter the arrival time and the execution time \n\n");
  
  for( N=0;N<n;N++)
  { printf(" P%d  ",N+1);
	scanf(" %d %d",&a[N],&b[N]);
	rt[N]=b[N];
  }
  r=n;
  printf("\n\n Process   Arrival Time   Execution Time   Waiting Time   Turnaround Time\n\n");
  for(i=0,time=0,count=0;r!=0;i++)
   { i=i%n;
	 if(count==n)
	  { //idle
		time++;
		count=0;
	  }
	  if(a[i]>time)
	   { count++;
		 continue;
	   }
	   count=0;
	   if(rt[i]<=q&&rt[i]>0)
		{ time+=rt[i];
		  rt[i]=0;
		  r--;
		  w[i]=time-a[i]-b[i];
		  avgtr[i]=w[i]+b[i];
		  printf("  P%d\t\t%d\t\t%d\t\t%d\t\t%d\n",i+1,a[i],b[i],w[i],avgtr[i]);
		}
		else 
		 if(rt[i]>0)
		  { rt[i]-=q;
			time+=q;
		  }
	}
	
	for(i=0;i<n;i++)
    { sum=sum+w[i];
      sum1=sum1+avgtr[i];
    }

    printf("\n\n Average Waiting Time : %0.2f",(float)(sum/n));
    printf("\n Average Turnaround Time : %0.2f",(float)(sum1/n));
    return 0;
}
