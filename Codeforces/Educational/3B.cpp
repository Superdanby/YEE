#include <bits/stdc++.h>
using namespace std;
bool Small(const int &a, const int &b)
{
    return a<b;
}
int main()
{
    int Servers;
    cin>>Servers;
    int Server[Servers];
    int sum=0;
    for(int x=0; x<Servers; x++)
    {
        cin>>Server[x];
        sum+=Server[x];
        //cout<<sum<<"\t";
    }
    int average=sum/Servers;
    sort(Server,Server+Servers, Small);
    int cnt=0;
    int x;
    if(average*Servers==sum)
        x=0;
    else
        x=1;
    cout<<average;
    while(Server[0]-average!=0)
    {
        if(Server[Servers-1]-average==1)
            x=0;
        if((Server[Servers-1]-average-x)<=(average+x-Server[0]))
        {
            cnt+=Server[Servers-1]-average-x;
            Server[0]+=Server[Servers-1]-average-x;
            Server[Servers-1]=average+x;
        }
        else
        {
            cnt+=average+x-Server[0];
            Server[0]=average+x;
            Server[Servers-1]-=average+x-Server[0];
        }
        cout<<Server[0]<<
        cout<<cnt<<"\t";
        sort(Server,Server+Servers, Small);

    }
    cout<<cnt;
    return 0;
}
