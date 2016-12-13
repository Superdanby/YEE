#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int nums;
    cin>>nums;
    string inp;
    cin>>inp;
    int cnt=0;
    for(int x=1; x<nums; x++)
    {
        if(inp[x]==inp[x-1])
            ++cnt;
    }
    cout<<cnt<<"\n";
    return 0;
}
