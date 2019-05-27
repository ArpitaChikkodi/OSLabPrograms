#include <stdio.h>
#include <stdlib.h>

#define Low 0
#define High 199

void main(){
  int queue[20],visited[20];
  int head, max, qsize, temp,i,j,diff=0; 


  printf("\nInput no of disk locations");
  scanf("%d", &qsize);

  printf("\nEnter head position");
  scanf("%d", &head);

  printf("\nEnter elements");
  for(i=0; i<qsize; i++){
    scanf("%d", &queue[i]);
    visited[i]=0;
  }

  //sort the array
  for(i=0; i<qsize;i++)
  {
    for(j=i; j<qsize; j++)
	{
      if(queue[i]>queue[j])
	  {
        temp = queue[i];
        queue[i] = queue[j];
        queue[j] = temp;
      }
    }
  }
  

  max = head;

	printf("\n%d",head);
	for(i=0;i<qsize;i++)
	{
		if(max<queue[i])
			{
				
				temp = abs(max - queue[i]);
				diff+=temp;
				printf("-->%d",queue[i]);
				max=queue[i];
				visited[i]=1;
			}
	}
	
	diff+=abs(High-max);
	max=High;
	
	for(i=qsize-1;i>=0;i--)
	{	
		if(max>queue[i] && !visited[i])
		{
				
			temp = abs(max - queue[i]);
			diff+=temp;
			printf("-->%d",queue[i]);
			max=queue[i];
			visited[i]=1;
		}
	}
	
  printf("\nTotal seek time is %d",diff);
  printf("\nAverage seek time is %1.3f",(diff/(float)qsize));

}
