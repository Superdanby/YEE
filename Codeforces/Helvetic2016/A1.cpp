#include <bits/stdc++.h>
using namespace std;
int main()
{
    unsigned int total;
    cin>>total;
    if(total&1)
        cout<<total/2+1<<"\n";
    else
        cout<<total/2<<"\n";
    return 0;
}
