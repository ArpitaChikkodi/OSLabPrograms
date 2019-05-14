#include<stdio.h>

void main()
{
	int n,i;
	printf("\nEnter number of files to create : ");
	scanf("%d",&n);
	FILE *files[n],*fp;
	char fname[n][20],fn[20];
	long int size=0;
	for(i=0;i<n;i++)
	{
		printf("\nEnter filename : ");
		scanf("%s",&fname[i]);
		files[i]=fopen(fname[i],"w");
		fclose(files[i]);
	}
	printf("\nFiles created succesfully!");
	//to find size of a file
	printf("\nEnter filename to find size : "); 
		scanf("%s",&fn);
	fp=fopen(fn,"r");
	fseek(fp,0,SEEK_END);
	
	size=ftell(fp);
	if(size!=-1)
	printf("\nSize of the file %s is %ld",fn,size);
	else
		printf("size is -1");
}
	

