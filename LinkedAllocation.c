#include<stdio.h>
struct file
{
	char fname[10];
	int start,size,block[10];
}f[10];
void main()
{
	int i,j,k,m,n,flag;
	printf("\nEnter num of files : ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("\nEnter filename : ");
		x : scanf("%s",&f[i].fname);
		
		for(j=0;j<n;j++)
		{
			if(!(strcmp(f[i].fname,f[j].fname)) && i!=j)	
			{
				printf("\nInvalid filename! Enter new name : ");
				goto x;
			}
		}
		
		printf("\nEnter number of blocks : ");
		scanf("%d",&f[i].size);
		printf("\nEnter blocks : ");
		for(j=0;j<f[i].size;j++)
		{
			y :	scanf("%d",&f[i].block[j]);
			for(k=0;k<i;k++)
			{
				for(m=0;m<f[k].size;m++)
				{
					if((f[i].block[j]==f[k].block[m]) && (k!=i || m!=j))
					{
						printf("\nBlock is allocated choose diferent block : ");
						goto y;	
					}
				}
			}
		}	
		f[i].start=f[i].block[0];
	}
	
	printf("\n\nFile \t Start \tSize \tBlocks\n");
	for(i=0;i<n;i++)
	{
		printf("%s\t %d \t %d \t%d",f[i].fname,f[i].start,f[i].size,f[i].start);
		for(j=1;j<f[i].size;j++)
		{
			printf("-->%d",f[i].block[j]);
		}
		printf("\n");
	}
}
