#include <iostream>

using namespace std;

int main()
{
    int pairs;
    cin>>pairs;
    int P[pairs];
    for(int x=0;x<pairs;x++)
    {
        int in;
        cin>>in;
        P[x]=in;
    }
    int cnt=0;
    for(int x=0;x<pairs;x++)
    {
        if(P[x]==1)
        {
            ++cnt;
        }
        if(P[x]==0 && P[x-1]==1 && P[x+1]==1)
        {
            ++cnt;
        }

    }
    cout<<cnt;
    return 0;
}
