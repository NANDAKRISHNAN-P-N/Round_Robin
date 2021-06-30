#include<stdio.h>
struct rrs{
  int pid;
  int burst_time;
  int wait_time;
  int turn_time;
  int rem_bt;
}process[100];
int n,tq,time=0;
int timear[100],ctl=1;
void main()
{
   printf("Enter the number of processes\n");
   scanf("%d",&n);
   printf("Enter the burst time for processes in order:\n"); 
   for(int i=1;i<=n;i++)
   {
       process[i].pid=i;
       printf("P[%d] :",i);
       scanf("%d",&process[i].burst_time);
       process[i].rem_bt=process[i].burst_time;
       process[i].wait_time=process[i].turn_time=0;
    }
    printf("Enter the time Quantun");
    scanf("%d",&tq);
    int k=n;
    printf("\n-------------------------------------------------------------------------------------------------------------------- ");
   printf("\n|");
    while(k>0)
    {
      for(int i=1;i<=n;i++)
      {
        if(process[i].rem_bt==0)
            continue;
        if(process[i].rem_bt>tq)
        {
          time=time+tq;
          timear[ctl]=time;   ctl++;
          process[i].rem_bt=process[i].rem_bt - tq;
          for(int j=1;j<=tq/2;j++)
               printf("  ");
          printf("P%d",process[i].pid);
          for(int j=(tq/2)+1;j<tq;j++)
             printf("  ");
          printf("|");
        }
        else
        {
          time=time+process[i].rem_bt;
          timear[ctl]=time; ctl++;
          process[i].turn_time=time;
          process[i].wait_time=process[i].turn_time - process[i].burst_time;
          for(int j=1;j<=tq/2;j++)
               printf("  ");
          printf("P%d",process[i].pid);
          for(int j=(tq/2)+1;j<tq;j++)
             printf("  ");
          printf("|");
          process[i].rem_bt=0;
          k--;
        } 
      }
   }
   printf("\n0");
   for(int i=1;i<ctl;i++)
   {
       for(int j=1;j<=tq;j++)
          printf("--");
       if(timear[i]>9)
          printf("\b");
       printf("%d",timear[i]);
   }
   int total_wait=0,total_turn=0;
   for(int i=1;i<=n;i++)
   {
       total_wait+=process[i].wait_time;
       total_turn+=process[i].turn_time;
   }
   float avg_wait=(float)total_wait/(float)n;
   float avg_turn=(float)total_turn/(float)n;
       
    printf("\nProcess Executed as:\n");
   for(int i=1;i<=n;i++)
   {
     printf("\nP[%d]:\tBurst Time=%d\tTurn Around Time=%d\tWaitingTime=%d",process[i].pid,process[i].burst_time,process[i].turn_time,process[i].wait_time);
   }
  printf("\nTotal Turn Around Time=%d",total_turn);
  printf("\nTotal Waiting Time=%d",total_wait);
  printf("\nAverage Turn Around Time=%.1f",avg_turn);
  printf("\nAverage Waiting Time=%.1f",avg_wait);
}









































































































   