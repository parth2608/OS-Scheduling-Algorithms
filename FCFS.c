#include<stdio.h>
#include<limits.h>
#include<string.h>

int main()
{
    int n;
    printf("Enter the number of processes: ");
	scanf("%d",&n);
	int AT[n],BT[n],CT[n],TAT[n],WT[n],flag[n],ES[n];
	for(int i=0;i<n;i++)
    {
		printf("\nFor process %d:-",(i+1));
		printf("\nEnter AT: ");
		scanf("%d",&AT[i]);
		printf("Enter BT: ");
		scanf("%d",&BT[i]);
	}
	memset(flag,0,sizeof(flag));
	for(int i=0;i<n;i++)
    {
		int min=INT_MAX;
		int minI;
		for(int j=0;j<n;j++)
		{
			if(flag[j]==0&&AT[j]<min)
			{
				min=AT[j];
				minI=j;
			}
		}
		ES[i]=minI;
		flag[minI]=1;
	}
	printf("\nGantt Chart:\n");
	for(int i=0;i<n;i++)
	{
		printf("   p%d",(ES[i]+1));
	}
	int last=0;
	for(int i=0;i<n;i++)
    {
		if(last>=AT[ES[i]])
		{
			CT[ES[i]]=BT[ES[i]]+last;
		}
        else
        {
			CT[ES[i]]=BT[ES[i]]+AT[ES[i]];
		}
		last=CT[ES[i]];
	}
	float averageTAT=0;
	for(int i=0;i<n;i++)
    {
		TAT[i]=CT[i]-AT[i];
		averageTAT+=(float)TAT[i];
	}
	averageTAT/=(float)n;
	for(int i=0;i<n;i++)
    {
		WT[i]=TAT[i]-BT[i];
	}
	float averageWT = 0;
	for(int i=0;i<n;i++)
    {
		averageWT+=(float)WT[i];
	}
	averageWT/=(float)n;
	printf("\n\nPNo\tAT\tBT\tCT\tTAT\tWT");
	for(int i=0;i<n;i++)
	{
		printf("\n%d\t%d\t%d\t%d\t%d\t%d",i+1,AT[i],BT[i],CT[i],TAT[i],WT[i]);
	}
	printf("\n\nAverage TAT: %f\nAverage WT: %f\nThroughput: %f\n",averageTAT,averageWT,((float)n)/CT[n-1]);
}
