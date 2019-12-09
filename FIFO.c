#include<stdio.h>

void main()
{
    int i=0,j=0,p=0,f=0,k,available,pgf=0,pgh=0;
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
        available=0;
        for(k=0;k<f;k++)
        {
            if(frame[k]==pages[i])
            {
                available=1;
                pgh++;
            }
        }
        if(available==0)
        {
            frame[j]=pages[i];
            j=(j+1)%f;
            pgf++;
            for(k=0;k<f;k++)
            {
                if(frame[k]==-1)
                {
                    printf("%d\t",frame[k]);
                }
                else
                {
                    printf(" %d\t",frame[k]);
                }
            }
            printf("\n");
        }
    }
    printf("\nPage Fault: %d",pgf);
    printf("\nFault ratio: %f",((float)pgf/(float)p)*100);
    printf("\n\nPage Hit: %d",pgh);
    printf("\nHit ratio: %f",((float)pgh/(float)p)*100);
}
