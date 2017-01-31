#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int inp;
    cin>>inp;
    while(1)
    {
        bool stop=true;
        ++inp;
        int temp=inp;
        int number[10]={};
        while(temp)
        {
            if(number[temp%10])
            {
                stop=false;
            }
            else
                number[temp%10]=1;
            temp/=10;
        }
        if(stop)
            break;
    }
    cout<<inp<<"\n";
    return 0;
}
