#include<stdio.h>
void main()
{
	int ms,os,bs, nob, ef,n, mp[10],tif=0;
	int i,p=0;

	printf("\nEnter the total memory available :");
	scanf("%d",&ms);
	printf("\nEnter the memory allotted for os :");
	scanf("%d", &os);
	ms-=os;
	printf("\nEnter the block size :");
	scanf("%d", &bs);
	nob=ms/bs;
	ef=ms - nob*bs;
	printf("\nEnter the number of processes :");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter memory required for process %d :",i+1);
		scanf("%d",&mp[i]);
	}
	printf("\nNo. of Blocks available in memory --%d",nob);
	printf("\n\nProcess\tMemory required\t Allocated\tInternal Fragmentation");
	for(i=0;i<n && p<nob;i++)
	{
		printf("\n %d\t\t%d",i+1,mp[i]);
		if(mp[i] > bs)
			printf("\t\tNo\t\t---");
		else
		{
			printf("\t\tYes\t%d",bs-mp[i]);
			tif = tif + bs-mp[i];
			p++;
		}
	}
	if(i<n)
	printf("\nMemory is Full, Remaining Processes cannot be accomodated");
	printf("\n\nTotal Internal Fragmentation is %d",tif);
	printf("\nTotal External Fragmentation is %d",ef);
	
}
