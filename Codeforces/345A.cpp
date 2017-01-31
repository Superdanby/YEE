#include <bits/stdc++.h>
using namespace std;
int main()
{
    int first, second, cnt=0;
    cin>>first>>second;
    while(first>0 && second>0 )
    {
        if(first==1 && second==1)
            break;
        if(first>= second)
        {
            ++second;
            first-=2;
        }
        else
        {
            ++first;
            second-=2;
        }
        ++cnt;
    }
    cout<<cnt;
    return 0;
}
