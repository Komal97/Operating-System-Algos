#include<stdio.h>
#include<conio.h>
int main()
{ int p[15],a[15],b[15],w[15],n,i,j,time=0,index,s[15];
  float sum=0;
  
  printf("\n Priority Scheduling");
  printf("\n -------------------");
  printf("\n Enter the number of processes : ");
  scanf("%d",&n);

  printf("\n Enter the arrival,execution time and priority of processes\n");
  for(i=0;i<n;i++)
   { scanf(" %d %d %d",&a[i],&b[i],&p[i]);
     s[i]=0;
   }

  printf("\n Process     Arrival Time     Burst Time    Priority     Waiting Time");
  for(i=0;i<n;i++)
   { index=-1;
     for(j=0;j<n;j++)
      { if(!s[j])
	{ if(a[j]<=time)
	  { if(index==-1)
	    { index=j;
	    }
	    else
	     { if(p[j]<p[index])
	       { index=j;
	       }
	     }
	  }
	}
      }
      if(index==-1)
       { --i;
	 ++time;
       }
       else
	{ w[index]=time-a[index];
	  s[index]=1;
	  time+=b[index];
	  printf("\n P%d\t\t%d\t\t%d\t\t%d\t\t%d",index+1,a[index],b[index],p[index],w[index]);
	}
   }

   for(i=0;i<n;i++)
    { sum=sum+w[i];
    }
   printf("\n\n Average Waiting Time : %0.2f",(float)(sum/n));
 return 0;
}
