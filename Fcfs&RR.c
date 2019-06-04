#include<stdio.h>
#include<stdlib.h>

int num,bt[20],at[20],wt[20],tat[20],rt[10];
int i,temp=0,ct=0;
float awt,atat;
float sumWT,sumTAT;

void takeInput(){
    printf("\nEnter the number of process : ");
    scanf("%d",&num);

    for(i=0;i<num;i++){
        printf("\nEnter execution time for process %d : ",i+1);
        scanf("%d",&bt[i]);
        printf("\nEnter arrival time for process %d : ",i+1);
        scanf("%d",&at[i]);
        rt[i]=bt[i]; 
    }
}
int roundRobin(){
    int count,j,time,remain,flag=0,tq; 
    remain=num;  

    printf("\nEnter Time Quantum:\t"); 
  scanf("%d",&tq); 
  printf("\n\nProcess\t|Turnaround Time|Waiting Time\n\n"); 
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
      printf("P[%d]\t|\t%d\t|\t%d\n",i+1,time-at[i],time-at[i]-bt[i]); 
      wt[i]+=time-at[i]-bt[i]; 
      tat[i]+=time-at[i]; 
      flag=0; 
    }
    if(i==num-1) 
      i=0; 
    else if(at[i+1]<=time) 
      i++; 
    else 
      i=0; 
  } 
  printf("\nAverage Waiting Time= %1.3f",wt[i]*1.0/num); 
  printf("\nAvg Turnaround Time = %1.3f",tat[i]*1.0/num); 
  return 0; 
}

int fcfsMethod(){
    wt[0]=0;  // take var temp and assign the first index value of arrival time,this helps to put process into ready queue
    temp = at[0];  // this code of section also remove the fcfs overhead or fcfs convoy effect
    for(i=1;i<num;i++){
        temp=temp+bt[i-1];
        wt[i]=temp-at[i];
        sumWT=sumWT+wt[i];
    }
    printf("\nPid \t\t AT \t\t BT \t\t CT \t\t WT \t\t TAT");
    for(i=0;i<num;i++){
        ct += bt[i];
        tat[i]=ct-at[i];
        sumTAT += tat[i];
        printf("\n%d \t\t %d \t\t %d \t\t %d \t\t %d \t\t %d\n",i+1,at[i],bt[i],ct,wt[i],tat[i]);
    }
    awt = sumWT/num;
    atat = sumTAT/num;
    printf("\nAverage turn around time : %f",atat);
    printf("\nAverage waiting time : %f",awt);
    printf("\n");
}
void main(){
    printf("\nRound Robin & FCFS scheduling algorithm \n");
    int ch;
    while(1){
        printf("\n1.Round Robin \n2.FCFS\n3.Exit\n");
        printf("Enter choice : ");
        scanf("%d",&ch);
        switch (ch)
        {
            case 1:
                 takeInput();
                 roundRobin();
                  break;
            case 2:
                 takeInput();
                 fcfsMethod();
                break;
                
            case 3: exit(0);
            default: printf("\nInvalid choice!");
        }
    }
}
