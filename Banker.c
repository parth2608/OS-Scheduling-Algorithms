#include <stdio.h>

void main()
{
	int i=0,j=0,p=0,r=0,flag_p=0,fl=0;
	printf("Enter the number of processes: ");
	scanf("%d",&p);
	printf("Enter the number of resources: ");
	scanf("%d",&r);
	int allocated[p][r],max[p][r],need[p][r],resources[r],flag[p],available[r];
	printf("Enter the values of allocated matrix:\n");
	for(i=0;i<p;i++)
	{
		for(j=0;j<r;j++)
		{
			scanf("%d",&allocated[i][j]);
		}
	}
	printf("\nEnter the values of maximum matrix:\n");
	for(i=0;i<p;i++)
	{
		for(j=0;j<r;j++)
		{
			scanf("%d",&max[i][j]);
		}
	}
	printf("\nEnter the available resources:\n");
	for(i=0;i<r;i++)
	{
		scanf("%d",&resources[i]);
		available[i]=resources[i];
	}
    for(i=0;i<p;i++)
	{
		for(j=0;j<r;j++)
		{
			available[j]-=allocated[i][j];
			need[i][j]=max[i][j]-allocated[i][j];
		}
		flag[i]=0;
	}
	printf("\nAllocated matrix:\n");
	for(i=0;i<p;i++)
	{
		for(j=0;j<r;j++)
		{
			printf("%d ",allocated[i][j]);
		}
		printf("\n");
	}
	printf("\nMaximum matrix:\n");
	for(i=0;i<p;i++)
	{
		for(j=0;j<r;j++)
		{
			printf("%d ",max[i][j]);
		}
		printf("\n");
	}
	printf("\nAvailable Resources Array:\n");
	for(i=0;i<r;i++)
	{
		printf("%d ",resources[i]);
	}
	printf("\n\nNeed Matrix:\n");
	for(i=0;i<p;i++)
	{
		for(j=0;j<r;j++)
		{
			printf("%d ",need[i][j]);
		}
		printf("\n");
	}
	printf("\nSequence:\n");
	while(243)
    {
		for(i=0;i<p;i++)
		{
            flag_p=1;
			for (j=0;j<r;j++)
			{
				if (need[i][j]>available[j])
				{
					flag_p=0;
					break;
				}
			}
			if(flag_p && (flag[i]!=1))
			{
				flag[i]=1;
				printf("p%d\t",i);
				for(j=0;j<r;j++)
				{
					available[j]+=allocated[i][j];
				}
			}
		}
		fl=1;
        for(i=0;i<p;i++)
        {
            if(flag[i]==0)
            {
                fl=0;
                break;
            }
        }
		if(fl)
        {
			break;
		}
	}
}
