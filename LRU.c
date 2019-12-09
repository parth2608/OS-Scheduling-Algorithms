#include<stdio.h>

int replace(int time[],int n);

void main()
{
    int i=0,j=0,f=0,p=0,counter=0,time[10],flag1,flag2,pos,pgf=0,pgh=0;
	printf("Enter number of pages: ");
	scanf("%d",&p);
    int pages[p];
	printf("Enter number of frames: ");
	scanf("%d",&f);
    int frame[f];
	printf("Enter reference string:\n");
    for(i=0;i<p;i++)
    {
    	scanf("%d",&pages[i]);
    }
	for(i=0;i<f;i++)
    {
    	frame[i]=-1;
    }
    printf("\nReference String:\n");
    for(i=0;i<p;i++)
    {
        printf("%d ",pages[i]);
    }
    printf("\n\nFrames:\n\n");
    for(i=0;i<p;i++)
    {
    	flag1=flag2=0;
    	for(j=0;j<f;j++)
    	{
    		if(frame[j]==pages[i])
    		{
	    		counter++;
	    		time[j]=counter;
	   			flag1=flag2=1;
	   			pgh++;
	   			break;
   			}
    	}
    	if(flag1==0)
    	{
			for(j=0;j<f;j++)
			{
	    		if(frame[j]==-1)
	    		{
	    			counter++;
	    			pgf++;
	    			frame[j]=pages[i];
	    			time[j]=counter;
	    			flag2=1;
	    			break;
	    		}
    		}
    	}
    	if(flag2==0)
    	{
    		pos=replace(time,f);
    		counter++;
    		pgf++;
    		frame[pos]=pages[i];
    		time[pos]=counter;
    	}
    	printf("\n");
    	for(j=0;j<f;j++)
    	{
    		if(frame[j]==-1)
            {
                printf("%d\t",frame[j]);
            }
            else
            {
                printf(" %d\t",frame[j]);
            }
    	}
	}
	printf("\n\nPage Fault: %d",pgf);
    printf("\nFault ratio: %f",((float)pgf/(float)p)*100);
    printf("\n\nPage Hit: %d",pgh);
    printf("\nHit ratio: %f",((float)pgh/(float)p)*100);
}

int replace(int time[],int n)
{
	int i,minimum=time[0],pos=0;
	for(i=1;i<n;i++)
    {
		if(time[i]<minimum)
		{
			minimum=time[i];
			pos=i;
		}
	}
	return pos;
}
