#include<stdio.h>
#include<limits.h>
#include<string.h>
#include<stdlib.h>

int Queue[500],front=-1,rear=0;

void insertBack(int i);
int min(int a,int b);

int main()
{
    memset(Queue,-1,sizeof(Queue));
    int n,totalBT=0,minATi=0,timeQ=0;
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    int AT[n],BT[n],CT[n],TAT[n],WT[n],ABT[n];
    memset(CT,0,sizeof(CT));
    for(int i=0;i<n;i++)
    {
        printf("\nFor process %d:-",i+1);
        printf("\nEnter AT: ");
        scanf("%d",&AT[i]);
        printf("Enter BT: ");
        scanf("%d",&BT[i]);
        ABT[i]=BT[i];
        totalBT+=BT[i];
        if(AT[i]<AT[minATi])
        {
            minATi=i;
        }
    }
    printf("\nEnter TQ: ");
    scanf("%d",&timeQ);
    insertBack(minATi);
    int lastTime=AT[minATi];
    while(totalBT)
    {
        if(Queue[front]==-1)
        {
            int MIN=INT_MAX,index;
            for(int i=0;i<n;i++)
            {
                if(AT[i]>lastTime)
                {
                    if(MIN>AT[i])
                    {
                        MIN=AT[i];
                        index=i;
                    }
                }
            }
            lastTime = MIN;
            insertBack(index);
        }
        int minTime=min(timeQ,BT[Queue[front]]);
        CT[Queue[front]]=(lastTime+minTime);
        BT[Queue[front]]-=minTime;
        totalBT-=minTime;
        for(int i=lastTime+1;i<=lastTime+minTime;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(AT[j]==i)
                {
                    insertBack(j);
                }
            }
        }
        if(BT[Queue[front]]!=0)
        {
            insertBack(Queue[front]);
        }
        ++front;
        lastTime+=minTime;
    }
    float averageTAT=0;
	for(int i=0;i<n;i++)
	{
		TAT[i]=CT[i]-AT[i];
		averageTAT+=(float)TAT[i];
	}
	averageTAT/=(float)n;
    float averageWT=0;
	for(int i=0;i<n;i++)
    {
		WT[i]=TAT[i]-ABT[i];
        averageWT+=(float)WT[i];
	}
	averageWT/=(float)n;
    printf("\nGantt Chart:\n");
    for(int i=0;i<rear;i++)
    {
        printf("p%d ",Queue[i]+1);
    }
    printf("\n\nPNo\tAT\tBT\tCT\tTAT\tWT");
    for(int i=0;i<n;i++)
    {
        printf("\n%d\t%d\t%d\t%d\t%d\t%d",i+1,AT[i],ABT[i],CT[i],TAT[i],WT[i]);
    }
    printf("\n\nAverage TAT: %f",averageTAT);
    printf("\nAverage WT: %f",averageWT);
    printf("\nThroughput: %f\n",(float)n/CT[n-1]);
    return 0;
}

int min(int a,int b)
{
    if(a<b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

void insertBack(int i)
{
    if(rear==500)
    {
        printf("Queue is full!!\n");
        exit(0);
    }
    Queue[rear++]=i;
    if(front==-1)
    {
        ++front;
    }
}
