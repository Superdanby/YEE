#include <bits/stdc++.h>
using namespace std;
int main()
{
    bool check[26];
    memset(check,0,sizeof(check));
    int length;
    cin>>length;
    string inp;
    cin>>inp;
    if(inp.length()>26)
    {
        cout<<"-1\n";
        return 0;
    }
    int cnt=0;
    for(c:inp)
    {
//        cout<<boolalpha<<check[0]<<"\n";
        if(!check[c-'a'])
            check[c-'a']=!check[c-'a'];
        else
            ++cnt;
    }
    cout<<cnt<<"\n";
    return 0;
}
