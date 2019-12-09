#include <bits/stdc++.h>
using namespace std;

int main()
{
    int i=0,n,initialPos,totalHeadMovement=0,maxR=199;
    cout<<"Enter total number of requests: ";cin>>n;
    int requests[n];
    int Sequence[n+2];
    int visited[n];
    memset(visited,0,sizeof(visited));
    cout<<"\nEnter Requests:\n";
    for(int i=0;i<n;i++)
    {
        cin>>requests[i];
    }
    cout<<"\nEnter Initial Head Position: ";cin>>initialPos;
    sort(requests,requests+n);
    int actualPos = initialPos;
    for(int j=0;j<n;j++)
    {
        if(requests[j]>initialPos && requests[j]!=maxR)
        {
            Sequence[i++] = requests[j];
            totalHeadMovement += (requests[j] - initialPos);
            initialPos = requests[j];
        }
    }
    totalHeadMovement += (maxR - initialPos);
    Sequence[i++] = maxR;
    totalHeadMovement += maxR;
    Sequence[i++] = 0;
    initialPos = 0;
    for(int j=0;j<n;j++)
    {
        if(requests[j]<actualPos)
        {
            if(requests[j]==0)
            {
                continue;
            }
            Sequence[i++] = requests[j];
            totalHeadMovement += (requests[j] - initialPos);
            initialPos = requests[j];
        }
    }
    cout<<"\nSequence: ";
    for(int j=0;j<i;j++)
    {
        cout<<Sequence[j]<<" ";
    }
    cout<<"\n\nTotal Head Movement: "<<totalHeadMovement<<"\n";
    return 0;
}
