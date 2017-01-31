#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int nums;
    cin>>nums;
    int odd=0, oddidx, even=0, evenidx;
    int inp;
    for(int x=0; x<nums; x++)
    {
        cin>>inp;
        if(inp%2)
        {
            ++odd;
            oddidx=x+1;
        }
        else
        {
            ++even;
            evenidx=x+1;
        }
    }
    if(even>odd)
        cout<<oddidx<<"\n";
    else
        cout<<evenidx<<"\n";
    return 0;
}
