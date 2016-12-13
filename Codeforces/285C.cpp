#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int nums;
    cin>>nums;
    int data[nums];
    for(int x=0; x<nums; x++)
    {
        cin>>data[x];
    }
    sort(data, data+nums);
    ll sum=0;
    for(int x=0; x<nums; x++)
    {
        sum+=abs(x+1-data[x]);
    }
    cout<<sum<<"\n";
    return 0;
}
