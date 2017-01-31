#include <bits/stdc++.h>
using namespace std;
int main()
{
    int query;
    cin>>query;
    string s;
    int x=1, num=0;
    while(true)
    {
        num+=1;
        int temp=num;
        stack<int> St;
        while(temp)
        {
            St.push(temp%10);
            temp/=10;
        }
        while(!St.empty())
        {
            if(x==query)
            {
                cout<<St.top()<<"\n";
                return 0;
            }
            St.pop();
            ++x;
        }
    }
    return 0;
}
