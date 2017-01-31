#include <bits/stdc++.h>
using namespace std;
int main()
{
    int num;
    long long ans=1;
    cin>>num;
    ++num;
    ans<<=num;
    ans=ans-2;
    cout<<ans;
    return 0;
}
