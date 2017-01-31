#include <bits/stdc++.h>
using namespace std;
int main()
{
    int sum=0, temp=0, ppl, bottles, towels;
    cin>>ppl>>bottles>>towels;
    int tto;
    tto=ppl*towels;
    while(ppl!=0)
    {
        ppl+=temp;
        temp=ppl%2;
        ppl/=2;
        sum+=ppl*(2*bottles+1);
    }
    cout<<sum<<" "<<tto;
    return 0;
}
