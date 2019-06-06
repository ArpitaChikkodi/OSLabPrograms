#include<stdio.h>
#include<stdlib.h>
int i,j,temp,k=1,btime=0,p[10]={1,2,3,4,5,6,7,8,9,10};
int sum=0,at[10],atWithIdle[10],wt[10],bt[10],tt[10],ct=0;
int idletime=0,min,npro;
float tsum=0,wsum=0,tavg=0,wavg=0;

void swap(int *xp,int *yp)
{
	temp=*xp;
	*xp=*yp;
	*yp=temp;
}

void take()
{
	printf("\nEnter number of process(less than 10) : ");
	scanf("%d",&npro);
	for(i=0;i<npro;i++)
	{
		printf("\n\tEnter burst time of %d process : ",i+1);
		scanf("%d",&bt[i]);
		printf("\n\tEnter arrival time of %d process : ",i+1);
		scanf("%d",&at[i]);
		atWithIdle[i]=at[i];
	}
}

void res()
{
	wt[0]=0;
	sum=at[0];
	for(i=1;i<npro;i++)
	{
		sum=sum+bt[i-1];
		wt[i]=sum-at[i];
		wsum=wsum+wt[i];
	}
	ct=at[0];
	printf("\n\n****Result****");
	printf("\nPID \t BT \t AT \t CT \t WT \t TAT");
	for(i=0;i<npro;i++)
	{
		ct=ct+bt[i];
		tt[i]=ct-at[i];
		tsum=tsum+tt[i];
		printf("\np%d \t %d\t %d\t %d\t %d\t %d",p[i],bt[i],at[i],ct,wt[i],tt[i]);
	}
	
	wavg=wsum/npro;
	tavg=tsum/npro;
	printf("\nAverage waiting time is %1.3f",wavg);	
	printf("\nAverage turn around time is %1.3f\n",tavg);
}

int sjf()
{
	printf("\nSJF\n");
	take();
	//sort
	for(i=0;i<npro;i++)
	{
		for(j=0;j<npro;j++)
		{
			if(at[i]<at[j])
			{
				swap(&p[i],&p[j]);
				swap(&at[i],&at[j]);
				swap(&bt[i],&bt[j]);	
			}
		}
	}
	
	btime=at[0];
	for(j=0;j<npro;j++)
	{
		btime=btime+bt[j];
		min=bt[k];
		for(i=k;i<npro;i++)
		{
			if(btime>=at[i] && bt[i]<min)
			{
				swap(&p[i],&p[k]);
				swap(&at[i],&at[k]);
				swap(&bt[i],&bt[k]);
			}
		}
		k++;
	}
	res();
	return 0;
}
 
int futuremethod()
{
	printf("\nFuture Knowledge\n");
	take();
	printf("\nEnter idle time : ");
	scanf("%d",&idletime);
	//sort
	for(i=0;i<npro;i++)
	{
		if(at[i]<idletime)
		{
			atWithIdle[i]=idletime;
		}
	}
	//sort 
	for(i=0;i<npro;i++)
	{
		for(j=0;j<npro;j++)
		{
			if(atWithIdle[i]<atWithIdle[j])
			{
				swap(&p[i],&p[j]);
				swap(&at[i],&at[j]);
				swap(&bt[i],&bt[j]);
				swap(&atWithIdle[i],&atWithIdle[j]);	
			}
			else if((atWithIdle[i]==atWithIdle[j]) && (bt[i]<bt[j]))
			{
				swap(&p[i],&p[j]);
				swap(&at[i],&at[j]);
				swap(&bt[i],&bt[j]);
				swap(&atWithIdle[i],&atWithIdle[j]);
			}
		}
	}
	
	btime=at[0];
	for(j=0;j<npro;j++)
	{
		btime=btime+bt[j];
		min=bt[k];
		for(i=k;i<npro;i++)
		{
			if(btime>=atWithIdle[i] && bt[i]<min)
			{
				swap(&p[i],&p[k]);
				swap(&at[i],&at[k]);
				swap(&bt[i],&bt[k]);
				swap(&atWithIdle[i],&atWithIdle[k]);
			}
		}
		k++;
	}
	res();
	return 0;
}
 
void main()
{
	int ch;
	while(1)
	{
		printf("\n1.SJF \t2.FutureKnowledge\n");
		printf("\nEnter choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: sjf();
					break;
					
			case 2: futuremethod();
					break;
		}
	}
}
