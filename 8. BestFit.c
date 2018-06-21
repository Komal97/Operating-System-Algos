#include<stdio.h>
void calculate(int bs[],int ps[],int pn[], int n,int m )
{ int i,j;
  for(i=0; i<n; i++)
   { int bestIdx = -1;
      for (j=0; j<m; j++)
        { if (bs[j] >= ps[i])
           { if (bestIdx == -1)
                bestIdx = j;
                else if (bs[bestIdx] > bs[j])
                  bestIdx = j;
            }
        }
        if (bestIdx != -1)
        { pn[i] = bestIdx+1;
          bs[bestIdx] -= ps[i];
        }
    }
}
void printTable(int processes[],int ps[],int pn[],int n)
{ int i;
  printf("\n\n Process_no\tProcess_size\tBlock_no");
  printf("\n ----------\t------------\t--------");
  for(i=0;i<n;i++)
   { printf("\n %d\t\t%d\t\t%d",processes[i],ps[i],pn[i]);
   }
}
int main(){
	int processes[]={1,2,3,4};
	int bs[]={100,500,200,300,600};
	int ps[]={212,417,112,426};
	int pn[5]={-1,-1,-1,-1,-1};
	int m=sizeof bs/sizeof bs[0];
	int n=sizeof ps/sizeof ps[0];
	printf("\n Best Fit Algorithm ");
	printf("\n ------------------\n");	
    calculate(bs,ps,pn,n,m);
   	printTable(processes,ps,pn,n);
	return 0;
}
