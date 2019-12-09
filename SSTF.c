#include <stdio.h>

int main()
{
    int n,initialPos,totalHeadMovement=0;
    printf("Enter total number of requests: ");
    scanf("%d",&n);
    int requests[n];
    int visited[n];
    int Sequence[n];
    memset(visited,0,sizeof(visited));
    printf("\nEnter the requests:\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&requests[i]);
    }
    printf("\nEnter Initial Head Position: ");
    scanf("%d",&initialPos);
    for(int i=0;i<n;i++)
    {
        int nearestInd=-1,neareast;
        char Ndir;
        for(int j=0;j<n;j++)
        {
            if(!visited[j])
            {
                int dist=abs(initialPos-requests[j]);
                char dir;
                if(initialPos-requests[j]>0)
                {
                    dir='L';
                }
                else
                {
                    dir = 'R';
                }
                if(nearestInd==-1)
                {
                    nearestInd = j;
                    neareast = dist;
                    Ndir = dir;
                }
                else if(dist<neareast)
                {
                    neareast = dist;
                    nearestInd = j;
                    Ndir = dir;
                }
                else if(dist==neareast)
                {
                    int countR=0,countL=0;
                    for(int k=0;k<n;k++)
                    {
                        if(!visited[j])
                        {
                            if(requests[j]<initialPos)
                            {
                                ++countL;
                            }
                            else
                            {
                                ++countR;
                            }
                        }
                    }
                    if(Ndir=='L' && countL<countR)
                    {
                        neareast = dist;
                        nearestInd = j;
                        Ndir = dir;
                    }
                }
            }
        }
        visited[nearestInd] = 1;
        totalHeadMovement += neareast;
        initialPos = requests[nearestInd];
        Sequence[i] = initialPos;
    }
    printf("\nSequence: ");
    for(int i=0;i<n;i++)
    {
        printf("%d ",Sequence[i]);
    }
    printf("\n");
    printf("\nTotal Head Movement: %d",totalHeadMovement);
    printf("\n");
    return 0;
}
