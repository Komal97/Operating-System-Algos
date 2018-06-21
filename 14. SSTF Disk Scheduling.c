#include<stdio.h>
struct head
{ int num;
  int flag;
};
 
int main()
{ struct head h[33];
  int array_1[33], array_2[33];
  int count = 0, j, x, limit, minimum, location, disk_head, sum = 0;
  printf("\n DISK SCHEDULING ALGORITHM - SHORTEST SEEK TIME FIRST ");
  printf("\n ------------------------------------------ ");
  printf("\n Enter total number of locations : ");
  scanf("%d", &limit);
  printf("\n Enter position of disk head : ");
  scanf("%d", &disk_head);
  printf("\n Enter elements of disk head queue : ");
  while(count < limit)
  { scanf("%d", &h[count].num);   
    h[count].flag = 0;
    count++;
  }
  for(count = 0; count < limit; count++)
   { x = 0; 
     minimum = 0;
     location = 0;
     for(j = 0; j < limit; j++)
      { if(h[j].flag == 0)
        { if(x == 0)
          { array_1[j] = disk_head - h[j].num;
            if(array_1[j] < 0)
             {  array_1[j] = h[j].num - disk_head;
             }
            minimum = array_1[j];
            location = j;
            x++; 
          }
          else 
		   { array_1[j] = disk_head - h[j].num;
             if(array_1[j] < 0)
                {  array_1[j] = h[j].num - disk_head;
                }
           }
            if(minimum > array_1[j])
             { minimum = array_1[j]; 
               location = j;
             }
        }
      }
     h[location].flag = 1;
     array_2[count] = h[location].num - disk_head;
     if(array_2[count] < 0)
      { array_2[count] = disk_head - h[location].num;
      }
     disk_head = h[location].num;
      }
     count = 0;
     while(count < limit)
      { sum = sum + array_2[count];      
        count++;
      }
     printf("\n Total movements of the cylinders :%d", sum);
     return 0;
}

