#include<stdio.h>

int search(int f_size,int *frame,int num)
{
	int flag =0,i,pos;
	for(i=0;i<f_size;i++)
	{
		if(num==frame[i])
		{
			flag=1;
			pos=i;
			break;
		}
	}
		if(flag==0)
		{
			return -1;
		}
		 return pos;
}

int minimum(int fsize,int *count){
	int min,i,pos;
	min=count[0];
	
	for(i=1;i<fsize;i++){
		if(count[i]<min){
			min=count[i];
			pos=i;
		}
	}
	return pos;
}
int main()
{
	printf("\n Page Replacement Algorithm - Least Recently Used");
	printf("\n ------------------------------------------------");
	
	int p_size,i,k,j=0,minpos,f_size,page[100],frame[10],pagefault=0,result,count[10];
	
	printf("\n Enter the no. of pages: ");
	scanf("%d",&p_size);
	printf("\n Enter %d pages: ",p_size);
	for(i=0;i<p_size;i++)
	{
		scanf("%d",&page[i]);
	}
	printf("\n Enter the frame size: ");
	scanf("%d",&f_size);
	
	for(k=0;k<f_size;k++)
	 {
      	count[k]=0;
      	frame[k]=-1;
	}
			    
	for(i=0;i<p_size;i++)
	{
	    result = search(f_size,frame,page[i]);
	    if(result==-1)
		 {
	    	if(j<f_size)
		     { frame[j]=page[i];
               pagefault++;
	           count[j]=i+1;
			   j++;
            }
            else  
			{ minpos=minimum(f_size,count);
           	  frame[minpos]=page[i];
      	      count[minpos]=i+1;	    
			  pagefault++;    	
		    }
         }
         else
         {
         	count[result]=i+1;	
		 }
     }
		
	printf("\n Page Fault: %d",pagefault);
	return 0;
}
