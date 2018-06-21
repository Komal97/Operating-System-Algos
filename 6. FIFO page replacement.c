#include<stdio.h>

int search(int fsize,int *frames,int num)
{ int i, flag=0;
	
	for(i=0;i<fsize;i++)
	 { if(frames[i]==num){
		 flag=1;
		 break;
	   }
	 }
	
	if(flag==1){
	  return 1;
	}
	
	else{
	  return 0;
	}
}

int main()
{ int fsize,i,j,pagefault=0,frames[10],searchresult,k=0;
  int page[]={4,3,2,1,4,3,5,4,3,2,1,5};
  int psize=sizeof(page)/sizeof(page[0]);
  printf("\n Page Replacement Algorithm - First In First Out");
  printf("\n -----------------------------------------------");
	
  printf("\n Enter the frame size : ");
  scanf("%d",&fsize);
  j=0;
	
	for(i=0;i<psize;i++)
	{
		frames[i]=-1;
	}
	
  for(i=0;i<psize;i++)
	{ j=j%fsize;
      searchresult=search(fsize,frames,page[i]);
		if(searchresult==0){
		  frames[j]=page[i];
		  pagefault++;
		  j++;
      }
    }
    
  printf("\n Total number of Page Faults : %d\n ",pagefault);
  return 0;
}
