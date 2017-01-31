/*
    sqrt() is more precise than pow(T, 0.5);
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define Max 1000000
bool prime[Max+1];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    memset(prime, 0, sizeof(prime));
    for(int x=2; x<=Max; x++)
    {
        if(!prime[x])
            for(int y=x+x; y<=Max; y+=x)
                prime[y]=1;
    }
    prime[0]=1;
    prime[1]=1;
    /*int cnt=0;
    for(int x=0; x<=Max; x++)
    {
        if(!prime[x])
        {
            cout<<x<<"\n";
            ++cnt;
        }
    }
    cout<<cnt<<"\n";*/
    int nums;
    cin>>nums;
    ll inp, trans;
    for(int x=0; x<nums; x++)
    {
        cin>>inp;
        trans=sqrt(inp);
        if(!prime[trans] && trans*trans==inp)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
