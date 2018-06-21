#include<stdio.h>
void calculate(int bs[],int ps[],int pn[], int n,int m )
{ int i,j,temp;
	for(i=0;i<m;i++)
	 { for(j=0;j<n;j++)
	   { if(ps[i]<bs[j])
	      { pn[i]=j+1;
			bs[j]=0;
			temp++;
			break;
		  }
		}
		if(temp==0)
		 { pn[i]=-1;
		 }
	   temp=0;
	}
}

void printTable(int processes[],int ps[],int pn[],int m)
{ int i;
  printf("\n\n Process_no\tProcess_size\tBlock_no\n");
  printf(" ----------\t------------\t--------");
  for(i=0;i<m;i++)
   { printf("\n %d\t\t%d\t\t%d",processes[i],ps[i],pn[i]);
   }
}

int main()
{ int processes[]={1,2,3,4};
  int bs[]={100,500,200,300,600};
  int ps[]={212,417,112,426};
  int pn[5];
  int n=sizeof bs/sizeof(bs[0]);
  int m=sizeof ps/sizeof(ps[0]);
  
  printf("\n First fit Algorithm");
  printf("\n -------------------");
  calculate(bs,ps,pn,n,m);
  printTable(processes,ps,pn,m);
  return 0;
}
