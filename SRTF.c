#include<stdio.h>
#include<stdlib.h>

void sort(int m,int x[]);
int check(int *flag,int n);
int val(int beg,int end,int *btc,int *flag,int *at,int tt);

int main()
{
	int n;
	printf("Enter the number of processes: ");
	scanf("%d",&n);
	int at[n],sort_at[n],bt[n],btc[n],ct[n],tat[n],wt[n],i,j=0,tt,flag[n];
	float avg_tat=0,avg_wt=0;
	for(i=0;i<n;i++)
    {
		ct[i]=0;
		tat[i]=0;
		wt[i]=0;
		flag[i]=0;
	}
	for(i=0;i<n;i++)
	{
        printf("\nFor process %d:-",(i+1));
		printf("\nEnter AT: ");
		scanf("%d",&at[i]);
		sort_at[i]=at[i];
		printf("Enter BT: ");
		scanf("%d",&bt[i]);
		btc[i]=bt[i];
	}
	sort(n,sort_at);
	tt=sort_at[0];
	printf("\nGantt Chart:\n");
	while(243)
	{
        i=val(0,n-1,btc,flag,at,tt);
        tt++;
        printf("p%d ",(i+1));
        if(btc[i]==1)
        {
        flag[i]=1;
        ct[i]=tt;
        tat[i]=ct[i]-at[i];
        wt[i]=tat[i]-bt[i];
        j++;
        if(sort_at[j]>tt)
        {
            tt=sort_at[j];
        }
        else
        {
            tt=tt;
        }
        }
        btc[i]--;
        if(check(flag,n))
        {
            break;
        }
	}
	printf("\n\nPNo\tAT\tBT\tCT\tTAT\tWT");
	for(i=0;i<n;i++)
	{
		avg_tat+=(float)tat[i];
		avg_wt+=(float)wt[i];
		printf("\n%d\t%d\t%d\t%d\t%d\t%d",i+1,at[i],bt[i],ct[i],tat[i],wt[i]);
	}
	avg_tat=avg_tat/(float)n;
	avg_wt/=(float)n;
	printf("\n\nAverage TAT: %f\nAverage WT: %f\nThroughput: %f\n",avg_tat,avg_wt,((float)n)/tt);
}

void sort(int m,int x[])
{
	int i,j,t;
    for(i=1;i<=m-1;i++)
    {
        for(j=1;j<=m-i;j++)
        {
            if(x[j-1]>=x[j])
            {
                t=x[j-1];
                x[j-1]=x[j];
                x[j]=t;
            }
        }
    }
}

int check(int *flag,int n)
{
	int i,temp=1;
	for(i=0;i<n;i++)
    {
        if(flag[i]==0)
        {
            temp=0;
            break;
        }
	}
	return temp;
}

int val(int beg,int end,int *btc,int *flag,int *at,int tt)
{
	int min=2147483647,i=beg,index;
	for(i=beg;i<(end+1);i++)
    {
		if((btc[i]<min)&&(flag[i]==0)&&(tt>=at[i]))
		{
			min=btc[i];
			index=i;
        }
	}
	return index;
}
