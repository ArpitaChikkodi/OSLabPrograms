#include<stdio.h>
#include<stdlib.h>
int i,j,p[10]={1,2,3,4,5,6,7,8,9,10};
int sum=0,at[10],rt[10],wt[10],bt[10],tt[10],ct=0;
int npro;
float tsum=0,wsum=0,tavg=0,wavg=0;
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
		rt[i]=bt[i];
	}
}

void fcfs()
{
	wt[0]=0;
	sum=at[0];
	for(i=1;i<npro;i++)
	{
		sum=sum+bt[i-1];
		wt[i]=sum-at[i];
		wsum=wsum+wt[i];
	}
	
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

int robin()
{
	int tq,time,remain,flag=0;
	printf("\nEnter time quantun : ");
	scanf("%d",&tq);
	remain=npro;
	printf("\n\nPID\tTurnAroundTime \t Waiting time\n\n");
	for(time=0,i=0;remain!=0;)
	{
		if(rt[i]<=tq && rt[i]>0)
		{
			time+=rt[i];
			rt[i]=0;
			flag=1;
		}
		else if(rt[i]>0)
		{
			rt[i]-=tq;
			time+=tq;
		}
		if(rt[i]==0 && flag==1)
		{
			remain--;
			printf("\np[%d]\t\t %d \t\t %d",i+1,time-at[i],time-at[i]-bt[i]);
			wt[i]=time-at[i]-bt[i];
			tt[i]=time-at[i];
			wsum+=wt[i];
			tsum+=tt[i];
			flag=0;
		}
		if(i==npro-1)
			i=0;
		else if(at[i+1]<=time)
			i++;
		else
			i=0;
	}
	printf("\nAverage waiting time is %f",wsum/npro);
	printf("\nAverage turn around time is %f",tsum/npro);
	return 0;
}

void main()
{
	int ch;
	while(1)
	{
		printf("\n1.FCFS \t2.RoundRobin\n");
		printf("\nEnter choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: take();
					fcfs();
					break;
					
			case 2: take();
					robin();
					break;
		}
	}
}
