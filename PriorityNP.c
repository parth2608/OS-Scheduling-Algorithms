#include<stdio.h>
#include<stdlib.h>

void sort(int m,int x[]);
int check(int *flag,int n);
int val(int beg,int end,int *bt,int *flag,int *at,int *priority,int tt);

int main()
{
	int n;
	printf("Enter the number of processes:");
	scanf("%d",&n);
	int at[n],bt[n],sort_at[n],btc[n],ct[n],tat[n],wt[n],j=0,i,tt,flag[n],priority[n];
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
		printf("\nEnter priority: ");
		scanf("%d",&priority[i]);
		printf("Enter AT: ");
		scanf("%d",&at[i]);
		sort_at[i]=at[i];
		printf("Enter BT: ");
		scanf("%d",&bt[i]);
	}
	sort(n,sort_at);
	tt=sort_at[0];
	while(243)
	{
		if((sort_at[j])>tt)
		{
			tt=sort_at[j];
		}
		else
		{
			tt=tt;
		}
		i=val(0,n-1,bt,flag,at,priority,tt);
		flag[i]=1;
		tt+=bt[i];
		ct[i]=tt;
		tat[i]=ct[i]-at[i];
		wt[i]=tat[i]-bt[i];
		if(check(flag,n))
		{
			break;
		}
		j++;
	}
	printf("\n\nPNo\tPriority\tAT\tBT\tCT\tTAT\tWT");
	for(i=0;i<n;i++)
	{
		avg_tat+=(float)tat[i];
		avg_wt+=(float)wt[i];
		printf("\n%d\t%d\t\t%d\t%d\t%d\t%d\t%d",i+1,priority[i],at[i],bt[i],ct[i],tat[i],wt[i]);
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

int val(int beg,int end,int *bt,int *flag,int *at,int *priority,int tt)
{
    int min=0,i=beg,index=-1;
	for(i=beg;i<(end+1);i++)
	{
		if(index!=-1)
		{
            if((priority[i]==min)&&(tt>=at[i])&&(flag[i]==0)&&(bt[i]<bt[index]))
			{
				min=priority[i];
				index=i;
			}
		}
		if((priority[i]>min)&&(tt>=at[i])&&(flag[i]==0))
		{
			min=priority[i];
			index=i;
		}
	}
	return index;
}
