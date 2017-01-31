/*
#include <iostream>
using namespace std;
#define quan 3402
#define totw 12880
int dp[quan+1][totw+1]={};
int weight[quan+1];
int charm[quan+1];
int main()
{
    int limq, limw;
    cin>>limq>>limw;
    for(int x=1; x<=limq; x++)
    {
        cin>>weight[x]>>charm[x];
    }
    for(int x=1; x<=limq; x++)
        cout<<weight[x]<<" ";
        cout<<"\n";
    for(int x=1; x<=limq; x++)
        cout<<charm[x]<<" ";
        cout<<"\n";

    for(int x=1; x<=limq; x++)
    {
        for(int y=1; y<=limw; y++)
        {
            if(y-weight[x]>=0)
                dp[x][y]=max(dp[x-1][y-weight[x]]+charm[x], dp[x-1][y]);
            else
                dp[x][y]=dp[x-1][y];
        }
    }
    for(int x=0; x<=limq; x++)
    {
        for(int y=0; y<=limw; y++)
            cout<<setw(3)<<dp[x][y]<<" ";
        cout<<"\n";
    }
    cout<<dp[limq][limw]<<"\n";


    return 0;
}
*/
#include <iostream>
using namespace std;
#define quan 3402
#define totw 12880
int dp[totw+1]={};
int weight[quan+1];
int charm[quan+1];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int limq, limw;
    cin>>limq>>limw;
    for(int x=1; x<=limq; x++)
    {
        cin>>weight[x]>>charm[x];
    }
    for(int x=1; x<=limq; x++)
    {
        for(int y=limw; y>=weight[x]; y--)
        {
            dp[y]=max(dp[y-weight[x]]+charm[x], dp[y]);
        }
    }
    cout<<dp[limw]<<"\n";
    return 0;
}
