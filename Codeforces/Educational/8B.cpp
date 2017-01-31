#include <bits/stdc++.h>
using namespace std;
int main()
{
    string inp;
    cin>>inp;
    unsigned long long ans=0;
    for(int x=0; x<inp.length(); x++)
    {
        if(inp[x]-'0'==0 || inp[x]-'0'==4 || inp[x]-'0'==8)
        {
            if((inp[x-1]-'0')%2==0)
            ans+=x+1;
            else
            ++ans;
        }
        else if(inp[x]-'0'==2 || inp[x]-'0'==6)
        {
            if((inp[x-1]-'0')%2==1)
            ans+=x;
        }
    }
    cout<<ans;
    return 0;
}
