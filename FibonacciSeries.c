#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/type.h>
#include<sys/wait.h>

int main()
{
    int a=0,b=1,n,i;
    Pid_t pid = fork();
    if(pid==0) //If child process has been created successfully
	{
        printf("\n Child process created sucessfully!\n");
        printf("\nChild will print fibonacci series\n");
        printf("\nEnter number :");
        scanf("%d",&i);
        if(i<=0)
        {
        	printf("\nEnter valid number!");
        	exit(0);
		}
        if(i==2)
        {
        	printf("0,%d",n);
			print("\nChild process ended!");
			exit(0);
		}
			printf("0,%d",n);
        while(i > 2)
		{
            n=a+b;
            printf("%d\n",n);
            a=b;
            b=n;
            i--;
        }
        printf("\nChild process ends!\n");
    }
    else
    {
        printf("\nparent is waiting for a child\n");
        waitpid(pid,NULL,0);
        printf("\nParent ends!\n");
    }
    return 0;
    
}
