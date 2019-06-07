#include<stdio.h>
void main(int argc,char *argv[])
{
	FILE *f1,*f2;
	char ch;
	if(argc!=3)
	{
		printf("\nInsufficient arguments!");
		return;
	}
	f1=fopen(argv[1],"r");
	f2=fopen(argv[2],"w");
	if((f1==NULL) || (f2==NULL))
	{
		printf("\nFile does not exists!");
		return;
	}
	while((ch=fgetc(f1)) != EOF)
	{
		fputc(ch,f2);
	}
	fclose(f1);
	fclose(f2);
	printf("\nFile copied!");
	return;
}
