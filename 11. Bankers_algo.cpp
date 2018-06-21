#include<stdio.h>
int main()
{  int need[10][10],work[10],sum=0;
   printf("\n Banker's Algorithm");
   printf("\n ------------------");
   int p_size,inst;
   int max_instances[10],allocation[10][10],max[10][10];
   char finish[10];
	
   printf("\n Enter number of processes : ");
   scanf("%d",&p_size);	
   printf(" Enter number of resources : ");
   scanf("%d",&inst);

   printf(" Enter max instances for each resource : ");
   for(int i=0;i<inst;i++){
      scanf("%d",&max_instances[i]);
   }
   
   printf("\n Enter allocation matrix ");
   printf("\n ----------------------- \n");
   for(int i=0;i<p_size;i++){
	 for(int j=0;j<inst;j++){
	   scanf("%d",&allocation[i][j]);
	 }
   }

   printf("\n Enter maximum matrix ");
   printf("\n --------------------- \n");
   for(int i=0;i<p_size;i++){
	 for(int j=0;j<inst;j++){
		scanf("%d",&max[i][j]);
	  }
   }

   for(int i=0;i<p_size;i++){
     finish[i]='f';
   }	
	
   for(int i=0;i<p_size;i++){
	 for(int j=0;j<inst;j++){
		need[i][j]=max[i][j]-allocation[i][j];
	  }
   }

   for(int i=0;i<inst;i++){
	  sum=0;	
	  for(int j=0;j<p_size;j++){
		sum=sum+allocation[j][i];
	  }
	  work[i]=max_instances[i]-sum;;
    }    
	
	printf("\n Safe sequence is : ");
	int size=p_size;
	while(size!=0){
	  int j,k;
	   for(int i=0;i<p_size;i++){
	      if(finish[i]=='f'){
	   	    for(j=0,k=0;j<inst;j++,k++){
		     if(need[i][j]>work[k]){
			  break;
	         }
		    }
		    if(j==inst){
			 printf("P%d ",i);
			 for(int m=0,n=0;m<inst;m++,n++){
			   finish[i]='t';
			   work[n]=work[n]+allocation[i][m];
			 }
	        }
	      }
	   }
	  size--;
	}
	return 0;
}

