#include<stdio.h>
#include<stdlib.h>

#define Low 0
#define High 199

void scan(){
  int queue[20],visited[20];
  int head, max, qsize, temp,i,j,diff=0; 


  printf("\nInput no of disk locations : ");
  scanf("%d", &qsize);

  printf("\nEnter head position : ");
  scanf("%d", &head);

  printf("\nEnter elements : ");
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

int fcfs()
{
	int head,seek=0,size,q[20],i,j,diff;
	float avg;
	printf("\nEnter size of queue : ");
	scanf("%d",&size);
	printf("\nEnter elements : ");
	for(i=1;i<=size;i++)
	{
		scanf("%d",&q[i]);
	}
	printf("\nEnter head position : ");
	scanf("%d",&head);
	q[0]=head;
	for(j=0;j<size;j++)
	{
		diff=abs(q[j]-q[j+1]);
		seek+=diff;
		printf("\nHead moved from %d to %d with seek %d",q[j],q[j+1],diff);
	}
	printf("\nTotal seek time is %d",seek);
	avg = seek/(float)size;
	printf("\nAverage seek time is %f",avg);
	return 0;
}

int sstf()
{
	int cp,seek=0,n,req[20],i,j=0,k,index[20],min,mini,cp1,a[20];
	 
	printf("\nEnter number of requests : ");
	scanf("%d",&n);
	printf("\nEnter elements : ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&req[i]);
	}
	printf("\nEnter current position : ");
	scanf("%d",&cp);
	cp1=cp;
	for(k=0;k<n;k++)
	{
		for(i=0;i<n;i++)
		{
			index[i]=abs(cp-req[i]);
		}
		
		//find nearest
		min=index[0];
		mini=0;
		for(i=1;i<n;i++)
		{
			if(min>index[i])
			{
				min=index[i];
				mini=i;
			}
		}
		a[j]=req[mini];
		j++;
		cp=req[mini];
		req[mini]=999;//change
	}
	printf("\nResulting sequence is ");
	printf("\n%d ",cp1);
	seek=seek+abs(cp1-a[0]);
	printf("-->%d",a[0]);
	for(i=1;i<n;i++)
	{
		seek=seek+abs(a[i]-a[i-1]);
		printf("-->%d",a[i]);
	}
	printf("\nTotal seek time is %d",seek);
	printf("\nAverage seek time is %f",seek/(float)n);
	return 0;
}

void main()
{
	int ch;
	while(1)
	{
		printf("\n1.FCFS \t2.SSTF \t3.FSCAN \t4.Exit \nEnter choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: fcfs();
					break;
			case 2:sstf();
					break;		
					
			case 3: scan();
					break;
		}
	}
}
